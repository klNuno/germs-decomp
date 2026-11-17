#include "common.h"
#include "game/sound.h"
#include "game/main.h"
#include "kaj/kaj.h"
#include "kaj/misc.h"
#include "kaj/tss.h"
#include "psyq/libapi.h"
#include "psyq/libc.h"
#include "psyq/libgte.h"
#include "psyq/libsnd.h"

/*
 * Sound effects, the BGM sequences and VAB streaming, footsteps.
 *
 * File boundaries: likely (docs/layout.md): sound.c asserts.
 */

typedef struct { s16 from_table; s16 se_id; s16 prog; s16 tone; s16 note; s16 bank_id; s16 voice; s16 keyed_on; s16 priority; s16 pinned; } SoundVoice;
extern SoundVoice sound_voice_table[8];
typedef struct SeBank {
    s16 vab_id;
    u16 tone_count;
    s16 bank_id;
    s16 scene_bank;
    s32 vab_head;
} SeBank;
extern SceneTables object_scene_tables;
extern s16 kaj_system_sep_volume[];
typedef struct {
    u8 unk0[0x22];
    s16 type;
    s16 cur;
    s16 target;
    u8 unk28[8];
    void (*on_step)();
    void (*on_end)();
    u8 unk38[4];
    s32 *data;
} TssSlot_u801A217C;
s32 sound_footstep_clock;
s32 sound_footstep_count;
s32 sound_footstep_phase;
extern char sound_str_err_vab_head[];
extern char sound_str_err_stack_full[];
extern s32 object_scene_se_bank_count[];
extern char sound_str_file[];
extern char sound_str_err_vab_transfer[];
extern GameVars action_vars;
static void sound_bgm_fade_step(TssSlot_u801A217C *task);
extern char sound_str_err_alloc_bgm_handle[];
extern char sound_str_err_alloc_bgm_buf[];
extern KajSystem kaj_system;
extern char sound_str_err_alloc_se_header[];
s32 sound_footstep_prev_state;
extern s32 kaj_system_vsync_delta[];
typedef struct { s16 unk0; s16 unk2; s16 bank_id; s16 prog; s16 tone; s16 note; s16 vol_l; s16 vol_r; s16 pinned; s16 unk12; } SeTableEntry;
extern SeTableEntry sound_se_table[];
typedef struct { u8 unk0; u8 vol; u8 unk2; u8 unk3; u8 pan; u8 unk5[0xB]; } VabProgram;
typedef struct { u8 unk0; u8 unk1; u8 vol; u8 pan; u8 unk4[0x10]; s16 prog; u8 unk16[0x1EA]; } VabToneBlock;
typedef struct {
    u8 unk0[0x12];
    u16 prog_count;
    u8 unk14[4];
    u8 master_vol;
    u8 master_pan;
    u8 unk1A[6];
    VabProgram progs[128];
    VabToneBlock tones[1];
} VabHeader;

INCLUDE_RODATA("asm/nonmatchings/game/sound", sound_str_err_stack_full);

INCLUDE_RODATA("asm/nonmatchings/game/sound", sound_str_err_alloc_se_header);

INCLUDE_RODATA("asm/nonmatchings/game/sound", sound_str_err_vab_head);

INCLUDE_RODATA("asm/nonmatchings/game/sound", sound_str_err_vab_transfer);

void sound_se_push(SeVabStream *bank) {
    SceneTables *tables = &object_scene_tables;
    SeBank *se;
    s32 i;

    se = kaj_malloc(0xC);
    if (se == NULL) {
        kaj_abend(3, "Error Allocating SE Pointer", sound_str_file, 0xD1);
    }
    se->vab_id = bank->vab_id;
    se->tone_count = bank->tone_count;
    se->bank_id = bank->bank_id;
    se->scene_bank = bank->scene_bank;
    se->vab_head = bank->head;
    if (tables->se_bank_count == 0) {
        for (i = 0; i < 8; i++) {
            sound_voice_table[i].se_id = -1;
            sound_voice_table[i].prog = -1;
            sound_voice_table[i].tone = -1;
            sound_voice_table[i].note = -1;
            sound_voice_table[i].bank_id = -1;
            sound_voice_table[i].voice = -1;
            sound_voice_table[i].keyed_on = 0;
            sound_voice_table[i].pinned = 0;
            sound_voice_table[i].priority = 0;
        }
    }
    tables->se_banks[tables->se_bank_count++] = se;
}

void sound_se_pop(void) {
    SceneTables *tables = &object_scene_tables;
    SeBank *se;
    s32 i;

    if (tables->se_bank_count != 0) {
        se = tables->se_banks[--tables->se_bank_count];
        if (se != NULL) {
            for (i = 0; i < 8; i++) {
                if (sound_voice_table[i].bank_id == se->bank_id && sound_voice_table[i].voice >= 0) {
                    if (sound_voice_table[i].keyed_on != 0) {
                        SsUtKeyOffV(sound_voice_table[i].voice);
                    }
                    sound_voice_table[i].se_id = -1;
                    sound_voice_table[i].prog = -1;
                    sound_voice_table[i].tone = -1;
                    sound_voice_table[i].note = -1;
                    sound_voice_table[i].bank_id = -1;
                    sound_voice_table[i].voice = -1;
                    sound_voice_table[i].keyed_on = 0;
                    sound_voice_table[i].pinned = 0;
                    sound_voice_table[i].priority = 0;
                }
            }
            if (se->vab_id >= 0) {
                SsVabClose(se->vab_id);
            }
            free3((void *)se->vab_head);
            free3(se);
            tables->se_banks[tables->se_bank_count] = NULL;
        }
    }
}

void sound_se_pop_scene(void) {
    SceneTables *tables = &object_scene_tables;
    SeBank *se;
    s32 i;

    if (tables->se_bank_count != 0) {
        se = tables->se_banks[tables->se_bank_count - 1];
        while (se->scene_bank > 0) {
            if (se != NULL) {
                for (i = 0; i < 8; i++) {
                    if (sound_voice_table[i].bank_id == se->bank_id && sound_voice_table[i].voice >= 0) {
                        if (sound_voice_table[i].keyed_on != 0) {
                            SsUtKeyOffV(sound_voice_table[i].voice);
                        }
                        sound_voice_table[i].se_id = -1;
                        sound_voice_table[i].prog = -1;
                        sound_voice_table[i].tone = -1;
                        sound_voice_table[i].note = -1;
                        sound_voice_table[i].bank_id = -1;
                        sound_voice_table[i].voice = -1;
                        sound_voice_table[i].keyed_on = 0;
                        sound_voice_table[i].pinned = 0;
                        sound_voice_table[i].priority = 0;
                    }
                }
                if (se->vab_id >= 0) {
                    SsVabClose(se->vab_id);
                }
                free3((void *)se->vab_head);
                free3(se);
                tables->se_banks[--tables->se_bank_count] = NULL;
                se = tables->se_banks[tables->se_bank_count - 1];
            }
        }
    }
}

void sound_se_stop_all(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (sound_voice_table[i].keyed_on != 0) {
            sound_voice_table[i].keyed_on = 0;
            if (sound_voice_table[i].pinned != 0) {
                sound_voice_table[i].priority = 0;
            } else {
                sound_voice_table[i].priority--;
            }
            SsUtKeyOffV(sound_voice_table[i].voice);
        }
    }
}

void sound_se_stop(s32 id) {
    s32 voice;

    for (voice = 0; voice < 8; voice++) {
        if (sound_voice_table[voice].from_table == 1 && sound_voice_table[voice].se_id == id) {
            break;
        }
    }
    if (voice != 8) {
        sound_voice_table[voice].keyed_on = 0;
        if (sound_voice_table[voice].pinned != 0) {
            sound_voice_table[voice].priority = 0;
        } else {
            sound_voice_table[voice].priority--;
        }
        SsUtKeyOffV(sound_voice_table[voice].voice);
    }
}

void sound_se_play(s32 id) {
    SceneTables *tables = &object_scene_tables;
    SeTableEntry *ent;
    SeBank *se;
    VabToneBlock *tone;
    s16 vol[2];
    s32 i;
    s16 pan;
    u8 level;
    VabProgram *prg;
    s16 min;
    s16 oldest;

    se = NULL;
    ent = &sound_se_table[id];
    for (i = 0; i < tables->se_bank_count; i++) {
        se = tables->se_banks[i];
        if (se->bank_id == ent->bank_id) {
            break;
        }
    }
    if (i == tables->se_bank_count) {
        return;
    }
    if (ent->vol_l != -1) {
        vol[0] = ent->vol_l;
    } else {
        vol[0] = 0x7F;
    }
    if (ent->vol_r != -1) {
        vol[1] = ent->vol_r;
    } else {
        vol[1] = 0x7F;
    }

    level = ((VabHeader *)se->vab_head)->master_vol;
    pan = ((VabHeader *)se->vab_head)->master_pan;
    vol[0] = vol[0] * level >> 7;
    vol[1] = vol[1] * level >> 7;
    if (pan < 0x40) {
        vol[1] = vol[1] / (0x40 - pan);
    } else if (pan > 0x40) {
        vol[0] = vol[0] / (pan - 0x40);
    }

    prg = &((VabHeader *)se->vab_head)->progs[ent->prog];
    level = prg->vol;
    pan = prg->pan;
    vol[0] = vol[0] * level >> 7;
    vol[1] = vol[1] * level >> 7;
    if (pan < 0x40) {
        vol[1] = vol[1] / (0x40 - pan);
    } else if (pan > 0x40) {
        vol[0] = vol[0] / (pan - 0x40);
    }

    tone = ((VabHeader *)se->vab_head)->tones;
    for (i = 0; i < ((VabHeader *)se->vab_head)->prog_count; i++, tone++) {
        if (tone->prog == ent->prog) {
            break;
        }
    }
    if (i < ((VabHeader *)se->vab_head)->prog_count) {
        level = tone->vol;
        pan = tone->pan;
        vol[0] = vol[0] * level >> 7;
        vol[1] = vol[1] * level >> 7;
        if (pan < 0x40) {
            vol[1] = vol[1] / (0x40 - pan);
        } else if (pan > 0x40) {
            vol[0] = vol[0] / (pan - 0x40);
        }
    }

    for (i = 0; i < 8; i++) {
        if (sound_voice_table[i].from_table == 1 && sound_voice_table[i].se_id == id) {
            break;
        }
    }
    if (i == 8) {
        min = 0x7FFF;
        oldest = -1;
        for (i = 0; i < 8; i++) {
            if (sound_voice_table[i].voice == -1) {
                break;
            }
            if (sound_voice_table[i].priority < min) {
                oldest = i;
                min = sound_voice_table[i].priority;
            }
        }
        if (i == 8) {
            i = 0;
            if (oldest != -1) {
                i = oldest;
            }
            sound_voice_table[i].priority = 0;
            SsUtKeyOffV(sound_voice_table[i].voice);
        }
        sound_voice_table[i].from_table = 1;
        sound_voice_table[i].se_id = id;
        sound_voice_table[i].bank_id = se->bank_id;
        sound_voice_table[i].voice = SsUtKeyOnV(i, se->vab_id, ent->prog, ent->tone, ent->note, 0, vol[0], vol[1]);
        sound_voice_table[i].keyed_on = 1;
        sound_voice_table[i].pinned = ent->pinned;
        if (ent->pinned != 0) {
            sound_voice_table[i].priority = 0x7FFF;
        } else {
            sound_voice_table[i].priority++;
        }
    } else {
        if (sound_voice_table[i].keyed_on != 0) {
            SsUtKeyOffV(sound_voice_table[i].voice);
        }
        sound_voice_table[i].voice = SsUtKeyOnV(sound_voice_table[i].voice, se->vab_id, ent->prog, ent->tone, ent->note, 0, vol[0], vol[1]);
        if (sound_voice_table[i].pinned == 0) {
            sound_voice_table[i].priority++;
        }
    }
}

void sound_se_play_note(s16 bank_id, s16 prog, s16 tone_no, s16 note, s16 vol_l, s16 vol_r, s16 pin) {
    SceneTables *tables = &object_scene_tables;
    SeBank *se;
    VabToneBlock *tone;
    s16 vol[2];
    s16 flag;
    s32 i;
    s16 pan;
    u8 level;
    VabProgram *prg;
    s16 min;
    s16 oldest;

    vol[0] = vol_l;
    vol[1] = vol_r;
    se = NULL;
    flag = pin;
    for (i = 0; i < tables->se_bank_count; i++) {
        se = tables->se_banks[i];
        if (se->bank_id == bank_id) {
            break;
        }
    }
    if (i == tables->se_bank_count) {
        return;
    }
    level = ((VabHeader *)se->vab_head)->master_vol;
    pan = ((VabHeader *)se->vab_head)->master_pan;
    vol[0] = vol[0] * level >> 7;
    vol[1] = vol[1] * level >> 7;
    if (pan < 0x40) {
        vol[1] = vol[1] / (0x40 - pan);
    } else if (pan > 0x40) {
        vol[0] = vol[0] / (pan - 0x40);
    }

    prg = &((VabHeader *)se->vab_head)->progs[prog];
    level = prg->vol;
    pan = prg->pan;
    vol[0] = vol[0] * level >> 7;
    vol[1] = vol[1] * level >> 7;
    if (pan < 0x40) {
        vol[1] = vol[1] / (0x40 - pan);
    } else if (pan > 0x40) {
        vol[0] = vol[0] / (pan - 0x40);
    }

    tone = ((VabHeader *)se->vab_head)->tones;
    for (i = 0; i < ((VabHeader *)se->vab_head)->prog_count; i++, tone++) {
        if (tone->prog == prog) {
            break;
        }
    }
    if (i < ((VabHeader *)se->vab_head)->prog_count) {
        level = tone->vol;
        pan = tone->pan;
        vol[0] = vol[0] * level >> 7;
        vol[1] = vol[1] * level >> 7;
        if (pan < 0x40) {
            vol[1] = vol[1] / (0x40 - pan);
        } else if (pan > 0x40) {
            vol[0] = vol[0] / (pan - 0x40);
        }
    }

    for (i = 0; i < 8; i++) {
        if (sound_voice_table[i].from_table == 0 && sound_voice_table[i].prog == prog && sound_voice_table[i].tone == tone_no && sound_voice_table[i].note == note) {
            break;
        }
    }
    if (i == 8) {
        min = 0x7FFF;
        oldest = -1;
        for (i = 0; i < 8; i++) {
            if (sound_voice_table[i].voice == -1) {
                break;
            }
            if (sound_voice_table[i].priority < min) {
                oldest = i;
                min = sound_voice_table[i].priority;
            }
        }
        if (i == 8) {
            i = 0;
            if (oldest != -1) {
                i = oldest;
            }
            sound_voice_table[i].priority = 0;
            SsUtKeyOffV(sound_voice_table[i].voice);
        }
        sound_voice_table[i].from_table = 0;
        sound_voice_table[i].prog = prog;
        sound_voice_table[i].tone = tone_no;
        sound_voice_table[i].note = note;
        sound_voice_table[i].bank_id = se->bank_id;
        sound_voice_table[i].voice = SsUtKeyOnV(i, se->vab_id, prog, tone_no, note, 0, vol[0], vol[1]);
        sound_voice_table[i].keyed_on = 1;
        sound_voice_table[i].pinned = flag;
        if (flag != 0) {
            sound_voice_table[i].priority = 0x7FFF;
        } else {
            sound_voice_table[i].priority++;
        }
    } else {
        if (sound_voice_table[i].keyed_on != 0) {
            SsUtKeyOffV(sound_voice_table[i].voice);
        }
        sound_voice_table[i].voice = SsUtKeyOnV(sound_voice_table[i].voice, se->vab_id, prog, tone_no, note, 0, vol[0], vol[1]);
        if (flag == 0) {
            sound_voice_table[i].priority++;
        }
    }
}

void sound_exec_command(Action *cmd) {
    s32 bank_id, prog, tone_no, note, e, vol_l, vol_r, pin;

    if (cmd->argc >= 5) {
        bank_id = atoi(cmd->args[0]);
        prog = atoi(cmd->args[1]);
        tone_no = atoi(cmd->args[2]);
        note = atoi(cmd->args[3]);
        e = atoi(cmd->args[4]);
        if (cmd->argc == 8) {
            vol_l = atoi(cmd->args[5]);
            vol_r = atoi(cmd->args[6]);
            pin = atoi(cmd->args[7]);
        } else if (cmd->argc == 7) {
            vol_l = atoi(cmd->args[5]);
            vol_r = atoi(cmd->args[6]);
            pin = 0;
        } else {
            vol_l = 0x7F;
            vol_r = 0x7F;
            pin = 0;
        }
        sound_se_play_note(bank_id, prog, tone_no, note, vol_l, vol_r, pin);
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/sound", sound_str_err_alloc_bgm_handle);

INCLUDE_RODATA("asm/nonmatchings/game/sound", sound_str_err_alloc_bgm_buf);

void sound_bgm_open(BgmSep *bgm) {
    SceneTables *tables = &object_scene_tables;
    SeBank *se = NULL;
    s32 i;

    if (tables->se_bank_count == 0) {
        kaj_abend(8, "VAB is not Ready", sound_str_file, 0x253);
    }
    for (i = 0; i < tables->se_bank_count; i++) {
        se = tables->se_banks[i];
        if (se->bank_id == 2) {
            break;
        }
        se = NULL;
    }
    if (se == NULL) {
        kaj_abend(8, "VAB is not Ready", sound_str_file, 0x25C);
    }
    bgm->seq_count = *(s32 *)bgm->data;
    if (bgm->seq_count >= 4) {
        kaj_abend(8, "Too Many SEQ in This SEP", sound_str_file, 0x260);
    }
    if (tables->bgm != NULL) {
        sound_bgm_close();
    }
    bgm->sep = SsSepOpen((u32 *)bgm->data + 1, se->vab_id, bgm->seq_count);
    if (bgm->sep < 0) {
        kaj_abend(8, "Can not Open Specified SEP", sound_str_file, 0x268);
    }
    for (i = 0; i < bgm->seq_count; i++) {
        SsSepSetVol(bgm->sep, i, kaj_system.sep_volume, kaj_system.sep_volume);
    }
    tables->bgm = bgm;
}

void sound_footstep_update(Player_u801A217C *player) {
    s32 dt = kaj_system_vsync_delta[0];
    s16 period;
    s32 period32;
    s32 angle;
    s32 step;
    s16 wrapped;

    sound_footstep_clock += dt;
    if (sound_footstep_clock > 12000) {
        sound_footstep_clock -= 12000;
    }
    switch (sound_footstep_prev_state) {
    case 2:
        if (player->move_state == 1 || player->move_state == 3) {
            player->bob_y = 0;
            sound_footstep_clock = 0;
            sound_footstep_count = 0;
            sound_footstep_phase = 0;
        }
        break;
    case 1:
    case 3:
        if (player->move_state == 2) {
            player->bob_y = 0;
            sound_footstep_clock = 0;
            sound_footstep_count = 0;
            sound_footstep_phase = 0;
        }
        break;
    }
    sound_footstep_prev_state = player->move_state;
    switch (player->move_state) {
    case 2:
        period = 15;
        break;
    case 1:
    case 3:
        period = 30;
        break;
    default:
        goto reset;
    }
    period32 = period;
    angle = ((sound_footstep_phase * 360 << 12) / period32 - 90) >> 12;
    sound_footstep_phase += dt;
    step = sound_footstep_clock / period32;
    if (sound_footstep_phase > period32) {
        sound_footstep_phase = period32;
    }
    wrapped = mail_wrap_angle(angle);
    player->bob_y = rsin((s16)((wrapped << 12) / 360)) * 25 / 4096 + 25;
    if (step != sound_footstep_count) {
        sound_se_play(3);
        player->bob_y = 0;
        sound_footstep_phase = 0;
    }
    sound_footstep_count = step;
    return;
reset:
    player->bob_y = 0;
    sound_footstep_clock = 0;
    sound_footstep_count = 0;
    sound_footstep_phase = 0;
    if (player->move_state == 4) {
        sound_se_play(0xE);
    }
}

VabHeadCopy *sound_se_alloc_header(u16 *src, s32 size, SeVabStream *bank) {
    SceneTables *tables = &object_scene_tables;

    memset(bank, 0, 0x1C);
    if (tables->se_bank_count == 4) {
        kaj_abend(0xD, sound_str_err_stack_full, sound_str_file, 0x99);
    }
    bank->bank_id = src[0];
    bank->scene_bank = src[1];
    src += 2;
    bank->head_size = size - 4;
    bank->head = (s32)kaj_malloc(size - 4);
    if (bank->head == 0) {
        kaj_abend(3, sound_str_err_alloc_se_header, sound_str_file, 0xA2);
    }
    *(VabHeadCopy *)bank->head = *(VabHeadCopy *)src;
    bank->tone_count = ((VabHeadCopy *)bank->head)->tone_count;
    return (VabHeadCopy *)bank->head + 1;
}

void sound_vab_open_head(VabStream *vab) {
    if (object_scene_se_bank_count[0] == 4) {
        kaj_abend(0xD, sound_str_err_stack_full, sound_str_file, 0xB5);
    }
    vab->vab_id = SsVabOpenHead(vab->head, -1);
    if (vab->vab_id < 0) {
        kaj_abend(8, sound_str_err_vab_head, sound_str_file, 0xB9);
    }
}

void sound_vab_transfer(VabStream *vab) {
    if (SsVabTransBodyPartly(vab->body_buf, vab->body_len, vab->vab_id) == -1) {
        kaj_abend(8, sound_str_err_vab_transfer, sound_str_file, 0xC4);
    }
    SsVabTransCompleted(1);
}

void sound_se_pop_all(void) {
    SceneTables *tables = &object_scene_tables;

    while (tables->se_bank_count > 0) {
        sound_se_pop();
    }
}

void sound_bgm_create(BgmSep **out, u32 size) {
    *out = kaj_malloc(0xC);
    if (*out == NULL) {
        kaj_abend(3, sound_str_err_alloc_bgm_handle, sound_str_file, 0x241);
    }
    (*out)->sep = -1;
    (*out)->seq = -1;
    (*out)->seq_count = 0;
    (*out)->data = kaj_malloc(size);
    if ((*out)->data == NULL) {
        kaj_abend(3, sound_str_err_alloc_bgm_buf, sound_str_file, 0x249);
    }
}

void sound_bgm_close(void) {
    BgmSep *bgm = object_scene_tables.bgm;

    if (bgm != NULL) {
        if (bgm->sep >= 0) {
            SsSepClose(bgm->sep);
        }
        if (bgm->data != NULL) {
            free3(bgm->data);
        }
        free3(bgm);
        object_scene_tables.bgm = NULL;
    }
}

void sound_bgm_play(s16 seq) {
    BgmSep *bgm = object_scene_tables.bgm;

    if (bgm != NULL && bgm->seq != seq && seq < bgm->seq_count) {
        if (bgm->seq != -1) {
            sound_bgm_stop();
        }
        bgm->seq = seq;
        SsSepPlay(bgm->sep, seq, 1, 0);
    }
}

void sound_bgm_stop(void) {
    BgmSep *bgm = object_scene_tables.bgm;

    if (bgm != NULL && bgm->seq >= 0) {
        SsSepStop(bgm->sep, bgm->seq);
        SsSepSetVol(bgm->sep, bgm->seq, kaj_system_sep_volume[0], kaj_system_sep_volume[0]);
        bgm->seq = -1;
    }
}

void sound_bgm_fade_out(s32 seconds) {
    GameVars *game = &action_vars;
    BgmSep *bgm = object_scene_tables.bgm;
    TssSlot_u801A217C *node;

    if (bgm != NULL && bgm->seq >= 0) {
        node = kaj_tss_alloc(4);
        node->type = 0xD;
        node->cur = kaj_system_sep_volume[0];
        node->target = 0;
        kaj_tss_set_steps(node, seconds * 30);
        node->on_step = sound_bgm_fade_step;
        node->on_end = sound_bgm_fade_step;
        *node->data = node->type;
        game->effect_task = kaj_tss_start(node);
    }
}

static void sound_bgm_fade_step(TssSlot_u801A217C *task) {
    BgmSep *bgm = object_scene_tables.bgm;
    s32 volume = (task->cur < task->target) ? task->target : task->cur;

    SsSepSetVol(bgm->sep, bgm->seq, volume, volume);
}

void sound_footstep_reset(Player_u801A217C *player) {
    player->bob_y = 0;
    sound_footstep_clock = 0;
    sound_footstep_count = 0;
    sound_footstep_phase = 0;
}

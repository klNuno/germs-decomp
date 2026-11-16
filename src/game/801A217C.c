#include "common.h"
#include "game/types.h"

typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; } Unk_801E1078;
extern Unk_801E1078 sound_voice_table[8];
void SsUtKeyOffV(s16 voice);
typedef struct Unk_801E02DC {
    s16 unk0;
    u16 unk2;
    s16 unk4;
    s16 unk6;
    s32 unk8;
} Unk_801E02DC;
extern SceneTables object_scene_tables;
void sound_se_pop(void);
void SsSepClose(s16 access_num);
void free3(void *ptr);
void sound_bgm_stop(void);
void SsSepPlay(s16 access_num, s16 seq_num, u8 play_mode, s16 l_count);
extern s16 D_801E6DB8[];
void SsSepStop(s16 access_num, s16 seq_num);
void SsSepSetVol(s16 access_num, s16 seq_num, s16 voll, s16 volr);
typedef struct {
    u8 unk0[0x22];
    s16 unk22;
    s16 unk24;
    s16 unk26;
    u8 unk28[8];
    void (*unk30)();
    void (*unk34)();
    u8 unk38[4];
    s32 *unk3C;
} Unk_801A3D74;
typedef struct { u8 unk0[0x4C]; s16 unk4C; } Unk_801A3DBC;
s32 sound_footstep_clock;
s32 sound_footstep_count;
s32 sound_footstep_phase;
extern char D_80171724[];
extern char D_801716EC[];
extern s32 D_801E02EC[];
s16 SsVabOpenHead(u8 *addr, s16 vabid);
extern char sound_str_file[];
void kaj_abend(s32 a, char *b, char *c, s32 d);
extern char D_8017173C[];
s16 SsVabTransBodyPartly(u8 *addr, u32 bufsize, s16 vabid);
s16 SsVabTransCompleted(s16 immediateFlag);
extern GameVars action_vars;
void *kaj_tss_alloc(u32 arg0);
void kaj_tss_set_steps(void *arg0, s32 arg1);
s32 kaj_tss_start(void *arg0);
void sound_bgm_fade_step(Unk_801A3D74 *arg0);
void *kaj_malloc(u32 size);
extern char D_80171770[];
extern char D_8017178C[];
void SsVabClose(s16 vabid);
typedef struct { s32 unk0; s32 unk4; char **unk8; } Unk_801A324C;
s32 atoi(char *s);
void sound_se_play_note(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6);
void sound_bgm_close(void);
extern KajSystem kaj_system;
s16 SsSepOpen(u32 *addr, s16 vab_id, s16 seq_num);
extern char D_80171708[];
typedef struct { u16 unk0[0xA]; u16 unk14; u8 unk16[0x7DE]; } Unk_801A37E4;
void *memset(void *dst, s32 c, u32 n);
typedef struct { u8 unk0[0x44]; u16 unk44; u8 unk46[6]; s16 unk4C; } Unk_801A358C;
s32 sound_footstep_prev_state;
extern s32 kaj_system_vsync_delta[];
s16 mail_wrap_angle(s16 a);
s32 rsin(s32 a);
void sound_se_play(s32 arg0);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; } Unk_801D7B58;
extern Unk_801D7B58 sound_se_table[];
typedef struct { u8 unk0; u8 unk1; u8 unk2; u8 unk3; u8 unk4; u8 unk5[0xB]; } Unk_801A2678_20;
typedef struct { u8 unk0; u8 unk1; u8 unk2; u8 unk3; u8 unk4[0x10]; s16 unk14; u8 unk16[0x1EA]; } Unk_801A2678_820;
typedef struct {
    u8 unk0[0x12];
    u16 unk12;
    u8 unk14[4];
    u8 unk18;
    u8 unk19;
    u8 unk1A[6];
    Unk_801A2678_20 unk20[128];
    Unk_801A2678_820 unk820[1];
} Unk_801A2678;
s16 SsUtKeyOnV(s16 voice, s16 vabId, s16 prog, s16 tone, s16 note, s16 fine, s16 voll, s16 volr);
typedef struct { u8 unk0; u8 unk1; u8 unk2; u8 unk3; u8 unk4; u8 unk5[0xB]; } Unk_801A2C60_20;
typedef struct { u8 unk0; u8 unk1; u8 unk2; u8 unk3; u8 unk4[0x10]; s16 unk14; u8 unk16[0x1EA]; } Unk_801A2C60_820;
typedef struct {
    u8 unk0[0x12];
    u16 unk12;
    u8 unk14[4];
    u8 unk18;
    u8 unk19;
    u8 unk1A[6];
    Unk_801A2C60_20 unk20[128];
    Unk_801A2C60_820 unk820[1];
} Unk_801A2C60;

INCLUDE_RODATA("asm/nonmatchings/game/801A217C", D_801716EC);

INCLUDE_RODATA("asm/nonmatchings/game/801A217C", D_80171708);

INCLUDE_RODATA("asm/nonmatchings/game/801A217C", D_80171724);

INCLUDE_RODATA("asm/nonmatchings/game/801A217C", D_8017173C);

void sound_se_push(Unk_801A217C *bank) {
    SceneTables *tables = &object_scene_tables;
    Unk_801E02DC *se;
    s32 i;

    se = kaj_malloc(0xC);
    if (se == NULL) {
        kaj_abend(3, "Error Allocating SE Pointer", sound_str_file, 0xD1);
    }
    se->unk0 = bank->unk14;
    se->unk2 = bank->unk16;
    se->unk4 = bank->unk18;
    se->unk6 = bank->unk1A;
    se->unk8 = bank->unk4;
    if (tables->se_bank_count == 0) {
        for (i = 0; i < 8; i++) {
            sound_voice_table[i].unk2 = -1;
            sound_voice_table[i].unk4 = -1;
            sound_voice_table[i].unk6 = -1;
            sound_voice_table[i].unk8 = -1;
            sound_voice_table[i].unkA = -1;
            sound_voice_table[i].unkC = -1;
            sound_voice_table[i].unkE = 0;
            sound_voice_table[i].unk12 = 0;
            sound_voice_table[i].unk10 = 0;
        }
    }
    tables->se_banks[tables->se_bank_count++] = se;
}

void sound_se_pop(void) {
    SceneTables *tables = &object_scene_tables;
    Unk_801E02DC *se;
    s32 i;

    if (tables->se_bank_count != 0) {
        se = tables->se_banks[--tables->se_bank_count];
        if (se != NULL) {
            for (i = 0; i < 8; i++) {
                if (sound_voice_table[i].unkA == se->unk4 && sound_voice_table[i].unkC >= 0) {
                    if (sound_voice_table[i].unkE != 0) {
                        SsUtKeyOffV(sound_voice_table[i].unkC);
                    }
                    sound_voice_table[i].unk2 = -1;
                    sound_voice_table[i].unk4 = -1;
                    sound_voice_table[i].unk6 = -1;
                    sound_voice_table[i].unk8 = -1;
                    sound_voice_table[i].unkA = -1;
                    sound_voice_table[i].unkC = -1;
                    sound_voice_table[i].unkE = 0;
                    sound_voice_table[i].unk12 = 0;
                    sound_voice_table[i].unk10 = 0;
                }
            }
            if (se->unk0 >= 0) {
                SsVabClose(se->unk0);
            }
            free3((void *)se->unk8);
            free3(se);
            tables->se_banks[tables->se_bank_count] = NULL;
        }
    }
}

void sound_se_pop_scene(void) {
    SceneTables *tables = &object_scene_tables;
    Unk_801E02DC *se;
    s32 i;

    if (tables->se_bank_count != 0) {
        se = tables->se_banks[tables->se_bank_count - 1];
        while (se->unk6 > 0) {
            if (se != NULL) {
                for (i = 0; i < 8; i++) {
                    if (sound_voice_table[i].unkA == se->unk4 && sound_voice_table[i].unkC >= 0) {
                        if (sound_voice_table[i].unkE != 0) {
                            SsUtKeyOffV(sound_voice_table[i].unkC);
                        }
                        sound_voice_table[i].unk2 = -1;
                        sound_voice_table[i].unk4 = -1;
                        sound_voice_table[i].unk6 = -1;
                        sound_voice_table[i].unk8 = -1;
                        sound_voice_table[i].unkA = -1;
                        sound_voice_table[i].unkC = -1;
                        sound_voice_table[i].unkE = 0;
                        sound_voice_table[i].unk12 = 0;
                        sound_voice_table[i].unk10 = 0;
                    }
                }
                if (se->unk0 >= 0) {
                    SsVabClose(se->unk0);
                }
                free3((void *)se->unk8);
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
        if (sound_voice_table[i].unkE != 0) {
            sound_voice_table[i].unkE = 0;
            if (sound_voice_table[i].unk12 != 0) {
                sound_voice_table[i].unk10 = 0;
            } else {
                sound_voice_table[i].unk10--;
            }
            SsUtKeyOffV(sound_voice_table[i].unkC);
        }
    }
}

void sound_se_stop(s32 id) {
    s32 voice;

    for (voice = 0; voice < 8; voice++) {
        if (sound_voice_table[voice].unk0 == 1 && sound_voice_table[voice].unk2 == id) {
            break;
        }
    }
    if (voice != 8) {
        sound_voice_table[voice].unkE = 0;
        if (sound_voice_table[voice].unk12 != 0) {
            sound_voice_table[voice].unk10 = 0;
        } else {
            sound_voice_table[voice].unk10--;
        }
        SsUtKeyOffV(sound_voice_table[voice].unkC);
    }
}

void sound_se_play(s32 id) {
    SceneTables *tables = &object_scene_tables;
    Unk_801D7B58 *ent;
    Unk_801E02DC *se;
    Unk_801A2678_820 *tone;
    s16 vol[2];
    s32 i;
    s16 pan;
    u8 level;
    Unk_801A2678_20 *prg;
    s16 min;
    s16 oldest;

    se = NULL;
    ent = &sound_se_table[id];
    for (i = 0; i < tables->se_bank_count; i++) {
        se = tables->se_banks[i];
        if (se->unk4 == ent->unk4) {
            break;
        }
    }
    if (i == tables->se_bank_count) {
        return;
    }
    if (ent->unkC != -1) {
        vol[0] = ent->unkC;
    } else {
        vol[0] = 0x7F;
    }
    if (ent->unkE != -1) {
        vol[1] = ent->unkE;
    } else {
        vol[1] = 0x7F;
    }

    level = ((Unk_801A2678 *)se->unk8)->unk18;
    pan = ((Unk_801A2678 *)se->unk8)->unk19;
    vol[0] = vol[0] * level >> 7;
    vol[1] = vol[1] * level >> 7;
    if (pan < 0x40) {
        vol[1] = vol[1] / (0x40 - pan);
    } else if (pan > 0x40) {
        vol[0] = vol[0] / (pan - 0x40);
    }

    prg = &((Unk_801A2678 *)se->unk8)->unk20[ent->unk6];
    level = prg->unk1;
    pan = prg->unk4;
    vol[0] = vol[0] * level >> 7;
    vol[1] = vol[1] * level >> 7;
    if (pan < 0x40) {
        vol[1] = vol[1] / (0x40 - pan);
    } else if (pan > 0x40) {
        vol[0] = vol[0] / (pan - 0x40);
    }

    tone = ((Unk_801A2678 *)se->unk8)->unk820;
    for (i = 0; i < ((Unk_801A2678 *)se->unk8)->unk12; i++, tone++) {
        if (tone->unk14 == ent->unk6) {
            break;
        }
    }
    if (i < ((Unk_801A2678 *)se->unk8)->unk12) {
        level = tone->unk2;
        pan = tone->unk3;
        vol[0] = vol[0] * level >> 7;
        vol[1] = vol[1] * level >> 7;
        if (pan < 0x40) {
            vol[1] = vol[1] / (0x40 - pan);
        } else if (pan > 0x40) {
            vol[0] = vol[0] / (pan - 0x40);
        }
    }

    for (i = 0; i < 8; i++) {
        if (sound_voice_table[i].unk0 == 1 && sound_voice_table[i].unk2 == id) {
            break;
        }
    }
    if (i == 8) {
        min = 0x7FFF;
        oldest = -1;
        for (i = 0; i < 8; i++) {
            if (sound_voice_table[i].unkC == -1) {
                break;
            }
            if (sound_voice_table[i].unk10 < min) {
                oldest = i;
                min = sound_voice_table[i].unk10;
            }
        }
        if (i == 8) {
            i = 0;
            if (oldest != -1) {
                i = oldest;
            }
            sound_voice_table[i].unk10 = 0;
            SsUtKeyOffV(sound_voice_table[i].unkC);
        }
        sound_voice_table[i].unk0 = 1;
        sound_voice_table[i].unk2 = id;
        sound_voice_table[i].unkA = se->unk4;
        sound_voice_table[i].unkC = SsUtKeyOnV(i, se->unk0, ent->unk6, ent->unk8, ent->unkA, 0, vol[0], vol[1]);
        sound_voice_table[i].unkE = 1;
        sound_voice_table[i].unk12 = ent->unk10;
        if (ent->unk10 != 0) {
            sound_voice_table[i].unk10 = 0x7FFF;
        } else {
            sound_voice_table[i].unk10++;
        }
    } else {
        if (sound_voice_table[i].unkE != 0) {
            SsUtKeyOffV(sound_voice_table[i].unkC);
        }
        sound_voice_table[i].unkC = SsUtKeyOnV(sound_voice_table[i].unkC, se->unk0, ent->unk6, ent->unk8, ent->unkA, 0, vol[0], vol[1]);
        if (sound_voice_table[i].unk12 == 0) {
            sound_voice_table[i].unk10++;
        }
    }
}

void sound_se_play_note(s16 bank_id, s16 prog, s16 tone_no, s16 note, s16 vol_l, s16 vol_r, s16 pin) {
    SceneTables *tables = &object_scene_tables;
    Unk_801E02DC *se;
    Unk_801A2C60_820 *tone;
    s16 vol[2];
    s16 flag;
    s32 i;
    s16 pan;
    u8 level;
    Unk_801A2C60_20 *prg;
    s16 min;
    s16 oldest;

    vol[0] = vol_l;
    vol[1] = vol_r;
    se = NULL;
    flag = pin;
    for (i = 0; i < tables->se_bank_count; i++) {
        se = tables->se_banks[i];
        if (se->unk4 == bank_id) {
            break;
        }
    }
    if (i == tables->se_bank_count) {
        return;
    }
    level = ((Unk_801A2C60 *)se->unk8)->unk18;
    pan = ((Unk_801A2C60 *)se->unk8)->unk19;
    vol[0] = vol[0] * level >> 7;
    vol[1] = vol[1] * level >> 7;
    if (pan < 0x40) {
        vol[1] = vol[1] / (0x40 - pan);
    } else if (pan > 0x40) {
        vol[0] = vol[0] / (pan - 0x40);
    }

    prg = &((Unk_801A2C60 *)se->unk8)->unk20[prog];
    level = prg->unk1;
    pan = prg->unk4;
    vol[0] = vol[0] * level >> 7;
    vol[1] = vol[1] * level >> 7;
    if (pan < 0x40) {
        vol[1] = vol[1] / (0x40 - pan);
    } else if (pan > 0x40) {
        vol[0] = vol[0] / (pan - 0x40);
    }

    tone = ((Unk_801A2C60 *)se->unk8)->unk820;
    for (i = 0; i < ((Unk_801A2C60 *)se->unk8)->unk12; i++, tone++) {
        if (tone->unk14 == prog) {
            break;
        }
    }
    if (i < ((Unk_801A2C60 *)se->unk8)->unk12) {
        level = tone->unk2;
        pan = tone->unk3;
        vol[0] = vol[0] * level >> 7;
        vol[1] = vol[1] * level >> 7;
        if (pan < 0x40) {
            vol[1] = vol[1] / (0x40 - pan);
        } else if (pan > 0x40) {
            vol[0] = vol[0] / (pan - 0x40);
        }
    }

    for (i = 0; i < 8; i++) {
        if (sound_voice_table[i].unk0 == 0 && sound_voice_table[i].unk4 == prog && sound_voice_table[i].unk6 == tone_no && sound_voice_table[i].unk8 == note) {
            break;
        }
    }
    if (i == 8) {
        min = 0x7FFF;
        oldest = -1;
        for (i = 0; i < 8; i++) {
            if (sound_voice_table[i].unkC == -1) {
                break;
            }
            if (sound_voice_table[i].unk10 < min) {
                oldest = i;
                min = sound_voice_table[i].unk10;
            }
        }
        if (i == 8) {
            i = 0;
            if (oldest != -1) {
                i = oldest;
            }
            sound_voice_table[i].unk10 = 0;
            SsUtKeyOffV(sound_voice_table[i].unkC);
        }
        sound_voice_table[i].unk0 = 0;
        sound_voice_table[i].unk4 = prog;
        sound_voice_table[i].unk6 = tone_no;
        sound_voice_table[i].unk8 = note;
        sound_voice_table[i].unkA = se->unk4;
        sound_voice_table[i].unkC = SsUtKeyOnV(i, se->unk0, prog, tone_no, note, 0, vol[0], vol[1]);
        sound_voice_table[i].unkE = 1;
        sound_voice_table[i].unk12 = flag;
        if (flag != 0) {
            sound_voice_table[i].unk10 = 0x7FFF;
        } else {
            sound_voice_table[i].unk10++;
        }
    } else {
        if (sound_voice_table[i].unkE != 0) {
            SsUtKeyOffV(sound_voice_table[i].unkC);
        }
        sound_voice_table[i].unkC = SsUtKeyOnV(sound_voice_table[i].unkC, se->unk0, prog, tone_no, note, 0, vol[0], vol[1]);
        if (flag == 0) {
            sound_voice_table[i].unk10++;
        }
    }
}

void sound_exec_command(Unk_801A324C *cmd) {
    s32 bank_id, prog, tone_no, note, e, vol_l, vol_r, pin;

    if (cmd->unk4 >= 5) {
        bank_id = atoi(cmd->unk8[0]);
        prog = atoi(cmd->unk8[1]);
        tone_no = atoi(cmd->unk8[2]);
        note = atoi(cmd->unk8[3]);
        e = atoi(cmd->unk8[4]);
        if (cmd->unk4 == 8) {
            vol_l = atoi(cmd->unk8[5]);
            vol_r = atoi(cmd->unk8[6]);
            pin = atoi(cmd->unk8[7]);
        } else if (cmd->unk4 == 7) {
            vol_l = atoi(cmd->unk8[5]);
            vol_r = atoi(cmd->unk8[6]);
            pin = 0;
        } else {
            vol_l = 0x7F;
            vol_r = 0x7F;
            pin = 0;
        }
        sound_se_play_note(bank_id, prog, tone_no, note, vol_l, vol_r, pin);
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/801A217C", D_80171770);

INCLUDE_RODATA("asm/nonmatchings/game/801A217C", D_8017178C);

void sound_bgm_open(BgmSep *bgm) {
    SceneTables *tables = &object_scene_tables;
    Unk_801E02DC *se = NULL;
    s32 i;

    if (tables->se_bank_count == 0) {
        kaj_abend(8, "VAB is not Ready", sound_str_file, 0x253);
    }
    for (i = 0; i < tables->se_bank_count; i++) {
        se = tables->se_banks[i];
        if (se->unk4 == 2) {
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
    bgm->sep = SsSepOpen((u32 *)bgm->data + 1, se->unk0, bgm->seq_count);
    if (bgm->sep < 0) {
        kaj_abend(8, "Can not Open Specified SEP", sound_str_file, 0x268);
    }
    for (i = 0; i < bgm->seq_count; i++) {
        SsSepSetVol(bgm->sep, i, kaj_system.unk18, kaj_system.unk18);
    }
    tables->bgm = bgm;
}

void sound_footstep_update(Unk_801A358C *player) {
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
        if (player->unk44 == 1 || player->unk44 == 3) {
            player->unk4C = 0;
            sound_footstep_clock = 0;
            sound_footstep_count = 0;
            sound_footstep_phase = 0;
        }
        break;
    case 1:
    case 3:
        if (player->unk44 == 2) {
            player->unk4C = 0;
            sound_footstep_clock = 0;
            sound_footstep_count = 0;
            sound_footstep_phase = 0;
        }
        break;
    }
    sound_footstep_prev_state = player->unk44;
    switch (player->unk44) {
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
    player->unk4C = rsin((s16)((wrapped << 12) / 360)) * 25 / 4096 + 25;
    if (step != sound_footstep_count) {
        sound_se_play(3);
        player->unk4C = 0;
        sound_footstep_phase = 0;
    }
    sound_footstep_count = step;
    return;
reset:
    player->unk4C = 0;
    sound_footstep_clock = 0;
    sound_footstep_count = 0;
    sound_footstep_phase = 0;
    if (player->unk44 == 4) {
        sound_se_play(0xE);
    }
}

Unk_801A37E4 *sound_se_alloc_header(u16 *src, s32 size, Unk_801A217C *bank) {
    SceneTables *tables = &object_scene_tables;

    memset(bank, 0, 0x1C);
    if (tables->se_bank_count == 4) {
        kaj_abend(0xD, D_801716EC, sound_str_file, 0x99);
    }
    bank->unk18 = src[0];
    bank->unk1A = src[1];
    src += 2;
    bank->unkC = size - 4;
    bank->unk4 = (s32)kaj_malloc(size - 4);
    if (bank->unk4 == 0) {
        kaj_abend(3, D_80171708, sound_str_file, 0xA2);
    }
    *(Unk_801A37E4 *)bank->unk4 = *(Unk_801A37E4 *)src;
    bank->unk16 = ((Unk_801A37E4 *)bank->unk4)->unk14;
    return (Unk_801A37E4 *)bank->unk4 + 1;
}

void sound_vab_open_head(VabStream *vab) {
    if (D_801E02EC[0] == 4) {
        kaj_abend(0xD, D_801716EC, sound_str_file, 0xB5);
    }
    vab->vab_id = SsVabOpenHead(vab->head, -1);
    if (vab->vab_id < 0) {
        kaj_abend(8, D_80171724, sound_str_file, 0xB9);
    }
}

void sound_vab_transfer(VabStream *vab) {
    if (SsVabTransBodyPartly(vab->body_buf, vab->body_len, vab->vab_id) == -1) {
        kaj_abend(8, D_8017173C, sound_str_file, 0xC4);
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
        kaj_abend(3, D_80171770, sound_str_file, 0x241);
    }
    (*out)->sep = -1;
    (*out)->seq = -1;
    (*out)->seq_count = 0;
    (*out)->data = kaj_malloc(size);
    if ((*out)->data == NULL) {
        kaj_abend(3, D_8017178C, sound_str_file, 0x249);
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
        SsSepSetVol(bgm->sep, bgm->seq, D_801E6DB8[0], D_801E6DB8[0]);
        bgm->seq = -1;
    }
}

void sound_bgm_fade_out(s32 seconds) {
    GameVars *game = &action_vars;
    BgmSep *bgm = object_scene_tables.bgm;
    Unk_801A3D74 *node;

    if (bgm != NULL && bgm->seq >= 0) {
        node = kaj_tss_alloc(4);
        node->unk22 = 0xD;
        node->unk24 = D_801E6DB8[0];
        node->unk26 = 0;
        kaj_tss_set_steps(node, seconds * 30);
        node->unk30 = sound_bgm_fade_step;
        node->unk34 = sound_bgm_fade_step;
        *node->unk3C = node->unk22;
        game->unk244 = kaj_tss_start(node);
    }
}

void sound_bgm_fade_step(Unk_801A3D74 *task) {
    BgmSep *bgm = object_scene_tables.bgm;
    s32 volume = (task->unk24 < task->unk26) ? task->unk26 : task->unk24;

    SsSepSetVol(bgm->sep, bgm->seq, volume, volume);
}

void sound_footstep_reset(Unk_801A3DBC *player) {
    player->unk4C = 0;
    sound_footstep_clock = 0;
    sound_footstep_count = 0;
    sound_footstep_phase = 0;
}

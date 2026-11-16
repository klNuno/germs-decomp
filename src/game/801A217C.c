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
extern s32 D_801E6DB4[];
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

void sound_se_push(Unk_801A217C *arg0) {
    SceneTables *p = &object_scene_tables;
    Unk_801E02DC *se;
    s32 i;

    se = kaj_malloc(0xC);
    if (se == NULL) {
        kaj_abend(3, "Error Allocating SE Pointer", sound_str_file, 0xD1);
    }
    se->unk0 = arg0->unk14;
    se->unk2 = arg0->unk16;
    se->unk4 = arg0->unk18;
    se->unk6 = arg0->unk1A;
    se->unk8 = arg0->unk4;
    if (p->unk14 == 0) {
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
    p->unk4[p->unk14++] = se;
}

void sound_se_pop(void) {
    SceneTables *p = &object_scene_tables;
    Unk_801E02DC *se;
    s32 i;

    if (p->unk14 != 0) {
        se = p->unk4[--p->unk14];
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
            p->unk4[p->unk14] = NULL;
        }
    }
}

void sound_se_pop_scene(void) {
    SceneTables *p = &object_scene_tables;
    Unk_801E02DC *se;
    s32 i;

    if (p->unk14 != 0) {
        se = p->unk4[p->unk14 - 1];
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
                p->unk4[--p->unk14] = NULL;
                se = p->unk4[p->unk14 - 1];
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

void sound_se_stop(s32 arg0) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (sound_voice_table[i].unk0 == 1 && sound_voice_table[i].unk2 == arg0) {
            break;
        }
    }
    if (i != 8) {
        sound_voice_table[i].unkE = 0;
        if (sound_voice_table[i].unk12 != 0) {
            sound_voice_table[i].unk10 = 0;
        } else {
            sound_voice_table[i].unk10--;
        }
        SsUtKeyOffV(sound_voice_table[i].unkC);
    }
}

void sound_se_play(s32 arg0) {
    SceneTables *p = &object_scene_tables;
    Unk_801D7B58 *ent;
    Unk_801E02DC *se;
    Unk_801A2678_820 *tone;
    s16 vol[2];
    s32 i;
    s16 pan;
    u8 m;
    Unk_801A2678_20 *prg;
    s16 min;
    s16 idx;

    se = NULL;
    ent = &sound_se_table[arg0];
    for (i = 0; i < p->unk14; i++) {
        se = p->unk4[i];
        if (se->unk4 == ent->unk4) {
            break;
        }
    }
    if (i == p->unk14) {
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

    m = ((Unk_801A2678 *)se->unk8)->unk18;
    pan = ((Unk_801A2678 *)se->unk8)->unk19;
    vol[0] = vol[0] * m >> 7;
    vol[1] = vol[1] * m >> 7;
    if (pan < 0x40) {
        vol[1] = vol[1] / (0x40 - pan);
    } else if (pan > 0x40) {
        vol[0] = vol[0] / (pan - 0x40);
    }

    prg = &((Unk_801A2678 *)se->unk8)->unk20[ent->unk6];
    m = prg->unk1;
    pan = prg->unk4;
    vol[0] = vol[0] * m >> 7;
    vol[1] = vol[1] * m >> 7;
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
        m = tone->unk2;
        pan = tone->unk3;
        vol[0] = vol[0] * m >> 7;
        vol[1] = vol[1] * m >> 7;
        if (pan < 0x40) {
            vol[1] = vol[1] / (0x40 - pan);
        } else if (pan > 0x40) {
            vol[0] = vol[0] / (pan - 0x40);
        }
    }

    for (i = 0; i < 8; i++) {
        if (sound_voice_table[i].unk0 == 1 && sound_voice_table[i].unk2 == arg0) {
            break;
        }
    }
    if (i == 8) {
        min = 0x7FFF;
        idx = -1;
        for (i = 0; i < 8; i++) {
            if (sound_voice_table[i].unkC == -1) {
                break;
            }
            if (sound_voice_table[i].unk10 < min) {
                idx = i;
                min = sound_voice_table[i].unk10;
            }
        }
        if (i == 8) {
            i = 0;
            if (idx != -1) {
                i = idx;
            }
            sound_voice_table[i].unk10 = 0;
            SsUtKeyOffV(sound_voice_table[i].unkC);
        }
        sound_voice_table[i].unk0 = 1;
        sound_voice_table[i].unk2 = arg0;
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

void sound_se_play_note(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6) {
    SceneTables *p = &object_scene_tables;
    Unk_801E02DC *se;
    Unk_801A2C60_820 *tone;
    s16 vol[2];
    s16 flag;
    s32 i;
    s16 pan;
    u8 m;
    Unk_801A2C60_20 *prg;
    s16 min;
    s16 idx;

    vol[0] = arg4;
    vol[1] = arg5;
    se = NULL;
    flag = arg6;
    for (i = 0; i < p->unk14; i++) {
        se = p->unk4[i];
        if (se->unk4 == arg0) {
            break;
        }
    }
    if (i == p->unk14) {
        return;
    }
    m = ((Unk_801A2C60 *)se->unk8)->unk18;
    pan = ((Unk_801A2C60 *)se->unk8)->unk19;
    vol[0] = vol[0] * m >> 7;
    vol[1] = vol[1] * m >> 7;
    if (pan < 0x40) {
        vol[1] = vol[1] / (0x40 - pan);
    } else if (pan > 0x40) {
        vol[0] = vol[0] / (pan - 0x40);
    }

    prg = &((Unk_801A2C60 *)se->unk8)->unk20[arg1];
    m = prg->unk1;
    pan = prg->unk4;
    vol[0] = vol[0] * m >> 7;
    vol[1] = vol[1] * m >> 7;
    if (pan < 0x40) {
        vol[1] = vol[1] / (0x40 - pan);
    } else if (pan > 0x40) {
        vol[0] = vol[0] / (pan - 0x40);
    }

    tone = ((Unk_801A2C60 *)se->unk8)->unk820;
    for (i = 0; i < ((Unk_801A2C60 *)se->unk8)->unk12; i++, tone++) {
        if (tone->unk14 == arg1) {
            break;
        }
    }
    if (i < ((Unk_801A2C60 *)se->unk8)->unk12) {
        m = tone->unk2;
        pan = tone->unk3;
        vol[0] = vol[0] * m >> 7;
        vol[1] = vol[1] * m >> 7;
        if (pan < 0x40) {
            vol[1] = vol[1] / (0x40 - pan);
        } else if (pan > 0x40) {
            vol[0] = vol[0] / (pan - 0x40);
        }
    }

    for (i = 0; i < 8; i++) {
        if (sound_voice_table[i].unk0 == 0 && sound_voice_table[i].unk4 == arg1 && sound_voice_table[i].unk6 == arg2 && sound_voice_table[i].unk8 == arg3) {
            break;
        }
    }
    if (i == 8) {
        min = 0x7FFF;
        idx = -1;
        for (i = 0; i < 8; i++) {
            if (sound_voice_table[i].unkC == -1) {
                break;
            }
            if (sound_voice_table[i].unk10 < min) {
                idx = i;
                min = sound_voice_table[i].unk10;
            }
        }
        if (i == 8) {
            i = 0;
            if (idx != -1) {
                i = idx;
            }
            sound_voice_table[i].unk10 = 0;
            SsUtKeyOffV(sound_voice_table[i].unkC);
        }
        sound_voice_table[i].unk0 = 0;
        sound_voice_table[i].unk4 = arg1;
        sound_voice_table[i].unk6 = arg2;
        sound_voice_table[i].unk8 = arg3;
        sound_voice_table[i].unkA = se->unk4;
        sound_voice_table[i].unkC = SsUtKeyOnV(i, se->unk0, arg1, arg2, arg3, 0, vol[0], vol[1]);
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
        sound_voice_table[i].unkC = SsUtKeyOnV(sound_voice_table[i].unkC, se->unk0, arg1, arg2, arg3, 0, vol[0], vol[1]);
        if (flag == 0) {
            sound_voice_table[i].unk10++;
        }
    }
}

void sound_exec_command(Unk_801A324C *arg0) {
    s32 a, b, c, d, e, f, g, h;

    if (arg0->unk4 >= 5) {
        a = atoi(arg0->unk8[0]);
        b = atoi(arg0->unk8[1]);
        c = atoi(arg0->unk8[2]);
        d = atoi(arg0->unk8[3]);
        e = atoi(arg0->unk8[4]);
        if (arg0->unk4 == 8) {
            f = atoi(arg0->unk8[5]);
            g = atoi(arg0->unk8[6]);
            h = atoi(arg0->unk8[7]);
        } else if (arg0->unk4 == 7) {
            f = atoi(arg0->unk8[5]);
            g = atoi(arg0->unk8[6]);
            h = 0;
        } else {
            f = 0x7F;
            g = 0x7F;
            h = 0;
        }
        sound_se_play_note(a, b, c, d, f, g, h);
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/801A217C", D_80171770);

INCLUDE_RODATA("asm/nonmatchings/game/801A217C", D_8017178C);

void sound_bgm_open(BgmSep *arg0) {
    SceneTables *p = &object_scene_tables;
    Unk_801E02DC *se = NULL;
    s32 i;

    if (p->unk14 == 0) {
        kaj_abend(8, "VAB is not Ready", sound_str_file, 0x253);
    }
    for (i = 0; i < p->unk14; i++) {
        se = p->unk4[i];
        if (se->unk4 == 2) {
            break;
        }
        se = NULL;
    }
    if (se == NULL) {
        kaj_abend(8, "VAB is not Ready", sound_str_file, 0x25C);
    }
    arg0->seq_count = *(s32 *)arg0->data;
    if (arg0->seq_count >= 4) {
        kaj_abend(8, "Too Many SEQ in This SEP", sound_str_file, 0x260);
    }
    if (p->unk0 != NULL) {
        sound_bgm_close();
    }
    arg0->sep = SsSepOpen((u32 *)arg0->data + 1, se->unk0, arg0->seq_count);
    if (arg0->sep < 0) {
        kaj_abend(8, "Can not Open Specified SEP", sound_str_file, 0x268);
    }
    for (i = 0; i < arg0->seq_count; i++) {
        SsSepSetVol(arg0->sep, i, kaj_system.unk18, kaj_system.unk18);
    }
    p->unk0 = arg0;
}

void sound_footstep_update(Unk_801A358C *arg0) {
    s32 dt = D_801E6DB4[0];
    s16 lim;
    s32 l;
    s32 t;
    s32 n;
    s16 a;

    sound_footstep_clock += dt;
    if (sound_footstep_clock > 12000) {
        sound_footstep_clock -= 12000;
    }
    switch (sound_footstep_prev_state) {
    case 2:
        if (arg0->unk44 == 1 || arg0->unk44 == 3) {
            arg0->unk4C = 0;
            sound_footstep_clock = 0;
            sound_footstep_count = 0;
            sound_footstep_phase = 0;
        }
        break;
    case 1:
    case 3:
        if (arg0->unk44 == 2) {
            arg0->unk4C = 0;
            sound_footstep_clock = 0;
            sound_footstep_count = 0;
            sound_footstep_phase = 0;
        }
        break;
    }
    sound_footstep_prev_state = arg0->unk44;
    switch (arg0->unk44) {
    case 2:
        lim = 15;
        break;
    case 1:
    case 3:
        lim = 30;
        break;
    default:
        goto reset;
    }
    l = lim;
    t = ((sound_footstep_phase * 360 << 12) / l - 90) >> 12;
    sound_footstep_phase += dt;
    n = sound_footstep_clock / l;
    if (sound_footstep_phase > l) {
        sound_footstep_phase = l;
    }
    a = mail_wrap_angle(t);
    arg0->unk4C = rsin((s16)((a << 12) / 360)) * 25 / 4096 + 25;
    if (n != sound_footstep_count) {
        sound_se_play(3);
        arg0->unk4C = 0;
        sound_footstep_phase = 0;
    }
    sound_footstep_count = n;
    return;
reset:
    arg0->unk4C = 0;
    sound_footstep_clock = 0;
    sound_footstep_count = 0;
    sound_footstep_phase = 0;
    if (arg0->unk44 == 4) {
        sound_se_play(0xE);
    }
}

Unk_801A37E4 *sound_se_alloc_header(u16 *arg0, s32 arg1, Unk_801A217C *arg2) {
    SceneTables *p = &object_scene_tables;

    memset(arg2, 0, 0x1C);
    if (p->unk14 == 4) {
        kaj_abend(0xD, D_801716EC, sound_str_file, 0x99);
    }
    arg2->unk18 = arg0[0];
    arg2->unk1A = arg0[1];
    arg0 += 2;
    arg2->unkC = arg1 - 4;
    arg2->unk4 = (s32)kaj_malloc(arg1 - 4);
    if (arg2->unk4 == 0) {
        kaj_abend(3, D_80171708, sound_str_file, 0xA2);
    }
    *(Unk_801A37E4 *)arg2->unk4 = *(Unk_801A37E4 *)arg0;
    arg2->unk16 = ((Unk_801A37E4 *)arg2->unk4)->unk14;
    return (Unk_801A37E4 *)arg2->unk4 + 1;
}

void sound_vab_open_head(VabStream *arg0) {
    if (D_801E02EC[0] == 4) {
        kaj_abend(0xD, D_801716EC, sound_str_file, 0xB5);
    }
    arg0->vab_id = SsVabOpenHead(arg0->head, -1);
    if (arg0->vab_id < 0) {
        kaj_abend(8, D_80171724, sound_str_file, 0xB9);
    }
}

void sound_vab_transfer(VabStream *arg0) {
    if (SsVabTransBodyPartly(arg0->body_buf, arg0->body_len, arg0->vab_id) == -1) {
        kaj_abend(8, D_8017173C, sound_str_file, 0xC4);
    }
    SsVabTransCompleted(1);
}

void sound_se_pop_all(void) {
    SceneTables *p = &object_scene_tables;

    while (p->unk14 > 0) {
        sound_se_pop();
    }
}

void sound_bgm_create(BgmSep **arg0, u32 arg1) {
    *arg0 = kaj_malloc(0xC);
    if (*arg0 == NULL) {
        kaj_abend(3, D_80171770, sound_str_file, 0x241);
    }
    (*arg0)->sep = -1;
    (*arg0)->seq = -1;
    (*arg0)->seq_count = 0;
    (*arg0)->data = kaj_malloc(arg1);
    if ((*arg0)->data == NULL) {
        kaj_abend(3, D_8017178C, sound_str_file, 0x249);
    }
}

void sound_bgm_close(void) {
    BgmSep *p = object_scene_tables.unk0;

    if (p != NULL) {
        if (p->sep >= 0) {
            SsSepClose(p->sep);
        }
        if (p->data != NULL) {
            free3(p->data);
        }
        free3(p);
        object_scene_tables.unk0 = NULL;
    }
}

void sound_bgm_play(s16 arg0) {
    BgmSep *p = object_scene_tables.unk0;

    if (p != NULL && p->seq != arg0 && arg0 < p->seq_count) {
        if (p->seq != -1) {
            sound_bgm_stop();
        }
        p->seq = arg0;
        SsSepPlay(p->sep, arg0, 1, 0);
    }
}

void sound_bgm_stop(void) {
    BgmSep *p = object_scene_tables.unk0;

    if (p != NULL && p->seq >= 0) {
        SsSepStop(p->sep, p->seq);
        SsSepSetVol(p->sep, p->seq, D_801E6DB8[0], D_801E6DB8[0]);
        p->seq = -1;
    }
}

void sound_bgm_fade_out(s32 arg0) {
    GameVars *g = &action_vars;
    BgmSep *p = object_scene_tables.unk0;
    Unk_801A3D74 *node;

    if (p != NULL && p->seq >= 0) {
        node = kaj_tss_alloc(4);
        node->unk22 = 0xD;
        node->unk24 = D_801E6DB8[0];
        node->unk26 = 0;
        kaj_tss_set_steps(node, arg0 * 30);
        node->unk30 = sound_bgm_fade_step;
        node->unk34 = sound_bgm_fade_step;
        *node->unk3C = node->unk22;
        g->unk244 = kaj_tss_start(node);
    }
}

void sound_bgm_fade_step(Unk_801A3D74 *arg0) {
    BgmSep *p = object_scene_tables.unk0;
    s32 v = (arg0->unk24 < arg0->unk26) ? arg0->unk26 : arg0->unk24;

    SsSepSetVol(p->sep, p->seq, v, v);
}

void sound_footstep_reset(Unk_801A3DBC *arg0) {
    arg0->unk4C = 0;
    sound_footstep_clock = 0;
    sound_footstep_count = 0;
    sound_footstep_phase = 0;
}

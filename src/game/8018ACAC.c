#include "common.h"
#include "game/types.h"

typedef struct { s16 unk0, unk2, unk4, unk6; } Unk_801DFD30;
Unk_801DFD30 *mail_list;
extern Unk_801E0340 D_801E0340;
void kaj_pad_reset(s32 a);
typedef struct { s16 unk0; s16 unk2; u16 unk4; } Unk_8018BD60_0;
typedef struct { Unk_8018BD60_0 *unk0; } Unk_8018BD60;
void mail_receive(u16 a);
extern GameVars action_vars;
extern Unk_801E058C mail_menu;
void effect_start_sprite_slide(s32 a, u16 b, s32 c);
void sprite_set_visible(s32 arg0, s32 arg1);
void mail_menu_draw(Unk_801E058C *p, s32 b);
u16 *mail_scrollbar;
s16 mail_list_top;
s16 mail_list_row;
extern char mail_str_file[];
u16 *sprite_find(u16 arg0);
void *kaj_malloc(u32 size);
void kaj_abend(s32 arg0, char *arg1, char *arg2, s32 arg3);
void mail_list_refresh(GameVars *a, s16 b);
void sprite_delete(s32 arg0);
void free3(void *ptr);
typedef struct Unk_80188FEC { u16 unk0; u8 unk2[0x5E]; } Unk_80188FEC;
typedef struct { u8 unk0[0xC]; u16 unkC; s16 unkE; } Unk_8018BC50_8;
typedef struct Unk_8018BC50 { u16 unk0; s16 unk2; s32 unk4; Unk_8018BC50_8 *unk8; Unk_8018BC50_8 *unkC; } Unk_8018BC50;
extern SceneTables object_scene_tables;
u16 mail_entry_saved_y;
u16 mail_scrollbar_saved_y;
void sprite_set_clut_entry(s32 a, s32 b, s32 c);
extern PlayerStatus player_status;
void action_update(void);
void npc_update_all(void);
void door_update_all(void);
void mod_npcrec_update_all(void);
void vehicle_update(void);
void mod_update_all(void);
void thing_update_all(void);
void player_update(u16 a, s16 b, s16 c);
void effect_flame_small_update(void);
void effect_clut_cycle_update(void);
void effect_flame_large_update(void);
void roadmap_draw_frame(u16 a);
void mail_menu_clear_rows(Unk_801E058C *p);
void sound_se_play(s32 a);
extern KajSystem kaj_system;
s32 kaj_event_get(s32 *arg0);
void kaj_event_done(s32 *arg0);
void func_80189928(s32 *a);
void event_handle_tick(s16 a);
void event_handle_mod_finish(s32 *a);
s16 event_handle_effect_done(s32 *arg0);
void mail_step_frame(u16 a, s16 b, s16 c);
void sprite_fill_clut(s32 a, s32 b, s32 c, s32 d);
void sprite_copy_cell(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
void mail_menu_draw_item_name(s32 a, s32 b, s32 c);
typedef struct { u16 unk0; u16 unk2; u8 unk4[0x10]; s16 unk14; } Unk_8018CD4C_1C;
typedef struct { u8 unk0[0x10]; s16 unk10; u16 unk12; s16 unk14; u16 unk16; s32 unk18; Unk_8018CD4C_1C *unk1C; } Unk_8018CD4C;
void *memset(void *dst, s32 c, u32 n);
s32 LoadImage2(void *rect, void *p);
void sound_se_play(s32 arg0);
typedef struct { s16 unk0; s16 unk2; } Unk_8018C864_1C;
typedef struct { u8 unk0[0x1C]; Unk_8018C864_1C *unk1C; } Unk_8018C864;
Unk_801891A4 *effect_item_find(s16 arg0);
s32 strlen(char *s);
u16 *Krom2RawAdd2(u16 sjis);
typedef struct {
    s16 unk0[5];
    s16 unkA;
    char *unkC;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    u8 unk1E[2];
    char unk20[4];
} Unk_8018C554;
char *strncpy(char *dst, char *src, u32 n);
typedef struct {
    s16 unk0;
    s16 unk2;
    u16 unk4;
    u16 unk6;
    u8 unk8[0xA];
    u16 unk12;
} Unk_801E0324_1C;
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s32 unk8;
    u16 unkC;
    s16 unkE;
    s16 unk10;
    u16 unk12;
    s32 unk14;
    s32 unk18;
    Unk_801E0324_1C *unk1C;
} Unk_801E0324_10;
typedef struct {
    u16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    u16 *unk8;
    u16 *unkC;
    Unk_801E0324_10 *unk10;
    Unk_801E0324_10 *unk14;
    Unk_801E0324_10 *unk18;
    Unk_801E0324_10 *unk1C;
} Unk_801E0324;
extern Unk_801E0324 *D_801E0324[];
s16 mail_page_tex_v_0;
s16 mail_page_tex_v_1;
s16 mail_page_tex_v_2;
s16 mail_page_tex_v_3;
s16 mail_page_height_0;
s16 mail_page_height_1;
s16 mail_page_height_2;
s16 mail_page_height_3;
typedef struct {
    u16 unk0;
    u16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Unk_8018ACAC;
void sprite_create(Unk_801E0324_10 **arg0, void *arg1);
void sprite_add(s32 arg0);
s16 mail_main_restarted;
extern s32 D_801DFED4;
extern s32 D_801DFED8;
extern s32 D_801DFEDC;
extern s32 D_801DFEE0;
extern s32 D_801DFEE4;
extern s32 D_801DFEE8;
extern void *action_set_list;
extern void *action_queue;
extern void *D_801DFE5C;
extern void *D_801DFE80;
extern void *mod_list;
extern void *sprite_list;
extern void *D_801DFFA0;
void kaj_init(void);
void kaj_ll_create(void *arg0);
void event_open(void);
void roadmap_init_draw(void);
void object_load_res(s32 arg0, s32 arg1);
void player_init(void);
void effect_clear_alarms(void);
void vehicle_train_init_state(void);
void sprite_title_run(s32 arg0);
void kaj_srand_ticks(void);
void event_draw_hud(void);
void block_building_main(void);
void object_room_run(void);
void thing_game_loop(void);

void mail_create(Unk_801E0324 **arg0, Unk_8018ACAC *arg1, s16 arg2) {
    *arg0 = kaj_malloc(0x20);
    if (*arg0 == NULL) {
        kaj_abend(3, "Error Allocating MAIL Handler", mail_str_file, 0x3B);
    }
    (*arg0)->unk0 = arg1->unk0;
    (*arg0)->unk2 = arg2;
    (*arg0)->unk4 = arg1->unk2;
    (*arg0)->unk6 = 0;

    sprite_create(&(*arg0)->unk10, (u8 *)arg1 + arg1->unk4);
    sprite_add((s32)(*arg0)->unk10);
    (*arg0)->unk10->unk4 = 1;
    (*arg0)->unk10->unkC = 0x43;
    (*arg0)->unk10->unkE = 1;
    mail_page_tex_v_0 = (*arg0)->unk10->unk1C->unk12;
    mail_page_height_0 = (*arg0)->unk10->unk12;

    if ((*arg0)->unk4 >= 2) {
        sprite_create(&(*arg0)->unk14, (u8 *)arg1 + arg1->unk8);
        sprite_add((s32)(*arg0)->unk14);
        (*arg0)->unk14->unk4 = 0;
        (*arg0)->unk14->unkC = 0x43;
        (*arg0)->unk14->unkE = 1;
        mail_page_tex_v_1 = (*arg0)->unk14->unk1C->unk12;
        mail_page_height_1 = (*arg0)->unk14->unk12;
    }
    if ((*arg0)->unk4 >= 3) {
        sprite_create(&(*arg0)->unk18, (u8 *)arg1 + arg1->unkC);
        sprite_add((s32)(*arg0)->unk18);
        (*arg0)->unk18->unk4 = 0;
        (*arg0)->unk18->unkC = 0x43;
        (*arg0)->unk18->unkE = 1;
        mail_page_tex_v_2 = (*arg0)->unk18->unk1C->unk12;
        mail_page_height_2 = (*arg0)->unk18->unk12;
    }
    if ((*arg0)->unk4 >= 4) {
        sprite_create(&(*arg0)->unk1C, (u8 *)arg1 + arg1->unk10);
        sprite_add((s32)(*arg0)->unk1C);
        (*arg0)->unk1C->unk4 = 0;
        (*arg0)->unk1C->unkC = 0x43;
        (*arg0)->unk1C->unkE = 1;
        mail_page_tex_v_3 = (*arg0)->unk1C->unk1C->unk12;
        mail_page_height_3 = (*arg0)->unk1C->unk12;
    }

    (*arg0)->unk8 = sprite_find((*arg0)->unk0 + 0x217);
    if ((*arg0)->unk8 != NULL) {
        sprite_set_clut_entry((u16)((*arg0)->unk0 + 0x217), 7, 0x4D44);
        sprite_set_clut_entry((u16)((*arg0)->unk0 + 0x217), 9, 0x6358);
        mail_entry_saved_y = (*arg0)->unk8[6];
        (*arg0)->unk8[6] = 0x33;
        (*arg0)->unk8[7] = 1;
    }
    (*arg0)->unkC = sprite_find(0x20C);
    if (mail_scrollbar != NULL) {
        mail_scrollbar_saved_y = mail_scrollbar[6];
    }
    if ((*arg0)->unkC != NULL) {
        (*arg0)->unkC[6] = 0x29;
    }
}

void mail_scroll(s16 arg0) {
    Unk_801E0324 *p = D_801E0324[0];
    s32 v;
    s32 n;
    s32 max;

    if (p == NULL || p->unk4 < 2) {
        return;
    }
    v = p->unk6;
    if (arg0 != 0) {
        v++;
    } else {
        v--;
    }
    n = p->unk4 - 1;
    max = n << 7;
    if (max < v) {
        v = max;
    }
    if (v < 0) {
        v = 0;
    }
    if (p->unkC != NULL) {
        p->unkC[6] = ((v * 114 / n) >> 7) + 41;
    }
    if (v == 0) {
        p->unk10->unk4 = 1;
        p->unk10->unkC = 0x43;
        p->unk10->unk12 = mail_page_height_0;
        p->unk10->unk1C->unk12 = mail_page_tex_v_0;
        p->unk14->unk4 = 0;
        if (p->unk18 != NULL) {
            p->unk18->unk4 = 0;
        }
        if (p->unk1C != NULL) {
            p->unk1C->unk4 = 0;
        }
    } else if (v > 0 && v < 128) {
        p->unk10->unk4 = 1;
        p->unk10->unk12 = mail_page_height_0 - v;
        p->unk10->unk1C->unk12 = mail_page_tex_v_0 + v;
        p->unk14->unk4 = 1;
        p->unk14->unkC = p->unk10->unkC + p->unk10->unk12 - 1;
        p->unk14->unk12 = v;
        if (p->unk18 != NULL) {
            p->unk18->unk4 = 0;
        }
        if (p->unk1C != NULL) {
            p->unk1C->unk4 = 0;
        }
    } else if (v == 128) {
        p->unk10->unk4 = 0;
        p->unk14->unk4 = 1;
        p->unk14->unkC = 0x43;
        p->unk14->unk12 = mail_page_height_1;
        p->unk14->unk1C->unk12 = mail_page_tex_v_1;
        if (p->unk18 != NULL) {
            p->unk18->unk4 = 0;
        }
        if (p->unk1C != NULL) {
            p->unk1C->unk4 = 0;
        }
    } else if (v > 128 && v < 256) {
        p->unk10->unk4 = 0;
        p->unk14->unk4 = 1;
        p->unk14->unk12 = mail_page_height_1 + 128 - v;
        p->unk14->unk1C->unk12 = mail_page_tex_v_1 - 128 + v;
        p->unk18->unk4 = 1;
        p->unk18->unkC = p->unk14->unkC + p->unk14->unk12 - 1;
        p->unk18->unk12 = v - 128;
        if (p->unk1C != NULL) {
            p->unk1C->unk4 = 0;
        }
    } else if (v == 256) {
        p->unk10->unk4 = 0;
        p->unk14->unk4 = 0;
        p->unk18->unk4 = 1;
        p->unk18->unkC = 0x43;
        p->unk18->unk12 = mail_page_height_2;
        p->unk18->unk1C->unk12 = mail_page_tex_v_2;
    } else if (v > 256 && v < 384) {
        p->unk10->unk4 = 0;
        p->unk14->unk4 = 0;
        p->unk18->unk4 = 1;
        p->unk18->unk12 = mail_page_height_2 + 256 - v;
        p->unk18->unk1C->unk12 = mail_page_tex_v_2 - 256 + v;
        p->unk1C->unk4 = 1;
        p->unk1C->unkC = p->unk18->unkC + p->unk18->unk12 - 1;
        p->unk1C->unk12 = v - 256;
    } else if (v == 384) {
        p->unk10->unk4 = 0;
        p->unk14->unk4 = 0;
        p->unk18->unk4 = 0;
        p->unk1C->unk4 = 1;
        p->unk1C->unkC = 0x43;
        p->unk1C->unk12 = mail_page_height_3;
        p->unk1C->unk1C->unk12 = mail_page_tex_v_3;
    }
    p->unk6 = v;
}

void mail_list_refresh(GameVars *a, s16 b) {
    s32 i;
    s32 n;
    u16 *q;
    Unk_801DFD30 *e;

    n = 0;
    e = mail_list;
    for (i = 0; i < (s16)a->vars[0x5F]; i++, e++) {
        q = sprite_find(e->unk0 + 0x217);
        if (q != NULL) {
            if (i >= mail_list_top && i < mail_list_top + 9) {
                q[2] = 1;
                q[5] = 0x30;
                q[6] = n * 16 + 0x33;
                n++;
                if (i == b) {
                    sprite_set_clut_entry((u16)(e->unk0 + 0x217), 9, 0x1F);
                } else {
                    sprite_set_clut_entry((u16)(e->unk0 + 0x217), 9, 0x6358);
                }
                if (e->unk4 != 0) {
                    sprite_set_clut_entry((u16)(e->unk0 + 0x217), 7, 0x2C1F);
                } else {
                    sprite_set_clut_entry((u16)(e->unk0 + 0x217), 7, 0x4D44);
                }
            } else {
                q[2] = 0;
            }
        }
    }
}

s32 mail_list_move(s16 a, s16 b) {
    GameVars *p = &action_vars;
    if ((s16)p->vars[0x5F] == 0) {
        return -1;
    }
    if (a != 0) {
        b--;
        if (b < 0) {
            return 0;
        }
        mail_list_row--;
        if (mail_list_row < 0) {
            mail_list_row = 0;
            if (mail_list_top > 0) {
                mail_list_top--;
            }
        }
    } else {
        b++;
        if (b >= (s16)p->vars[0x5F]) {
            return (s16)(p->vars[0x5F] - 1);
        }
        mail_list_row++;
        if (mail_list_row >= 9) {
            mail_list_row = 8;
            if (mail_list_top != b - 8) {
                mail_list_top = b - 8;
            }
        }
    }
    mail_list_refresh(p, b);
    if (mail_scrollbar != NULL) {
        mail_scrollbar[6] = b * 114 / ((s16)p->vars[0x5F] - 1) + 0x29;
    }
    sound_se_play(0xF);
    return b;
}

void mail_list_open(void) {
    s32 i;
    s32 j;
    u16 v;
    Unk_801DFD30 *e;
    GameVars *p = &action_vars;
    if ((s16)p->vars[0x5F] != 0) {
        mail_list_row = 0;
        mail_list_top = 0;
        mail_scrollbar = sprite_find(0x20C);
        if (mail_scrollbar != NULL) {
            mail_scrollbar[6] = 0x29;
        }
        mail_list = kaj_malloc((s16)p->vars[0x5F] * 8);
        if (mail_list == NULL) {
            kaj_abend(3, "Error Allocating Mail List", mail_str_file, 0x16A);
        }
        for (i = 0; i < 0x20; i++) {
            j = i / 2 + 0x60;
            if (i & 1) {
                v = (u8)*(p->vars + j);
            } else {
                v = *(p->vars + j) >> 8;
            }
            if (v & 0x80) {
                e = &mail_list[v & 0x3F];
                e->unk0 = i;
                e->unk2 = v;
                e->unk4 = (v & 0x40) >> 6;
            }
        }
        mail_list_refresh(p, 0);
    }
}

void mail_list_close(void) {
    s32 i;
    s32 j;
    s32 v;
    s32 t;
    Unk_801DFD30 *e;
    GameVars *p = &action_vars;
    if ((s16)p->vars[0x5F] != 0) {
        if (mail_scrollbar != NULL) {
            mail_scrollbar[6] = 0x29;
            mail_scrollbar = NULL;
        }
        e = mail_list;
        for (i = 0; i < (s16)p->vars[0x5F]; i++, e++) {
            v = 0x80;
            if (e->unk4 != 0) {
                v = 0xC0;
            }
            v += i & 0x3F;
            j = e->unk0 / 2 + 0x60;
            if (e->unk0 % 2) {
                t = *(p->vars + j);
                *(p->vars + j) = v | (t & ~0xFF);
            } else {
                *(p->vars + j) = (u8)*(p->vars + j) | (v << 8);
            }
        }
        free3(mail_list);
        mail_list = NULL;
        for (i = 0; i < 0x20; i++) {
            sprite_delete((u16)(i + 0x217));
        }
    }
}

void mail_receive(u16 a) {
    s32 v;
    s32 i;
    s16 odd;
    u16 n;
    GameVars *p = &action_vars;
    if (a < 0x20) {
        i = a / 2 + 0x60;
        odd = a % 2;
        if (odd) {
            v = (u8)*(p->vars + i) & 0x80;
        } else {
            v = (*(p->vars + i) >> 8) & 0x80;
        }
        if (v == 0) {
            n = p->vars[0x5F]++ | 0x80;
            if (odd) {
                *(p->vars + i) = n | (*(p->vars + i) & 0xFF00);
            } else {
                *(p->vars + i) = (u8)*(p->vars + i) | (n << 8);
            }
        }
    }
}

void mail_check_schedule(s32 a, s32 b) {
    GameVars *p = &action_vars;
    if ((s16)p->vars[0x30] == 0) {
        if (a == 0) {
            if (b == 10) {
                mail_receive(0xE);
            } else if (b == 0x11) {
                mail_receive(8);
            } else if (b == 0x15) {
                mail_receive(0x17);
            }
        } else if (a == 1) {
            if (b == 10) {
                mail_receive(0xF);
            } else if (b == 0x10) {
                mail_receive(0x1C);
            }
        } else if (a == 2) {
            if (b == 10) {
                if ((s16)p->vars[0xB] == 100 && (s16)p->vars[1] == 0) {
                    mail_receive(2);
                }
                mail_receive(0x11);
                if ((s16)p->vars[0x13] == 100) {
                    mail_receive(0x14);
                }
            } else if (b == 0xE) {
                if ((s16)p->vars[0x11] == 10) {
                    mail_receive(0x15);
                }
                mail_receive(0x1A);
            }
        } else if (a == 3) {
            if (b == 0xC) {
                mail_receive(0x1D);
                if ((s16)p->vars[0x4D] == 0) {
                    mail_receive(0x1F);
                }
            }
        }
    }
}

void mail_free(void) {
    SceneTables *p = &object_scene_tables;
    Unk_8018BC50 *e = p->unk4C;
    if (e != NULL) {
        mail_list[e->unk2].unk4 = 1;
        if (e->unk8 != NULL) {
            sprite_set_clut_entry((u16)(e->unk0 + 0x217), 7, 0x2C1F);
            sprite_set_clut_entry((u16)(e->unk0 + 0x217), 9, 0x1F);
            e->unk8->unkC = mail_entry_saved_y;
            e->unk8->unkE = 2;
        }
        if (e->unkC != NULL) {
            e->unkC->unkC = mail_scrollbar_saved_y;
        }
        sprite_delete(0x213);
        sprite_delete(0x214);
        sprite_delete(0x215);
        sprite_delete(0x216);
        free3(e);
        p->unk4C = NULL;
    }
}

s16 mail_list_get_id(s16 i) { return mail_list[i].unk0; }

void mail_cmd_receive(Unk_8018BD60 *a) {
    mail_receive(a->unk0->unk4);
}

s32 mail_is_read(s16 a) {
    s32 v;
    GameVars *p = &action_vars;
    s32 i = a / 2 + 0x60;
    if (a & 1) {
        v = (u8)p->vars[i] & 0x40;
    } else {
        v = (p->vars[i] >> 8) & 0x40;
    }
    return v != 0;
}

void main(void) {
    Unk_801E0340 *p;
    Unk_801E0340 *q;
    GameVars *r;
    s16 f;
    u16 a;
    u16 b;

    kaj_init();
    memset(&object_scene_tables, 0, 0x64);
    D_801DFED8 = 0;
    D_801DFEE4 = 0;
    D_801DFEE0 = 0;
    D_801DFEDC = 0;
    D_801DFED4 = 0;
    D_801DFEE8 = 0;
    kaj_ll_create(&action_set_list);
    kaj_ll_create(&action_queue);
    kaj_ll_create(&D_801DFE5C);
    kaj_ll_create(&D_801DFE80);
    kaj_ll_create(&mod_list);
    kaj_ll_create(&sprite_list);
    kaj_ll_create(&D_801DFFA0);
    event_open();
    roadmap_init_draw();
    object_load_res(1, 0);
    r = &action_vars;
    while (1) {
        q = &D_801E0340;
        f = mail_main_restarted;
        if (f != 0) {
            a = r->unk200;
            b = r->unk202;
        }
        memset(r, 0, sizeof(action_vars));
        memset(q, 0, 0x24);
        if (f != 0) {
            r->unk200 = a;
            r->unk202 = b;
        } else {
            r->unk200 = 1;
            r->unk202 = 1;
        }
        q->unk0[0] = -1;
        q->unk0[1] = -1;
        player_init();
        r->vars[0x5F] = 3;
        r->unkC0 = -0x7E80;
        r->unkC2[4] = 0x82;
        r->vars[0xA] = 100;
        r->vars[0xB] = 100;
        r->vars[0xC] = 100;
        r->vars[0xD] = 100;
        r->vars[0x1B] = 100;
        r->vars[0x3E] = 5;
        r->vars[0x3F] = 0;
        r->vars[0x30] = 0;
        r->drain_minute = 0;
        r->drain_count = 0;
        effect_clear_alarms();
        p = &D_801E0340;
        vehicle_train_init_state();
        sprite_title_run(mail_main_restarted);
        kaj_srand_ticks();
        sprite_set_visible(0x400, 1);
        sprite_set_visible(0x409, 1);
        event_draw_hud();
        while (p->unk0[4] == 0) {
            if (p->unk0[0] != p->unk0[1]) {
                p->unk0[0] = p->unk0[1];
            }
            switch (p->unk0[0]) {
            case 1:
                block_building_main();
                break;
            case 0:
                object_room_run();
                break;
            case 2:
                thing_game_loop();
                break;
            }
        }
        p->unk0[4] = 0;
        sprite_set_visible(0x400, 0);
        sprite_set_visible(0x409, 0);
        if (mail_main_restarted == 0) {
            mail_main_restarted = 1;
        }
    }
}

s32 mail_angle_to_dir8(s16 a) {
    s32 b;

loop:
    if (a < 0) a += 360;
    if (a >= 360) a -= 360;
    if ((u16)a >= 360) goto loop;
    b = a;
    if (b >= 23 && b < 68) return 1;
    if (b >= 68 && b < 113) return 0;
    if (b >= 113 && b < 158) return 7;
    if (b >= 158 && b < 203) return 6;
    if (b >= 203 && b < 248) return 5;
    if (b >= 248 && b < 293) return 4;
    if (b >= 293 && b < 338) return 3;
    return 2;
}

s32 mail_take_scene_change(void) {
    Unk_801E0340 *p = &D_801E0340;
    if (p->unkA == 0) {
        return 0;
    }
    p->unkA = 0;
    kaj_pad_reset(0);
    return 1;
}

void mail_wait(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 buf[6];
    s32 n;
    for (n = arg3 * 30; n > 0;) {
            switch (kaj_event_get(buf)) {
            case 2:
                func_80189928(buf);
                continue;
            case 4:
                event_handle_tick(0);
                continue;
            case 0x200:
                event_handle_mod_finish(buf);
                continue;
            case 0:
                n -= kaj_system.vsync_delta;
                break;
            case 0x100:
                event_handle_effect_done(buf);
                continue;
            default:
                kaj_event_done(buf);
                continue;
            }
            if ((u16)arg0 == 3) {
                thing_update_all();
                roadmap_draw_frame(3);
            } else {
                do { mail_step_frame(arg0, arg1, arg2); } while (0);
            }
    }
}

void mail_step_frame(u16 a, s16 b, s16 c) {
    GameVars *p = &action_vars;
    action_update();
    if (a < 2) {
        npc_update_all();
        door_update_all();
        mod_npcrec_update_all();
    } else if (a == 2) {
        vehicle_update();
    }
    mod_update_all();
    thing_update_all();
    player_update(a, b, c);
    if ((u16)(a - 1) < 2) {
        if (p->unk252 != 0) {
            effect_flame_small_update();
        }
        if (p->unk254 != 0) {
            effect_clut_cycle_update();
        }
        if (p->unk250 != 0) {
            effect_flame_large_update();
        }
    }
    roadmap_draw_frame(a);
}

void mail_goto_ofc(s16 a, s16 b, s16 c, s16 d) {
    Unk_801E0340 *p = &D_801E0340;
    PlayerStatus *g = &player_status;
    GameVars *q = &action_vars;
    p->unk12 = b;
    ((s16 *)&p->unk14)[0] = c;
    ((s16 *)&p->unk14)[1] = d;
    p->unk0[1] = 0;
    p->unkA = 1;
    p->unkC = "\\S\\OFC.S;1";
    p->unk0[3] = 0;
    p->unk0[2] = 0;
    p->unk10 = a;
    if (d == 2) {
        return;
    }
    if ((s16)q->vars[0x30] != 0 || g->mutant != 0) {
        return;
    }
    switch (g->unk30) {
    case 0:
        if (g->unk2E >= 3) {
            p->unk0[3] = 1;
            g->unk30 = 1;
            g->unk2E = 0;
        }
        break;
    case 1:
        if (g->unk2E >= 5 && (s16)q->vars[0x11] != 100) {
            q->vars[0x11] = 100;
            p->unk0[3] = 1;
            g->unk30 = 2;
            g->unk2E = 0;
        }
        break;
    }
}

void mail_goto_twn(s32 a, s32 b, s32 c, s16 d, s16 e) {
    Unk_801E0340 *p = &D_801E0340;
    p->unkA = 1;
    p->unk0[1] = 2;
    p->unk0[3] = 0;
    p->unk0[2] = 1;
    p->unkC = "\\S\\TWN.S;1";
    p->unk14 = a;
    p->unk18 = b;
    p->unk1C = c;
    p->unk12 = d;
    p->unk10 = e;
}

void mail_goto_building(u16 arg0, char *arg1, s16 arg2, s16 arg3, u16 arg4, u16 arg5, u16 arg6, u32 arg7, u16 arg8) {
    Unk_8018C554 *p = (Unk_8018C554 *)&D_801E0340;
    GameVars *g = &action_vars;

    p->unkA = 1;
    switch ((s16)g->vars[arg2]) {
    case 0:
        p->unk0[3] = 0;
        break;
    case 10:
        p->unk0[3] = 2;
        break;
    case 1000:
        p->unk0[3] = 3;
        break;
    case 2000:
        p->unk0[3] = 4;
        break;
    default:
        p->unk0[3] = 1;
        break;
    }
    p->unk0[1] = 1;
    p->unkC = NULL;
    p->unk0[2] = arg6;
    memset(p->unk20, 0, 4);
    strncpy(p->unk20, arg1, 3);
    p->unk16 = arg3;
    p->unk18 = arg4;
    p->unk1A = arg5;
    p->unk14 = 0;
    p->unk1C = arg8;
    if (arg2 != 13 && (u16)(arg2 - 11) < 16 && (u32)(*(g->vars + arg2) - 11) < 90) {
        p->unk14 = 1;
    }
    if (arg0 == 1) {
        switch ((arg7 >> 16) & 0xFF) {
        case 0xF6:
            p->unk10 = 1;
            p->unk12 = arg7 & 0xFF;
            break;
        case 0xF9:
            p->unk10 = 2;
            p->unk12 = arg7 & 0xFF;
            break;
        default:
            p->unk10 = 0;
            p->unk12 = (s8)(arg7 >> 8);
            break;
        }
    } else {
        p->unk10 = ((arg7 & 0xFF00) >> 8) + 2;
        p->unk12 = arg7 & 0xFF;
    }
}

s16 mail_wrap_angle(s16 a) {
    do {
        if (a < 0) a += 360;
        if (a >= 360) a -= 360;
    } while ((u16)a >= 360);
    return a;
}

s32 mail_angle_to_dir4(s16 a) {
    s32 b;

loop:
    if (a < 0) a += 360;
    if (a >= 360) a -= 360;
    if ((u16)a >= 360) goto loop;
    b = a;
    if (b >= 45 && b < 135) return 0;
    if (b >= 135 && b < 225) return 6;
    if (b >= 225 && b < 315) return 4;
    return 2;
}

s32 mail_exp_for_level(s32 a) {
    s32 i;
    s32 r;
    if (a == 1) return 0;
    if (a == 2) return 0x144;
    r = 0x144;
    for (i = 3; i <= a; i++) {
        r += 0x195 + (i - 3) * 0xA2;
    }
    return r;
}

void mail_menu_draw_item_name(s32 a, s32 b, s32 c) {
    s16 r[4];
    u16 buf[0x20];
    Unk_8018C864 *p;
    Unk_801891A4 *e;
    u16 *d;
    u16 *f;
    s32 i;
    s32 t;
    s32 j;
    s32 n;
    s32 x;

    p = (Unk_8018C864 *)sprite_find(a);
    e = effect_item_find(c);
    if (p == NULL || e == NULL) {
        return;
    }
    x = p->unk1C->unk0;
    b += p->unk1C->unk2;
    r[2] = 2;
    r[3] = 15;
    r[0] = x;
    r[1] = b;
    n = strlen((char *)e->unk4);
    for (i = 0; i < 24; i += 2) {
        d = buf;
        if (i < n) {
            f = Krom2RawAdd2((e->unk4[i] << 8) | e->unk4[i + 1]);
            for (j = 0; j < 15; j++, f++) {
                {
                    u16 v;
                    s32 k;
                    s32 sh;
                    s32 m;
                    u16 c1;
                    u16 c2;

                    m = 4;
                    v = 0;
                    k = 7;
                    sh = 0;
                    do {
                        c1 = (*f >> k) & 1 ? 2 : 14;
                        k--;
                        c2 = (*f >> k) & 1 ? 2 : 14;
                        k--;
                        if (c1 == c2) {
                            v |= c1 << sh;
                        } else {
                            v |= 10 << sh;
                        }
                        sh += 4;
                    } while (k > m);
                    d[0] = v;
                }
                {
                    u16 v;
                    s32 k;
                    s32 sh;
                    s32 m;
                    u16 c1;
                    u16 c2;

                    m = 0;
                    v = 0;
                    k = 3;
                    sh = 0;
                    do {
                        c1 = (*f >> k) & 1 ? 2 : 14;
                        k--;
                        c2 = (*f >> k) & 1 ? 2 : 14;
                        k--;
                        if (c1 == c2) {
                            v |= c1 << sh;
                        } else {
                            v |= 10 << sh;
                        }
                        sh += 4;
                    } while (k > m);
                    t = d[0];
                    t |= (u16)(v << 8);
                    d[0] = t;
                    d++;
                }
                {
                    u16 v;
                    s32 k;
                    s32 sh;
                    s32 m;
                    u16 c1;
                    u16 c2;

                    m = 12;
                    v = 0;
                    k = 15;
                    sh = 0;
                    do {
                        c1 = (*f >> k) & 1 ? 2 : 14;
                        k--;
                        c2 = (*f >> k) & 1 ? 2 : 14;
                        k--;
                        if (c1 == c2) {
                            v |= c1 << sh;
                        } else {
                            v |= 10 << sh;
                        }
                        sh += 4;
                    } while (k > m);
                    d[0] = v;
                }
                {
                    u16 v;
                    s32 k;
                    s32 sh;
                    s32 m;
                    u16 c1;
                    u16 c2;

                    m = 8;
                    v = 0;
                    k = 11;
                    sh = 0;
                    do {
                        c1 = (*f >> k) & 1 ? 2 : 14;
                        k--;
                        c2 = (*f >> k) & 1 ? 2 : 14;
                        k--;
                        if (c1 == c2) {
                            v |= c1 << sh;
                        } else {
                            v |= 10 << sh;
                        }
                        sh += 4;
                    } while (k > m);
                    t = d[0];
                    t |= (u16)(v << 8);
                    d[0] = t;
                    d++;
                }
            }
        } else {
            memset(d, 0xEE, 0x40);
        }
        LoadImage2(r, buf);
        r[0] += 2;
    }
}

void mail_menu_draw(Unk_801E058C *p, s32 b) {
    s32 i;
    s16 start;
    s16 end;
    s32 j;
    u16 col;
    u16 row;

    sprite_fill_clut(p->unkA, p->unk8, p->unk8 + p->unk18 - 1, p->unk10);
    sprite_set_clut_entry(p->unkA, p->unk4, (u16)p->unk12);
    start = p->unk6;
    if (p->unk18 < p->unk1A) {
        end = start + p->unk18;
    } else {
        end = start + p->unk1A;
    }
    if ((s16)b != 0 && p->unk16 != 0) {
        for (i = start, j = 0; i < end; i++, j++) {
            if (p->unkC >= 0) {
                if (p->unk1C == NULL) {
                    col = i / p->unkE;
                    row = i % p->unkE;
                } else {
                    col = p->unk1C[i] / p->unkE;
                    row = p->unk1C[i] % p->unkE;
                }
                sprite_copy_cell((u16)p->unkC, col, row, p->unkA, 0x10, (u16)(j * 0x11 + 0xC));
            } else if (p->unkC == -2) {
                mail_menu_draw_item_name((s16)p->unkA, j * 0x11 + 0xC, p->unk1C[i]);
            }
        }
    }
}

void mail_menu_clear_rows(Unk_801E058C *p) {
    s16 r[4];
    Unk_8018CD4C *a;
    Unk_8018CD4C *b;
    u8 *buf;
    s32 n;
    s32 i;

    a = (Unk_8018CD4C *)sprite_find(p->unkA);
    b = (Unk_8018CD4C *)sprite_find(p->unkC);
    if (a != NULL) {
        r[0] = a->unk1C->unk0;
        r[1] = a->unk1C->unk2 + 0xC;
        r[2] = 0x18;
        r[3] = 0x10;
        if (b != NULL) {
            r[0] = a->unk1C->unk0 + (0x10 >> a->unk1C->unk14);
            r[1] = a->unk1C->unk2 + 0xC;
            r[2] = b->unk10 >> b->unk1C->unk14;
            r[3] = b->unk12;
            p->unkE = b->unk16;
        }
        n = r[2] * r[3] * 2;
        buf = kaj_malloc(n);
        if (buf != NULL) {
            memset(buf, 0xEE, n);
            for (i = 0; i < 6; i++) {
                LoadImage2(r, buf);
                r[1] += 0x11;
            }
            free3(buf);
        }
    }
}

s16 mail_menu_move(s16 a) {
    s16 snd = 1;
    s32 flag = 0;
    Unk_801E058C *p = &mail_menu;

    if (a != 0) {
        p->unk2--;
        if (p->unk14 != 0) {
            p->unk4--;
            if (p->unk2 < 0) {
                p->unk2 = p->unk1A - 1;
                p->unk4 = p->unk8 + p->unk2;
            }
        } else {
            if (p->unk2 < 0) {
                p->unk2 = 0;
            }
            p->unk4--;
            if (p->unk4 < p->unk8) {
                p->unk4 = p->unk8;
                snd = 0;
                if (p->unk6 > 0) {
                    p->unk6--;
                    flag = 1;
                    snd = 1;
                }
            }
        }
    } else {
        p->unk2++;
        if (p->unk14 != 0) {
            p->unk4++;
            if (p->unk2 >= p->unk1A) {
                p->unk2 = 0;
                p->unk4 = p->unk8;
            }
        } else {
            if (p->unk2 >= p->unk1A) {
                p->unk2 = p->unk1A - 1;
            }
            p->unk4++;
            if (p->unk4 >= p->unk8 + p->unk18) {
                p->unk4 = p->unk8 + p->unk18 - 1;
                snd = 0;
                if (p->unk6 != p->unk2 - p->unk18 + 1) {
                    p->unk6 = p->unk2 - p->unk18 + 1;
                    flag = 1;
                    snd = 1;
                }
            }
        }
    }
    if (snd) {
        sound_se_play(0xF);
    }
    mail_menu_draw(p, flag);
    return p->unk2;
}

s32 mail_menu_open(s16 a, s16 b, s16 c, s16 d, s16 e, s16 *f, s16 g, s16 h, s16 i) {
    GameVars *p = &action_vars;
    Unk_801E058C *q = &p->unk224;
    if (p->unk224.unk0 != 0) {
        return 0;
    }
    p->unk24C = 1;
    p->unk224.unk0 = 2;
    if (a != 0) {
        q->unk2 = 0;
        q->unk4 = g;
        q->unk6 = 0;
    }
    q->unk8 = g;
    q->unkA = b;
    q->unkC = c;
    q->unk10 = h;
    q->unk12 = i;
    q->unk14 = 1;
    if (e < d) {
        q->unk14 = 0;
    }
    q->unk16 = 1;
    if (c == -1) {
        q->unk16 = 0;
    }
    q->unk18 = e;
    q->unk1A = d;
    q->unk1C = f;
    if ((c == 0x40C || c == 0x402 || c == -2) && b == 0x40B) {
        mail_menu_clear_rows(q);
    }
    mail_menu_draw(q, 1);
    effect_start_sprite_slide(0xB, b, 2);
    return 1;
}

s32 mail_menu_close(void) {
    Unk_801E058C *p = &mail_menu;
    if (p->unk0 != 1) {
        return 0;
    }
    p->unk0 = 2;
    effect_start_sprite_slide(0xC, p->unkA, 2);
    return 1;
}

s16 mail_menu_get_state(void) { return mail_menu.unk0; }

s32 mail_menu_set_list(u16 a, s16 *b) {
    Unk_801E058C *p = &mail_menu;
    if (p->unk0 == 2) {
        return 0;
    }
    p->unk2 = 0;
    p->unk6 = 0;
    p->unk1C = b;
    p->unk4 = p->unk8;
    sprite_set_visible(p->unkA, 0);
    sprite_set_visible(a, 1);
    p->unkA = a;
    mail_menu_draw(p, 0);
    return 1;
}

s16 mail_menu_get_entry(s16 i) {
    Unk_801E058C *p = &mail_menu;
    if (i < 0 || p->unk1A < i) {
        return -1;
    }
    return p->unk1C[i];
}

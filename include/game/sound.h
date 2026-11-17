#ifndef GAME_SOUND_H
#define GAME_SOUND_H

#include "common.h"
#include "game/types.h"

typedef struct VabStream {
    u8 unk0[0x4];
    u8 *head;
    u8 *body_buf;
    u8 unkC[0x4];
    s32 body_len;
    s16 vab_id;
} VabStream;

typedef struct SeVabStream {
    u8 unk0[0x4];
    s32 head;
    u8 unk8[0x4];
    s32 head_size;
    u8 unk10[0x4];
    u16 vab_id;
    u16 tone_count;
    u16 bank_id;
    u16 scene_bank;
} SeVabStream;

typedef struct { u8 unk0[0x44]; u16 move_state; u8 unk46[6]; s16 bob_y; } Player_u801A217C;

typedef struct { u16 unk0[0xA]; u16 tone_count; u8 unk16[0x7DE]; } VabHeadCopy;

/* Functions of src/game/sound.c that other files call or a table names. */
void sound_se_push(SeVabStream *bank);
void sound_se_pop(void);
void sound_se_pop_scene(void);
void sound_se_stop_all(void);
void sound_se_stop(s32 id);
void sound_se_play(s32 id);
void sound_se_play_note(s16 bank_id, s16 prog, s16 tone_no, s16 note, s16 vol_l, s16 vol_r, s16 pin);
void sound_exec_command(Action *cmd);
void sound_bgm_open(BgmSep *bgm);
void sound_footstep_update(Player_u801A217C *player);
VabHeadCopy *sound_se_alloc_header(u16 *src, s32 size, SeVabStream *bank);
void sound_vab_open_head(VabStream *vab);
void sound_vab_transfer(VabStream *vab);
void sound_bgm_create(BgmSep **out, u32 size);
void sound_bgm_close(void);
void sound_bgm_play(s16 seq);
void sound_bgm_stop(void);
void sound_bgm_fade_out(s32 seconds);

#endif

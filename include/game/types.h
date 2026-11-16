#ifndef GAME_TYPES_H
#define GAME_TYPES_H

/* Struct types shared by several units, one definition each. */

typedef struct KajSystem {
    s32 pad_now;
    s32 pad_prev;
    s16 timer_enabled;
    s16 pad_mode;
    s32 timer_ticks;
    s32 timer_period;
    s32 vsync_delta;
    s16 unk18;
    u8 unk1A[0x2];
} KajSystem;

typedef struct GsCoordinate2 {
    s32 flg;
    s16 coord_m[0xA];
    s32 coord_tx;
    s32 coord_ty;
    s32 coord_tz;
    u8 unk24[0x2C];
} GsCoordinate2;

typedef struct Unk_801E076C_18 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u8 unk14[0x4];
    s32 unk18;
    s16 unk1C;
    s16 unk1E;
    u16 unk20;
} Unk_801E076C_18;

typedef struct Player {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC[0x4];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 unk16[0x2];
    Unk_801E076C_18 unk18;
    s16 unk3C;
    s16 unk3E;
    s16 unk40;
    u16 flags;
    s16 move_state;
    u16 vehicle_mode;
    s16 unk48;
    s16 speed_step;
    s16 unk4C;
    s16 unk4E;
    s16 unk50;
    u8 unk52[0x2];
    s32 pos_x;
    s32 pos_y;
    s32 pos_z;
    s32 unk60;
    s32 unk64;
    s32 unk68;
    s16 pitch;
    s16 yaw;
    s16 unk70;
    s16 cell_x;
    s16 cell_y;
    s16 cell_z;
    s16 unk78;
    u8 unk7A[0x2];
    u8 unk7C[0x14];
    s32 unk90[3];
    s32 unk9C;
    GsCoordinate2 coord[1];
} Player;

typedef struct Inventory {
    s16 unk0;
    s16 weapon_slot;
    s16 weapon_ids[2];
    s16 weapon_rate[2];
    s16 unkC[0x12];
    s16 unk30;
    s16 item_ids[8];
    s16 unk42;
    s16 weapon_shown;
    s16 armed;
    u16 weapon_state;
    u8 unk4A[0x2];
    s32 weapon_model;
} Inventory;

typedef struct Npc {
    u16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    u8 unkA;
    u8 unkB;
    s16 unkC;
    u8 unkE;
    u8 unkF;
    s16 unk10;
    u16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    s16 unk1E;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s16 unk38;
    s16 unk3A;
    s16 unk3C;
    s16 unk3E;
    s16 unk40;
    s16 unk42;
    u8 unk44;
    u8 unk45;
    s16 unk46;
    s32 unk48;
} Npc;

typedef struct Unk_8018E56C {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    u16 unk14;
    u16 unk16;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    void *unk24;
    void *unk28;
    void *unk2C;
    void *unk30;
    s32 unk34;
    void *unk38;
    s32 unk3C;
    u8 unk40[0x14];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    u8 unk60[0x2C];
    void *unk8C;
    s16 *unk90;
} Unk_8018E56C;

typedef struct PlayerStatus {
    s16 energy;
    s16 level;
    u32 exp;
    u32 next_exp;
    u16 unkC;
    u16 unkE;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    s16 unk16;
    u16 unk18;
    s16 unk1A;
    u16 unk1C;
    s16 unk1E;
    u16 unk20;
    s16 unk22;
    u16 unk24;
    s16 unk26;
    u16 unk28;
    s16 unk2A;
    s16 mutant;
    s16 unk2E;
    s16 unk30;
    s16 unk32;
    s16 unk34;
    s16 hours_awake;
    s16 unk38;
    s16 limb_state[5];
    s16 drain_pending;
    s16 limb_redraw;
    s16 weapon_redraw;
    s16 infected;
    Npc *target_npc;
    Unk_8018E56C *model;
    struct Unk_801AC55C *vehicle;
    Inventory *inventory;
    Player *player;
} PlayerStatus;

typedef struct Unk_801854B8 {
    u16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s32 unk28;
    u8 unk2C[0x14];
    s32 unk40;
    s32 unk44;
    s32 unk48;
    u8 unk4C[0x2C];
    void *unk78;
    void *unk7C;
} Unk_801854B8;

typedef struct Unk_801CCB70 {
    struct Unk_801CCB70 *unk0;
    struct Unk_801CCB70 *unk4;
    struct Unk_80174B10 *unk8;
} Unk_801CCB70;

typedef struct Unk_801A7AFC {
    u16 unk0;
    u16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    u8 unk12[0x2];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    u8 unk2A[0x2];
    s32 unk2C;
    u8 unk30[0x14];
    s32 unk44;
    s32 unk48;
    s32 unk4C;
    u8 unk50[0x2C];
    void *unk7C;
    void *unk80;
    void *unk84;
} Unk_801A7AFC;

typedef struct Unk_8017CCE4 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    u8 unkA[0x2];
    s16 unkC;
    u16 unkE;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    u8 unk2C[0x14];
    s32 unk40;
    s32 unk44;
    s32 unk48;
    u8 unk4C[0x2C];
    void *unk78;
    void *unk7C;
    void *unk80;
    void *unk84;
    struct Unk_8017C9F8 *unk88;
    void *unk8C;
} Unk_8017CCE4;

typedef struct Unk_80192F20 {
    s32 unk0;
    s32 unk4;
    struct Unk_80192E18 *unk8;
    void *unkC;
} Unk_80192F20;

typedef struct Unk_801DFFE8 {
    s32 unk0;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    u16 unk10;
    u16 unk12;
} Unk_801DFFE8;

typedef struct SceneTables {
    struct Unk_801A3B5C *unk0;
    struct Unk_801E02DC *unk4[4];
    s32 unk14;
    s32 trigger_count;
    s32 npc_count;
    s32 unk20;
    s32 npc_body_count;
    s32 npc_stats_count;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    struct SceneTrigger *triggers;
    Npc *npcs;
    struct NpcBody *npc_bodies;
    struct NpcStats *npc_stats;
    void *unk48;
    struct Unk_8018BC50 *unk4C;
    struct Unk_8018F590 *unk50;
    struct Unk_801AC278 *unk54;
    struct Unk_80188FEC *unk58;
    void *unk5C[1];
} SceneTables;

typedef struct Unk_801E056C {
    s32 unk0;
    s16 unk4;
} Unk_801E056C;

typedef struct Unk_801E058C {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    u16 unkA;
    s16 unkC;
    s16 unkE;
    u16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    s16 *unk1C;
} Unk_801E058C;

typedef struct GameVars {
    u16 vars[0x5A];
    s16 limb_damage[5];
    u8 unkBE[0x2];
    s16 unkC0;
    u16 unkC2[0xF];
    u8 unkE0[0x11C];
    s16 drain_count;
    s16 drain_minute;
    u16 unk200;
    u16 unk202;
    Unk_801E056C unk204[4];
    Unk_801E058C unk224;
    s32 unk244;
    u8 unk248[0x4];
    s16 unk24C;
    u8 unk24E[0x2];
    s16 unk250;
    s16 unk252;
    s16 unk254;
} GameVars;

typedef struct NpcBody {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 radius;
    char unkC[0x20];
    char unk2C[0x20];
    char unk4C[0x20];
    u8 unk6C[0x60];
} NpcBody;

typedef struct Unk_801CC1E8 {
    s32 unk0;
    u32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Unk_801CC1E8;

typedef struct Unk_80174B10 {
    struct Unk_80174A14 *unk0;
    s32 unk4;
    struct Unk_80174CB8 *unk8;
} Unk_80174B10;

typedef struct Unk_801E1040 {
    s16 unk0[3];
    s16 unk6;
    s16 unk8[3];
    s16 unkE;
    s16 unk10;
} Unk_801E1040;

typedef struct NpcStats {
    u16 unk0;
    s16 weapon_kind;
    u16 unk4;
    u8 unk6[0x2];
    s16 damage;
    u16 defence;
    s16 unkC;
    u16 unkE;
    s16 speed;
    u16 resist_types;
    u16 unk14;
    s16 unk16;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
} NpcStats;

typedef struct Unk_801A3B5C {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    void *unk8;
} Unk_801A3B5C;

typedef struct Unk_80174FFC {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u8 unk6[0x2];
} Unk_80174FFC;

typedef struct Unk_801E1118 {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    u16 unkE;
    u16 unk10;
    u16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s16 unk2C;
    s16 unk2E;
    s16 unk30;
    u8 unk32[0x2];
    s16 unk34;
    s16 unk36;
    s16 unk38;
} Unk_801E1118;

typedef struct Unk_801A3970 {
    u8 unk0[0x4];
    u8 *unk4;
    u8 *unk8;
    u8 unkC[0x4];
    s32 unk10;
    s16 unk14;
} Unk_801A3970;

typedef struct Unk_801DFE68 {
    u16 unk0;
    u16 unk2;
} Unk_801DFE68;

typedef struct Unk_80184230 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
} Unk_80184230;

typedef struct Unk_801E07C0 {
    u16 unk0;
    s16 unk2;
    s16 *unk4;
    s16 *unk8;
    s16 *unkC;
} Unk_801E07C0;

typedef struct Unk_8017CAC8 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
} Unk_8017CAC8;

typedef struct Unk_8017C9F8 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    void *unk8;
    Unk_8017CAC8 *unkC;
} Unk_8017C9F8;

typedef struct Unk_801855C8 {
    u8 unk0[0x4];
    struct Unk_801855C8 *unk4;
    Unk_801854B8 *unk8;
} Unk_801855C8;

typedef struct Unk_801DFE80 {
    Unk_801855C8 *unk0;
    Unk_801855C8 *unk4;
    Unk_801855C8 *unk8;
    s32 unkC;
} Unk_801DFE80;

typedef struct Unk_80173954 {
    s16 unk0;
    s16 unk2;
    u16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
} Unk_80173954;

typedef struct Unk_80174A14 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    Unk_80173954 unk8;
    Unk_80173954 unk14;
    Unk_80173954 unk20;
    Unk_80173954 unk2C;
} Unk_80174A14;

typedef struct Unk_80174BC8 {
    void *unk0;
} Unk_80174BC8;

typedef struct Unk_80174CB8 {
    void *unk0;
    s32 unk4;
    Unk_80174BC8 *unk8;
} Unk_80174CB8;

typedef struct Unk_801DFE54 {
    Unk_801CCB70 *unk0;
    Unk_801CCB70 *unk4;
    Unk_801CCB70 *unk8;
    s32 unkC;
} Unk_801DFE54;

typedef struct Unk_80176370 {
    u8 unk0[0x4];
    s16 unk4;
} Unk_80176370;

typedef struct Unk_80174D6C {
    u8 unk0[0x4];
    s16 unk4;
    s16 unk6;
    u8 unk8[0x2];
    s16 unkA;
} Unk_80174D6C;

typedef struct Unk_801DFC60 {
    u8 unk0[0x8];
    s16 unk8;
    u8 unkA[0x4];
    u16 unkE;
    s32 unk10;
    u8 unk14[0x4];
    s32 unk18;
    u8 unk1C[0x68];
    void *unk84;
    s32 unk88;
} Unk_801DFC60;

typedef struct Unk_8017D0E0 {
    u8 unk0[0x4];
    struct Unk_8017D0E0 *unk4;
    Unk_8017CCE4 *unk8;
} Unk_8017D0E0;

typedef struct Unk_801DFE5C {
    Unk_8017D0E0 *unk0;
    Unk_8017D0E0 *unk4;
    Unk_8017D0E0 *unk8;
    s32 unkC;
} Unk_801DFE5C;

typedef struct Unk_8018F590 {
    u16 unk0;
    s16 unk2;
    u16 unk4;
    u16 unk6;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    u8 unk1A;
    u8 unk1B;
    s16 unk1C;
    s16 unk1E;
} Unk_8018F590;

typedef struct Unk_801A217C {
    u8 unk0[0x4];
    s32 unk4;
    u8 unk8[0x4];
    s32 unkC;
    u8 unk10[0x4];
    u16 unk14;
    u16 unk16;
    u16 unk18;
    u16 unk1A;
} Unk_801A217C;

typedef struct Unk_801A4370 {
    u16 unk0;
    u16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    u16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    s32 unk1C;
} Unk_801A4370;

typedef struct Unk_801A3DD4 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u8 unkA[0x2];
    u16 unkC;
    u16 unkE;
    u8 unk10[0x2];
    s16 unk12;
    u8 unk14[4];
} Unk_801A3DD4;

typedef struct Unk_801AC278 {
    u16 unk0;
    u8 unk2[0xB6];
    void *unkB8;
    void *unkBC;
    void *unkC0;
} Unk_801AC278;

typedef struct Unk_80192E18 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} Unk_80192E18;

typedef struct Unk_801E0600 {
    s32 unk0;
    u16 unk4;
    u8 unk6[0x2];
    s32 unk8;
    u8 unkC[0x4];
} Unk_801E0600;

typedef struct Unk_80192F60 {
    u8 unk0[0x8];
    s32 unk8;
    s32 unkC;
} Unk_80192F60;

typedef struct Unk_801DFF30 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} Unk_801DFF30;

typedef struct Unk_801DFF28 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Unk_801DFF28;

typedef struct Unk_8019A07C_3C {
    u16 unk0;
    u16 unk2;
    u8 unk4[0x10];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    u8 unk20[0x1C];
    s16 unk3C;
    s16 unk3E;
    s16 unk40;
} Unk_8019A07C_3C;

typedef struct Unk_8019A07C {
    u8 unk0[0x3C];
    Unk_8019A07C_3C *unk3C;
} Unk_8019A07C;

typedef struct Unk_801D1BD4 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Unk_801D1BD4;

typedef struct Unk_801D05F8 {
    s32 unk0;
    void *unk4;
    s32 unk8;
    s32 unkC;
} Unk_801D05F8;

typedef struct Unk_801DFBB8 {
    Unk_801D05F8 *unk0;
    s32 unk4;
    s32 unk8;
    s16 unkC;
    u8 unkE[0x2];
    s32 unk10;
    s32 unk14;
} Unk_801DFBB8;

typedef struct Unk_801D1088 {
    u8 unk0[0x2];
    u16 unk2;
    u32 unk4;
} Unk_801D1088;

typedef struct Unk_801D12A8 {
    struct Unk_801D12A8 *unk0;
    u8 unk4[0x1C];
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    u8 unk2A[0x2];
    s32 unk2C;
    void (*unk30)(struct Unk_801D12A8 *);
    void (*unk34)(struct Unk_801D12A8 *);
    void (*unk38)(struct Unk_801D12A8 *);
    void *unk3C;
} Unk_801D12A8;

typedef struct Unk_801DFBD0 {
    s32 unk0;
    Unk_801D12A8 *unk4;
    Unk_801D12A8 *unk8;
    Unk_801D12A8 *unkC;
} Unk_801DFBD0;

typedef struct Unk_801E6FF0 {
    u8 unk0[0x17];
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C[0x40];
    u8 unk5C[0x14];
    s32 unk70;
    u32 *unk74;
    s32 unk78;
    s32 unk7C;
    u32 *unk80;
    u32 *unk84;
    s32 unk88;
} Unk_801E6FF0;

typedef struct Unk_801A7C3C {
    u8 unk0[0x4];
    s16 unk4;
    s16 unk6;
    u8 unk8[0x8];
    s16 unk10;
    u8 unk12[0x2];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    u8 unk2A[0x2];
    s32 unk2C;
    u8 unk30[0x14];
    s32 unk44;
    s32 unk48;
    s32 unk4C;
} Unk_801A7C3C;

typedef struct Unk_801A742C_10 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u8 unk6[0x2];
} Unk_801A742C_10;

typedef struct Unk_801AC55C {
    u8 unk0[0x4];
    s16 unk4;
    u8 unk6[0x4];
    s16 unkA;
    s16 unkC;
    u8 unkE[0x2];
    s16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
    s16 unk18;
    s16 unk1A;
    struct Unk_801AC55C_1C *unk1C;
} Unk_801AC55C;

typedef struct Unk_8017E504 {
    u8 unk0[0xC];
    s32 unkC;
    s32 unk10;
} Unk_8017E504;

typedef struct Unk_80184100 {
    u8 unk0[0x6];
    s16 unk6;
    u16 unk8;
} Unk_80184100;

typedef struct Unk_801DFCAC {
    u16 unk0;
    u16 unk2;
} Unk_801DFCAC;

typedef struct Unk_80181C10 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    struct Unk_801A44B8 *unk8;
    struct Unk_801A44B8 *unkC;
} Unk_80181C10;

typedef struct Unk_80184338 {
    u8 unk0[0x22];
    s16 unk22;
    u16 unk24;
    s16 unk26;
    s16 unk28;
    u8 unk2A[0x2];
    s32 unk2C;
    void (*unk30)(struct Unk_80184338 *arg0);
    void (*unk34)(void);
    void (*unk38)(void);
    s32 *unk3C;
} Unk_80184338;

typedef struct Unk_80184814 {
    u16 unk0;
    u16 unk2;
    s16 unk4;
    s16 unk6;
    u8 unk8[0x2];
    u16 unkA;
    s16 unkC;
    s16 unkE;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    u8 unk26[0x2];
    s32 unk28;
    u8 unk2C[0x14];
    s32 unk40;
    s32 unk44;
    s32 unk48;
} Unk_80184814;

typedef struct Unk_8017B1E8 {
    u16 unk0;
    u8 unk2[0x1];
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7[0x1];
    u16 unk8;
    u16 unkA;
    u16 unkC;
    u16 unkE;
} Unk_8017B1E8;

typedef struct Unk_8017B3E8 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Unk_8017B3E8;

typedef struct Unk_8018519C_0 {
    u8 unk0[0x2];
    u16 unk2;
    u16 unk4;
} Unk_8018519C_0;

typedef struct Unk_8018FA18 {
    u8 unk0[0x7F8];
} Unk_8018FA18;

typedef struct Unk_8019120C {
    u8 unk0[0x7F4];
} Unk_8019120C;

typedef struct Unk_80193068 {
    u8 unk0[0x8];
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Unk_80193068;

typedef struct Unk_801DFF20 {
    u8 unk0[0x4];
} Unk_801DFF20;

typedef struct Unk_80191AB0_C {
    s32 unk0;
    s32 unk4;
    s16 unk8;
} Unk_80191AB0_C;

typedef struct Unk_80191AB0 {
    s16 unk0;
    u8 unk2[0xE];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 unk16[0x6];
    s16 unk1C;
} Unk_80191AB0;

typedef struct Unk_801DFC64 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u8 *unk8;
} Unk_801DFC64;

typedef struct Unk_801E1158 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    Unk_801A742C_10 unk1C;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    u8 unk2A[0x2];
    Unk_801A742C_10 unk2C[4];
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    u8 unk58[0x4];
    s32 unk5C;
    s32 unk60;
    s32 unk64;
} Unk_801E1158;

typedef struct Unk_801E0340 {
    s16 unk0[5];
    s16 unkA;
    char *unkC;
    s16 unk10;
    s16 unk12;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} Unk_801E0340;

typedef struct Unk_801D7FB0 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u8 unk6[0x2];
    u32 unk8;
    Unk_801AC55C *unkC;
    Unk_801AC55C *unk10;
} Unk_801D7FB0;

typedef struct Unk_801891A4 {
    u16 unk0;
    u16 unk2;
    char unk4[0x22];
    s16 unk26;
} Unk_801891A4;

typedef struct SceneTrigger {
    s32 id;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
} SceneTrigger;

typedef struct Unk_80173250 {
    u16 unk0;
    u16 unk2;
    s32 unk4;
} Unk_80173250;

#endif

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

typedef struct PlayerExit {
    s32 distance;
    s32 pos_x;
    s32 pos_y;
    s32 pos_z;
    s32 unk10;
    u8 unk14[0x4];
    s32 unk18;
    s16 direction;
    s16 facing;
    u16 yaw;
} PlayerExit;

typedef struct Player {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC[0x4];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 unk16[0x2];
    PlayerExit exit;
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
    s16 roll;
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
    s32 block;
} Npc;

typedef struct Model {
    s16 id;
    s16 kind;
    s16 ready;
    s16 owns_data;
    s16 playing;
    s16 unkA;
    s16 frame;
    s16 end_frame;
    s16 loop;
    s16 frame_step;
    u16 anim_count;
    u16 anim;
    s32 tod_ptr;
    s32 tmd_ids;
    s32 tmd;
    void *tod_table;
    void *obj_table;
    void *dobj_table;
    void *tmd_objects;
    s32 parent_coord;
    void *coord_table;
    s32 coord_flg;
    u8 coord_m[0x14];
    s32 coord_tx;
    s32 coord_ty;
    s32 coord_tz;
    u8 unk60[0x2C];
    void *coord_params;
    s16 *data;
} Model;

typedef struct PlayerStatus {
    s16 energy;
    s16 level;
    u32 exp;
    u32 next_exp;
    u16 stat0;
    u16 stat1;
    u16 stat2;
    u16 stat3;
    u16 weapon0_level;
    s16 weapon0_exp;
    u16 weapon1_level;
    s16 weapon1_exp;
    u16 weapon2_level;
    s16 weapon2_exp;
    u16 weapon3_level;
    s16 weapon3_exp;
    u16 weapon4_level;
    s16 weapon4_exp;
    u16 defense_level;
    s16 defense_exp;
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
    Model *model;
    struct VehicleSprite *vehicle;
    Inventory *inventory;
    Player *player;
} PlayerStatus;

typedef struct Door {
    u16 id;
    s16 axis;
    s16 active;
    s16 visible;
    s16 unk8;
    s16 state;
    s16 move_from;
    s16 move_to;
    s32 block;
    s32 pos_x;
    s32 pos_y;
    s32 pos_z;
    s16 angle;
    s16 speed;
    s16 auto_return;
    s16 unk26;
    s32 coord_flg;
    u8 coord_m[0x14];
    s32 coord_tx;
    s32 coord_ty;
    s32 coord_tz;
    u8 unk4C[0x2C];
    void *tmd_objects;
    void *record;
} Door;

typedef struct LlNode {
    struct LlNode *prev;
    struct LlNode *next;
    struct ActionSet *data;
} LlNode;

typedef struct Thing {
    u16 id;
    u16 type;
    s16 active;
    s16 animate;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 block_fixed;
    u8 unk12[0x2];
    s32 block;
    s32 pos_x;
    s32 pos_y;
    s32 pos_z;
    s16 rot_x;
    s16 rot_y;
    s16 rot_z;
    u8 unk2A[0x2];
    s32 coord_flg;
    u8 coord_m[0x14];
    s32 coord_tx;
    s32 coord_ty;
    s32 coord_tz;
    u8 unk50[0x2C];
    void *tmd_objects;
    void *hit_model;
    void *record;
} Thing;

typedef struct Block {
    s16 active;
    s16 owns_data;
    s16 visible;
    s16 player_inside;
    s16 in_arena;
    u8 unkA[0x2];
    s16 far;
    u16 model_flags;
    s32 pos_x;
    s32 pos_y;
    s32 pos_z;
    s32 size_x;
    s32 size_y;
    s32 size_z;
    s32 coord_flg;
    u8 unk2C[0x14];
    s32 coord_tx;
    s32 coord_ty;
    s32 coord_tz;
    u8 unk4C[0x2C];
    void *model3;
    void *model2;
    void *model1;
    void *floor_model;
    struct Arena *arena;
    void *data;
} Block;

typedef struct IffContext {
    s32 size;
    s32 pos;
    struct IffEntry *header;
    void *chunk;
} IffContext;

typedef struct EventState {
    s32 trigger;
    s16 trigger_type;
    s16 state;
    s16 circle_flags;
    s16 circle_set;
    s16 cross_flags;
    s16 cross_set;
    u16 wait_timer;
    u16 wait_flags;
} EventState;

/* WEPN chunk record (0x60 bytes), the table at SceneTables.weapons searched by effect_weapon_find. */
typedef struct WeaponRecord {
    u16 id;
    u16 weapon_class;
    char name[0x20];
    u16 drain_extra;
    u8 unk26[2];
    s16 req_level_on;
    u8 unk2A[6];
    u16 req_level;
    u8 unk32[2];
    s16 req_stat_on;
    u8 unk36[2];
    u16 req_stat_id;
    u8 unk3A[2];
    s16 req_stat;
    u8 unk3E[2];
    s16 req_class_on;
    u8 unk42[6];
    s16 req_class;
    u8 unk4A[2];
    u16 fire_frame;
    u8 unk4E[2];
    u16 accuracy;
    u16 damage;
    s32 range_min;
    s32 range_full;
    s32 range_max;
} WeaponRecord;

typedef struct SceneTables {
    struct BgmSep *bgm;
    struct Unk_801E02DC *se_banks[4];
    s32 se_bank_count;
    s32 trigger_count;
    s32 npc_count;
    s32 npc_record_count;
    s32 npc_body_count;
    s32 npc_stats_count;
    s32 item_count;
    s32 weapon_count;
    s32 text_count;
    struct SceneTrigger *triggers;
    Npc *npcs;
    struct NpcBody *npc_bodies;
    struct NpcStats *npc_stats;
    void *items;
    struct Unk_8018BC50 *mail;
    struct NpcRecord *npc_records;
    struct Vehicle *vehicle;
    WeaponRecord *weapons;
    void *texts[1];
} SceneTables;

typedef struct EffectAlarm {
    s32 alarm;
    s16 active;
} EffectAlarm;

typedef struct MailMenu {
    s16 state;
    s16 index;
    s16 cursor_entry;
    s16 scroll;
    s16 first_entry;
    u16 sprite;
    s16 icon_sprite;
    s16 icon_rows;
    u16 color;
    s16 cursor_color;
    s16 wrap;
    s16 draw_rows;
    s16 rows;
    s16 count;
    s16 *list;
} MailMenu;

typedef struct GameVars {
    u16 vars[0x5A];
    s16 limb_damage[5];
    u8 unkBE[0x2];
    s16 unkC0;
    u16 unkC2[0xF];
    u8 unkE0[0x11C];
    s16 drain_count;
    s16 drain_minute;
    u16 car_speed_setting;
    u16 text_speed_setting;
    EffectAlarm alarms[4];
    MailMenu mail_menu;
    s32 unk244;
    u8 unk248[0x4];
    s16 menu_busy;
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

typedef struct KajEvent {
    s32 type;
    u32 ticks;
    s32 param0;
    s32 param1;
    s32 param2;
} KajEvent;

typedef struct ActionSet {
    struct ActionSetHeader *header;
    s32 count;
    struct Action *actions;
} ActionSet;

typedef struct ScreenLight {
    s16 unk0[3];
    s16 fade_active;
    s16 unk8[3];
    s16 fade_level;
    s16 dark;
} ScreenLight;

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

typedef struct BgmSep {
    s16 sep;
    s16 seq;
    s32 seq_count;
    void *data;
} BgmSep;

typedef struct SVector {
    s16 vx;
    s16 vy;
    s16 vz;
    u8 unk6[0x2];
} SVector;

typedef struct TrainState {
    s32 door_task;
    s32 trigger;
    s16 direction;
    s16 unkA;
    s16 unkC;
    u16 door_state;
    u16 station;
    u16 motion;
    s16 speed;
    s16 stop_timer;
    s16 unk18;
    s16 unk1A;
    s32 mark_start;
    s32 mark_cruise;
    s32 mark_brake;
    s32 mark_stop;
    s16 carry_vx;
    s16 carry_vy;
    s16 carry_vz;
    u8 unk32[0x2];
    s16 view_pitch;
    s16 view_yaw;
    s16 unk38;
} TrainState;

typedef struct VabStream {
    u8 unk0[0x4];
    u8 *head;
    u8 *body_buf;
    u8 unkC[0x4];
    s32 body_len;
    s16 vab_id;
} VabStream;

typedef struct BuildingState {
    u16 building;
    u16 unk2;
} BuildingState;

typedef struct Rect {
    u16 x;
    u16 y;
    u16 w;
    u16 h;
} Rect;

typedef struct RoadMap {
    u16 mode;
    s16 unk2;
    s16 *part0;
    s16 *part1;
    s16 *part2;
} RoadMap;

typedef struct ArenaHeader {
    u16 origin_x;
    u16 origin_z;
    u16 width;
    u16 depth;
} ArenaHeader;

typedef struct Arena {
    u16 origin_x;
    u16 origin_z;
    u16 width;
    u16 depth;
    void *data;
    ArenaHeader *cells;
} Arena;

typedef struct DoorListNode {
    u8 unk0[0x4];
    struct DoorListNode *next;
    Door *data;
} DoorListNode;

typedef struct DoorList {
    DoorListNode *head;
    DoorListNode *tail;
    DoorListNode *cursor;
    s32 count;
} DoorList;

typedef struct ActionCond {
    s16 used;
    s16 invert;
    u16 index;
    s16 unk6;
    s16 low;
    s16 high;
} ActionCond;

typedef struct ActionSetHeader {
    u16 unk0;
    u16 unk2;
    u16 next_set;
    u16 next_mode;
    ActionCond cond_var_a;
    ActionCond cond_var_b;
    ActionCond cond_status;
    ActionCond cond_inventory;
} ActionSetHeader;

typedef struct Action {
    struct ActionCmd *cmd;
    s32 argc;
    char **args;
} Action;

typedef struct LlList {
    LlNode *head;
    LlNode *tail;
    LlNode *cursor;
    s32 count;
} LlList;

typedef struct BlockListNode {
    u8 unk0[0x4];
    struct BlockListNode *next;
    Block *data;
} BlockListNode;

typedef struct BlockList {
    BlockListNode *head;
    BlockListNode *tail;
    BlockListNode *cursor;
    s32 count;
} BlockList;

/* kaj ll list of models (mod_list): same handle and node layout as BlockList, but the nodes hold
   the Model * that mod_list_add inserts (mod_alloc result) and mod_find walks. */
typedef struct ModelListNode {
    u8 unk0[0x4];
    struct ModelListNode *next;
    Model *data;
} ModelListNode;

typedef struct ModelList {
    ModelListNode *head;
    ModelListNode *tail;
    ModelListNode *cursor;
    s32 count;
} ModelList;

typedef struct NpcRecord {
    u16 id;
    s16 enabled;
    u16 unk4;
    u16 model;
    s32 pos_x;
    s32 pos_y;
    s32 pos_z;
    s16 rot_x;
    s16 rot_y;
    s16 rot_z;
    u8 scaled;
    u8 shown;
    s16 move_task;
    s16 moving;
} NpcRecord;

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

typedef struct Sprite {
    u16 id;
    u16 mode;
    s16 visible;
    s16 clut_dirty;
    s16 color;
    s16 x;
    s16 y;
    s16 depth;
    s16 cell_w;
    u16 cell_h;
    s16 columns;
    s16 rows;
    s16 cell_col;
    s16 cell_row;
    s32 tim;
} Sprite;

typedef struct SpriteRecord {
    u16 id;
    u16 mode;
    u16 x;
    u16 y;
    u16 depth;
    u8 unkA[0x2];
    u16 columns;
    u16 rows;
    u8 unk10[0x2];
    s16 unk12;
    u8 unk14[4];
} SpriteRecord;

typedef struct Vehicle {
    u16 kind;
    s16 unk2;
    s32 pos_x;
    s32 pos_y;
    s32 pos_z;
    s16 rot_x;
    s16 rot_y;
    s16 rot_z;
    u8 unk16[0x2];
    GsCoordinate2 coord;
    GsCoordinate2 coord2;
    void *model0;
    void *model1;
    void *data;
} Vehicle;

typedef struct IffEntry {
    s32 offset;
    s32 size;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} IffEntry;

typedef struct AreaTrigger {
    s32 trigger;
    u16 trigger_type;
    u8 unk6[0x2];
    s32 scene_trigger;
    u8 unkC[0x4];
} AreaTrigger;

typedef struct RoomPhone {
    s16 ringing;
    s16 state;
    s16 message;
} RoomPhone;

typedef struct RoomStorage {
    s16 open;
    s16 choice;
    s16 stage;
    s16 unk6;
} RoomStorage;

typedef struct PlayerMove {
    u16 flag_op;
    u16 flag_bits;
    s32 from_x;
    s32 from_y;
    s32 from_z;
    u8 unk10[4];
    s32 to_x;
    s32 to_y;
    s32 to_z;
    u8 unk20[4];
    s32 delta_x;
    s32 delta_y;
    s32 delta_z;
    u8 unk30[4];
    s16 from_pitch;
    s16 from_yaw;
    s16 from_roll;
    u8 unk3A[2];
    s16 to_pitch;
    s16 to_yaw;
    s16 to_roll;
    u8 unk42[2];
    s16 delta_pitch;
    s16 delta_yaw;
    s16 delta_roll;
} PlayerMove;

typedef struct TimerAlarm {
    s32 due;
    void *id;
    s32 data;
    s32 wrap;
} TimerAlarm;

typedef struct TimerHeap {
    TimerAlarm *entries;
    s32 capacity;
    s32 count;
    s16 full;
    u8 unkE[0x2];
    s32 popped_id;
    s32 popped_data;
} TimerHeap;

typedef struct TodFrame {
    u8 unk0[0x2];
    u16 packet_count;
    u32 frame;
} TodFrame;

typedef struct TssSlot {
    struct TssSlot *next;
    u8 unk4[0x1C];
    s16 index;
    s16 type;
    s16 cur;
    s16 target;
    s16 step;
    u8 unk2A[0x2];
    s32 delay;
    void (*on_step)(struct TssSlot *);
    void (*on_end)(struct TssSlot *);
    void (*on_kill)(struct TssSlot *);
    void *data;
} TssSlot;

typedef struct TssTable {
    s32 count;
    TssSlot *slots;
    TssSlot *free_list;
    TssSlot *done_list;
} TssTable;

typedef struct ViewBuffer {
    u8 unk0[0x17];
    u8 dfe;
    u8 isbg;
    u8 bg_r;
    u8 bg_g;
    u8 bg_b;
    u8 unk1C[0x40];
    u8 disp_env[0x14];
    s32 ot_length;
    u32 *ot_org;
    s32 ot_offset;
    s32 ot_point;
    u32 *ot_tag;
    u32 *ot_tags;
    s32 packets;
} ViewBuffer;

typedef struct VehicleSprite {
    u8 unk0[0x4];
    s16 visible;
    u8 unk6[0x4];
    s16 x;
    s16 y;
    u8 unkE[0x2];
    s16 cell_w;
    u16 cell_h;
    u16 columns;
    u16 rows;
    s16 cell_col;
    s16 cell_row;
    struct Unk_801AC55C_1C *tim;
} VehicleSprite;

typedef struct Unk_80184100 {
    u8 unk0[0x6];
    s16 unk6;
    u16 unk8;
} Unk_80184100;

typedef struct TextCmd {
    u16 opcode;
    u16 state;
} TextCmd;

typedef struct PauseMenu {
    s16 item;
    s16 page;
    s16 unk4;
    s16 row;
    struct Unk_801A44B8 *unk8;
    struct Unk_801A44B8 *unkC;
} PauseMenu;

typedef struct DoorMove {
    u16 id;
    u16 axis;
    s16 active;
    s16 visible;
    u8 unk8[0x2];
    u16 state;
    s16 move_from;
    s16 move_to;
    s32 block;
    s32 pos_x;
    s32 pos_y;
    s32 pos_z;
    s16 angle;
    s16 speed;
    s16 auto_return;
    u8 unk26[0x2];
    s32 coord_flg;
    u8 coord_m[0x14];
    s32 coord_tx;
    s32 coord_ty;
    s32 coord_tz;
} DoorMove;

typedef struct TmdTri {
    u16 unk0;
    u8 unk2[0x1];
    u8 mode;
    u8 code_r;
    u8 code_g;
    u8 code_b;
    u8 unk7[0x1];
    u16 normal;
    u16 vert0;
    u16 vert1;
    u16 vert2;
} TmdTri;

/* TMD object table entry: vertex, normal and primitive tops and counts (block_hit_tris walks the primitives). */
typedef struct TmdObject {
    s32 vert_top;
    s32 unk4;
    s32 normal_top;
    s32 unkC;
    TmdTri *primitive_top;
    s32 n_primitive;
} TmdObject;

/* GsDOBJ2 head as the block and vehicle code read it: attribute, coordinate, TMD object. */
typedef struct GsDobj2 {
    s32 unk0;
    GsCoordinate2 *coord2;
    TmdObject *tmd;
} GsDobj2;

typedef struct ShopState {
    s16 unk0;
    s16 menu_stage;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12[3];
    s16 *list;
    s16 *texts;
} ShopState;

typedef struct Vec3 {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

/* View of ActionCmd for the handlers that read the target +4 as u16 (lhu): npc_exec_command, door_exec_command. */
typedef struct ActionCmdShort {
    u16 opcode;
    u16 sub;
    u16 target;
} ActionCmdShort;

typedef struct IffChunkBody {
    u8 unk0[0x7F8];
} IffChunkBody;

typedef struct Unk_8019120C {
    u8 unk0[0x7F4];
} Unk_8019120C;

typedef struct CdLoc {
    u8 unk0[0x4];
} CdLoc;

typedef struct IffChunk {
    s32 tag;
    s32 size;
    s16 unk8;
} IffChunk;

typedef struct Unk_80191AB0 {
    s16 unk0;
    u8 unk2[0xE];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 unk16[0x6];
    s16 unk1C;
} Unk_80191AB0;

typedef struct CarState {
    s16 stopped;
    s16 unk2;
    s16 steer;
    s16 gear;
    s32 brake;
    s32 throttle;
    s32 speed;
    s32 unk14;
    s32 unk18;
    SVector unk1C;
    s16 look_pitch;
    s16 look_yaw;
    s16 unk28;
    u8 unk2A[0x2];
    SVector corners[4];
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    u8 unk58[0x4];
    s32 unk5C;
    s32 unk60;
    s32 unk64;
} CarState;

typedef struct SceneRequest {
    s16 unk0[5];
    s16 change;
    char *path;
    s16 unk10;
    s16 yaw;
    s32 pos_x;
    s32 pos_y;
    s32 pos_z;
} SceneRequest;

typedef struct CarNavi {
    s16 active;
    s16 unk2;
    s16 dest;
    u8 unk6[0x2];
    u32 start_dist;
    VehicleSprite *dest_sprite;
    VehicleSprite *unk10;
} CarNavi;

typedef struct ItemRecord {
    u16 id;
    u16 kind;
    char name[0x22];
    s16 value;
} ItemRecord;

typedef struct SceneTrigger {
    s32 id;
    s16 enter_set;
    s16 leave_set;
    s16 unk8;
    s16 enabled;
} SceneTrigger;

typedef struct ActionCmd {
    u16 opcode;
    u16 sub;
    s32 target;
} ActionCmd;

#endif

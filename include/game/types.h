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
    s16 sep_volume;
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
    s32 centre_x;
    u8 unk14[0x4];
    s32 centre_z;
    s16 direction;
    s16 facing;
    u16 yaw;
} PlayerExit;

typedef struct Player {
    s32 car_x;
    s32 car_y;
    s32 car_z;
    u8 unkC[0x4];
    s16 car_rot_x;
    s16 car_rot_y;
    s16 car_rot_z;
    u8 unk16[0x2];
    PlayerExit exit;
    s16 view_dirty;
    s16 reground;
    s16 climbing;
    u16 flags;
    s16 move_state;
    u16 vehicle_mode;
    s16 move_task;
    s16 speed_step;
    s16 bob_y;
    s16 strafe_speed;
    s16 walk_speed;
    u8 unk52[0x2];
    s32 pos_x;
    s32 pos_y;
    s32 pos_z;
    s32 world_x;
    s32 world_y;
    s32 world_z;
    s16 pitch;
    s16 yaw;
    s16 roll;
    s16 cell_x;
    s16 cell_y;
    s16 cell_z;
    s16 eye_height;
    u8 unk7A[0x2];
    u8 view_matrix[0x14];
    s32 view_trans[3];
    s32 view_super;
    GsCoordinate2 coord[1];
} Player;

typedef struct Inventory {
    s16 weapon_count;
    s16 weapon_slot;
    s16 weapon_ids[2];
    s16 weapon_rate[2];
    s16 weapon_stock[0x12];
    s16 item_count;
    s16 item_ids[8];
    s16 kind2_item;
    s16 weapon_shown;
    s16 armed;
    u16 weapon_state;
    u8 unk4A[0x2];
    s32 weapon_model;
} Inventory;

typedef struct Npc {
    u16 id;
    s16 kind;
    s16 placed;
    s16 active;
    s16 talkable;
    u8 ot_layer;
    u8 fire_decision;
    s16 hp;
    u8 mode;
    u8 state;
    s16 target;
    u16 flags;
    s16 body_id;
    s16 model_id;
    s16 stats_id;
    s16 talk_set;
    s16 leave_set;
    s16 death_set;
    s32 pos_x;
    s32 pos_y;
    s32 pos_z;
    s32 dest_x;
    s32 dest_y;
    s32 dest_z;
    s16 pitch;
    s16 yaw;
    s16 roll;
    s16 target_yaw;
    s16 target_dist;
    s16 exp;
    u8 aim_pitch_diff;
    u8 aim_elevation;
    s16 aim_timer;
    s32 block;
} Npc;

typedef struct Model {
    s16 id;
    s16 kind;
    s16 ready;
    s16 owns_data;
    s16 playing;
    s16 tod_mode;
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
    s16 kills_since_arrest;
    s16 arrests;
    s16 humans_killed;
    s16 naps_today;
    s16 hours_awake;
    s16 low_energy_alarm;
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
    s16 ot_layer;
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
    s16 script_enabled;
    s16 ot_layer;
    s16 enter_set;
    s16 leave_set;
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
    struct SeBank *se_banks[4];
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
    struct MailHandler *mail;
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
    s16 mail_codes[0x10];
    u8 unkE0[0x118];
    u16 shop_entry_hour;
    u8 unk1FA[0x2];
    s16 drain_count;
    s16 drain_minute;
    u16 car_speed_setting;
    u16 text_speed_setting;
    EffectAlarm alarms[4];
    MailMenu mail_menu;
    s32 effect_task;
    s32 narration_task;
    s16 menu_busy;
    s16 text_open;
    s16 flame_large_on;
    s16 flame_small_on;
    s16 clut_cycle_on;
} GameVars;

typedef struct NpcBody {
    u16 id;
    u16 height;
    u16 sex;
    u16 age;
    u16 blood_type;
    u16 radius;
    char line0[0x20];
    char line1[0x20];
    char line2[0x20];
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
    s16 daylight_on;
    s16 bg_color_pending;
    s16 fog_on;
    s16 fade_active;
    s16 daylight_step;
    s16 clip_mode;
    s16 ot_bias;
    s16 fade_level;
    s16 dark;
} ScreenLight;

typedef struct NpcStats {
    u16 id;
    s16 weapon_kind;
    u16 on_hit;
    u8 unk6[0x2];
    s16 damage;
    u16 defence;
    s16 accuracy;
    u16 aim_time;
    s16 speed;
    u16 resist_types;
    u16 fire_chance;
    s16 fire_frames;
    s32 range_min;
    s32 range_mid;
    s32 range_max;
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
    s16 placed;
    s16 prompt_on;
    u16 door_state;
    u16 station;
    u16 motion;
    s16 speed;
    s16 stop_timer;
    s16 arrive_digit_dir1;
    s16 arrive_digit_dir0;
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
    s16 view_roll;
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
    u16 entry;
} BuildingState;

typedef struct Rect {
    u16 x;
    u16 y;
    u16 w;
    u16 h;
} Rect;

typedef struct RoadMap {
    u16 mode;
    s16 zoomed;
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
    ArenaHeader *header;
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
    s16 skip_test;
    s16 low;
    s16 high;
} ActionCond;

typedef struct ActionSetHeader {
    u16 id;
    u16 match_all;
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
    u16 ot_layer;
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
    s16 keep_clut;
    u8 tim[4];
} SpriteRecord;

typedef struct Vehicle {
    u16 kind;
    s16 ot_layer;
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
    s32 count0;
    s32 count1;
    s32 count2;
    s32 count3;
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
    s16 cursor;
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
    struct TimHandle *tim;
} VehicleSprite;

typedef struct TextCmd {
    u16 opcode;
    u16 state;
} TextCmd;

typedef struct PauseMenu {
    s16 item;
    s16 page;
    s16 animating;
    s16 row;
    struct MenuSprite *item_sprite;
    struct MenuSprite *label_sprite;
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
    u16 run_count;
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
    s16 active;
    s16 menu_stage;
    s16 to_inventory;
    s16 alt_speaker;
    s16 at_counter;
    s16 has_second_menu;
    s16 has_third_menu;
    s16 deal_level;
    s16 cursor;
    s16 picks[3];
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

typedef struct IffSectorBody {
    u8 unk0[0x7F4];
} IffSectorBody;

typedef struct CdLoc {
    u8 unk0[0x4];
} CdLoc;

typedef struct IffChunk {
    s32 tag;
    s32 size;
    s16 id;
} IffChunk;

typedef struct SceneRequestLoadView {
    s16 loop;
    u8 unk2[0xE];
    s16 loop_param;
    s16 office_no_gauge;
    s16 arrival_sound;
    u8 unk16[0x6];
    s16 building_gauge;
} SceneRequestLoadView;

typedef struct CarState {
    s16 stopped;
    s16 slowed;
    s16 steer;
    s16 gear;
    s32 brake;
    s32 throttle;
    s32 speed;
    s32 turn_yaw;
    s32 turn_radius;
    SVector seat;
    s16 look_pitch;
    s16 look_yaw;
    s16 look_roll;
    u8 unk2A[0x2];
    SVector corners[4];
    s32 axle_x;
    s32 axle_y;
    s32 axle_z;
    u8 unk58[0x4];
    s32 pivot_x;
    s32 pivot_y;
    s32 pivot_z;
} CarState;

typedef struct SceneRequest {
    s16 loop;
    s16 next_loop;
    s16 scene_index;
    s16 variant;
    s16 quit;
    s16 change;
    char *path;
    s16 loop_param;
    s16 yaw;
    s32 pos_x;
    s32 pos_y;
    s32 pos_z;
} SceneRequest;

typedef struct CarNavi {
    s16 active;
    s16 menu_reset;
    s16 dest;
    u8 unk6[0x2];
    u32 start_dist;
    VehicleSprite *dest_sprite;
    VehicleSprite *arrow_sprite;
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
    s16 passable;
    s16 enabled;
} SceneTrigger;

typedef struct ActionCmd {
    u16 opcode;
    u16 sub;
    s32 target;
} ActionCmd;

#endif

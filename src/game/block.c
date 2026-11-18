#include "common.h"
#include "game/block.h"
#include "game/actor.h"
#include "game/block.h"
#include "game/building.h"
#include "game/door.h"
#include "game/mod.h"
#include "game/player.h"
#include "game/thing.h"
#include "game/vehicle.h"
#include "kaj/cdmgr.h"
#include "kaj/kaj.h"
#include "kaj/ll.h"
#include "kaj/map.h"
#include "kaj/misc.h"
#include "kaj/tim.h"
#include "kaj/view.h"
#include "psyq/libapi.h"
#include "psyq/libc.h"
#include "psyq/libgpu.h"
#include "psyq/libgs.h"
#include "psyq/libgte.h"
#include "gte.h"

/*
 * The city and room blocks: streaming, visibility, ground and surface tests.
 *
 * File boundaries: likely (docs/layout.md): block.c asserts; ends where block_area_flames stops being read through gp.
 */

/* GsDOBJ2 head as the block and vehicle code read it: attribute, coordinate, TMD object. */
typedef struct GsDobj2 {
    s32 unk0;
    GsCoordinate2 *coord2;
    TmdObject *tmd;
} GsDobj2;

typedef struct Vec3 {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

s16 kaj_ll_at_tail(BlockList *list);
BlockList *block_list;
s16 block_reloaded;
extern s16 kaj_cdmgr_state;
u8 block_area_kind;
u8 block_area_flames[1];
u8 block_area_low;
extern GameVars action_vars;
typedef struct {
    s32 x;
    s32 y;
    s32 z;
    s32 unkC;
} PolyVert;
extern Player *player_status_player[];
extern char block_str_file[];
typedef struct SpriteTimView {
    u8 pad0[0x1C];
    Rect *tim;
} SpriteTimView;
extern char block_str_err_alloc_ptr[];
extern Block *block_slots[];
u16 block_building_id;
static void block_load_all(u16 mode);
static void block_set_zone_flags(s32 x, s32 z);
extern Vehicle *object_scene_vehicle[];
static s32 block_hit_tris(TmdTri *prims, s32 verts, s32 normals, Vec3 *offset, s32 count, s32 x, s32 z, s32 height_out);
static s32 block_hit_quads(TmdTri *prims, s32 verts, s32 normals, Vec3 *offset, s32 count, s32 x, s32 z, s32 height_out);
extern SceneRequestBuilding main_scene_request;
extern char block_str_err_alloc_buf[];
s32 __nedf2(double arg0, double arg1);
static s16 block_point_in_poly(PolyVert *verts, s32 count, s32 x, s32 z);
static s32 block_poly_height(PolyVert *verts, SVector *normal, s32 count, s32 x, s32 z);
s32 abs(s32 x);
extern char block_str_err_city_mode[];
extern char block_str_err_building_mode[];
s16 kaj_map_load_city_dir(void);
s16 kaj_map_city_ready(void);
s16 kaj_map_load_place_dir(void);
typedef struct {
    s32 slot;
    s32 offset;
} BlockDataEntry;
typedef struct {
    s32 room_x_cell_z;
    s32 room_y_cell_x;
    s32 room_z_cell_depth;
    union {
        struct {
            s32 width;
            s32 entry_count;
        } cell;
        struct {
            u16 size_x;
            u16 size_y;
            u16 size_z;
            s16 entry_count;
        } room;
    } dims;
    BlockDataEntry entries[1];
} BlockDataHeader;
extern CarState vehicle_car_state;
static s32 block_test_player_inside(Player *player, u16 mode, Block *block, s32 *lo, s32 *hi);
s32 main_angle_to_dir8(s16 angle);
extern ScreenLight roadmap_screen_light;

void block_setup(Block *block, u16 mode) {
    s32 offsets[5];
    Player *player;
    BlockDataHeader *hdr;
    ArenaHeader *src;
    Arena **arena;
    s32 i;

    player = player_status_player[0];
    memset(offsets, 0, 0x14);
    if (mode == 2) {
        hdr = block->data;
        block->pos_x = hdr->room_y_cell_x * 100;
        block->pos_y = 0;
        block->pos_z = hdr->room_x_cell_z * 100;
        block->size_x = hdr->dims.cell.width * 100;
        block->size_y = 0;
        block->size_z = hdr->room_z_cell_depth * 100;
        block->far = 1;
        for (i = 0; i < hdr->dims.cell.entry_count; i++) {
            offsets[hdr->entries[i].slot] = hdr->entries[i].offset;
        }
    } else {
        hdr = block->data;
        block->visible = 1;
        block->player_inside = 1;
        block->pos_x = hdr->room_x_cell_z;
        block->pos_y = hdr->room_y_cell_x;
        block->pos_z = hdr->room_z_cell_depth;
        block->size_x = hdr->dims.room.size_x;
        block->size_y = hdr->dims.room.size_y;
        block->size_z = hdr->dims.room.size_z;
        block->far = 0;
        for (i = 0; i < hdr->dims.room.entry_count; i++) {
            offsets[hdr->entries[i].slot] = hdr->entries[i].offset;
        }
    }
    block->model_flags = 0;
    if (offsets[0] != 0) {
        kaj_tmd_load(&block->floor_model, (u8 *)block->data + offsets[0], &block->coord_flg);
        block->model_flags |= 1;
    }
    if (offsets[1] != 0) {
        kaj_tmd_load(&block->model1, (u8 *)block->data + offsets[1], &block->coord_flg);
        block->model_flags |= 2;
    }
    if (offsets[2] != 0) {
        kaj_tmd_load(&block->model2, (u8 *)block->data + offsets[2], &block->coord_flg);
        block->model_flags |= 4;
    }
    if (offsets[3] != 0) {
        kaj_tmd_load(&block->model3, (u8 *)block->data + offsets[3], &block->coord_flg);
        block->model_flags |= 8;
    }
    if (offsets[4] != 0) {
        arena = &block->arena;
        src = (ArenaHeader *)((u8 *)block->data + offsets[4]);
        if (*arena == NULL) {
            *arena = kaj_malloc(0x10);
            if (*arena == NULL) {
                kaj_abend(3, "Error Allocating Arena Buffer", block_str_file, 0x49);
            }
        } else {
            memset(*arena, 0, 0x10);
        }
        (*arena)->origin_x = src->origin_x;
        (*arena)->origin_z = src->origin_z;
        (*arena)->width = src->width;
        (*arena)->depth = src->depth;
        (*arena)->data = src + 1;
        (*arena)->header = src;
        block->model_flags |= 0x10;
    }
    GsInitCoordinate2(NULL, &block->coord_flg);
    block->coord_tx = block->pos_x - player->cell_x * 12500;
    block->coord_ty = block->pos_y + player->cell_y * 32000;
    block->coord_tz = block->pos_z - player->cell_z * 12500;
    block->coord_flg = 0;
    block->active = 1;
}

void block_draw_all(ViewBuffer *view, u16 mode) {
    s32 ls[8];
    BlockList *list = block_list;
    Player *player = player_status_player[0];
    ScreenLight *light = &roadmap_screen_light;
    Block *block;

    if (list->count == 0) {
        return;
    }
    list->cursor = list->head;
    while (1) {
        block = list->cursor->data;
        if (block != NULL && block->active != 0 && block->visible != 0) {
            light->clip_mode = block->far;
            GsGetLs(&block->coord_flg, ls);
            GsSetLsMatrix(ls);
            if (block->model_flags & 2) {
                if (mode == 2 && player->vehicle_mode != 3) {
                    light->bg_color_pending = block->player_inside;
                }
                light->ot_bias = 0x100;
                SetSpadStack(0x1F8003FC);
                GsSortObject4J(block->model1, &view->ot_length, 1, (void *)0x1F800000);
                ResetSpadStack();
            }
            light->bg_color_pending = 0;
            if (block->model_flags & 4) {
                light->ot_bias = 0xC0;
                SetSpadStack(0x1F8003FC);
                GsSortObject4J(block->model2, &view->ot_length, 1, (void *)0x1F800000);
                ResetSpadStack();
            }
            if (block->model_flags & 8) {
                light->ot_bias = 0x80;
                SetSpadStack(0x1F8003FC);
                GsSortObject4J(block->model3, &view->ot_length, 1, (void *)0x1F800000);
                ResetSpadStack();
            }
        }
        if (kaj_ll_at_tail(list) != 0) {
            return;
        }
        list->cursor = list->cursor->next;
    }
}

static s32 block_test_player_inside(Player *player, u16 mode, Block *block, s32 *lo, s32 *hi) {
    s32 a;
    s32 unused[2];
    s32 b;
    s32 dist;
    s32 f;
    s32 x;
    s32 z;
    s32 w;
    s32 h;
    Arena *arena;
    s32 *lo_p = lo;

    lo_p[0] = block->coord_tx - player->pos_x;
    hi[0] = block->size_x + lo_p[0];
    lo_p[1] = player->pos_y - player->eye_height - block->coord_ty;
    hi[1] = block->size_y + lo_p[1];
    lo_p[2] = block->coord_tz - player->pos_z;
    hi[2] = block->size_z + lo_p[2];
    if (mode == 2) {
        a = hi[0] >> 1;
        b = hi[2] >> 1;
        dist = SquareRoot0(a * a + b * b);
        block->far = 1;
        if (block->size_x < 5001 && block->size_z < 5001) {
            f = dist < 3537;
        } else {
            f = dist < 7073;
        }
        if (f) {
            block->far = 0;
        }
    } else {
        block->far = 0;
    }
    if (block->model_flags & 0x10) {
        arena = block->arena;
        x = player->pos_x + player->cell_x * 12500 - block->pos_x;
        z = player->pos_z + player->cell_z * 12500 - block->pos_z;
        h = x >> 8;
        w = arena->origin_x;
        x = (x & 0xFF) ? (f = w + 1, h + f) : h + w;
        h = z >> 8;
        w = arena->origin_z;
        z = (z & 0xFF) ? (f = w + 1, h + f) : h + w;
        if (x >= 0 && x < arena->width && z >= 0 && z < arena->depth) {
            block->in_arena = 1;
        }
    }
    if (lo_p[0] > 0 || hi[0] <= 0 || lo_p[2] > 0 || hi[2] <= 0) {
        return 0;
    }
    if (mode == 1 && (s16)player->climbing != 0 && (lo_p[1] > 0 || hi[1] < 0)) {
        return 0;
    }
    return 1;
}

INCLUDE_RODATA("asm/nonmatchings/game/block", block_str_err_alloc_ptr);

INCLUDE_RODATA("asm/nonmatchings/game/block", block_str_err_alloc_buf);

INCLUDE_RODATA("asm/nonmatchings/game/block", block_str_err_city_mode);

INCLUDE_RODATA("asm/nonmatchings/game/block", block_str_err_building_mode);

static inline s32 block_car_corner_inside(Player *player, s32 *lo, s32 *hi) {
    CarState *car = &vehicle_car_state;
    s32 pos[4];
    s32 flag;
    s32 i;
    GsSetLsMatrix(object_scene_vehicle[0]->coord.coord_m);
    for (i = 0; i < 4; i++) {
        RotTrans(&car->corners[i], pos, &flag);
        pos[0] -= player->pos_x;
        pos[2] -= player->pos_z;
        if (pos[0] >= lo[0] && pos[0] < hi[0] && pos[2] >= lo[2] && pos[2] < hi[2]) {
            return 1;
        }
    }
    return 0;
}

static inline s16 block_in_view_dir(s32 dir, s32 *lo, s32 *hi) {
    switch (dir) {
    case 2:
        if (hi[2] >= 0) {
            break;
        }
        return 0;
    case 0:
        if (hi[0] >= 0) {
            break;
        }
        return 0;
    case 6:
        if (lo[2] > 0) {
            return 0;
        }
        break;
    case 4:
        if (lo[0] > 0) {
            return 0;
        }
        break;
    case 1:
        if (lo[0] >= 0 || lo[2] >= 0) {
            break;
        }
        return 0;
    case 3:
        if (hi[0] <= 0 || lo[2] >= 0) {
            break;
        }
        return 0;
    case 5:
        if (hi[0] <= 0 || hi[2] <= 0) {
            break;
        }
        return 0;
    case 7:
        if (lo[0] >= 0 || hi[2] <= 0) {
            break;
        }
        return 0;
    }
    return 1;
}

void block_update_visibility(u16 mode) {
    BlockList *list = block_list;
    Player *player = player_status_player[0];
    Block *block;
    s32 lo[4];
    s32 hi[4];

    if (list->count == 0) {
        return;
    }
    list->cursor = list->head;
    while (1) {
        block = list->cursor->data;
        if (block != NULL && block->active != 0) {
            block->in_arena = 0;
            block->player_inside = block_test_player_inside(player, mode, block, lo, hi);
            if (block->player_inside != 0) {
                block->visible = 1;
            } else if (mode == 2) {
                if (player->vehicle_mode == 1 && block_car_corner_inside(player, lo, hi) && block->player_inside == 0) {
                    block->player_inside = 1;
                    block->visible = 1;
                } else {
                    block->visible = block_in_view_dir((s16)main_angle_to_dir8(player->yaw), lo, hi);
                }
            }
        }
        if (kaj_ll_at_tail(list) != 0) {
            return;
        }
        list->cursor = list->cursor->next;
    }
}

void block_create_all(void) {
    s32 i;

    for (i = 0; i < 12; i++) {
        block_slots[i] = kaj_malloc(0x90);
        if (block_slots[i] == NULL) {
            kaj_abend(3, block_str_err_alloc_ptr, block_str_file, 0x5D);
        }
        block_slots[i]->active = 0;
        block_slots[i]->owns_data = 0;
        block_slots[i]->visible = 0;
        block_slots[i]->player_inside = 0;
        block_slots[i]->in_arena = 0;
        block_slots[i]->far = 1;
        block_slots[i]->model_flags = 0;
        block_slots[i]->model3 = NULL;
        block_slots[i]->model2 = NULL;
        block_slots[i]->model1 = NULL;
        block_slots[i]->floor_model = NULL;
        block_slots[i]->arena = NULL;
        block_slots[i]->data = NULL;
        block_slots[i]->active = 0;
        block_slots[i]->model_flags = 0;
        {
            Block *block = block_slots[i];

            if (block_list->count == 0) {
                kaj_ll_insert_before(block_list, (s32)block);
            } else {
                block_list->cursor = block_list->tail;
                kaj_ll_insert_after(block_list, (s32)block);
            }
        }
    }
}

static void block_load_all(u16 mode) {
    s32 res_ids[12];
    s16 count;
    s32 i;
    Block *block;
    s32 fresh;
    s32 type;
    void **res;

    block_reloaded = 1;
    count = 12;
    if (mode == 2) {
        kaj_map_cell_slots(&count, res_ids);
    } else {
        kaj_map_room_slots(&count, res_ids);
    }
    for (i = 0; i < 12; i++) {
        block = block_slots[i];
        block->active = 0;
        block->data = NULL;
        if (i < count) {
            fresh = (s16)kaj_cdmgr_is_fresh(res_ids[i]);
            type = kaj_cdmgr_get_type(res_ids[i]);
            res = kaj_cdmgr_get(res_ids[i]);
            if (type == 5) {
                if (res != NULL && fresh != 0) {
                    mod_create(*res);
                    kaj_cdmgr_mark_used(res_ids[i]);
                    continue;
                }
            } else if (type == 6) {
                if (res != NULL && fresh != 0) {
                    kaj_tim_upload_hdr(*res);
                    kaj_cdmgr_mark_used(res_ids[i]);
                    kaj_map_room_release(res_ids[i]);
                    continue;
                }
            } else if (res != NULL) {
                block->data = *res;
                block_setup(block, mode);
            }
        }
    }
    if (mode == 1) {
        actor_update_blocks();
    }
}

static void block_set_zone_flags(s32 x, s32 z) {
    GameVars *vars = &action_vars;

    vars->flame_small_on = 0;
    vars->flame_large_on = 0;
    vars->clut_cycle_on = 0;
    if (x >= 0x3CF && x < 0x433 && z > 0x8B0 && z < 0xA0F) {
        vars->flame_small_on = 1;
        vars->flame_large_on = 1;
        vars->clut_cycle_on = 1;
        return;
    }
    if ((x >= 0x3CF && x < 0x4C9 && z >= -0x19 && z < 0x8B1) ||
        (x >= 0x36B && x < 0x3CF && z >= 0x23F && z < 0x307) ||
        (x >= 0x433 && x < 0x497 && z >= -0x1A9 && z < -0xE1) ||
        (x >= 0x81B && x < 0x9AB && z >= 0x1A9 && z < 0x401) ||
        (x >= -0x4FB && x < -0x401 && z >= 0x5F5 && z < 0x9DD) ||
        (x >= -0x591 && x < -0x4C9 && z >= -0x4B && z < 0x1A9) ||
        (x >= -0x591 && x < -0x497 && z >= -0x4C9 && z < -0x23F) ||
        (x >= 0x2D5 && x < 0x433 && z < -0x4C9) ||
        (x >= 0x2D5 && x < 0x433 && z < -0x23F) ||
        z < -0x4C9) {
        vars->clut_cycle_on = 1;
    }
}

void block_set_mode(u16 mode) {
    s32 pos[4];
    SceneRequestBuilding *req = &main_scene_request;
    Player *player = player_status_player[0];
    GameVars *vars;

    if (mode == 2) {
        if (kaj_map_open_city() != 0) {
            kaj_abend(4, block_str_err_city_mode, block_str_file, 0x2EC);
        }
        while (kaj_map_load_city_dir() == 0) {
            kaj_cdmgr_poll();
        }
        while (kaj_map_city_ready() == 0) {
            kaj_map_update_city(player->world_z, player->world_x);
            if (kaj_cdmgr_poll() != 0) {
                kaj_map_set_cell_ready();
            }
        }
        block_set_zone_flags(player->world_x, player->world_z);
    } else {
        if (kaj_map_open_place(req->place_letter, req->name) != 0) {
            kaj_abend(4, block_str_err_building_mode, block_str_file, 0x2F8);
        }
        while (kaj_map_load_place_dir() == 0) {
            kaj_cdmgr_poll();
        }
        block_building_id = req->place_entry;
        kaj_map_get_entry(block_building_id, pos, &block_area_kind);
        vars = &action_vars;
        vars->flame_small_on = 0;
        vars->flame_large_on = 0;
        switch (block_area_flames[0]) {
        case 1:
            vars->flame_small_on = 1;
            break;
        case 2:
            vars->flame_large_on = 1;
            break;
        case 3:
            vars->flame_small_on = 1;
            vars->flame_large_on = 1;
            break;
        }
        player->pos_x = pos[0];
        player->pos_y = pos[1];
        player->pos_z = pos[2];
        player_place_for_scene(1);
        while (kaj_map_place_ready() == 0) {
            kaj_map_update_place(block_building_id, &block_area_kind);
            if (kaj_cdmgr_poll() != 0) {
                kaj_map_set_room_ready();
            }
        }
    }
    block_load_all(mode);
    door_refresh_all();
    thing_refresh_all();
    block_reloaded = 0;
}

void block_stream_update(u16 mode) {
    s32 res_ids[12];
    s16 count;
    Player *player = player_status_player[0];
    s32 status;
    s32 i;
    Block *block;
    void **res;

    block_reloaded = 0;
    if (mode == 2) {
        status = kaj_map_update_city(player->world_z, player->world_x);
        block_set_zone_flags(player->world_x, player->world_z);
    } else {
        status = kaj_map_update_place(block_building_id, &block_area_kind);
    }
    if (status == 3) {
        block_reloaded = 1;
        count = 12;
        if (mode == 2) {
            kaj_map_cell_loaded_slots(&count, res_ids);
        } else {
            kaj_map_room_loaded_slots(&count, res_ids);
        }
        for (i = 0; i < 12; i++) {
            block = block_slots[i];
            block->active = 0;
            block->data = NULL;
            if (i < count) {
                s32 type = kaj_cdmgr_get_type(res_ids[i]);
                if (type != 5 && type != 6) {
                    res = kaj_cdmgr_get(res_ids[i]);
                    if (res != NULL) {
                        block->data = *res;
                        block_setup(block, mode);
                    }
                }
            }
        }
        if (mode == 1) {
            actor_update_blocks();
        }
        kaj_cdmgr_poll();
    } else if (status == 1 || kaj_cdmgr_poll() != 0) {
        if (mode == 2) {
            kaj_map_set_cell_ready();
        } else {
            kaj_map_set_room_ready();
        }
        block_load_all(mode);
    }
}

static s16 block_point_in_poly(PolyVert *verts, s32 count, s32 x, s32 z) {
    double cross_x[2];
    double x0;
    double z0;
    double x1;
    double z1;
    double px;
    double pz;
    double t;
    s32 i;
    s32 j;
    s32 crossings;

    px = x;
    pz = z;
    crossings = 0;
    for (i = 0; i < count; i++) {
        j = (i + 1) % count;
        x0 = verts[i].x;
        z0 = verts[i].z;
        x1 = verts[j].x;
        z1 = verts[j].z;
        if (__nedf2(z0, z1)) {
            t = (pz - z0) / (z1 - z0);
            if (!(t < 0.0) && !(t > 1.0)) {
                cross_x[crossings] = (x1 - x0) * t + x0;
                if (crossings != 1 || __nedf2(cross_x[0], cross_x[1])) {
                    if (px < cross_x[crossings]) {
                        crossings++;
                    }
                    if (crossings == 2) {
                        break;
                    }
                }
            }
        }
    }
    return crossings % 2;
}

static s32 block_poly_height(PolyVert *verts, SVector *normal, s32 count, s32 x, s32 z) {
    s32 maxx;
    s32 minx;
    s32 maxz;
    s32 minz;

    if (count == 4) {
        if (verts[0].x > verts[1].x) {
            maxx = verts[0].x;
            minx = verts[1].x;
        } else {
            minx = verts[0].x;
            maxx = verts[1].x;
        }
        if (maxx < verts[2].x) {
            maxx = verts[2].x;
        } else if (verts[2].x < minx) {
            minx = verts[2].x;
        }
        if (maxx < verts[3].x) {
            maxx = verts[3].x;
        } else if (verts[3].x < minx) {
            minx = verts[3].x;
        }
        if (verts[0].z > verts[1].z) {
            maxz = verts[0].z;
            minz = verts[1].z;
        } else {
            minz = verts[0].z;
            maxz = verts[1].z;
        }
        if (maxz < verts[2].z) {
            maxz = verts[2].z;
        } else if (verts[2].z < minz) {
            minz = verts[2].z;
        }
        if (maxz < verts[3].z) {
            maxz = verts[3].z;
        } else if (verts[3].z < minz) {
            minz = verts[3].z;
        }
    } else {
        if (verts[0].x > verts[1].x) {
            maxx = verts[0].x;
            minx = verts[1].x;
        } else {
            minx = verts[0].x;
            maxx = verts[1].x;
        }
        if (maxx < verts[2].x) {
            maxx = verts[2].x;
        } else if (verts[2].x < minx) {
            minx = verts[2].x;
        }
        if (verts[0].z > verts[1].z) {
            maxz = verts[0].z;
            minz = verts[1].z;
        } else {
            minz = verts[0].z;
            maxz = verts[1].z;
        }
        if (maxz < verts[2].z) {
            maxz = verts[2].z;
        } else if (verts[2].z < minz) {
            minz = verts[2].z;
        }
    }
    if (x < minx || maxx < x || z < minz || maxz < z) {
        return 99999999;
    }
    if (block_point_in_poly(verts, count, x, z) == 0) {
        return 99999999;
    }
    if (normal->vy == 0) {
        return 99999999;
    }
    return (verts[2].x * normal->vx + verts[2].y * normal->vy + verts[2].z * normal->vz
            - (normal->vx * x + normal->vz * z)) / normal->vy;
}

static s32 block_hit_tris(TmdTri *prims, s32 verts, s32 normals, Vec3 *offset, s32 count, s32 x, s32 z, s32 height_out) {
    PolyVert poly[3];
    s32 i;
    TmdTri *prim;
    s32 height;

    prim = prims;
    for (i = 0; i < count; i++, prim++) {
        poly[0].x = ((SVector *)verts)[prim->vert0].vx + offset->x;
        poly[0].y = ((SVector *)verts)[prim->vert0].vy + offset->y;
        poly[0].z = ((SVector *)verts)[prim->vert0].vz + offset->z;
        poly[1].x = ((SVector *)verts)[prim->vert1].vx + offset->x;
        poly[1].y = ((SVector *)verts)[prim->vert1].vy + offset->y;
        poly[1].z = ((SVector *)verts)[prim->vert1].vz + offset->z;
        poly[2].x = ((SVector *)verts)[prim->vert2].vx + offset->x;
        poly[2].y = ((SVector *)verts)[prim->vert2].vy + offset->y;
        poly[2].z = ((SVector *)verts)[prim->vert2].vz + offset->z;
        height = block_poly_height(poly, (SVector *)normals + prim->normal, 3, x, z);
        *(s32 *)height_out = height;
        if (height != 99999999) {
            return (prim->code_r << 16) | (prim->code_g << 8) | prim->code_b;
        }
    }
    return 0;
}

static s32 block_hit_quads(TmdTri *prims, s32 verts, s32 normals, Vec3 *offset, s32 count, s32 x, s32 z, s32 height_out) {
    PolyVert poly[4];
    struct {
        u16 run_count;
        u8 unk2;
        u8 mode;
        u8 code_r;
        u8 code_g;
        u8 code_b;
        u8 pad7[0x1];
        u16 normal;
        u16 vert0;
        u16 vert1;
        u16 vert2;
        u16 vert3;
        u8 pad12[0x2];
    } *prim;
    s32 i;
    s32 height;
    s32 code;
    s32 minx;
    s32 maxx;
    s32 minz;
    s32 maxz;
    Player *player;
    PolyVert *centre;

    prim = (void *)prims;
    for (i = 0; i < count; i++, prim++) {
        poly[0].x = ((SVector *)verts)[prim->vert0].vx + offset->x;
        poly[0].y = ((SVector *)verts)[prim->vert0].vy + offset->y;
        poly[0].z = ((SVector *)verts)[prim->vert0].vz + offset->z;
        poly[1].x = ((SVector *)verts)[prim->vert1].vx + offset->x;
        poly[1].y = ((SVector *)verts)[prim->vert1].vy + offset->y;
        poly[1].z = ((SVector *)verts)[prim->vert1].vz + offset->z;
        poly[3].x = ((SVector *)verts)[prim->vert2].vx + offset->x;
        poly[3].y = ((SVector *)verts)[prim->vert2].vy + offset->y;
        poly[3].z = ((SVector *)verts)[prim->vert2].vz + offset->z;
        poly[2].x = ((SVector *)verts)[prim->vert3].vx + offset->x;
        poly[2].y = ((SVector *)verts)[prim->vert3].vy + offset->y;
        poly[2].z = ((SVector *)verts)[prim->vert3].vz + offset->z;
        height = block_poly_height(poly, (SVector *)normals + prim->normal, 4, x, z);
        *(s32 *)height_out = height;
        if (height != 99999999) {
            code = (prim->code_r << 16) | (prim->code_g << 8) | prim->code_b;
            if (prim->code_r == 0xFF) {
                player = player_status_player[0];
                centre = (PolyVert *)&player->exit; /* this unit reads +0x18 as two quads */
                if (poly[0].x > poly[1].x) {
                    maxx = poly[0].x;
                    minx = poly[1].x;
                } else {
                    minx = poly[0].x;
                    maxx = poly[1].x;
                }
                if (maxx < poly[2].x) {
                    maxx = poly[2].x;
                } else if (poly[2].x < minx) {
                    minx = poly[2].x;
                }
                if (maxx < poly[3].x) {
                    maxx = poly[3].x;
                } else if (poly[3].x < minx) {
                    minx = poly[3].x;
                }
                if (poly[0].z > poly[1].z) {
                    maxz = poly[0].z;
                    minz = poly[1].z;
                } else {
                    minz = poly[0].z;
                    maxz = poly[1].z;
                }
                if (maxz < poly[2].z) {
                    maxz = poly[2].z;
                } else if (poly[2].z < minz) {
                    minz = poly[2].z;
                }
                if (maxz < poly[3].z) {
                    maxz = poly[3].z;
                } else if (poly[3].z < minz) {
                    minz = poly[3].z;
                }
                centre[1].x = player->cell_x * 12500 + ((minx + maxx) >> 1);
                centre[1].z = player->cell_z * 12500 + ((minz + maxz) >> 1);
            }
            return code;
        }
    }
    return 0;
}

s16 block_point_on_model(void *obj, s32 x, s32 y, s32 z, u16 mode) {
    PolyVert poly[4];
    s32 flag;
    GsDobj2 *model;
    struct {
        u16 run_count;
        u8 unk2;
        u8 mode;
        u8 code_r;
        u8 code_g;
        u8 code_b;
        u8 pad7[0x1];
        u16 normal;
        u16 vert0;
        u16 vert1;
        u16 vert2;
        u16 vert3;
        u8 pad12[0x2];
    } *prim;
    Player *player;
    SVector *verts;
    SVector *normals;
    s32 left;
    s32 cnt;
    s32 i;
    s32 min;
    s32 max;

    model = obj;
    prim = (void *)model->tmd->primitive_top;
    left = model->tmd->n_primitive;
    player = player_status_player[0];
    verts = (SVector *)model->tmd->vert_top;
    normals = (SVector *)model->tmd->normal_top;
    while (left != 0) {
        cnt = prim->run_count;
        if ((prim->mode & 0xFD) == 0x20) {
            for (i = 0; i < cnt; prim = (void *)((TmdTri *)prim + 1), i++) {
                RotTrans(&verts[prim->vert0], &poly[0].x, &flag);
                if (flag < 0) {
                    return 0;
                }
                RotTrans(&verts[prim->vert1], &poly[1].x, &flag);
                if (flag < 0) {
                    return 0;
                }
                RotTrans(&verts[prim->vert2], &poly[2].x, &flag);
                if (flag < 0) {
                    return 0;
                }
                if (block_poly_height(poly, &normals[prim->normal], 3, x, z) != 99999999) {
                    if (mode != 1) {
                        return 1;
                    }
                    if (poly[0].y > poly[1].y) {
                        max = poly[0].y;
                        min = poly[1].y;
                    } else {
                        min = poly[0].y;
                        max = poly[1].y;
                    }
                    if (max < poly[2].y) {
                        max = poly[2].y;
                    } else if (poly[2].y < min) {
                        min = poly[2].y;
                    }
                    if (min == max) {
                        if (y >= max + player->eye_height && y <= max - player->eye_height) {
                            return 1;
                        }
                    } else if (y >= min && y <= max) {
                        return 1;
                    }
                }
            }
            left -= cnt;
        } else if ((prim->mode & 0xFD) == 0x28) {
            for (i = 0; i < cnt; prim++, i++) {
                RotTrans(&verts[prim->vert0], &poly[0].x, &flag);
                if (flag < 0) {
                    return 0;
                }
                RotTrans(&verts[prim->vert1], &poly[1].x, &flag);
                if (flag < 0) {
                    return 0;
                }
                RotTrans(&verts[prim->vert2], &poly[3].x, &flag);
                if (flag < 0) {
                    return 0;
                }
                RotTrans(&verts[prim->vert3], &poly[2].x, &flag);
                if (flag < 0) {
                    return 0;
                }
                if (block_poly_height(poly, &normals[prim->normal], 4, x, z) != 99999999) {
                    if (mode != 1) {
                        return 1;
                    }
                    if (poly[0].y > poly[1].y) {
                        max = poly[0].y;
                        min = poly[1].y;
                    } else {
                        min = poly[0].y;
                        max = poly[1].y;
                    }
                    if (max < poly[2].y) {
                        max = poly[2].y;
                    } else if (poly[2].y < min) {
                        min = poly[2].y;
                    }
                    if (max < poly[3].y) {
                        max = poly[3].y;
                    } else if (poly[3].y < min) {
                        min = poly[3].y;
                    }
                    if (min == max) {
                        if (y >= max + player->eye_height && y <= max - player->eye_height) {
                            return 1;
                        }
                    } else if (y >= min && y <= max) {
                        return 1;
                    }
                }
            }
            left -= cnt;
        } else {
            return 0;
        }
    }
    return 0;
}

s32 block_vehicle_surface(s32 x, s32 z, s32 height_out) {
    Vec3 offset;
    TmdTri *prim;
    s32 left;
    s32 verts;
    s32 normals;
    s32 cnt;
    s32 code;
    s32 hit;
    GsDobj2 *model;

    model = object_scene_vehicle[0]->model1;
    offset.x = model->coord2->coord_tx;
    offset.y = model->coord2->coord_ty;
    offset.z = model->coord2->coord_tz;
    prim = model->tmd->primitive_top;
    left = model->tmd->n_primitive;
    verts = model->tmd->vert_top;
    normals = model->tmd->normal_top;
    while (left != 0) {
        cnt = prim->run_count;
        switch (prim->mode & 0xFD) {
        case 0x20:
            hit = block_hit_tris(prim, verts, normals, &offset, cnt, x, z, height_out);
            if (hit != 0) {
                code = hit;
                goto end;
            }
            left -= cnt;
            prim = (TmdTri *)((u8 *)prim + cnt * 0x10);
            break;
        case 0x28:
            hit = block_hit_quads(prim, verts, normals, &offset, cnt, x, z, height_out);
            if (hit != 0) {
                code = hit;
                goto end;
            }
            left -= cnt;
            prim = (TmdTri *)((u8 *)prim + cnt * 0x14);
            break;
        default:
            code = 0;
            goto end;
        }
    }
    code = 0;
end:
    if (code != 0) {
        return code;
    }
    return 0;
}

s32 block_find_surface(s32 x, s32 z, s32 *height_out, s16 all) {
    BlockList *list = block_list;
    Vec3 offset;
    TmdTri *prim;
    s32 left;
    s32 verts;
    s32 normals;
    s32 cnt;
    s32 code;
    s32 hit;
    s32 all_blocks;
    GsDobj2 *model;

    if (list->count == 0) {
        return 0;
    }
    *height_out = 0;
    all_blocks = all;
    list->cursor = list->head;
    while (1) {
        Block *block = list->cursor->data;
        if (block != NULL && block->active != 0 && (block->model_flags & 1) && (all_blocks != 0 || block->player_inside != 0)) {
            model = block->floor_model;
            offset.x = model->coord2->coord_tx;
            offset.y = model->coord2->coord_ty;
            offset.z = model->coord2->coord_tz;
            prim = model->tmd->primitive_top;
            left = model->tmd->n_primitive;
            verts = model->tmd->vert_top;
            normals = model->tmd->normal_top;
            while (left != 0) {
                cnt = prim->run_count;
                switch (prim->mode & 0xFD) {
                case 0x20:
                    hit = block_hit_tris(prim, verts, normals, &offset, cnt, x, z, (s32)height_out);
                    if (hit != 0) {
                        code = hit;
                        goto found;
                    }
                    left -= cnt;
                    prim = (TmdTri *)((u8 *)prim + cnt * 0x10);
                    break;
                case 0x28:
                    hit = block_hit_quads(prim, verts, normals, &offset, cnt, x, z, (s32)height_out);
                    if (hit != 0) {
                        code = hit;
                        goto found;
                    }
                    left -= cnt;
                    prim = (TmdTri *)((u8 *)prim + cnt * 0x14);
                    break;
                default:
                    code = 0;
                    goto found;
                }
            }
            code = 0;
        found:
            if (code != 0) {
                return code;
            }
        }
        if (kaj_ll_at_tail(list) != 0) {
            return 0;
        }
        list->cursor = list->cursor->next;
    }
}

s32 block_find_surface_nearest(s32 x, s32 y, s32 z, s32 *height_out) {
    BlockList *list = block_list;
    Vec3 hits[12];
    Vec3 offset;
    s32 height;
    s32 *height_p;
    TmdTri *prim;
    s32 left;
    s32 verts;
    s32 normals;
    s32 cnt;
    s32 code;
    s32 hit;
    s32 n_hits;
    s32 i;
    s32 best_dy;
    GsDobj2 *model;

    if (list->count == 0) {
        return 0;
    }
    *height_out = 0;
    n_hits = 0;
    list->cursor = list->head;
    while (1) {
        Block *block = list->cursor->data;
        if (block != NULL && block->active != 0 && block->player_inside != 0 && (block->model_flags & 1)) {
            model = block->floor_model;
            offset.x = model->coord2->coord_tx;
            offset.y = model->coord2->coord_ty;
            offset.z = model->coord2->coord_tz;
            prim = model->tmd->primitive_top;
            left = model->tmd->n_primitive;
            verts = model->tmd->vert_top;
            normals = model->tmd->normal_top;
            height_p = &height;
            while (left != 0) {
                cnt = prim->run_count;
                switch (prim->mode & 0xFD) {
                case 0x20:
                    hit = block_hit_tris(prim, verts, normals, &offset, cnt, x, z, (s32)height_p);
                    if (hit != 0) {
                        code = hit;
                        goto found;
                    }
                    left -= cnt;
                    prim = (TmdTri *)((u8 *)prim + cnt * 0x10);
                    break;
                case 0x28:
                    hit = block_hit_quads(prim, verts, normals, &offset, cnt, x, z, (s32)height_p);
                    if (hit != 0) {
                        code = hit;
                        goto found;
                    }
                    left -= cnt;
                    prim = (TmdTri *)((u8 *)prim + cnt * 0x14);
                    break;
                default:
                    code = 0;
                    goto found;
                }
            }
            code = 0;
        found:
            if (code != 0) {
                hits[n_hits].x = code;
                hits[n_hits].y = height;
                hits[n_hits].z = abs(y - height);
                n_hits++;
            }
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->cursor = list->cursor->next;
    }
    if (n_hits == 0) {
        return 0;
    }
    if (n_hits == 1) {
        *height_out = hits[0].y;
        return hits[0].x;
    }
    if (n_hits != 0) {
        best_dy = 1600;
        for (i = 0; i < n_hits; i++) {
            if (hits[i].z < best_dy) {
                code = hits[i].x;
                *height_out = hits[i].y;
                best_dy = hits[i].z;
            }
        }
        return code;
    }
    return 0;
}

static inline s32 block_floor_hit(GsDobj2 *model, Vec3 *offset, s32 x, s32 z, s32 height_out) {
    TmdTri *prim;
    s32 left;
    s32 verts;
    s32 normals;
    s32 cnt;
    s32 hit;
    offset->x = model->coord2->coord_tx;
    offset->y = model->coord2->coord_ty;
    offset->z = model->coord2->coord_tz;
    prim = model->tmd->primitive_top;
    left = model->tmd->n_primitive;
    verts = model->tmd->vert_top;
    normals = model->tmd->normal_top;
    while (left != 0) {
        cnt = prim->run_count;
        switch (prim->mode & 0xFD) {
        case 0x20:
            hit = block_hit_tris(prim, verts, normals, offset, cnt, x, z, height_out);
            if (hit != 0) {
                return hit;
            }
            left -= cnt;
            prim = (TmdTri *)((u8 *)prim + cnt * 0x10);
            break;
        case 0x28:
            hit = block_hit_quads(prim, verts, normals, offset, cnt, x, z, height_out);
            if (hit != 0) {
                return hit;
            }
            left -= cnt;
            prim = (TmdTri *)((u8 *)prim + cnt * 0x14);
            break;
        default:
            return 0;
        }
    }
    return 0;
}

s32 block_fit_ground_tilt(s32 *height_out, s16 all) {
    PolyVert corners[4];
    PolyVert centre;
    SVector origin;
    s32 codes[5];
    Vec3 offset;
    s32 flag;
    BlockList *list = block_list;
    Vehicle *m = object_scene_vehicle[0];
    CarState *car = &vehicle_car_state;
    GsDobj2 *model;
    Block *block;
    s32 i;
    s16 c1;
    s16 c2;
    s32 dx1;
    s32 dx2;
    s32 dz1;
    s32 dz2;
    s32 sn;
    s32 cs;
    s32 tilt_x;
    s32 tilt_z;

    if (list->count == 0) {
        return 0;
    }
    GsSetLsMatrix(&m->coord.coord_m);
    for (i = 0; i < 4; i++) {
        codes[i] = 0;
        RotTrans(&car->corners[i], &corners[i].x, &flag);
        if (flag >= 0) {
            list->cursor = list->head;
            while (1) {
                block = list->cursor->data;
                if (block != NULL && block->active != 0 && (model = block->floor_model) != NULL && (all != 0 || block->player_inside != 0)) {
                    codes[i] = block_floor_hit(model, &offset, corners[i].x, corners[i].z, (s32)&corners[i].y);
                    if (codes[i] != 0) {
                        break;
                    }
                }
                if (kaj_ll_at_tail(list) != 0) {
                    break;
                }
                list->cursor = list->cursor->next;
            }
        }
    }
    if (codes[0] == 0 || codes[1] == 0 || codes[2] == 0 || codes[3] == 0) {
        return 0;
    }
    c2 = c1 = 0;
    for (i = 0; i < 4; i++) {
        switch (codes[i]) {
        case 0xFFFF:
            c1++;
            break;
        case 0xFF00:
            if (car->slowed == 0) {
                car->slowed = 1;
            }
            break;
        default:
            continue;
        }
        c2++;
    }
    if (c1 == 4 && car->slowed != 0) {
        car->slowed = 0;
        car->throttle /= 4;
        car->brake /= 4;
    }
    if (c2 == 0) {
        return 0;
    }
    list->cursor = list->head;
    origin.vx = 0;
    origin.vy = 0;
    origin.vz = 0;
    RotTrans(&origin, &centre.x, &flag);
    if (flag < 0) {
        return 0;
    }
    while (1) {
        block = list->cursor->data;
        if (block != NULL && block->active != 0 && (model = block->floor_model) != NULL && (all != 0 || block->player_inside != 0)) {
            codes[4] = block_floor_hit(model, &offset, centre.x, centre.z, (s32)height_out);
            if (codes[4] != 0) {
                m->rot_z = 0;
                m->rot_x = 0;
                dx1 = corners[1].y - corners[0].y;
                dx2 = corners[3].y - corners[2].y;
                dz1 = corners[2].y - corners[0].y;
                dz2 = corners[3].y - corners[1].y;
                if (dx1 != 0 || dx2 != 0 || dz1 != 0 || dz2 != 0) {
                    sn = rsin((m->rot_y << 12) / 360);
                    cs = rcos((m->rot_y << 12) / 360);
                    tilt_x = 0;
                    tilt_z = 0;
                    if (dx1 != 0) {
                        tilt_x = ratan2(dx1, 300);
                    }
                    if (abs(dz1) >= abs(dz2)) {
                        if (dz1 != 0) {
                            tilt_z = ratan2(dz1, 508);
                        }
                    } else if (dz2 != 0) {
                        tilt_z = ratan2(dz2, 508);
                    }
                    {
                        s32 t0 = tilt_x * cs;
                        s32 t1 = tilt_x * sn;
                        s32 t2 = tilt_z * cs;
                        s32 t3 = tilt_z * sn;
                        m->rot_x = ((t1 + t2) >> 12) * 45 >> 9;
                        m->rot_z = ((t0 - t3) >> 12) * 45 >> 9;
                    }
                }
                *height_out += 370;
                return codes[4];
            }
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->cursor = list->cursor->next;
    }
    return 0;
}

void block_replace_arena(ArenaHeader *old_header, ArenaHeader *new_header) {
    BlockList *list = block_list;
    Arena *arena;

    if (list->count != 0) {
        list->cursor = list->head;
        while (1) {
            Block *block = list->cursor->data;
            if (block != NULL && (block->model_flags & 0x10)) {
                arena = block->arena;
                if (arena->header == old_header) {
                    break;
                }
            }
            if (kaj_ll_at_tail(list) != 0) {
                arena = NULL;
                break;
            }
            list->cursor = list->cursor->next;
        }
    } else {
        arena = NULL;
    }
    if (arena != NULL) {
        arena->header = new_header;
        arena->data = new_header + 1;
    }
}

void block_arena_init(Arena **arena_p, ArenaHeader *src) {
    if (*arena_p == NULL) {
        *arena_p = kaj_malloc(0x10);
        if (*arena_p == NULL) {
            kaj_abend(3, "Error Allocating Arena Buffer", block_str_file, 0x49);
        }
    } else {
        memset(*arena_p, 0, 0x10);
    }
    (*arena_p)->origin_x = src->origin_x;
    (*arena_p)->origin_z = src->origin_z;
    (*arena_p)->width = src->width;
    (*arena_p)->depth = src->depth;
    (*arena_p)->data = src + 1;
    (*arena_p)->header = src;
}

void block_create(Block **block_p, s32 size) {
    *block_p = kaj_malloc(0x90);
    if (*block_p == NULL) {
        kaj_abend(3, block_str_err_alloc_ptr, block_str_file, 0x5D);
    }
    (*block_p)->active = 0;
    (*block_p)->owns_data = 0;
    (*block_p)->visible = 0;
    (*block_p)->player_inside = 0;
    (*block_p)->in_arena = 0;
    (*block_p)->far = 1;
    (*block_p)->model_flags = 0;
    (*block_p)->model3 = NULL;
    (*block_p)->model2 = NULL;
    (*block_p)->model1 = NULL;
    (*block_p)->floor_model = NULL;
    (*block_p)->arena = NULL;
    (*block_p)->data = NULL;
    if (size != 0) {
        (*block_p)->data = kaj_malloc(size);
        if ((*block_p)->data == NULL) {
            kaj_abend(3, block_str_err_alloc_buf, block_str_file, 0x70);
        }
        (*block_p)->owns_data = 1;
    }
}

void block_free(Block *block) {
    if (block != NULL) {
        if (block->model3 != NULL) {
            free3(block->model3);
        }
        if (block->model2 != NULL) {
            free3(block->model2);
        }
        if (block->model1 != NULL) {
            free3(block->model1);
        }
        if (block->floor_model != NULL) {
            free3(block->floor_model);
        }
        if (block->arena != NULL) {
            free3(block->arena);
        }
        if (block->owns_data != 0) {
            free3(block->data);
        }
        free3(block);
    }
}

Block *block_find_at(s32 x, s32 y, s32 z) {
    BlockList *list = block_list;
    SceneRequestBuilding *req = &main_scene_request;

    if (list->count == 0) {
        return NULL;
    }
    list->cursor = list->head;
    while (1) {
        Block *block = list->cursor->data;
        if (block != NULL && block->active != 0 && x >= block->pos_x && x < block->pos_x + block->size_x && z >= block->pos_z && z < block->pos_z + block->size_z) {
            if (req->scene_state[0] != 1) {
                return block;
            }
            if (block->size_y == 0) {
                if (y == block->pos_y) {
                    return block;
                }
            } else if (block->pos_y >= y && y >= block->pos_y - block->size_y) {
                return block;
            }
        }
        if (kaj_ll_at_tail(list) != 0) {
            return NULL;
        }
        list->cursor = list->cursor->next;
    }
}

void block_set_origin(s32 x, s32 y, s32 z) {
    BlockList *list = block_list;

    if (list->count != 0) {
        list->cursor = list->head;
        while (1) {
            Block *block = list->cursor->data;
            if (block != NULL && block->active != 0) {
                block->coord_flg = 0;
                block->coord_tx = block->pos_x - x;
                block->coord_ty = block->pos_y - y;
                block->coord_tz = block->pos_z - z;
            }
            if (kaj_ll_at_tail(list) != 0) {
                break;
            }
            list->cursor = list->cursor->next;
        }
    }
}

s32 block_has_ground_at(s32 x, s32 height_out, s32 z) {
    BlockList *list = block_list;
    s32 code;
    s32 ret;

    if (list->cursor == NULL) {
        return 0;
    }
    list->cursor = list->head;
    while (1) {
        Block *block = list->cursor->data;
        if (block != NULL && block->active != 0 && (block->model_flags & 1)) {
            code = block_model_surface(block->floor_model, x, z, height_out);
            if (code != 0 && code != 0xC8 && (code & 0xFF0000) != 0xFF0000) {
                ret = 1;
                break;
            }
        }
        if (kaj_ll_at_tail(list) != 0) {
            ret = 0;
            break;
        }
        list->cursor = list->cursor->next;
    }
    return ret;
}

void block_hide_all(void) {
    BlockList *list = block_list;

    if (list->count != 0) {
        list->cursor = list->head;
        while (1) {
            if (list->cursor->data != NULL && list->cursor->data->active != 0) {
                list->cursor->data->visible = 0;
            }
            if (kaj_ll_at_tail(list) != 0) {
                break;
            }
            list->cursor = list->cursor->next;
        }
    }
}

void block_list_add(s32 block) {
    if (block_list->count == 0) {
        kaj_ll_insert_before(block_list, block);
    } else {
        block_list->cursor = block_list->tail;
        kaj_ll_insert_after(block_list, block);
    }
}

void block_free_all(void) {
    BlockList *list = block_list;
    Block *block;

    while (1) {
        if (list->count == 0) {
            break;
        }
        block = list->cursor->data;
        if (block != NULL) {
            if (block->model3 != NULL) {
                free3(block->model3);
            }
            if (block->model2 != NULL) {
                free3(block->model2);
            }
            if (block->model1 != NULL) {
                free3(block->model1);
            }
            if (block->floor_model != NULL) {
                free3(block->floor_model);
            }
            if (block->arena != NULL) {
                free3(block->arena);
            }
            if (block->owns_data != 0) {
                free3(block->data);
            }
            free3(block);
        }
        kaj_ll_remove_to_prev(list);
    }
}

void block_free_owned(void) {
    BlockList *list = block_list;

    if (list->count != 0) {
        list->cursor = list->head;
        while (1) {
            Block *block = list->cursor->data;
            if (block != NULL && block->owns_data != 0) {
                if (block->model3 != NULL) {
                    free3(block->model3);
                }
                if (block->model2 != NULL) {
                    free3(block->model2);
                }
                if (block->model1 != NULL) {
                    free3(block->model1);
                }
                if (block->floor_model != NULL) {
                    free3(block->floor_model);
                }
                if (block->arena != NULL) {
                    free3(block->arena);
                }
                if (block->owns_data != 0) {
                    free3(block->data);
                }
                free3(block);
                kaj_ll_remove_to_prev(list);
            }
            if (kaj_ll_at_tail(list) != 0) {
                break;
            }
            list->cursor = list->cursor->next;
        }
    }
}

void block_stream_stop(void) {
    block_reloaded = 0;
    kaj_cdmgr_free_all();
}

s32 block_model_surface(void *obj, s32 x, s32 z, s32 height_out) {
    Vec3 offset;
    TmdTri *prim;
    s32 left;
    s32 verts;
    s32 normals;
    s32 cnt;
    s32 hit;
    GsDobj2 *model = obj;

    offset.x = model->coord2->coord_tx;
    offset.y = model->coord2->coord_ty;
    offset.z = model->coord2->coord_tz;
    prim = model->tmd->primitive_top;
    left = model->tmd->n_primitive;
    verts = model->tmd->vert_top;
    normals = model->tmd->normal_top;
    while (left != 0) {
        cnt = prim->run_count;
        switch (prim->mode & 0xFD) {
        case 0x20:
            hit = block_hit_tris(prim, verts, normals, &offset, cnt, x, z, height_out);
            if (hit != 0) {
                return hit;
            }
            left -= cnt;
            prim = (TmdTri *)((u8 *)prim + cnt * 0x10);
            break;
        case 0x28:
            hit = block_hit_quads(prim, verts, normals, &offset, cnt, x, z, height_out);
            if (hit != 0) {
                return hit;
            }
            left -= cnt;
            prim = (TmdTri *)((u8 *)prim + cnt * 0x14);
            break;
        default:
            return 0;
        }
    }
    return 0;
}

s32 block_cd_idle(void) {
    return kaj_cdmgr_state == 0;
}

void block_enter_area(u32 code) {
    s32 kind = (code >> 16) & 0xFF;

    block_area_kind = kind;
    if (kind != 0x80) {
        return;
    }
    block_area_flames[0] = code >> 8;
    block_area_low = code;
    action_vars.flame_small_on = 0;
    action_vars.flame_large_on = 0;
    switch (block_area_flames[0]) {
    case 1:
        action_vars.flame_small_on = 1;
        break;
    case 2:
        action_vars.flame_large_on = 1;
        break;
    case 3:
        action_vars.flame_small_on = 1;
        action_vars.flame_large_on = 1;
        break;
    }
}

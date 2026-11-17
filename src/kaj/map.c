#include "common.h"
#include "kaj/map.h"
#include "kaj/cdmgr.h"
#include "psyq/libc.h"

/*
 * The city cell and place room streaming maps.
 *
 * File boundaries: likely (docs/layout.md): no assert: a normal function after cdmgr.c's deferred inline tail; end of
 * .text after.
 */

typedef struct {
    s16 cx;
    s16 cy;
    s16 saved_cx;
    s16 saved_cy;
    u8 layer;
    u8 first_layer;
    s16 ready;
    s16 count;
    u8 unkE[2];
    s32 handles[20];
} MapCellState;
u8 kaj_map_cell_cur;
extern MapCellState kaj_map_cells[];
static MapCellState *kaj_map_get_cell_state(void);
typedef struct {
    u8 code_hi;
    u8 code_lo;
    s16 group;
    s16 block_pos;
    s16 ready;
    s16 reserved;
    s16 count;
    u8 unkC[4];
    s32 handles[0x20];
} MapRoomState;
u8 kaj_map_room_cur;
extern MapRoomState kaj_map_rooms[];
s32 kaj_map_mode;
s32 kaj_map_slot;
s32 kaj_map_dir_slot;
typedef struct {
    s32 unk0;
    s32 model_ids;
} PlaceLinkRaw;
s16 kaj_map_room_dirty;
extern char kaj_map_str_city_mp[];
static void kaj_map_reset_cells(void);
typedef struct {
    u8 unk0[0x14];
    s32 cols;
    s32 rows;
    u8 unk1C[4];
} CityMapHeader;
typedef struct {
    s32 pos_x;
    s32 pos_y;
    s32 pos_z;
    u8 code_hi;
    u8 code_lo;
    s16 link_count;
    s16 tim_count;
    u8 unk12[2];
    PlaceLinkRaw *links;
    s32 tim_ids;
} PlaceArea;
typedef struct {
    s32 unk0;
    s32 x0;
    s32 y0;
    s32 x1;
    s32 y1;
    s32 cols;
    s32 rows;
    u8 unk1C[4];
    s16 cells[1];
} CityMap;
static s32 kaj_map_cell_link(s16 cx, s16 cy, u8 layer, s16 nx, s16 ny, u8 *next_layer);
extern char kaj_map_str_place_b[];
s32 kaj_map_letter;
static void kaj_map_reset_rooms(void);
static s32 kaj_map_cell_exists(s16 cx, s16 cy);
static void kaj_map_world_to_cell(s32 x, s32 y, s32 *cx, s32 *cy);
static s32 kaj_map_stream_cell(s16 cx, s16 cy);
typedef struct {
    s16 block_count;
    s16 key_count;
    s32 block_ids;
    s32 keys;
} PlaceGroup;
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s16 area_count;
    s16 group_count;
    PlaceArea *areas;
    PlaceGroup *groups;
} PlaceMap;
extern char kaj_map_str_place_rm[];
extern char kaj_map_str_place_f[];
static void kaj_map_fix_place(void);
static s32 kaj_map_cell_flags(s16 cx, s16 cy, u8 layer, u8 *flags);
typedef struct {
    u8 code_hi;
    u8 code_lo;
} PlaceRoomKey;
s32 kaj_map_file_count;
extern CdmgrFileEntry kaj_map_file_list[];
static void kaj_map_set_room(MapRoomState *room, u8 *entry);
static void kaj_map_list_room_files(s32 area, MapRoomState *room);
static s32 kaj_map_cmp_index(CdmgrFileEntry *a, CdmgrFileEntry *b);
static u8 kaj_map_next_neighbor(s16 cx, s16 cy, u8 layer, s16 *nx, s16 *ny, u8 *next_layer);
static void kaj_map_list_cell_files(MapCellState *cell);
typedef struct {
    s16 block_id;
    s16 model_count;
    s16 *model_ids;
} PlaceLink;

INCLUDE_RODATA("asm/nonmatchings/kaj/map", kaj_map_str_place_b);

INCLUDE_RODATA("asm/nonmatchings/kaj/map", kaj_map_str_place_rm);

INCLUDE_RODATA("asm/nonmatchings/kaj/map", kaj_map_str_place_f);

INCLUDE_RODATA("asm/nonmatchings/kaj/map", kaj_map_str_city_mp);

s32 kaj_map_load_city_dir(void) {
    CdmgrFile file;

    if (kaj_map_mode == 1 && kaj_map_slot != 0 && (s16)kaj_cdmgr_is_ready(kaj_map_slot)) {
        if (kaj_map_dir_slot == 0) {
            if (kaj_cdmgr_find_file(&file, "\\C\\CITY.F;1") == 0) {
                kaj_map_dir_slot = kaj_cdmgr_load(&file, 0, 0);
            }
        } else if (kaj_map_dir_slot > 0 && (s16)kaj_cdmgr_is_ready(kaj_map_dir_slot)) {
            kaj_cdmgr_find_file(&file, "\\C\\CITY.F;1");
            if (kaj_cdmgr_rebase_dir(kaj_map_dir_slot, file.size, "\\C\\CITY.BC;1") == 0) {
                return 1;
            }
        }
    }
    return 0;
}

static inline s32 kaj_map_load_place_dir_name(char *buf, s32 type) {
    PlaceMap **q = NULL;
    if (kaj_map_mode == 2 && kaj_map_slot > 0) {
        q = (PlaceMap **)kaj_cdmgr_get(kaj_map_slot);
    }
    if (q != NULL) {
        if (type != 0) {
            sprintf(buf, kaj_map_str_place_rm, kaj_map_letter, *q);
        } else {
            sprintf(buf, kaj_map_str_place_f, kaj_map_letter, *q);
        }
        return 1;
    }
    return 0;
}

s32 kaj_map_load_place_dir(void) {
    char name[32];
    CdmgrFile file;

    if (kaj_map_mode != 2 || kaj_map_slot == 0 || !(s16)kaj_cdmgr_is_ready(kaj_map_slot)) {
        return 0;
    }
    if (kaj_map_dir_slot == 0) {
        if (kaj_map_load_place_dir_name(name, 0) && kaj_cdmgr_find_file(&file, name) == 0) {
            kaj_map_dir_slot = kaj_cdmgr_load(&file, 0, 0);
            return 0;
        }
    } else {
        if (kaj_map_dir_slot <= 0) {
            return 1;
        }
        if (!(s16)kaj_cdmgr_is_ready(kaj_map_dir_slot)) {
            return 0;
        }
        kaj_map_load_place_dir_name(name, 0);
        kaj_cdmgr_find_file(&file, name);
        kaj_map_load_place_dir_name(name, 1);
        if (kaj_cdmgr_rebase_dir(kaj_map_dir_slot, file.size, name) != 0) {
            return 0;
        }
        kaj_map_fix_place();
    }
    return 1;
}

static s32 kaj_map_cell_exists(s16 cx, s16 cy) {
    CityMapHeader **city;
    s32 ret;

    ret = 0;
    if (kaj_map_mode != 1) {
        city = (CityMapHeader **)ret;
    } else {
        if (kaj_map_slot > 0) {
            ret = kaj_cdmgr_get(kaj_map_slot);
        }
        city = (CityMapHeader **)ret;
    }
    if (city != NULL) {
        if (cx >= 0 && cx < (*city)->cols && cy >= 0 && cy < (*city)->rows) {
            if (((s16 *)(*city + 1))[(cx * (*city)->rows + cy) * 2] != 0) {
                return 1;
            }
        }
    }
    return 0;
}

static inline s32 kaj_map_cell_flags_city(void) {
    s32 ret = 0;
    if (kaj_map_mode == 1 && kaj_map_slot > 0) {
        ret = kaj_cdmgr_get(kaj_map_slot);
    }
    return ret;
}

static inline u8 kaj_map_cell_flags_in_bounds(s32 cx, s32 cy) {
    CityMap **city = (CityMap **)kaj_map_cell_flags_city();
    if (city == NULL) {
        return 0;
    }
    if (!(((*city)->x0 <= cx && cx <= (*city)->x1) || (cx <= (*city)->x0 && (*city)->x1 <= cx))) {
        return 0;
    }
    if (!(((*city)->y0 <= cy && cy <= (*city)->y1) || (cy <= (*city)->y0 && (*city)->y1 <= cy))) {
        return 0;
    }
    return 1;
}

static s32 kaj_map_cell_flags(s16 cx, s16 cy, u8 layer, u8 *flags) {
    CityMap **city = (CityMap **)kaj_map_cell_flags_city();
    u8 *entry;

    if (city != NULL && kaj_map_cell_flags_in_bounds(cx, cy)) {
        entry = (u8 *)&(*city)->cells[(cx * (*city)->rows + cy) * 2];
        if (((s16 *)entry)[0] == -1) {
            entry = (u8 *)&(*city)->cells[(((s16 *)entry)[1] + layer) * 2];
        }
        if (layer == 0) {
            *flags = entry[2];
        } else {
            *flags = entry[3];
        }
        return 1;
    }
    return 0;
}

static s32 kaj_map_cell_link(s16 cx, s16 cy, u8 layer, s16 nx, s16 ny, u8 *next_layer) {
    u8 flags;

    if ((u8)kaj_map_cell_flags(cx, cy, layer, &flags)) {
        if (nx == cx + 1 && ny == cy) {
            if (flags & 4) {
                if (flags & 0x40) {
                    *next_layer = 1;
                } else {
                    *next_layer = 0;
                }
            }
        } else if (nx == cx && ny == cy + 1) {
            if (flags & 8) {
                if (flags & 0x80) {
                    *next_layer = 1;
                } else {
                    *next_layer = 0;
                }
            }
        } else if (nx == cx - 1 && ny == cy) {
            if (flags & 1) {
                if (flags & 0x10) {
                    *next_layer = 1;
                } else {
                    *next_layer = 0;
                }
            }
        } else if (nx == cx && ny == cy - 1) {
            if (flags & 2) {
                if (flags & 0x20) {
                    *next_layer = 1;
                } else {
                    *next_layer = 0;
                }
            }
        } else {
            *next_layer = 0;
        }
        if ((u8)kaj_map_cell_exists(nx, ny)) {
            return 1;
        }
    }
    *next_layer = 0;
    return 0;
}

static u8 kaj_map_next_neighbor(s16 cx, s16 cy, u8 layer, s16 *nx, s16 *ny, u8 *next_layer) {
    u8 flags;
    u8 flags2;

    if (*nx == -1 && *ny == -1) {
        return 0;
    }
    if (!(u8)kaj_map_cell_flags(cx, cy, layer, &flags)) {
        return 0;
    }
    if (*nx == cx && *ny == cy) {
        *nx = cx + 1;
        *ny = cy;
        if (flags & 4) {
            if (flags & 0x40) {
                *next_layer = 1;
            } else {
                *next_layer = 0;
            }
            if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                return 1;
            }
        }
    }
    if (*nx == cx + 1 && *ny == cy) {
        *nx = cx;
        *ny = cy + 1;
        if (flags & 8) {
            if (flags & 0x80) {
                *next_layer = 1;
            } else {
                *next_layer = 0;
            }
            if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                return 1;
            }
        }
    }
    if (*nx == cx && *ny == cy + 1) {
        *nx = cx - 1;
        *ny = cy;
        if (flags & 1) {
            if (flags & 0x10) {
                *next_layer = 1;
            } else {
                *next_layer = 0;
            }
            if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                return 1;
            }
        }
    }
    if (*nx == cx - 1 && *ny == cy) {
        *nx = cx;
        *ny = cy - 1;
        if (flags & 2) {
            if (flags & 0x20) {
                *next_layer = 1;
            } else {
                *next_layer = 0;
            }
            if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                return 1;
            }
        }
    }
    if (*nx == cx && *ny == cy - 1) {
        *nx = cx + 2;
        *ny = cy;
        if (flags & 4) {
            if ((u8)kaj_map_cell_flags(cx + 1, cy, (flags >> 6) & 1, &flags2)) {
                if (flags2 & 4) {
                    if (flags2 & 0x40) {
                        *next_layer = 1;
                    } else {
                        *next_layer = 0;
                    }
                    if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                        return 1;
                    }
                }
            }
        }
    }
    if (*nx == cx + 2 && *ny == cy) {
        *nx = cx;
        *ny = cy + 2;
        if (flags & 8) {
            if ((u8)kaj_map_cell_flags(cx, cy + 1, flags >> 7, &flags2)) {
                if (flags2 & 8) {
                    if (flags2 & 0x80) {
                        *next_layer = 1;
                    } else {
                        *next_layer = 0;
                    }
                    if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                        return 1;
                    }
                }
            }
        }
    }
    if (*nx == cx && *ny == cy + 2) {
        *nx = cx - 2;
        *ny = cy;
        if (flags & 1) {
            if ((u8)kaj_map_cell_flags(cx - 1, cy, (flags >> 4) & 1, &flags2)) {
                if (flags2 & 1) {
                    if (flags2 & 0x10) {
                        *next_layer = 1;
                    } else {
                        *next_layer = 0;
                    }
                    if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                        return 1;
                    }
                }
            }
        }
    }
    if (*nx == cx - 2 && *ny == cy) {
        *nx = cx;
        *ny = cy - 2;
        if (flags & 2) {
            if ((u8)kaj_map_cell_flags(cx, cy - 1, (flags >> 5) & 1, &flags2)) {
                if (flags2 & 2) {
                    if (flags2 & 0x20) {
                        *next_layer = 1;
                    } else {
                        *next_layer = 0;
                    }
                    if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                        return 1;
                    }
                }
            }
        }
    }
    if (*nx == cx && *ny == cy - 2) {
        *nx = cx + 1;
        *ny = cy + 1;
        if (flags & 4) {
            if ((u8)kaj_map_cell_flags(cx + 1, cy, (flags >> 6) & 1, &flags2)) {
                if (flags2 & 8) {
                    if (flags2 & 0x80) {
                        *next_layer = 1;
                    } else {
                        *next_layer = 0;
                    }
                    if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                        return 1;
                    }
                }
            }
        }
        if (flags & 8) {
            if ((u8)kaj_map_cell_flags(cx, cy + 1, flags >> 7, &flags2)) {
                if (flags2 & 4) {
                    if (flags2 & 0x40) {
                        *next_layer = 1;
                    } else {
                        *next_layer = 0;
                    }
                    if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                        return 1;
                    }
                }
            }
        }
    }
    if (*nx == cx + 1 && *ny == cy + 1) {
        *nx = cx - 1;
        *ny = cy + 1;
        if (flags & 8) {
            if ((u8)kaj_map_cell_flags(cx, cy + 1, flags >> 7, &flags2)) {
                if (flags2 & 1) {
                    if (flags2 & 0x10) {
                        *next_layer = 1;
                    } else {
                        *next_layer = 0;
                    }
                    if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                        return 1;
                    }
                }
            }
        }
        if (flags & 1) {
            if ((u8)kaj_map_cell_flags(cx - 1, cy, (flags >> 4) & 1, &flags2)) {
                if (flags2 & 8) {
                    if (flags2 & 0x80) {
                        *next_layer = 1;
                    } else {
                        *next_layer = 0;
                    }
                    if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                        return 1;
                    }
                }
            }
        }
    }
    if (*nx == cx - 1 && *ny == cy + 1) {
        *nx = cx - 1;
        *ny = cy - 1;
        if (flags & 1) {
            if ((u8)kaj_map_cell_flags(cx - 1, cy, (flags >> 4) & 1, &flags2)) {
                if (flags2 & 2) {
                    if (flags2 & 0x20) {
                        *next_layer = 1;
                    } else {
                        *next_layer = 0;
                    }
                    if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                        return 1;
                    }
                }
            }
        }
        if (flags & 2) {
            if ((u8)kaj_map_cell_flags(cx, cy - 1, (flags >> 5) & 1, &flags2)) {
                if (flags2 & 1) {
                    if (flags2 & 0x10) {
                        *next_layer = 1;
                    } else {
                        *next_layer = 0;
                    }
                    if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                        return 1;
                    }
                }
            }
        }
    }
    if (*nx == cx - 1 && *ny == cy - 1) {
        *nx = cx + 1;
        *ny = cy - 1;
        if (flags & 2) {
            if ((u8)kaj_map_cell_flags(cx, cy - 1, (flags >> 5) & 1, &flags2)) {
                if (flags2 & 4) {
                    if (flags2 & 0x40) {
                        *next_layer = 1;
                    } else {
                        *next_layer = 0;
                    }
                    if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                        return 1;
                    }
                }
            }
        }
        if (flags & 4) {
            if ((u8)kaj_map_cell_flags(cx + 1, cy, (flags >> 6) & 1, &flags2)) {
                if (flags2 & 2) {
                    if (flags2 & 0x20) {
                        *next_layer = 1;
                    } else {
                        *next_layer = 0;
                    }
                    if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                        return 1;
                    }
                }
            }
        }
    }
    if (*nx == cx + 1 && *ny == cy - 1) {
        *nx = -1;
        *ny = -1;
    }
    return 0;
}

static inline u8 kaj_map_update_city_in_bounds(s32 x, s32 y) {
    CityMap **city;
    s32 ret = 0;
    if (kaj_map_mode == 1 && kaj_map_slot > 0) {
        ret = kaj_cdmgr_get(kaj_map_slot);
    }
    city = (CityMap **)ret;
    if (city == NULL) {
        return 0;
    }
    if (!((x >= (*city)->x0 && x <= (*city)->x1) || (x <= (*city)->x0 && x >= (*city)->x1))) {
        return 0;
    }
    if (!((y >= (*city)->y0 && y <= (*city)->y1) || (y <= (*city)->y0 && y >= (*city)->y1))) {
        return 0;
    }
    return 1;
}

static void kaj_map_world_to_cell(s32 x, s32 y, s32 *cx, s32 *cy) {
    CityMap **city;
    s32 ret = 0;
    s32 w;
    s32 h;

    *cx = -1;
    *cy = -1;
    if (kaj_map_mode == 1 && kaj_map_slot > 0) {
        ret = kaj_cdmgr_get(kaj_map_slot);
    }
    city = (CityMap **)ret;
    if (city != NULL && kaj_map_update_city_in_bounds(x, y)) {
        w = ((*city)->x1 - (*city)->x0) / (*city)->cols;
        h = ((*city)->y1 - (*city)->y0) / (*city)->rows;
        if (w != 0 && h != 0) {
            *cx = (x - (*city)->x0) / w;
            *cy = (y - (*city)->y0) / h;
        }
    }
}

s32 kaj_map_update_city(s32 x, s32 y) {
    s32 cx;
    s32 cy;

    if (kaj_map_update_city_in_bounds(x, y)) {
        kaj_map_world_to_cell(x, y, &cx, &cy);
        if ((u8)kaj_map_cell_exists(cx, cy)) {
            return kaj_map_stream_cell(cx, cy);
        }
        return 0;
    }
    return 0;
}

static void kaj_map_set_room(MapRoomState *room, u8 *entry) {
    s32 ret;
    PlaceMap **place = NULL;
    PlaceGroup *group;
    s16 i;
    s16 j;

    if (entry[1] == room->code_hi && entry[2] == room->code_lo) {
        return;
    }
    for (i = 0; i < room->count; i++) {
        if (room->handles[i] != 0) {
            kaj_cdmgr_release(room->handles[i]);
            room->handles[i] = 0;
        }
    }
    room->code_hi = entry[1];
    room->code_lo = entry[2];
    room->count = 0;
    room->ready = 0;
    room->block_pos = 0;
    for (i = 0; i < 32; i++) {
        room->handles[i] = 0;
    }
    ret = 0;
    if (kaj_map_mode == 2 && kaj_map_slot > 0) {
        ret = kaj_cdmgr_get(kaj_map_slot);
    }
    place = (PlaceMap **)ret;
    if (place != NULL) {
        for (room->group = 0; room->group < (*place)->group_count; room->group++) {
            group = &(*place)->groups[room->group];
            for (j = 0; j < group->key_count; j++) {
                if (((PlaceRoomKey *)group->keys)[j].code_hi == room->code_hi && ((PlaceRoomKey *)group->keys)[j].code_lo == room->code_lo) {
                    return;
                }
            }
        }
    } else {
        room->group = (*place)->group_count;
    }
}

static inline s16 kaj_map_list_room_files_first(MapRoomState *room, s16 *out) {
    PlaceMap **place = NULL;
    PlaceGroup *group;
    s32 ret = 0;
    if (kaj_map_mode == 2 && kaj_map_slot > 0) {
        ret = kaj_cdmgr_get(kaj_map_slot);
    }
    place = (PlaceMap **)ret;
    if (place != NULL && room->group < (*place)->group_count) {
        group = &(*place)->groups[room->group];
        if (room->block_pos < group->block_count) {
            *out = ((s16 *)group->block_ids)[room->block_pos];
            if (*out != 0) {
                return 1;
            }
        }
    }
    return 0;
}

static inline s16 kaj_map_list_room_files_next(MapRoomState *room, s16 *out) {
    PlaceMap **place = NULL;
    PlaceGroup *group;
    s32 ret = 0;
    if (kaj_map_mode == 2 && kaj_map_slot > 0) {
        ret = kaj_cdmgr_get(kaj_map_slot);
    }
    place = (PlaceMap **)ret;
    if (place != NULL && room->group < (*place)->group_count) {
        group = &(*place)->groups[room->group];
        if (room->block_pos < group->block_count - 1) {
            room->block_pos++;
            *out = ((s16 *)group->block_ids)[room->block_pos];
            return 1;
        }
    }
    return 0;
}

static inline s16 kaj_map_list_room_files_get(s16 id, CdmgrFileEntry *file) {
    if (kaj_cdmgr_dir_entry(kaj_map_dir_slot, id, (CdmgrFile *)file) == 0) {
        return 1;
    }
    return 0;
}

static void kaj_map_list_room_files(s32 area, MapRoomState *room) {
    CdmgrFileEntry file;
    s16 id;
    s32 ret;
    PlaceMap **place;
    PlaceArea *area_desc;
    PlaceLink *r;
    s32 max;
    s32 total;
    s32 i;
    s32 j;
    s32 k;
    s32 ok;

    if (room->ready != 0) {
        return;
    }
    max = kaj_cdmgr_pool_size(1);
    total = 0;
    kaj_map_file_count = 0;
    for (i = 0; i < 20; i++) {
        if (i == 0) {
            ok = kaj_map_list_room_files_first(room, &id);
        } else {
            ok = kaj_map_list_room_files_next(room, &id);
        }
        if (!ok) {
            break;
        }
        if (kaj_map_list_room_files_get(id, &file)) {
            for (j = 0; j < kaj_map_file_count; j++) {
                if (kaj_map_file_list[j].index == file.index) {
                    break;
                }
            }
            if (j >= kaj_map_file_count) {
                total += file.alloc_size;
                if (total >= max) {
                    break;
                }
                file.type = 3;
                kaj_map_file_list[kaj_map_file_count] = file;
                kaj_map_file_count++;
            }
        }
    }
    ret = 0;
    if (kaj_map_mode == 2 && kaj_map_slot > 0) {
        ret = kaj_cdmgr_get(kaj_map_slot);
    }
    place = (PlaceMap **)ret;
    if (place != NULL) {
        area_desc = &(*place)->areas[area];
        r = (PlaceLink *)area_desc->links;
        for (i = 0; i < area_desc->link_count; i++, r++) {
            if (kaj_cdmgr_find_slot(1, r->block_id) == NULL) {
                for (j = 0; j < kaj_map_file_count; j++) {
                    if (kaj_map_file_list[j].index == r->block_id) {
                        break;
                    }
                }
                if (j == kaj_map_file_count) {
                    continue;
                }
            }
            for (j = 0; j < r->model_count; j++) {
                for (k = 0; k < kaj_map_file_count; k++) {
                    if (kaj_map_file_list[k].index == r->model_ids[j]) {
                        break;
                    }
                }
                if (k < kaj_map_file_count) {
                    continue;
                }
                if (kaj_map_list_room_files_get(r->model_ids[j], &file)) {
                    total += file.alloc_size;
                    if (total >= max) {
                        break;
                    }
                    file.type = 5;
                    kaj_map_file_list[kaj_map_file_count] = file;
                    kaj_map_file_count++;
                }
            }
            if (j < r->model_count) {
                break;
            }
        }
        for (i = 0; i < area_desc->tim_count; i++) {
            for (j = 0; j < kaj_map_file_count; j++) {
                if (kaj_map_file_list[j].index == ((s16 *)area_desc->tim_ids)[i]) {
                    break;
                }
            }
            if (j < kaj_map_file_count) {
                continue;
            }
            if (kaj_map_list_room_files_get(((s16 *)area_desc->tim_ids)[i], &file)) {
                total += file.alloc_size;
                if (total >= max) {
                    break;
                }
                file.type = 6;
                kaj_map_file_list[kaj_map_file_count] = file;
                kaj_map_file_count++;
            }
        }
    }
    qsort(kaj_map_file_list, kaj_map_file_count, sizeof(CdmgrFileEntry), kaj_map_cmp_index);
}

static inline u8 kaj_map_update_place_changed(MapRoomState *room, u8 *entry) {
    if (entry[1] != room->code_hi || entry[2] != room->code_lo) {
        return 1;
    }
    return 0;
}

static inline s32 kaj_map_update_place_count(void) {
    MapRoomState *room = &kaj_map_rooms[kaj_map_room_cur];
    if (room->ready > 0) {
        return room->count;
    }
    return 0;
}

static inline s32 kaj_map_update_place_load(MapRoomState *room, u8 *entry, s32 prev) {
    s16 moved = 0;
    s32 *buf = room->handles;
    if (kaj_cdmgr_count_refs(kaj_map_file_count, kaj_map_file_list, buf, 1) == 0) {
        room->ready = 1;
    }
    kaj_map_room_dirty = 0;
    kaj_map_room_cur = kaj_map_room_cur == 0;
    kaj_map_set_room(&kaj_map_rooms[1 - kaj_map_room_cur], entry);
    if (kaj_cdmgr_load_list(&kaj_map_file_count, kaj_map_file_list, buf, 1, &moved) == 0) {
        room->ready = 1;
    }
    room->count = kaj_map_file_count;
    if (room->ready == 1) {
        return prev != kaj_map_file_count;
    }
    if (moved != 0) {
        return 3;
    }
    return 2;
}

s32 kaj_map_update_place(s32 area, u8 *entry) {
    s16 moved = 0;
    s32 ret = 0;
    s32 prev;
    s32 *buf;
    MapRoomState *room;
    MapRoomState *r;

    if (!kaj_map_update_place_changed(&kaj_map_rooms[kaj_map_room_cur], entry)) {
        if (kaj_map_room_dirty != 0) {
            kaj_map_room_dirty = 0;
            ret = 1;
        }
        return ret;
    }
    if (!kaj_map_update_place_changed(&kaj_map_rooms[1 - kaj_map_room_cur], entry)) {
        return ret;
    }
    if ((s16)kaj_cdmgr_is_idle() == 0) {
        return ret;
    }
    prev = kaj_map_update_place_count();
    kaj_cdmgr_clear_dirty();
    kaj_map_set_room(&kaj_map_rooms[1 - kaj_map_room_cur], entry);
    kaj_map_list_room_files(area, &kaj_map_rooms[1 - kaj_map_room_cur]);
    room = &kaj_map_rooms[1 - kaj_map_room_cur];
    r = room;
    buf = room->handles;
    if (kaj_cdmgr_count_refs(kaj_map_file_count, kaj_map_file_list, buf, 1) == 0) {
        room->ready = 1;
    }
    kaj_map_room_dirty = 0;
    kaj_map_room_cur = kaj_map_room_cur == 0;
    kaj_map_set_room(&kaj_map_rooms[1 - kaj_map_room_cur], entry);
    if (kaj_cdmgr_load_list(&kaj_map_file_count, kaj_map_file_list, buf, 1, &moved) == 0) {
        room->ready = 1;
    }
    r->count = kaj_map_file_count;
    if (r->ready == 1) {
        ret = prev != kaj_map_file_count;
    } else if (moved != 0) {
        ret = 3;
    } else {
        ret = 2;
    }
    return ret;
}

static void kaj_map_fix_place(void) {
    s32 ret = 0;
    PlaceMap **place;
    PlaceArea *area_desc;
    PlaceLinkRaw *r;
    PlaceGroup *group;
    s32 i;
    s32 j;

    if (kaj_map_mode == 2 && kaj_map_slot > 0) {
        ret = kaj_cdmgr_get(kaj_map_slot);
    }
    place = (PlaceMap **)ret;
    if (place != NULL) {
        (*place)->areas = (PlaceArea *)((s32)*place + (s32)(*place)->areas);
        area_desc = (*place)->areas;
        for (i = 0; i < (*place)->area_count; i++, area_desc++) {
            r = area_desc->links = (void *)((s32)*place + (s32)area_desc->links);
            for (j = 0; j < area_desc->link_count; j++, r++) {
                r->model_ids = (s32)*place + r->model_ids;
            }
            area_desc->tim_ids = (s32)*place + area_desc->tim_ids;
        }
        (*place)->groups = (void *)((s32)*place + (s32)(*place)->groups);
        for (i = 0; i < (*place)->group_count; i++) {
            group = &(*place)->groups[i];
            group->block_ids = (s32)*place + group->block_ids;
            group->keys = (s32)*place + group->keys;
        }
    }
}

static void kaj_map_reset_cells(void) {
    MapCellState *cell;
    s32 i;

    cell = &kaj_map_cells[kaj_map_cell_cur];
    if (cell != NULL) {
        cell->cx = -1;
        cell->cy = -1;
        cell->saved_cx = -1;
        cell->saved_cy = -1;
        cell->count = 0;
        cell->layer = 0;
        cell->first_layer = 0;
        cell->ready = -1;
        for (i = 19; i >= 0; i--) {
            cell->handles[i] = 0;
        }
    }
    cell = &kaj_map_cells[1 - kaj_map_cell_cur];
    if (cell != NULL) {
        cell->cx = -1;
        cell->cy = -1;
        cell->saved_cx = -1;
        cell->saved_cy = -1;
        cell->count = 0;
        cell->layer = 0;
        cell->first_layer = 0;
        cell->ready = -1;
        for (i = 19; i >= 0; i--) {
            cell->handles[i] = 0;
        }
    }
}

static inline u8 kaj_map_list_cell_files_get(s16 cx, s16 cy, u8 layer, CdmgrFileEntry *file) {
    CityMap **city = NULL;
    s16 *entry;
    s32 ret = 0;
    if (kaj_map_mode == 1 && kaj_map_slot > 0) {
        ret = kaj_cdmgr_get(kaj_map_slot);
    }
    city = (CityMap **)ret;
    if (city == NULL) {
        return 0;
    }
    if (cx < 0 || cx >= (*city)->cols) {
        return 0;
    }
    if (cy < 0 || cy >= (*city)->rows) {
        return 0;
    }
    entry = &(*city)->cells[(cx * (*city)->rows + cy) * 2];
    if (entry[0] == -1) {
        entry = &(*city)->cells[(entry[1] + layer) * 2];
    }
    if (kaj_cdmgr_dir_entry(kaj_map_dir_slot, entry[0], (CdmgrFile *)file) == 0) {
        return 1;
    }
    return 0;
}

static void kaj_map_list_cell_files(MapCellState *cell) {
    CdmgrFileEntry file;
    s16 cx;
    s16 cy;
    u8 cd;
    s16 x;
    s16 y;
    u8 layer;
    s32 max;
    s32 total;
    s32 i;
    s32 j;

    x = cx = cell->cx;
    y = cy = cell->cy;
    layer = cell->layer;
    cd = cell->first_layer;
    max = kaj_cdmgr_pool_size(1);
    total = 0;
    kaj_map_file_count = 0;
    for (i = 0; i < 20; i++) {
        if (!kaj_map_list_cell_files_get(cx, cy, cd, &file)) {
            if (!kaj_map_next_neighbor(x, y, layer, &cx, &cy, &cd)) {
                break;
            }
        } else {
            for (j = 0; j < kaj_map_file_count; j++) {
                if (kaj_map_file_list[j].index == file.index) {
                    break;
                }
            }
            if (j < kaj_map_file_count) {
                if (!kaj_map_next_neighbor(x, y, layer, &cx, &cy, &cd)) {
                    break;
                }
            } else {
                total += file.alloc_size;
                if (total >= max) {
                    break;
                }
                file.type = 1;
                kaj_map_file_list[kaj_map_file_count] = file;
                kaj_map_file_count++;
                if (!kaj_map_next_neighbor(x, y, layer, &cx, &cy, &cd)) {
                    break;
                }
            }
        }
    }
    qsort(kaj_map_file_list, kaj_map_file_count, sizeof(CdmgrFileEntry), kaj_map_cmp_index);
    i = 0;
    while (i < kaj_map_file_count) {
        i++;
    }
}

static inline s32 kaj_map_stream_cell_changed(MapCellState *cell, s16 x, s16 y) {
    if (cell->cx != x || cell->cy != y) {
        return 1;
    }
    return 0;
}

static inline s32 kaj_map_stream_cell_count(void) {
    MapCellState *cell = &kaj_map_cells[kaj_map_cell_cur];
    return cell->ready > 0 ? cell->count : 0;
}

static inline void kaj_map_stream_cell_set(MapCellState *cell, s16 x, s16 y) {
    s32 i;
    u8 next_layer;
    if (cell->cx == x && cell->cy == y) {
        return;
    }
    for (i = 0; i < cell->count; i++) {
        if (cell->handles[i] != 0) {
            kaj_cdmgr_release(cell->handles[i]);
            cell->handles[i] = 0;
        }
    }
    cell->count = 0;
    cell->ready = 0;
    if (cell->cx >= 0 && cell->cy >= 0) {
        next_layer = 0;
        kaj_map_cell_link(cell->cx, cell->cy, cell->layer, x, y, &next_layer);
        cell->layer = next_layer;
    } else {
        cell->layer = 0;
    }
    cell->cx = x;
    cell->cy = y;
    cell->saved_cx = x;
    cell->saved_cy = y;
    cell->first_layer = cell->layer;
}

static s32 kaj_map_stream_cell(s16 cx, s16 cy) {
    s16 moved;
    s32 ret = 0;
    s32 prev;
    MapCellState *cell;

    if (!kaj_map_stream_cell_changed(&kaj_map_cells[kaj_map_cell_cur], cx, cy)) {
        return ret;
    }
    if (!kaj_map_stream_cell_changed(&kaj_map_cells[1 - kaj_map_cell_cur], cx, cy)) {
        return ret;
    }
    if ((s16)kaj_cdmgr_is_idle() == 0) {
        return ret;
    }
    prev = kaj_map_stream_cell_count();
    kaj_cdmgr_clear_dirty();
    kaj_map_stream_cell_set(&kaj_map_cells[1 - kaj_map_cell_cur], cx, cy);
    kaj_map_list_cell_files(&kaj_map_cells[1 - kaj_map_cell_cur]);
    cell = &kaj_map_cells[1 - kaj_map_cell_cur];
    if (kaj_cdmgr_count_refs(kaj_map_file_count, kaj_map_file_list, cell->handles, 1) == 0) {
        cell->ready = 1;
    }
    kaj_map_cell_cur = kaj_map_cell_cur == 0;
    kaj_map_stream_cell_set(&kaj_map_cells[1 - kaj_map_cell_cur], cx, cy);
    if (kaj_cdmgr_load_list(&kaj_map_file_count, kaj_map_file_list, cell->handles, 1, &moved) == 0) {
        cell->ready = 1;
    }
    cell->count = kaj_map_file_count;
    if (cell->ready == 1) {
        ret = prev != kaj_map_file_count;
    } else if (moved != 0) {
        ret = 3;
    } else {
        ret = 2;
    }
    return ret;
}

void kaj_map_cell_slots(s16 *count, s32 *handles) {
    MapCellState *cell;
    s16 n;
    s16 i;
    s16 j;
    u8 found;
    s16 max;

    max = *count;
    *count = 0;
    cell = &kaj_map_cells[kaj_map_cell_cur];
    if (cell->ready > 0) {
        n = 0;
        for (i = 0; i < cell->count; i++) {
            found = 0;
            for (j = 0; j < n; j++) {
                if (handles[j] == cell->handles[i]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                handles[n] = cell->handles[i];
                n++;
                if (n == max) {
                    break;
                }
            }
        }
        *count = n;
    }
}

void kaj_map_cell_loaded_slots(s16 *count, s32 *handles) {
    s16 max = *count;
    MapCellState *cell;
    s16 n;
    s16 i;
    s16 j;
    u8 found;

    *count = 0;
    n = 0;
    cell = &kaj_map_cells[kaj_map_cell_cur];
    for (i = 0; i < cell->count; i++) {
        found = 0;
        for (j = 0; j < n; j++) {
            if (handles[j] == cell->handles[i]) {
                found = 1;
                break;
            }
        }
        if (!found && kaj_cdmgr_is_loaded(cell->handles[i])) {
            handles[n] = cell->handles[i];
            n++;
            if (n == max) {
                break;
            }
        }
    }
    *count = n;
}

s32 kaj_map_open_city(void) {
    CdmgrFile file;
    s32 ret;

    kaj_cdmgr_init();
    kaj_map_mode = 1;
    kaj_map_dir_slot = 0;
    ret = kaj_cdmgr_find_file(&file, kaj_map_str_city_mp);
    if (ret == 0) {
        kaj_map_slot = kaj_cdmgr_load(&file, 0, 2);
        if (kaj_map_slot == 0) {
            ret = -1;
        }
    }
    kaj_map_reset_cells();
    return ret;
}

s32 kaj_map_city_ready(void) {
    MapCellState *cell = &kaj_map_cells[kaj_map_cell_cur];

    if (cell != NULL && cell->ready > 0) {
        return 1;
    }
    return 0;
}

s32 kaj_map_open_place(s32 letter, char *place_name) {
    char name[32];
    CdmgrFile file;
    s32 ret;
    char *p = name;
    CdmgrFile *f = &file;

    kaj_cdmgr_init();
    kaj_map_mode = 2;
    kaj_map_slot = 0;
    kaj_map_dir_slot = 0;
    kaj_map_letter = letter;
    sprintf(p, kaj_map_str_place_b, letter, place_name);
    ret = kaj_cdmgr_find_file(f, p);
    if (ret == 0) {
        kaj_map_slot = kaj_cdmgr_load(f, 0, 4);
        if (kaj_map_slot == 0) {
            ret = -1;
        }
    } else {
        ret = -1;
    }
    kaj_map_reset_rooms();
    return ret;
}

void kaj_map_get_entry(s32 area, s32 *pos, u8 *entry) {
    s32 ret = 0;
    PlaceMap **place = NULL;
    PlaceArea *area_desc;

    if (kaj_map_mode == 2 && kaj_map_slot > 0) {
        ret = kaj_cdmgr_get(kaj_map_slot);
    }
    place = (PlaceMap **)ret;
    if (place != NULL) {
        area_desc = &((PlaceArea *)(*place)->areas)[area];
        pos[0] = area_desc->pos_x;
        pos[1] = area_desc->pos_y;
        pos[2] = area_desc->pos_z;
        entry[0] = 0;
        entry[1] = area_desc->code_hi;
        entry[2] = area_desc->code_lo;
    }
}

void kaj_map_set_cell_ready(void) {
    kaj_map_get_cell_state()->ready = 1;
}

void kaj_map_set_room_ready(void) {
    MapRoomState *room = &kaj_map_rooms[kaj_map_room_cur];

    room->ready = 1;
}

static void kaj_map_reset_rooms(void) {
    MapRoomState *room;
    s32 i;

    room = &kaj_map_rooms[kaj_map_room_cur];
    if (room != NULL) {
        room->code_hi = 0;
        room->code_lo = 0;
        room->group = 0;
        room->block_pos = 0;
        room->reserved = 0;
        room->count = 0;
        room->ready = 0;
        for (i = 31; i >= 0; i--) {
            room->handles[i] = 0;
        }
    }
    room = &kaj_map_rooms[1 - kaj_map_room_cur];
    if (room != NULL) {
        room->code_hi = 0;
        room->code_lo = 0;
        room->group = 0;
        room->block_pos = 0;
        room->reserved = 0;
        room->count = 0;
        room->ready = 0;
        for (i = 31; i >= 0; i--) {
            room->handles[i] = 0;
        }
    }
}

s32 kaj_map_get_city(void) {
    s32 ret = 0;

    if (kaj_map_mode == 1 && kaj_map_slot > 0) {
        ret = kaj_cdmgr_get(kaj_map_slot);
    }
    return ret;
}

s32 kaj_map_get_place(void) {
    s32 ret = 0;

    if (kaj_map_mode == 2 && kaj_map_slot > 0) {
        ret = kaj_cdmgr_get(kaj_map_slot);
    }
    return ret;
}

s32 kaj_map_get_dir_slot(void) {
    return kaj_map_dir_slot;
}

s32 kaj_map_in_bounds(s32 x, s32 y) {
    s32 ret = 0;
    CityMap **city = NULL;

    if (kaj_map_mode == 1 && kaj_map_slot > 0) {
        ret = kaj_cdmgr_get(kaj_map_slot);
    }
    city = (CityMap **)ret;
    if (city == NULL) {
        return 0;
    }
    if (!(((*city)->x0 <= x && x <= (*city)->x1) || (x <= (*city)->x0 && (*city)->x1 <= x))) {
        return 0;
    }
    if (!(((*city)->y0 <= y && y <= (*city)->y1) || (y <= (*city)->y0 && (*city)->y1 <= y))) {
        return 0;
    }
    return 1;
}

s32 kaj_map_cell_file(s16 cx, s16 cy, u8 layer, CdmgrFile *info) {
    s32 ret = 0;
    CityMap **city = NULL;
    s16 *entry;

    if (kaj_map_mode == 1 && kaj_map_slot > 0) {
        ret = kaj_cdmgr_get(kaj_map_slot);
    }
    city = (CityMap **)ret;
    if (city != NULL && cx >= 0 && cx < (*city)->cols && cy >= 0 && cy < (*city)->rows) {
        entry = &(*city)->cells[(cx * (*city)->rows + cy) * 2];
        if (entry[0] == -1) {
            entry = &(*city)->cells[(entry[1] + layer) * 2];
        }
        if (kaj_cdmgr_dir_entry(kaj_map_dir_slot, entry[0], info) == 0) {
            return 1;
        }
    }
    return 0;
}

static s32 kaj_map_cmp_index(CdmgrFileEntry *a, CdmgrFileEntry *b) {
    return a->index - b->index;
}

s16 kaj_map_room_slot_count(void) {
    MapRoomState *room = &kaj_map_rooms[kaj_map_room_cur];

    if (room->ready <= 0) {
        return 0;
    }
    return room->count;
}

s32 kaj_map_place_ready(void) {
    MapRoomState *room = &kaj_map_rooms[kaj_map_room_cur];

    if (room != NULL && room->ready > 0) {
        return 1;
    }
    return 0;
}

void kaj_map_room_slots(s16 *count, s32 *handles) {
    s16 max = *count;
    MapRoomState *room;
    s16 n;
    s16 i;
    s16 j;
    u8 found;
    s32 handle;

    *count = 0;
    room = &kaj_map_rooms[kaj_map_room_cur];
    n = 0;
    if (room->ready > 0) {
        for (i = 0; i < room->count; i++) {
            found = 0;
            handle = room->handles[i];
            for (j = 0; j < n; j++) {
                if (handles[j] == handle) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                handles[n] = handle;
                n++;
                if (n == max) {
                    break;
                }
            }
        }
        *count = n;
    }
}

void kaj_map_room_loaded_slots(s16 *count, s32 *handles) {
    s16 max = *count;
    MapRoomState *room;
    s16 n;
    s16 i;
    s16 j;
    u8 found;
    s32 handle;

    *count = 0;
    n = 0;
    room = &kaj_map_rooms[kaj_map_room_cur];
    for (i = 0; i < room->count; i++) {
        found = 0;
        handle = room->handles[i];
        for (j = 0; j < n; j++) {
            if (handles[j] == handle) {
                found = 1;
                break;
            }
        }
        if (!found && kaj_cdmgr_is_loaded(handle)) {
            handles[n] = handle;
            n++;
            if (n == max) {
                break;
            }
        }
    }
    *count = n;
}

void kaj_map_room_release(s32 handle) {
    MapRoomState *room = &kaj_map_rooms[kaj_map_room_cur];
    s32 i;

    for (i = 0; i < room->count; i++) {
        if (room->handles[i] == handle) {
            kaj_cdmgr_release(room->handles[i]);
            room->handles[i] = 0;
            kaj_map_room_dirty = 1;
            return;
        }
    }
}

static MapCellState *kaj_map_get_cell_state(void) {
    return &kaj_map_cells[kaj_map_cell_cur];
}

s16 kaj_map_cell_slot_count(void) {
    MapCellState *cell = &kaj_map_cells[kaj_map_cell_cur];
    if (cell->ready <= 0) {
        return 0;
    }
    return cell->count;
}

void kaj_map_set_cell(MapCellState *cell, s16 cx, s16 cy) {
    s32 i;
    u8 next_layer;

    if (cell->cx != cx || cell->cy != cy) {
        for (i = 0; i < cell->count; i++) {
            if (cell->handles[i] != 0) {
                kaj_cdmgr_release(cell->handles[i]);
                cell->handles[i] = 0;
            }
        }
        cell->count = 0;
        cell->ready = 0;
        if (cell->cx >= 0 && cell->cy >= 0) {
            next_layer = 0;
            kaj_map_cell_link(cell->cx, cell->cy, cell->layer, cx, cy, &next_layer);
            cell->layer = next_layer;
        } else {
            cell->layer = 0;
        }
        cell->cx = cx;
        cell->cy = cy;
        cell->saved_cx = cx;
        cell->saved_cy = cy;
        cell->first_layer = cell->layer;
    }
}

s32 kaj_map_cell_changed(s16 *cell, s16 cx, s16 cy) {
    if (cell[0] != cx || cell[1] != cy) {
        return 1;
    }
    return 0;
}

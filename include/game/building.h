#ifndef GAME_BUILDING_H
#define GAME_BUILDING_H

#include "common.h"
#include "game/types.h"

typedef struct BuildingState {
    u16 building;
    u16 entry;
} BuildingState;

/* Local view of SceneRequest: this unit reads 0x14-0x19 as halfwords, the shared type has two s32 there. */
typedef struct {
    s16 scene_state[5];
    s16 change;
    char *path;
    s16 building;
    s16 entry;
    s16 entry_se;
    s16 place_letter;
    u16 place_entry;
    u8 pad1A[0x2];
    s32 unk1C;
    u8 name[0x10];
} SceneRequestBuilding;

/* Functions of src/game/building.c that other files call or a table names. */
void block_building_main(void);
void block_bus_run(s16 building, s16 start_floor);

#endif

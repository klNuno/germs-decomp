#ifndef KAJ_TOD_H
#define KAJ_TOD_H

#include "common.h"
#include "game/types.h"

typedef struct TodFrame {
    u8 unk0[0x2];
    u16 packet_count;
    u32 frame;
} TodFrame;

typedef struct {
    s16 m[9];
    u8 pad12[0x2];
    s32 t[3];
} TodMatrix;

typedef struct {
    s32 flg;
    TodMatrix coord;
    TodMatrix workm;
    void *param;
    void *super;
    void *sub;
} TodCoord;

/* PSY-Q GsDOBJ2 as the TOD player reads it: kaj_tod_init_table sets attribute 0x80000000 (GsDOFF),
   coordinate arg2[i], tmd 0 and id -1; kaj_tod_find_obj matches id. Not TodObj: same size, other roles. */
typedef struct TodObj {
    s32 attribute;
    void *coord2;
    s32 tmd;
    s32 id;
} TodObj;

/* PSY-Q GsOBJTABLE2: kaj_tod_init_table sets top = the object array, nobj = 0, maxobj = arg4;
   kaj_tod_create_obj appends at nobj while nobj < maxobj. Not TodObjTable: count roles inverted. */
typedef struct TodObjTable {
    TodObj *top;
    s32 nobj;
    s32 maxobj;
} TodObjTable;

/* Functions of src/kaj/tod.c that other files call or a table names. */
void *kaj_tod_set_packet(void *packet, void *table, s32 *ids, void *tmd, s32 mode, s32 root_coord);
void kaj_tod_init_table(TodObjTable *table, TodObj *objs, TodCoord *coords, u8 *params, s32 count);
void *kaj_tod_set_frame(u32 frame, TodFrame *tod, void *table, s32 *ids, void *tmd, s32 mode, s32 root_coord);

#endif

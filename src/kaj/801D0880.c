#include "common.h"
#include "game/types.h"

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
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 nobj;
    s32 objects[1][7];
} TodTmd;
void GsInitCoordinate2(void *super, void *base);
void *kaj_tod_set_packet(void *packet, void *table, s32 *ids, void *tmd, s32 mode, s32 root_coord);
typedef struct {
    s32 scale_x;
    s32 scale_y;
    s32 scale_z;
    s32 unkC;
    s16 rot_x;
    s16 rot_y;
    s16 rot_z;
    s16 unk16;
    s32 trans_x;
    s32 trans_y;
    s32 trans_z;
    s32 unk24;
} TodCoordParam;
void RotMatrix(s16 *r, TodMatrix *m);
void ScaleMatrix(TodMatrix *m, TodCoordParam *v);
void TransMatrix(TodMatrix *m, s32 *v);
void GsLinkObject4(void *a, void *b, s32 c);

static inline TodObj *kaj_tod_find_obj_inl(TodObjTable *table, s32 id) {
    TodObj *p;
    s32 i;
    p = table->top;
    for (i = 0; i < table->nobj; i++, p++) {
        if (id == p->id) {
            break;
        }
    }
    if (i == table->nobj) {
        return NULL;
    }
    return p;
}

static inline TodObj *kaj_tod_create_obj_inl(TodObjTable *table, s32 id) {
    TodObj *p;
    s32 i;
    p = table->top;
    for (i = 0; i < table->nobj; i++, p++) {
        if (p->id == -1) {
            break;
        }
    }
    if (i < table->nobj) {
        p->id = id;
        p->attribute = 0;
        GsInitCoordinate2(NULL, p->coord2);
        p->tmd = 0;
        return p;
    }
    if (i < table->maxobj) {
        p = &table->top[table->nobj++];
        p->id = id;
        p->attribute = 0;
        GsInitCoordinate2(NULL, p->coord2);
        p->tmd = 0;
        return p;
    }
    return NULL;
}

static inline TodObj *kaj_tod_remove_obj_inl(TodObjTable *table, s32 id) {
    TodObj *p;
    s32 i;
    p = table->top;
    for (i = 0; i < table->nobj; i++, p++) {
        if (p->id == id) {
            break;
        }
    }
    if (i < table->nobj) {
        p->id = -1;
        if (i == table->nobj - 1) {
            do {
                p--;
                table->nobj--;
            } while (p->id == -1);
        }
        return p;
    }
    return NULL;
}

static inline s32 *kaj_tod_find_tmd_inl(TodTmd *tmd, s32 *ids, s32 id) {
    s32 *p;
    s32 n;
    p = tmd->objects[0];
    for (n = tmd->nobj; n > 0; n--) {
        if (id == *ids) {
            break;
        }
        p += 7;
        ids++;
    }
    if (n == 0) {
        return NULL;
    }
    return p;
}

void *kaj_tod_set_packet(void *packet, void *table, s32 *ids, void *tmd, s32 mode, s32 root_coord) {
    s32 unused[6];
    TodObj tmp;
    TodMatrix mtx;
    TodCoordParam prm;
    s32 *data = (s32 *)packet + 1;
    TodObj *obj;
    TodObj *parent;
    TodCoord *coord;
    TodCoordParam *param;
    TodMatrix *matrix;
    s32 *model;
    u32 header;
    s32 id;
    s32 type;
    s32 flags;
    s32 len;
    s32 rot;

    header = *(u32 *)packet;
    id = header & 0xFFFF;
    type = (header >> 16) & 0xF;
    flags = (header >> 20) & 0xF;
    len = (header >> 24) & 0xF;

    obj = kaj_tod_find_obj_inl(table, id);
    matrix = &mtx;
    if (obj == NULL) {
        obj = &tmp;
        param = &prm;
    } else {
        coord = obj->coord2;
        param = coord->param;
        matrix = &coord->coord;
        coord->flg = 0;
    }

    switch (type) {
    case 0:
        obj->attribute = (obj->attribute & data[0]) | data[1];
        break;
    case 1:
        if (flags & 1) {
            if (flags & 2) {
                param->rot_x += data[0] / 360;
                param->rot_y += data[1] / 360;
                param->rot_z += data[2] / 360;
                data += 3;
            }
            if (flags & 4) {
                param->scale_x = param->scale_x * ((s16 *)data)[0] >> 12;
                param->scale_y = param->scale_y * ((s16 *)data)[1] >> 12;
                param->scale_z = param->scale_z * ((s16 *)data)[2] >> 12;
                data += 2;
            }
            if (flags & 8) {
                param->trans_x += data[0];
                param->trans_y += data[1];
                param->trans_z += data[2];
            }
            RotMatrix(&param->rot_x, matrix);
            ScaleMatrix(matrix, param);
            TransMatrix(matrix, &param->trans_x);
        } else {
            rot = flags & 2;
            if (rot) {
                param->rot_x = data[0] / 360;
                param->rot_y = data[1] / 360;
                param->rot_z = data[2] / 360;
                data += 3;
                RotMatrix(&param->rot_x, matrix);
            }
            if (flags & 4) {
                param->scale_x = ((s16 *)data)[0];
                param->scale_y = ((s16 *)data)[1];
                param->scale_z = ((s16 *)data)[2];
                data += 2;
                if (!rot) {
                    RotMatrix(&param->rot_x, matrix);
                }
                ScaleMatrix(matrix, param);
            }
            if (flags & 8) {
                param->trans_x = data[0];
                param->trans_y = data[1];
                param->trans_z = data[2];
                TransMatrix(matrix, &param->trans_x);
            }
        }
        break;
    case 2:
        if (tmd != NULL) {
            model = kaj_tod_find_tmd_inl(tmd, ids, (u16)data[0]);
            if (model != NULL) {
                GsLinkObject4(model, obj, 0);
            }
        }
        break;
    case 3:
        if (mode != 2) {
            if (data[0] == 0 || data[0] == 0xFFFF) {
                ((TodCoord *)obj->coord2)->super = (void *)root_coord;
            } else if ((parent = kaj_tod_find_obj_inl(table, data[0])) == NULL) {
                ((TodCoord *)obj->coord2)->super = (void *)root_coord;
            } else {
                ((TodCoord *)obj->coord2)->super = parent->coord2;
            }
        }
        break;
    case 8:
        if (table != NULL) {
            switch (flags) {
            case 0:
                kaj_tod_create_obj_inl(table, id);
                break;
            case 1:
                kaj_tod_remove_obj_inl(table, id);
                break;
            }
            rot = flags;
        }
        break;
    }
    return (s32 *)packet + len;
}

void kaj_tod_init_table(TodObjTable *table, TodObj *objs, TodCoord *coords, u8 *params, s32 count) {
    s32 i;

    table->nobj = 0;
    table->top = objs;
    table->maxobj = count;
    for (i = 0; i < count;) {
        i++;
        objs->attribute = 0x80000000;
        objs->id = -1;
        objs->coord2 = coords;
        coords->param = params;
        objs->tmd = 0;
        objs++;
        coords++;
        params += 0x28;
    }
}

TodObj *kaj_tod_find_obj(TodObjTable *table, s32 id) {
    TodObj *p;
    s32 i;

    p = table->top;
    for (i = 0; i < table->nobj; i++, p++) {
        if (id == p->id) {
            break;
        }
    }
    if (i == table->nobj) {
        return NULL;
    }
    return p;
}

TodObj *kaj_tod_create_obj(TodObjTable *table, s32 id) {
    TodObj *p;
    s32 i;

    p = table->top;
    for (i = 0; i < table->nobj; i++, p++) {
        if (p->id == -1) {
            break;
        }
    }
    if (i < table->nobj) {
        p->id = id;
        p->attribute = 0;
        GsInitCoordinate2(NULL, p->coord2);
        p->tmd = 0;
        return p;
    }
    if (i < table->maxobj) {
        p = &table->top[table->nobj++];
        p->id = id;
        p->attribute = 0;
        GsInitCoordinate2(NULL, p->coord2);
        p->tmd = 0;
        return p;
    }
    return NULL;
}

TodObj *kaj_tod_remove_obj(TodObjTable *table, s32 id) {
    TodObj *p;
    s32 i;

    p = table->top;
    for (i = 0; i < table->nobj; i++, p++) {
        if (p->id == id) {
            break;
        }
    }
    if (i < table->nobj) {
        p->id = -1;
        if (i == table->nobj - 1) {
            do {
                p--;
                table->nobj--;
            } while (p->id == -1);
        }
        return p;
    }
    return NULL;
}

s32 *kaj_tod_find_tmd(TodTmd *tmd, s32 *ids, s32 id) {
    s32 *p;
    s32 n;

    p = tmd->objects[0];
    for (n = tmd->nobj; n > 0; n--) {
        if (id == *ids) {
            break;
        }
        p += 7;
        ids++;
    }
    if (n == 0) {
        return NULL;
    }
    return p;
}

void *kaj_tod_set_frame(u32 frame, TodFrame *tod, void *table, s32 *ids, void *tmd, s32 mode, s32 root_coord) {
    void *packet;
    u32 n;
    u32 i;

    packet = tod;
    n = tod->packet_count;
    if (frame < tod->frame) {
        return packet;
    }
    packet = tod + 1;
    for (i = 0; i < n; i++) {
        packet = kaj_tod_set_packet(packet, table, ids, tmd, mode, root_coord);
    }
    return packet;
}

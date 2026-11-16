#include "common.h"
#include "game/types.h"

typedef struct {
    s16 unk0[9];
    u8 pad12[0x2];
    s32 unk14[3];
} Unk_801D0880_38;
typedef struct {
    s32 unk0;
    Unk_801D0880_38 unk4;
    Unk_801D0880_38 unk24;
    void *unk44;
    void *unk48;
    void *unk4C;
} Unk_801D0E58;
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC[1][7];
} Unk_801D1044;
void GsInitCoordinate2(void *super, void *base);
void *kaj_tod_set_packet(void *arg0, void *arg1, s32 *arg2, void *arg3, s32 arg4, s32 arg5);
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
} Unk_801D0880;
void RotMatrix(s16 *r, Unk_801D0880_38 *m);
void ScaleMatrix(Unk_801D0880_38 *m, Unk_801D0880 *v);
void TransMatrix(Unk_801D0880_38 *m, s32 *v);
void GsLinkObject4(void *a, void *b, s32 c);

static inline Unk_801D05F8 *func_801D0EB8_inl(Unk_801DFBB8 *arg0, s32 arg1) {
    Unk_801D05F8 *p;
    s32 i;
    p = arg0->unk0;
    for (i = 0; i < arg0->unk4; i++, p++) {
        if (arg1 == p->unkC) {
            break;
        }
    }
    if (i == arg0->unk4) {
        return NULL;
    }
    return p;
}

static inline Unk_801D05F8 *func_801D0F04_inl(Unk_801DFBB8 *arg0, s32 arg1) {
    Unk_801D05F8 *p;
    s32 i;
    p = arg0->unk0;
    for (i = 0; i < arg0->unk4; i++, p++) {
        if (p->unkC == -1) {
            break;
        }
    }
    if (i < arg0->unk4) {
        p->unkC = arg1;
        p->unk0 = 0;
        GsInitCoordinate2(NULL, p->unk4);
        p->unk8 = 0;
        return p;
    }
    if (i < arg0->unk8) {
        p = &arg0->unk0[arg0->unk4++];
        p->unkC = arg1;
        p->unk0 = 0;
        GsInitCoordinate2(NULL, p->unk4);
        p->unk8 = 0;
        return p;
    }
    return NULL;
}

static inline Unk_801D05F8 *func_801D0FB8_inl(Unk_801DFBB8 *arg0, s32 arg1) {
    Unk_801D05F8 *p;
    s32 i;
    p = arg0->unk0;
    for (i = 0; i < arg0->unk4; i++, p++) {
        if (p->unkC == arg1) {
            break;
        }
    }
    if (i < arg0->unk4) {
        p->unkC = -1;
        if (i == arg0->unk4 - 1) {
            do {
                p--;
                arg0->unk4--;
            } while (p->unkC == -1);
        }
        return p;
    }
    return NULL;
}

static inline s32 *func_801D1044_inl(Unk_801D1044 *arg0, s32 *arg1, s32 arg2) {
    s32 *p;
    s32 n;
    p = arg0->unkC[0];
    for (n = arg0->unk8; n > 0; n--) {
        if (arg2 == *arg1) {
            break;
        }
        p += 7;
        arg1++;
    }
    if (n == 0) {
        return NULL;
    }
    return p;
}

void *kaj_tod_set_packet(void *arg0, void *arg1, s32 *arg2, void *arg3, s32 arg4, s32 arg5) {
    s32 unused[6];
    Unk_801D05F8 tmp;
    Unk_801D0880_38 mtx;
    Unk_801D0880 prm;
    s32 *d = (s32 *)arg0 + 1;
    Unk_801D05F8 *e;
    Unk_801D05F8 *f;
    Unk_801D0E58 *c;
    Unk_801D0880 *r;
    Unk_801D0880_38 *m;
    s32 *q;
    u32 h;
    s32 id;
    s32 type;
    s32 flags;
    s32 len;
    s32 rot;

    h = *(u32 *)arg0;
    id = h & 0xFFFF;
    type = (h >> 16) & 0xF;
    flags = (h >> 20) & 0xF;
    len = (h >> 24) & 0xF;

    e = func_801D0EB8_inl(arg1, id);
    m = &mtx;
    if (e == NULL) {
        e = &tmp;
        r = &prm;
    } else {
        c = e->unk4;
        r = c->unk44;
        m = &c->unk4;
        c->unk0 = 0;
    }

    switch (type) {
    case 0:
        e->unk0 = (e->unk0 & d[0]) | d[1];
        break;
    case 1:
        if (flags & 1) {
            if (flags & 2) {
                r->unk10 += d[0] / 360;
                r->unk12 += d[1] / 360;
                r->unk14 += d[2] / 360;
                d += 3;
            }
            if (flags & 4) {
                r->unk0 = r->unk0 * ((s16 *)d)[0] >> 12;
                r->unk4 = r->unk4 * ((s16 *)d)[1] >> 12;
                r->unk8 = r->unk8 * ((s16 *)d)[2] >> 12;
                d += 2;
            }
            if (flags & 8) {
                r->unk18 += d[0];
                r->unk1C += d[1];
                r->unk20 += d[2];
            }
            RotMatrix(&r->unk10, m);
            ScaleMatrix(m, r);
            TransMatrix(m, &r->unk18);
        } else {
            rot = flags & 2;
            if (rot) {
                r->unk10 = d[0] / 360;
                r->unk12 = d[1] / 360;
                r->unk14 = d[2] / 360;
                d += 3;
                RotMatrix(&r->unk10, m);
            }
            if (flags & 4) {
                r->unk0 = ((s16 *)d)[0];
                r->unk4 = ((s16 *)d)[1];
                r->unk8 = ((s16 *)d)[2];
                d += 2;
                if (!rot) {
                    RotMatrix(&r->unk10, m);
                }
                ScaleMatrix(m, r);
            }
            if (flags & 8) {
                r->unk18 = d[0];
                r->unk1C = d[1];
                r->unk20 = d[2];
                TransMatrix(m, &r->unk18);
            }
        }
        break;
    case 2:
        if (arg3 != NULL) {
            q = func_801D1044_inl(arg3, arg2, (u16)d[0]);
            if (q != NULL) {
                GsLinkObject4(q, e, 0);
            }
        }
        break;
    case 3:
        if (arg4 != 2) {
            if (d[0] == 0 || d[0] == 0xFFFF) {
                ((Unk_801D0E58 *)e->unk4)->unk48 = (void *)arg5;
            } else if ((f = func_801D0EB8_inl(arg1, d[0])) == NULL) {
                ((Unk_801D0E58 *)e->unk4)->unk48 = (void *)arg5;
            } else {
                ((Unk_801D0E58 *)e->unk4)->unk48 = f->unk4;
            }
        }
        break;
    case 8:
        if (arg1 != NULL) {
            switch (flags) {
            case 0:
                func_801D0F04_inl(arg1, id);
                break;
            case 1:
                func_801D0FB8_inl(arg1, id);
                break;
            }
            rot = flags;
        }
        break;
    }
    return (s32 *)arg0 + len;
}

void kaj_tod_init_table(Unk_801DFBB8 *arg0, Unk_801D05F8 *arg1, Unk_801D0E58 *arg2, u8 *arg3, s32 arg4) {
    s32 i;

    arg0->unk4 = 0;
    arg0->unk0 = arg1;
    arg0->unk8 = arg4;
    for (i = 0; i < arg4;) {
        i++;
        arg1->unk0 = 0x80000000;
        arg1->unkC = -1;
        arg1->unk4 = arg2;
        arg2->unk44 = arg3;
        arg1->unk8 = 0;
        arg1++;
        arg2++;
        arg3 += 0x28;
    }
}

Unk_801D05F8 *kaj_tod_find_obj(Unk_801DFBB8 *arg0, s32 arg1) {
    Unk_801D05F8 *p;
    s32 i;

    p = arg0->unk0;
    for (i = 0; i < arg0->unk4; i++, p++) {
        if (arg1 == p->unkC) {
            break;
        }
    }
    if (i == arg0->unk4) {
        return NULL;
    }
    return p;
}

Unk_801D05F8 *kaj_tod_create_obj(Unk_801DFBB8 *arg0, s32 arg1) {
    Unk_801D05F8 *p;
    s32 i;

    p = arg0->unk0;
    for (i = 0; i < arg0->unk4; i++, p++) {
        if (p->unkC == -1) {
            break;
        }
    }
    if (i < arg0->unk4) {
        p->unkC = arg1;
        p->unk0 = 0;
        GsInitCoordinate2(NULL, p->unk4);
        p->unk8 = 0;
        return p;
    }
    if (i < arg0->unk8) {
        p = &arg0->unk0[arg0->unk4++];
        p->unkC = arg1;
        p->unk0 = 0;
        GsInitCoordinate2(NULL, p->unk4);
        p->unk8 = 0;
        return p;
    }
    return NULL;
}

Unk_801D05F8 *kaj_tod_remove_obj(Unk_801DFBB8 *arg0, s32 arg1) {
    Unk_801D05F8 *p;
    s32 i;

    p = arg0->unk0;
    for (i = 0; i < arg0->unk4; i++, p++) {
        if (p->unkC == arg1) {
            break;
        }
    }
    if (i < arg0->unk4) {
        p->unkC = -1;
        if (i == arg0->unk4 - 1) {
            do {
                p--;
                arg0->unk4--;
            } while (p->unkC == -1);
        }
        return p;
    }
    return NULL;
}

s32 *kaj_tod_find_tmd(Unk_801D1044 *arg0, s32 *arg1, s32 arg2) {
    s32 *p;
    s32 n;

    p = arg0->unkC[0];
    for (n = arg0->unk8; n > 0; n--) {
        if (arg2 == *arg1) {
            break;
        }
        p += 7;
        arg1++;
    }
    if (n == 0) {
        return NULL;
    }
    return p;
}

void *kaj_tod_set_frame(u32 arg0, Unk_801D1088 *arg1, void *arg2, s32 *arg3, void *arg4, s32 arg5, s32 arg6) {
    void *p;
    u32 n;
    u32 i;

    p = arg1;
    n = arg1->unk2;
    if (arg0 < arg1->unk4) {
        return p;
    }
    p = arg1 + 1;
    for (i = 0; i < n; i++) {
        p = kaj_tod_set_packet(p, arg2, arg3, arg4, arg5, arg6);
    }
    return p;
}

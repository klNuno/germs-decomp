#include "common.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    u16 unk12;
    u16 unk14;
    s16 unk16;
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
typedef struct Unk_8017D0E0 {
    s32 unk0;
    struct Unk_8017D0E0 *unk4;
    Unk_8018E56C *unk8;
} Unk_8017D0E0;
typedef struct {
    Unk_8017D0E0 *unk0;
    Unk_8017D0E0 *unk4;
    Unk_8017D0E0 *unk8;
    s32 unkC;
} Unk_801DFE5C;
void func_801CCBF4(Unk_801DFE5C *arg0, s32 arg1);
void func_801CCCF4(Unk_801DFE5C *arg0, s32 arg1);
Unk_801DFE5C *D_801DFF0C;
typedef struct { s32 unk0; s32 unk4; s32 unk8; } Unk_80174F54;
typedef struct { u16 unk0; s16 unk2; s16 unk4; s16 unk6; s32 unk8; u8 unkC; u8 unkD; u8 unkE; u8 unkF; s32 unk10; s16 unk14; s16 unk16; s32 unk18; s32 unk1C; s32 unk20; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34; s32 unk38; s32 unk3C; s32 unk40; s32 unk44; s32 unk48; } Unk_801762F4;
typedef struct { u16 unk0; s16 unk2; s32 unk4; s16 unk8; u16 unkA; u8 unkC[0xC0]; } Unk_801767D4;
typedef struct { u16 unk0; s16 unk2; s32 unk4[8]; } Unk_80176890;
typedef struct {
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
typedef struct {
    s32 unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; s32 unk14;
    s32 unk18; s32 unk1C; s32 unk20; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34;
    Unk_80174F54 *unk38; Unk_801762F4 *unk3C; Unk_801767D4 *unk40; Unk_80176890 *unk44;
    s32 unk48; s32 unk4C; Unk_8018F590 *unk50;
} Unk_801E02D8;
extern Unk_801E02D8 D_801E02D8;
void free3(void *ptr);
typedef struct {
    u8 unk0[0x6];
    s16 unk6;
    u8 unk8[0xA];
    u16 unk12;
} Unk_801DFFE8;
typedef struct {
    u16 unk0;
    u16 unk2;
    u8 unk4[0xC];
    s16 unk10;
    u8 unk12[0x4];
    s16 unk16;
} Unk_801DFF08;
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Unk_801CC1E8;
extern Unk_801DFFE8 D_801DFFE8;
Unk_801DFF08 *D_801DFF08;
void UnDeliverEvent(u32 ev, u32 spec);
Unk_801CC1E8 *func_801CC1E8(s32 arg0);
void func_8018DA2C(void *arg0, s16 arg1, s16 arg2);
extern Unk_8018F590 *D_801E0328[];
extern s16 D_801E0368[];
Unk_8018E56C *func_8018E56C(u16 arg0);
void func_8018D2DC(Unk_8018E56C *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_8018E8B8(Unk_8018F590 *arg0, Unk_8018E56C *arg1);
void func_8018E6D8(s32 arg0, Unk_8018E56C *arg1, u16 arg2);
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC[0x4];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    u8 unk1C[0x4];
    s32 unk20;
    s32 unk24;
    s32 unk28;
    u8 unk2C[0x4];
    s16 unk30;
    s16 unk32;
    s16 unk34;
    u8 unk36[0x2];
    s16 unk38;
    s16 unk3A;
    s16 unk3C;
    u8 unk3E[0x2];
    s16 unk40;
    s16 unk42;
    s16 unk44;
    u8 unk46[0x2];
    Unk_8018F590 *unk48;
} Unk_8018F958_3C;
typedef struct {
    u8 unk0[0x22];
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    u8 unk2A[0x2];
    s32 unk2C;
    void *unk30;
    void *unk34;
    void *unk38;
    Unk_8018F958_3C *unk3C;
} Unk_8018F958;
s16 func_801CD000(Unk_801DFE5C *arg0);
Unk_801762F4 *func_801762F4(s16 arg0, u16 arg1);
Unk_8018F590 *func_8018F590(u16 arg0);
void func_8018E344(u16 arg0);
void func_801CCDF8(Unk_801DFE5C *arg0);
void func_8018F91C(void);
extern char D_80170A80[];
void *func_801CC898(u32 size);
void func_801CD54C(s32 arg0, char *arg1, char *arg2, s32 arg3);
extern char D_801DFD4C[];
void func_8018E2F8(s32 arg0);
extern char D_80170AA0[];
void func_801CD78C(s32 arg0, s32 arg1);
extern s32 D_801E6DB4[];
void *func_801D0880(void *arg0, void *arg1, s32 *arg2, void *arg3, s32 arg4, s32 arg5);
typedef struct {
    u16 unk0;
    u16 unk2;
    u32 unk4;
} Unk_801D1088;
void func_80188E0C(s32 arg0);
void *func_801D1088(u32 arg0, Unk_801D1088 *arg1, void *arg2, s32 *arg3, void *arg4, s32 arg5, s32 arg6);
void EnterCriticalSection(void);
void ExitCriticalSection(void);
void DeliverEvent(u32 ev, u32 spec);
typedef struct {
    u8 pad0[0x42];
    u16 unk42;
    u8 pad44[0x10];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    u8 pad60[0x12];
    s16 unk72;
    s16 unk74;
    s16 unk76;
} Unk_801E076C;
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Unk_8018E8B8;
extern Unk_801E076C *D_801E076C[];
void RotMatrix(Unk_8018E8B8 *arg0, void *arg1);
void GsSetLsMatrix(void *m);
s16 func_8017B7CC(void *arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4);
typedef struct {
    u16 unk0;
    u16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} Unk_8018D2DC;
void GsInitCoordinate2(void *super, void *base);
void func_801CD3F0(void *arg0);
void func_801CD028(void *arg0, void *arg1, void *arg2);
void func_801D0E58(void *arg0, void *arg1, void *arg2, void *arg3, s32 arg4);
void *func_801D15C8(u32 arg0);
s32 func_801D14B8(void *arg0);
void func_8018EA00(Unk_8018F958 *arg0);
void func_8018F958(Unk_8018F958 *arg0);
s16 func_8018C750(s16 a);
s32 ratan2(s32 y, s32 x);
typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
} Unk_8018EED4_0;
typedef struct {
    Unk_8018EED4_0 *unk0;
    s32 unk4;
    char **unk8;
} Unk_8018EED4;
s32 atoi(char *s);
void func_8018E610(u16 arg0, s16 arg1, s16 arg2);
void func_8018EC44(Unk_8018F590 *arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s16 arg6, s32 arg7);

INCLUDE_RODATA("asm/nonmatchings/game/8018D2DC", D_80170A80);

INCLUDE_RODATA("asm/nonmatchings/game/8018D2DC", D_80170AA0);

void func_8018D2DC(Unk_8018E56C *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Unk_8018D2DC *h;
    s32 n;
    s32 i;
    s32 j;
    s32 end;
    s32 cnt;
    s32 len;
    s32 k;
    s32 *p;
    s32 *q;
    Unk_8018E8B8 rot;

    if (arg0->unk4 == 0) {
        h = (Unk_8018D2DC *)arg0->unk90;
        arg0->unk2 = (u8)arg2;
        arg0->unk10 = 0;
        arg0->unk0 = h->unk0;
        arg0->unk14 = h->unk2;
        arg0->unk1C = (s32)arg0->unk90 + h->unk8;
        arg0->unk20 = (s32)arg0->unk90 + h->unkC;
        arg0->unk30 = NULL;
        n = h->unk4;
        func_801CD3F0((void *)arg0->unk20);
        if (h->unk10 != 0) {
            func_801CD028(&arg0->unk30, (u8 *)arg0->unk90 + h->unk10, &arg0->unk3C);
        }
        arg0->unk28 = func_801CC898(0xC);
        if (arg0->unk28 == NULL) {
            func_801CD54C(3, "Error Allocating GsOBJTABLE2", D_801DFD4C, 0x8E);
        }
        arg0->unk2C = func_801CC898(n * 16);
        if (arg0->unk2C == NULL) {
            func_801CD54C(3, "Error Allocating GsDOBJ2 Table", D_801DFD4C, 0x92);
        }
        arg0->unk38 = func_801CC898(n * 80);
        if (arg0->unk38 == NULL) {
            func_801CD54C(3, "Error Allocating GsCOORDINATE2", D_801DFD4C, 0x97);
        }
        arg0->unk8C = func_801CC898(n * 40);
        if (arg0->unk8C == NULL) {
            func_801CD54C(3, "Error Allocating GsCOORD2PARAM", D_801DFD4C, 0x9C);
        }
        arg0->unk24 = func_801CC898(arg0->unk14 * 4);
        if (arg0->unk24 == NULL) {
            func_801CD54C(3, "Error Allocating TOD Table", D_801DFD4C, 0xA0);
        }
        p = (s32 *)((u8 *)arg0->unk90 + h->unk14);
        for (i = 0; i < arg0->unk14; i++) {
            len = *p++;
            ((s32 **)arg0->unk24)[i] = p;
            p += len >> 2;
        }
        func_801D0E58(arg0->unk28, arg0->unk2C, arg0->unk38, arg0->unk8C, n);
        arg0->unk54 = 0;
        arg0->unk58 = 0;
        arg0->unk5C = 0;
        if (arg1 == 0) {
            arg0->unk34 = (s32)&arg0->unk3C;
            GsInitCoordinate2(NULL, &arg0->unk3C);
        } else {
            arg0->unk34 = arg1;
            GsInitCoordinate2((void *)arg1, &arg0->unk3C);
        }
        rot.unk0 = 0;
        rot.unk2 = 0;
        rot.unk4 = 0;
        RotMatrix(&rot, &arg0->unk40);
        q = ((s32 **)arg0->unk24)[(u16)arg3];
        q++;
        end = *q++;
        j = q[1];
        for (i = j; i < j + end; i++) {
            cnt = ((u16 *)q)[1];
            q += 2;
            for (k = 0; k < cnt; k++) {
                q = func_801D0880(q, arg0->unk28, (s32 *)arg0->unk1C, (void *)arg0->unk20, 0, arg0->unk34);
            }
        }
        arg0->unk16 = arg3;
        arg0->unk18 = (s32)q;
        arg0->unk4 = 1;
        arg0->unk3C = 0;
    }
}

void func_8018D5F8(s16 *arg0) {
    Unk_8018E56C *mod;
    Unk_8018E56C **pp = &mod;
    Unk_801762F4 *e;
    u16 id;

    *pp = func_801CC898(0x94);
    if (*pp == NULL) {
        func_801CD54C(3, D_80170A80, D_801DFD4C, 0x56);
    }
    (*pp)->unk2 = 3;
    (*pp)->unk10 = 0;
    (*pp)->unk4 = 0;
    (*pp)->unk6 = 0;
    (*pp)->unk8 = 0;
    (*pp)->unkA = 0;
    (*pp)->unkC = -1;
    (*pp)->unkE = -1;
    mod->unk90 = arg0;
    id = *arg0;
    if (id < 0x440) {
        e = func_801762F4(1, id);
        if (e != NULL && e->unkF == 6) {
            func_8018D2DC(mod, 0, 0, 8);
        } else {
            func_8018D2DC(mod, 0, 0, 0);
        }
    }
    func_8018E2F8((s32)mod);
}

void func_8018D6DC(s32 *arg0, s32 *arg1) {
    Unk_801DFE5C *list = D_801DFF0C;
    Unk_8018E56C *item;
    Unk_8018E56C *t;
    s32 n;
    s32 i;
    s32 *p;

    if (list->unkC == 0) {
        item = NULL;
    } else {
        list->unk8 = list->unk0;
        while (1) {
            t = list->unk8->unk8;
            if (t != NULL && (s32 *)t->unk90 == arg0) {
                item = t;
                break;
            }
            if (func_801CD000(list) != 0) {
                item = NULL;
                break;
            }
            list->unk8 = list->unk8->unk4;
        }
    }
    if (item != NULL) {
        n = arg0 - arg1;
        if (item->unk18 != 0) {
            item->unk18 -= n * 4;
        }
        item->unk1C -= n * 4;
        item->unk20 -= n * 4;
        func_801CD78C(item->unk20, n);
        for (i = 0; i < item->unk14; i++) {
            ((s32 *)item->unk24)[i] -= n * 4;
        }
        *(void **)item->unk28 = item->unk2C;
        p = (s32 *)item->unk2C;
        for (i = 0; i < ((s32 *)item->unk28)[1]; i++, p += 4) {
            if (p[2] != 0) {
                p[2] -= n * 4;
            }
        }
        if (item->unk30 != NULL) {
            ((s32 *)item->unk30)[2] -= n * 4;
            func_801CD78C((s32)arg1 + arg1[4], n);
        }
        item->unk90 = (s16 *)arg1;
    }
}

void func_8018D8B8(void) {
    Unk_801DFE5C *list = D_801DFF0C;
    Unk_8018E56C *mod;
    Unk_801762F4 *e;
    Unk_8018F590 *f;
    u16 id;

    if (list->unkC == 0) {
        return;
    }
    list->unk8 = list->unk0;
    while (1) {
        mod = list->unk8->unk8;
        if (mod != NULL && mod->unk6 == 0) {
            id = mod->unk0;
            if (id >= 0x440) {
                f = func_8018F590(id - 0x440);
                if (f != NULL) {
                    f->unk1B = 1;
                }
            } else {
                e = func_801762F4(1, mod->unk0);
                if (e != NULL) {
                    e->unk4 = 0;
                }
            }
            if (mod != NULL) {
                if (mod->unk4 != 0) {
                    free3(mod->unk28);
                    free3(mod->unk2C);
                    free3(mod->unk38);
                    free3(mod->unk8C);
                    free3(mod->unk24);
                }
                if (mod->unk30 != NULL) {
                    free3(mod->unk30);
                }
                if (mod->unk6 != 0) {
                    free3(mod->unk90);
                }
                free3(mod);
            }
            func_801CCDF8(list);
        }
        if (func_801CD000(list) != 0) {
            break;
        }
        list->unk8 = list->unk8->unk4;
    }
}

void func_8018DA2C(void *arg0, s16 arg1, s16 arg2) {
    u16 *p;
    s32 i;
    s32 n;

    if (((Unk_8018E56C *)arg0) != NULL && ((Unk_8018E56C *)arg0)->unk4 != 0) {
        ((Unk_8018E56C *)arg0)->unk16 = arg1;
        p = ((u16 **)((Unk_8018E56C *)arg0)->unk24)[arg1];
        p += 2;
        ((Unk_8018E56C *)arg0)->unkE = p[0];
        p += 2;
        ((Unk_8018E56C *)arg0)->unkC = p[2];
        n = p[1];
        p += 4;
        for (i = 0; i < n; i++) {
            p = func_801D0880(p, ((Unk_8018E56C *)arg0)->unk28, (s32 *)((Unk_8018E56C *)arg0)->unk1C, (void *)((Unk_8018E56C *)arg0)->unk20, 2, ((Unk_8018E56C *)arg0)->unk34);
        }
        ((Unk_8018E56C *)arg0)->unk18 = (s32)p;
        ((Unk_8018E56C *)arg0)->unkA = 2;
        if (((Unk_8018E56C *)arg0)->unkE >= 2) {
            if (arg2 == 0) {
                ((Unk_8018E56C *)arg0)->unk10 = 0;
                ((Unk_8018E56C *)arg0)->unkE = ((Unk_8018E56C *)arg0)->unkC + ((Unk_8018E56C *)arg0)->unkE - 1;
            } else if (arg2 < 0) {
                ((Unk_8018E56C *)arg0)->unk10 = 1;
                ((Unk_8018E56C *)arg0)->unkE = ((Unk_8018E56C *)arg0)->unkC + ((Unk_8018E56C *)arg0)->unkE - 1;
            } else {
                ((Unk_8018E56C *)arg0)->unk10 = 0;
                ((Unk_8018E56C *)arg0)->unkE = ((Unk_8018E56C *)arg0)->unkC + arg2 - 1;
            }
            ((Unk_8018E56C *)arg0)->unk8 = 1;
            ((Unk_8018E56C *)arg0)->unk12 = 1;
            if (D_801E6DB4[0] == 4 || D_801E6DB4[0] == 5) {
                ((Unk_8018E56C *)arg0)->unk12 = 2;
            } else if (D_801E6DB4[0] >= 6) {
                ((Unk_8018E56C *)arg0)->unk12 = 3;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", func_8018DBA4);

void func_8018DE58(void) {
    Unk_801DFE5C *list = D_801DFF0C;
    Unk_8018E56C *mod;
    s16 cnt;
    s32 k;

    if (list->unkC == 0) {
        return;
    }
    list->unk8 = list->unk0;
    while (1) {
        mod = list->unk8->unk8;
        if (mod != NULL && mod->unk4 != 0 && mod->unk8 != 0) {
            cnt = mod->unk12;
            {
again:
                if (mod->unkC < mod->unkE) {
                    if ((u16)mod->unk2 == 1 && (u16)mod->unk16 == 2) {
                        func_80188E0C(mod->unkC);
                    }
                    mod->unkC++;
                    mod->unk18 = (s32)func_801D1088(mod->unkC, (Unk_801D1088 *)mod->unk18, mod->unk28, (s32 *)mod->unk1C, (void *)mod->unk20, (u16)mod->unkA, mod->unk34);
                    cnt--;
                    if (cnt > 0) {
                        goto again;
                    }
                } else {
                    mod->unk18 = (s32)func_801D1088(mod->unkE, (Unk_801D1088 *)mod->unk18, mod->unk28, (s32 *)mod->unk1C, (void *)mod->unk20, (u16)mod->unkA, mod->unk34);
                    k = (u16)mod->unk2;
                    mod->unk8 = 0;
                    mod->unkC = -1;
                    mod->unkE = -1;
                    if (k != 0 && (k != 1 || (u16)mod->unk16 != 5)) {
                        EnterCriticalSection();
                        D_801DFF08 = (Unk_801DFF08 *)mod;
                        DeliverEvent(0xF3000002, 2);
                        ExitCriticalSection();
                    }
                }
            }
        }
        if (func_801CD000(list) != 0) {
            break;
        }
        list->unk8 = list->unk8->unk4;
    }
}

void func_8018E03C(Unk_8018E56C **arg0, u32 arg1) {
    *arg0 = func_801CC898(0x94);
    if (*arg0 == NULL) {
        func_801CD54C(3, D_80170A80, D_801DFD4C, 0x56);
    }
    (*arg0)->unk2 = 3;
    (*arg0)->unk10 = 0;
    (*arg0)->unk4 = 0;
    (*arg0)->unk6 = 0;
    (*arg0)->unk8 = 0;
    (*arg0)->unkA = 0;
    (*arg0)->unkC = -1;
    (*arg0)->unkE = -1;
    if (arg1 != 0) {
        (*arg0)->unk90 = func_801CC898(arg1);
        if ((*arg0)->unk90 == NULL) {
            func_801CD54C(3, D_80170AA0, D_801DFD4C, 0x64);
        }
        (*arg0)->unk6 = 1;
    }
}

void func_8018E144(Unk_8018E56C *arg0) {
    if (arg0 != NULL) {
        if (arg0->unk4 != 0) {
            free3(arg0->unk28);
            free3(arg0->unk2C);
            free3(arg0->unk38);
            free3(arg0->unk8C);
            free3(arg0->unk24);
        }
        if (arg0->unk30 != NULL) {
            free3(arg0->unk30);
        }
        if (arg0->unk6 != 0) {
            free3(arg0->unk90);
        }
        free3(arg0);
    }
}

void func_8018E1F0(s16 *arg0) {
    Unk_801DFE5C *list = D_801DFF0C;
    Unk_8018E56C *item;
    Unk_8018E56C *t;
    Unk_801762F4 *e;
    Unk_8018F590 *f;
    s16 id;

    if (list->unkC == 0) {
        item = NULL;
    } else {
        list->unk8 = list->unk0;
        while (1) {
            t = list->unk8->unk8;
            if (t != NULL && t->unk90 == arg0) {
                item = t;
                break;
            }
            if (func_801CD000(list) != 0) {
                item = NULL;
                break;
            }
            list->unk8 = list->unk8->unk4;
        }
    }
    if (item != NULL) {
        id = *item->unk90;
        func_8018E344(id);
        if (id >= 0x440) {
            f = func_8018F590(id - 0x440);
            if (f != NULL) {
                f->unk1B = 1;
            }
        } else {
            e = func_801762F4(1, id);
            if (e != NULL) {
                e->unk4 = 0;
            }
        }
    }
}

void func_8018E2F8(s32 arg0) {
    if (D_801DFF0C->unkC == 0) {
        func_801CCBF4(D_801DFF0C, arg0);
    } else {
        D_801DFF0C->unk8 = D_801DFF0C->unk4;
        func_801CCCF4(D_801DFF0C, arg0);
    }
}

void func_8018E344(u16 arg0) {
    Unk_801DFE5C *list = D_801DFF0C;
    Unk_8018E56C *mod;

    if (list->unkC == 0) {
        return;
    }
    mod = func_8018E56C(arg0);
    if (mod == NULL) {
        return;
    }
    list->unk8 = list->unk0;
    while (1) {
        if (mod == list->unk8->unk8) {
            if (mod != NULL) {
                if (mod->unk4 != 0) {
                    free3(mod->unk28);
                    free3(mod->unk2C);
                    free3(mod->unk38);
                    free3(mod->unk8C);
                    free3(mod->unk24);
                }
                if (mod->unk30 != NULL) {
                    free3(mod->unk30);
                }
                if (mod->unk6 != 0) {
                    free3(mod->unk90);
                }
                free3(mod);
            }
            func_801CCDF8(list);
            return;
        }
        if (func_801CD000(list) != 0) {
            break;
        }
        list->unk8 = list->unk8->unk4;
    }
}

void func_8018E47C(void) {
    Unk_801DFE5C *list = D_801DFF0C;
    Unk_8018E56C *mod;

    while (1) {
        if (list->unkC == 0) {
            break;
        }
        mod = list->unk8->unk8;
        if (mod != NULL) {
            if (mod->unk4 != 0) {
                free3(mod->unk28);
                free3(mod->unk2C);
                free3(mod->unk38);
                free3(mod->unk8C);
                free3(mod->unk24);
            }
            if (mod->unk30 != NULL) {
                free3(mod->unk30);
            }
            if (mod->unk6 != 0) {
                free3(mod->unk90);
            }
            free3(mod);
        }
        func_801CCDF8(list);
    }
    func_8018F91C();
}

Unk_8018E56C *func_8018E56C(u16 arg0) {
    Unk_801DFE5C *list = D_801DFF0C;
    Unk_8018E56C *item;

    if (list->unkC == 0) {
        return NULL;
    }
    list->unk8 = list->unk0;
    while (1) {
        item = list->unk8->unk8;
        if (item != NULL && *item->unk90 == arg0) {
            return item;
        }
        if (func_801CD000(list) != 0) {
            break;
        }
        list->unk8 = list->unk8->unk4;
    }
    return NULL;
}

void func_8018E610(u16 arg0, s16 arg1, s16 arg2) {
    Unk_801DFE5C *list = D_801DFF0C;
    Unk_8018E56C *item;

    if (list->unkC == 0) {
        item = NULL;
    } else {
        list->unk8 = list->unk0;
        while (1) {
            item = list->unk8->unk8;
            if (item != NULL && *item->unk90 == arg0) {
                break;
            }
            if (func_801CD000(list) != 0) {
                item = NULL;
                break;
            }
            list->unk8 = list->unk8->unk4;
        }
    }
    func_8018DA2C(item, arg1, arg2);
}

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", func_8018E6D8);

s32 func_8018E7EC(void) {
    Unk_801DFFE8 *s = &D_801DFFE8;
    Unk_801CC1E8 *e;

    UnDeliverEvent(0xF3000002, 2);
    e = func_801CC1E8(0x200);
    if (e != NULL) {
        e->unk8 = D_801DFF08->unk0;
        e->unkC = D_801DFF08->unk2;
    }
    if (D_801DFF08->unk2 == 2) {
        if (s->unk12 & 8) {
            s->unk12 &= ~8;
            if (s->unk12 == 0) {
                s->unk6 = 1;
            }
        }
    }
    if (D_801DFF08->unk10 != 0) {
        D_801DFF08->unk10 = 0;
        func_8018DA2C(D_801DFF08, D_801DFF08->unk16, -1);
    }
    return 0;
}

void func_8018E8B8(Unk_8018F590 *arg0, Unk_8018E56C *arg1) {
    Unk_801E076C *g = D_801E076C[0];
    Unk_8018E8B8 rot;

    arg1->unk54 = arg0->unk8 - g->unk72 * 12500;
    arg1->unk58 = arg0->unkC + g->unk74 * 32000;
    arg1->unk5C = arg0->unk10 - g->unk76 * 12500;
    rot.unk0 = (arg0->unk14 << 12) / 360;
    rot.unk2 = (arg0->unk16 << 12) / 360;
    rot.unk4 = (arg0->unk18 << 12) / 360;
    RotMatrix(&rot, arg1->unk40);
    arg1->unk3C = 0;
}

void func_8018EA00(Unk_8018F958 *arg0) {
    Unk_8018F958_3C *p = arg0->unk3C;
    Unk_8018F590 *e = p->unk48;
    Unk_8018E56C *item;

    e->unk8 = p->unk0 + p->unk20 * arg0->unk24 / arg0->unk26;
    e->unkC = p->unk4 + p->unk24 * arg0->unk24 / arg0->unk26;
    e->unk10 = p->unk8 + p->unk28 * arg0->unk24 / arg0->unk26;
    e->unk14 = p->unk30 + p->unk40 * arg0->unk24 / arg0->unk26;
    e->unk16 = p->unk32 + p->unk42 * arg0->unk24 / arg0->unk26;
    e->unk18 = p->unk34 + p->unk44 * arg0->unk24 / arg0->unk26;
    item = func_8018E56C(e->unk6);
    if (item != NULL) {
        func_8018E8B8(e, item);
    }
}

void func_8018EC44(Unk_8018F590 *arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s16 arg6, s32 arg7) {
    Unk_8018F958 *t;
    Unk_8018F958_3C *p;

    t = func_801D15C8(0x4C);
    t->unk22 = 5;
    t->unk28 = 1;
    t->unk2C = 2;
    t->unk30 = func_8018EA00;
    t->unk24 = 0;
    t->unk34 = func_8018F958;
    t->unk38 = func_8018F958;
    t->unk26 = arg7 * 30;
    if (arg0->unk8 == arg1 && arg0->unkC == arg2 && arg0->unk10 == arg3 &&
        arg0->unk14 == arg4 && arg0->unk16 == arg5 && arg0->unk18 == arg6) {
        t->unk26 = 0;
    }
    p = t->unk3C;
    p->unk48 = arg0;
    p->unk0 = arg0->unk8;
    p->unk4 = arg0->unkC;
    p->unk8 = arg0->unk10;
    p->unk30 = arg0->unk14;
    p->unk32 = arg0->unk16;
    p->unk34 = arg0->unk18;
    p->unk10 = arg1;
    p->unk14 = arg2;
    p->unk18 = arg3;
    p->unk38 = arg4;
    p->unk3A = arg5;
    p->unk3C = arg6;
    p->unk20 = arg1 - arg0->unk8;
    p->unk24 = arg2 - arg0->unkC;
    p->unk28 = arg3 - arg0->unk10;
loop:
    p->unk40 = arg4 - arg0->unk14;
    p->unk42 = arg5 - arg0->unk16;
    p->unk44 = arg6 - arg0->unk18;
    if (p->unk40 > 180) {
        arg4 -= 360;
        goto loop;
    }
    if (p->unk40 < -180) {
        arg4 += 360;
        goto loop;
    }
    if (p->unk42 > 180) {
        arg5 -= 360;
        goto loop;
    }
    if (p->unk42 < -180) {
        arg5 += 360;
        goto loop;
    }
    if (p->unk44 > 180) {
        arg6 -= 360;
        goto loop;
    }
    if (p->unk44 < -180) {
        arg6 += 360;
        goto loop;
    }
    arg0->unk1C = func_801D14B8(t);
    arg0->unk1E = 1;
}

void func_8018EED4(Unk_8018EED4 *arg0, Unk_8018E56C *arg1) {
    Unk_801E02D8 *p = &D_801E02D8;
    Unk_8018F590 *e = p->unk50;
    Unk_8018EED4_0 *cmd = arg0->unk0;
    u16 id = cmd->unk4;
    Unk_8018F590 *found;
    Unk_8018F590 *t;
    Unk_8018E56C *obj;
    s32 i;
    Unk_8018F590 *tb;
    s16 *f;
    s32 x, y, z;
    s32 a, b;

    if (p->unk20 == 0) {
        found = NULL;
    } else {
        for (i = 0; i < p->unk20; i++, e++) {
            if (e->unk0 == id) {
                found = e;
                goto done;
            }
        }
        found = NULL;
    }
done:
    if (found == NULL) {
        return;
    }
    switch (cmd->unk2) {
    case 0:
        found->unk2 = atoi(arg0->unk8[0]);
        break;
    case 1:
        found->unk6 = atoi(arg0->unk8[0]);
        tb = D_801E0328[0];
        f = D_801E0368;
        t = tb + cmd->unk4;
        if (f[cmd->unk4] == 0) {
            break;
        }
        if (t->unk1A == 0) {
            t->unk1A = 1;
            t->unk8 *= 10;
            t->unkC *= 10;
            t->unk10 *= 10;
        }
        t->unk1B = 1;
        t->unk1C = -1;
        t->unk1E = 0;
        obj = func_8018E56C(t->unk6);
        if (obj == NULL) {
            break;
        }
        if (obj->unk4 == 0) {
            func_8018D2DC(obj, 0, 2, 0);
        }
        func_8018E8B8(t, obj);
        t->unk1B = 2;
        break;
    case 3:
        x = atoi(arg0->unk8[0]) * 10;
        y = atoi(arg0->unk8[1]) * 10;
        z = atoi(arg0->unk8[2]) * 10;
        a = atoi(arg0->unk8[3]);
        b = atoi(arg0->unk8[4]);
        if (atoi(arg0->unk8[5]) == 1) {
            arg1->unk6 = 4;
            arg1->unk12 |= 0x10;
        }
        func_8018EC44(found, x, y, z, 0, a, 0, b);
        break;
    case 4:
        if (atoi(arg0->unk8[1]) == 1) {
            arg1->unk6 = 4;
            arg1->unk12 |= 8;
        }
        ((void (*)())func_8018E610)((s16)found->unk6, (s16)atoi(arg0->unk8[0]), (s16)atoi(arg0->unk8[2]));
        break;
    }
}

void func_8018F234(void) {
    Unk_8018F590 *p;
    Unk_801E076C *cam;
    Unk_8018E56C *mod;
    Unk_8018E56C *mod2;
    Unk_801E02D8 *g;
    s32 i;

    g = &D_801E02D8;
    p = g->unk50;
    cam = D_801E076C[0];
    if (g->unk20 != 0) {
        for (i = 0; i < g->unk20; i++, p++) {
            if (p->unk1A != 0 && p->unk1B != 0) {
                if (p->unk1B == 1) {
                    mod = func_8018E56C(p->unk6);
                    if (mod != NULL) {
                        if (mod->unk4 == 0) {
                            func_8018D2DC(mod, 0, 2, 0);
                        }
                        func_8018E8B8(p, mod);
                        p->unk1B = 2;
                    }
                } else if (p->unk2 != 0 && p->unk1E == 0 && p->unk0 != 0) {
                    p->unk16 = func_8018C750((ratan2(cam->unk54 + cam->unk72 * 12500 - p->unk8,
                                                     cam->unk5C + cam->unk76 * 12500 - p->unk10) * 360 >> 12) - 180);
                    mod2 = func_8018E56C(p->unk6);
                    if (mod2 != NULL) {
                        func_8018E8B8(p, mod2);
                    }
                }
            }
        }
    }
}

void func_8018F428(u16 arg0, s16 arg1) {
    Unk_8018F590 *e;
    s16 *f;
    Unk_8018F590 *b;
    Unk_8018E56C *mod;

    b = D_801E0328[0];
    f = D_801E0368;
    e = b + arg0;
    if (f[arg0] != 0 || arg1 != 0) {
        if (e->unk1A == 0) {
            e->unk1A = 1;
            e->unk8 *= 10;
            e->unkC *= 10;
            e->unk10 *= 10;
        }
        e->unk1B = 1;
        e->unk1C = -1;
        e->unk1E = 0;
        mod = func_8018E56C(e->unk6);
        if (mod != NULL) {
            if (mod->unk4 == 0) {
                func_8018D2DC(mod, 0, 2, 0);
            }
            func_8018E8B8(e, mod);
            e->unk1B = 2;
        }
    }
}

void func_8018F53C(void) {
    Unk_801E02D8 *p = &D_801E02D8;
    if (p->unk20 != 0) {
        if (p->unk50 != NULL) {
            free3(p->unk50);
        }
        p->unk20 = 0;
        p->unk50 = NULL;
    }
}

Unk_8018F590 *func_8018F590(u16 arg0) {
    Unk_801E02D8 *p = &D_801E02D8;
    s32 n = p->unk20;
    Unk_8018F590 *e = p->unk50;
    s32 i;

    if (n == 0) {
        return NULL;
    }
    for (i = 0; i < n; i++, e++) {
        if (e->unk0 == arg0) {
            return e;
        }
    }
    return NULL;
}

void func_8018F5E8(s32 arg0, s32 arg1, s32 arg2) {
    Unk_801E02D8 *p = &D_801E02D8;
    Unk_8018F590 *e = p->unk50;
    Unk_8018E56C *mod;
    s32 i;

    if (p->unk20 == 0) {
        return;
    }
    for (i = 0; i < p->unk20; i++, e++) {
        if (e->unk1A != 0 && e->unk2 != 0 && e->unk1B == 2) {
            mod = func_8018E56C(e->unk6);
            if (mod != NULL) {
                mod->unk54 = e->unk8 - arg0;
                mod->unk58 = e->unkC - arg1;
                mod->unk5C = e->unk10 - arg2;
                mod->unk3C = 0;
            }
        }
    }
}

void func_8018F6E8(s32 arg0) {
    Unk_801E02D8 *p = &D_801E02D8;
    Unk_8018F590 *e = p->unk50;
    Unk_8018E56C *mod;
    s32 i;

    if (p->unk20 == 0) {
        return;
    }
    for (i = 0; i < p->unk20; i++, e++) {
        if (e != NULL && e->unk1A != 0 && e->unk2 != 0 && e->unk1B == 2) {
            mod = func_8018E56C(e->unk6);
            if (mod != NULL && mod->unk4 != 0) {
                func_8018E6D8(arg0, mod, e->unk4);
            }
        }
    }
}

s16 func_8018F7D0(s32 arg0, s32 arg1, s32 arg2) {
    Unk_801E02D8 *p = &D_801E02D8;
    Unk_8018F590 *e = p->unk50;
    Unk_8018E56C *mod;
    s32 i;

    if (p->unk20 == 0) {
        return -2;
    }
    for (i = 0; i < p->unk20; i++, e++) {
        if (e->unk1A != 0 && e->unk2 != 0 && e->unk1B == 2) {
            mod = func_8018E56C(e->unk6);
            if (mod != NULL && mod->unk4 != 0 && mod->unk30 != NULL) {
                GsSetLsMatrix(mod->unk40);
                if (func_8017B7CC(mod->unk30, arg0, arg1, arg2, 1) != 0) {
                    return e->unk0;
                }
            }
        }
    }
    return -2;
}

void func_8018F91C(void) {
    Unk_801E02D8 *p = &D_801E02D8;
    Unk_8018F590 *e = p->unk50;
    s32 i;

    for (i = 0; i < p->unk20; i++, e++) {
        e->unk1B = 0;
    }
}

void func_8018F958(Unk_8018F958 *arg0) {
    Unk_801DFFE8 *s = &D_801DFFE8;
    Unk_8018F958_3C *p = arg0->unk3C;
    Unk_8018F590 *e = p->unk48;
    Unk_8018E56C *item;

    e->unk8 = p->unk10;
    e->unkC = p->unk14;
    e->unk10 = p->unk18;
    e->unk14 = p->unk38;
    e->unk16 = p->unk3A;
    e->unk18 = p->unk3C;
    e->unk1E = 0;
    item = func_8018E56C(e->unk6);
    if (item != NULL) {
        func_8018E8B8(e, item);
    }
    if (s->unk12 & 0x10) {
        s->unk12 &= ~0x10;
        if (s->unk12 == 0) {
            s->unk6 = 1;
        }
    }
    e->unk1C = -1;
}

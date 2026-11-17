#ifndef PSYQ_LIBC_H
#define PSYQ_LIBC_H

#include "types.h"

/* LIBC functions the game calls. */

s32 atoi(char *s);
void *memcpy(void *dst, const void *src, unsigned int n);
void *memmove(void *dst, const void *src, u32 n);
void *memset(void *dst, s32 c, u32 n);
int printf(const char *fmt, ...);
void qsort(void *base, s32 n, s32 size, s32 (*cmp)());
int rand(void);
int sprintf(char *buf, const char *fmt, ...);
void srand(u32 seed);
s32 strlen(char *s);
int strncmp(const char *a, const char *b, int n);
char *strncpy(char *dst, char *src, u32 n);

#endif

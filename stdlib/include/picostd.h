#pragma once
#include "systypes.h"

void *memcpy(void *restrict s1, const void *restrict s2, size_t n);
void *memset(void *s, int c, size_t n);
int strcmp(const char *p1, const char *p2);
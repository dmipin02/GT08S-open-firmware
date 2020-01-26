#pragma once
#include <systypes.h>

#define SystemMemorySize (3 * 1024 * 1024)

size_t InitializeMemoryPool(void);
void *malloc(size_t size);
void free(void *ptr);
void *realloc(void *ptr, size_t size);
void *calloc(size_t nelem, size_t elem_size);
uint32_t GetSysMemoryAddress(void);
bool IsDynamicMemory(void *Memory);
size_t GetTotalUsedMemory(void);
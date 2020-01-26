#pragma once

#define swab32(x) ((uint32_t)((((uint32_t)(x) & (uint32_t)0x000000ffUL) << 24) | (((uint32_t)(x) & (uint32_t)0x0000ff00UL) << 8) | (((uint32_t)(x) & (uint32_t)0x00ff0000UL) >> 8) | (((uint32_t)(x) & (uint32_t)0xff000000UL) >> 24)))

typedef void *pHANDLE; //A temporary definition, may not be necessary in the future.
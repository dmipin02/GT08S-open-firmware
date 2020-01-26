#pragma once
#include <mt6261.h>
#include <drivers/tcmcache.h>

typedef enum
{
    MR_BOOTCODE = 0,        //Boot jump code
    MR_FB0RB1   = 2,        //Flash - Bank0, RAM - Bank1
    MR_FB1RB0   = 3         //Flash - Bank1, RAM - Bank0
} MREMAP;


#define EMI_REMAP                   (*(volatile uint16_t*)(BOOT_ENG_base))
#define EMI_REMAP_MODE_MASK         0x03


void EMI_MemoryRemap(MREMAP Mode);
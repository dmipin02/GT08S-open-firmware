#pragma once
#include <utils.h>
#include <systypes.h>
#include <drivers/evmngr.h>

#define LRTMRHWTIMER GP_TIMER1
#define LRTMRFrequency 100

typedef enum tag_MRFLAGS
{
    TF_ENABLED    = (1 << 0),
    TF_AUTOREPEAT = (1 << 1),
    TF_DIRECT     = (1 << 2)
} TMRFLAGS;

typedef struct tag_TIMER *pTIMER;
typedef struct tag_TIMER
{
    TMRFLAGS   Flags;
    uint32_t   Interval;
    int32_t    StartTicks;
    pHANDLE    Parent;
    void       (*Handler)(pTIMER);
} TTIMER, *pTIMER;

bool LRT_Initialize(void);
pTIMER LRT_Create(uint32_t Interval, pHANDLE Parent, void (*Handler)(pTIMER), TMRFLAGS Flags);
bool LRT_Destroy(pTIMER Timer);
bool LRT_Start(pTIMER Timer);
bool LRT_Stop(pTIMER Timer);
bool LRT_SetMode(pTIMER Timer, TMRFLAGS Flags);
#pragma once
#include <drivers/dlist.h>
#include <systypes.h>
#include <drivers/lrtimer.h>

typedef enum tag_EVTYPE
{
    ET_UNKNOWN,
    /* Touchscreen events */
    ET_PENPRESSED,
    ET_PENRELEASED,
    ET_PENMOVED,
    /* GUI events */
    ET_ONPAINT,
    /* System events */
    ET_PWRKEY,
    ET_ONTIMER
} TEVTYPE;

typedef struct tag_EVENT
{
    TEVTYPE  Event;
    void     *Object;
    uint32_t ParamSz;
    uint8_t  Param[];
} TEVENT, *pEVENT;

bool EM_Initialize(void);
bool EM_PostEvent(TEVTYPE Type, void *Object, void *Param, uint32_t ParamSz);
void EM_ProcessEvents(void);

#include <drivers/lrtimer.h>
#include <drivers/dlist.h>
#include <drivers/gpt.h>

#define LRTMININTERVAL  (1000000 / LRTMRFrequency)

pDLIST TimersList;

void LRT_GPTHandler(void)
{
    if (TimersList != NULL)
    {
        pDLITEM tmrItem = DL_GetFirstItem(TimersList);

        while(tmrItem != NULL)
        {
            pTIMER tmpLRT = tmrItem->Data;

            if (tmpLRT != NULL)
            {
                if (tmpLRT->Flags & TF_ENABLED)
                {
                    int32_t CurrTicks = USC_GetCurrentTicks();
                    int32_t DeltaTicks = CurrTicks - tmpLRT->StartTicks;

                    if (DeltaTicks >= tmpLRT->Interval)
                    {
                        if (tmpLRT->Handler != NULL)
                        {
                            if (tmpLRT->Flags & TF_DIRECT) tmpLRT->Handler(tmpLRT);
                            else EM_PostEvent(ET_ONTIMER, tmpLRT->Parent, &tmpLRT, sizeof(pTIMER));
                        }
                        if (tmpLRT->Flags & TF_AUTOREPEAT) tmpLRT->StartTicks = CurrTicks;
                        else tmpLRT->Flags &= ~TF_ENABLED;
                    }
                }
            }
            else
            {
                pDLITEM tmpItem = tmrItem;

                tmrItem = DL_GetNextItem(tmpItem);
                DL_DeleteItem(TimersList, tmpItem);
                continue;
            }
            tmrItem = DL_GetNextItem(tmrItem);
        }
    }
}

bool LRT_Initialize(void)
{
    GPT_InitializeTimers();

    if (TimersList == NULL) TimersList = DL_Create(0);
    if (TimersList != NULL)
    {
        if (GPT_SetupTimer(LRTMRHWTIMER, LRTMRFrequency, true, LRT_GPTHandler, true) &&
                GPT_StartTimer(LRTMRHWTIMER))
            return true;
        GPT_SetupTimer(LRTMRHWTIMER, 0, false, NULL, false);
    }
    return false;
}

pTIMER LRT_Create(uint32_t Interval, pHANDLE Parent, void (*Handler)(pTIMER), TMRFLAGS Flags)
{
    pTIMER tmpTimer = NULL;

    if (Interval)
    {
        Interval *= 1000;                                                                           // Set interval to us

        if (Interval < LRTMININTERVAL) Interval = LRTMININTERVAL;
        tmpTimer = malloc(sizeof(TTIMER));
        if (tmpTimer != NULL)
        {
            tmpTimer->Flags = Flags;
            tmpTimer->Interval = Interval;
            tmpTimer->StartTicks = USC_GetCurrentTicks();
            tmpTimer->Parent = Parent;
            tmpTimer->Handler = Handler;
            if (!DL_AddItem(TimersList, tmpTimer))
            {
                free(tmpTimer);
                tmpTimer = NULL;
            }
        }
    }
    return tmpTimer;
}

bool LRT_Destroy(pTIMER Timer)                                                                   // Do not use this method in the timer handler in TFDIRECT mode!!!
{
    if (Timer != NULL)
    {
        pDLITEM tmpItem = DL_FindItemByData(TimersList, Timer, NULL);

        if (tmpItem != NULL)
        {
            free(tmpItem->Data);
            DL_DeleteItem(TimersList, tmpItem);
            return true;
        }
    }
    return false;
}

bool LRT_Start(pTIMER Timer)
{
    if (Timer != NULL)
    {
        if (Timer->Flags & TF_ENABLED)
        {
            uint32_t iflags = DisableInterrupts();

            Timer->Flags &= ~TF_ENABLED;
            RestoreInterrupts(iflags);
        }
        Timer->StartTicks = USC_GetCurrentTicks();
        Timer->Flags |= TF_ENABLED;
        return true;
    }
    return false;
}

bool LRT_Stop(pTIMER Timer)
{
    if (Timer != NULL)
    {
        if (Timer->Flags & TF_ENABLED)
        {
            uint32_t iflags = DisableInterrupts();

            Timer->Flags &= ~TF_ENABLED;
            RestoreInterrupts(iflags);
        }
        return true;
    }
    return false;
}

bool LRT_SetMode(pTIMER Timer, TMRFLAGS Flags)
{
    if (Timer != NULL)
    {
        uint32_t iflags = DisableInterrupts();

        Timer->Flags = Flags;
        if (Flags & TF_ENABLED) Timer->StartTicks = USC_GetCurrentTicks();
        RestoreInterrupts(iflags);

        return true;
    }
    return false;
}

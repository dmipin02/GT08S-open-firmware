#include <drivers/evmngr.h>

static pDLIST EventsList;

static bool EM_AddEvent(pEVENT Event)
{
    return ((Event == NULL) || (DL_AddItem(EventsList, Event) == NULL)) ? false : true;
}

static pEVENT EM_GetTopEvent(void)
{
    pDLITEM tmpItem = DL_GetFirstItem(EventsList);

    return (tmpItem != NULL) ? tmpItem->Data : NULL;
}

bool EM_Initialize(void)
{
    if (EventsList == NULL) EventsList = DL_Create(0);
    if (EventsList == NULL) return false;

    return true;
}

bool EM_PostEvent(TEVTYPE Type, void *Object, void *Param, uint32_t ParamSz)
{
    pEVENT tmpEvent;

    if (Param == NULL) ParamSz = 0;

    tmpEvent = malloc(sizeof(TEVENT) + ParamSz);
    if (tmpEvent != NULL)
    {
        tmpEvent->Event = Type;
        tmpEvent->Object = Object;
        tmpEvent->ParamSz = ParamSz;
        if (Param != NULL) memcpy(tmpEvent->Param, Param, ParamSz);
        if (EM_AddEvent(tmpEvent)) return true;
        else free(tmpEvent);
    }
    return false;
}

void EM_ProcessEvents(void)
{
    pEVENT tmpEvent;

    while((tmpEvent = EM_GetTopEvent()) != NULL)
    {
        DL_DeleteFirstItem(EventsList);

        switch(tmpEvent->Event)
        {
//         case ET_PENPRESSED:
//         {
//             pPENEVENT TSEvent = (pPENEVENT)tmpEvent->Param;

//             if (tmpEvent->ParamSz)
//             {
// //                GUI_OnPenPressed(TSEvent);
//                 DebugPrint("Pen %u Pressed x= %d, y= %d\r\n", TSEvent->PenIndex, TSEvent->PXY.x, TSEvent->PXY.y);
//             }
//         }
//         break;
//         case ET_PENRELEASED:
//         {
//             pPENEVENT TSEvent = (pPENEVENT)tmpEvent->Param;

//             if (tmpEvent->ParamSz)
//             {
// //                GUI_OnPenReleased(TSEvent);
//                 DebugPrint("Pen %u Released x= %d, y= %d\r\n", TSEvent->PenIndex, TSEvent->PXY.x, TSEvent->PXY.y);
//             }
//         }
//         break;
//         case ET_PENMOVED:
//         {
//             pPENEVENT TSEvent = (pPENEVENT)tmpEvent->Param;

//             if (tmpEvent->ParamSz)
//             {
// //                GUI_OnPenMoved(TSEvent);
//                 DebugPrint("Pen %u Moved x= %d, y= %d\r\n", TSEvent->PenIndex, TSEvent->PXY.x, TSEvent->PXY.y);
//             }
//         }
//         break;
        // case ET_ONPAINT:
        //     GUI_OnPaintHandler((pPAINTEV)tmpEvent->Param);
        //     break;
        case ET_PWRKEY:
            break;
        case ET_ONTIMER:
            if (tmpEvent->ParamSz)
            {
                pTIMER EvTimer = *(pTIMER *)tmpEvent->Param;

                if (EvTimer->Handler != NULL) EvTimer->Handler(EvTimer);
            }
            break;
        default:
            break;
        }
        free(tmpEvent);
    }
}






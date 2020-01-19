#include <systypes.h>
#include <mtktypes.h>
#include <vibro.h>

extern uint32_t ROM_Image_Base, ROM_Image_Limit;

int main(void)
{
    pSF_HEADER_v1 sf_header = (pSF_HEADER_v1)ROM_Image_Base;

    HW_VibroToggle(true);

    return 0;
}
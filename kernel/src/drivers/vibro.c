#include <drivers/vibro.h>

void HW_Vibro_Toggle(bool enabled)
{
#ifdef VIBRVoltage
    uint16_t En = (enabled) ? RG_VIBR_EN : 0;

#if VIBRVoltage == VIBR_VO18V
    VIBR_CON0 = RG_VIBR_VOSEL(VIBR_VO18V) | VIBR_ON_SEL | En;
#elif VIBRVoltage == VIBR_VO28V
    VIBR_CON0 = RG_VIBR_VOSEL(VIBR_VO28V) | VIBR_ON_SEL | En;
#elif VIBRVoltage == VIBR_VO30V
    VIBR_CON0 = RG_VIBR_VOSEL(VIBR_VO30V) | VIBR_ON_SEL | En;
#endif
#endif
}
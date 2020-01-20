#include <drivers/lcd.h>

void HW_LCD_SetISINKMode(bool UsePWM)
{
    if (UsePWM)
        ISINKS_CON0 = ISINKS_MODE_PWM;
    else
        ISINKS_CON0 = ISINKS_MODE_SINK;
}

void HW_LCD_SetISINKOutput(ISINKCHNL Channel, bool Enable)
{
    volatile uint16_t *ISINK_CON;

    if (Channel == ISINK_CH0)
        ISINK_CON = &ISINK0_CON0;
    else if (Channel == ISINK_CH1)
        ISINK_CON = &ISINK1_CON0;
    else
        return;

    if (Enable)
        *ISINK_CON |= NI_ISINKS_CH0_EN;
    else
        *ISINK_CON &= ~NI_ISINKS_CH0_EN;

    *ISINK_CON &= ~NI_ISINKS_CH0_EN;
}

void HW_LCD_SetISINKParameters(ISINKCHNL Channel, ICVAL Value, bool Enable)
{
    volatile uint16_t *ISINK_CON;
    uint16_t En;

    if (Channel == ISINK_CH0)
        ISINK_CON = &ISINK0_CON0;
    else if (Channel == ISINK_CH1)
        ISINK_CON = &ISINK1_CON0;
    else
        return;

    En = (Enable) ? NI_ISINKS_CH0_EN : 0;

    switch (Value)
    {
    case IC_4mA:
        *ISINK_CON = RG_ISINKS_CH0(ISINKS_CH0_4mA) | En;
        break;
    case IC_8mA:
        *ISINK_CON = RG_ISINKS_CH0(ISINKS_CH0_8mA) | En;
        break;
    case IC_12mA:
        *ISINK_CON = RG_ISINKS_CH0(ISINKS_CH0_12mA) | En;
        break;
    case IC_16mA:
        *ISINK_CON = RG_ISINKS_CH0(ISINKS_CH0_16mA) | En;
        break;
    case IC_20mA:
        *ISINK_CON = RG_ISINKS_CH0(ISINKS_CH0_20mA) | En;
        break;
    case IC_24mA:
        *ISINK_CON = RG_ISINKS_CH0(ISINKS_CH0_24mA) | En;
        break;
    case IC_32mA:
        *ISINK_CON = RG_ISINKS_CH0(ISINKS_CH0_16mA) | RG_ISINK0_DOUBLE | En;
        break;
    case IC_40mA:
        *ISINK_CON = RG_ISINKS_CH0(ISINKS_CH0_20mA) | RG_ISINK0_DOUBLE | En;
        break;
    case IC_48mA:
        *ISINK_CON = RG_ISINKS_CH0(ISINKS_CH0_24mA) | RG_ISINK0_DOUBLE | En;
        break;
    }
}
#include <drivers/vibro.h>
#include <drivers/lcd.h>
#include <drivers/pctl.h>
#include <drivers/pll.h>
#include <drivers/ustimer.h>
#include <drivers/emi.h>
#include <drivers/gpio.h>
#include <drivers/rtc.h>
#include <drivers/memory.h>
#include <drivers/nvic.h>
#include <drivers/lrtimer.h>

#define _DEBUG_ (1)
#define _USEBATTERY_ (0)

int main(void)
{
    MPU_Initialize();
    PCTL_Initialize();
    GPIO_Initialize();
    RTC_Initialize();

    USC_StartCounter();

    size_t MemSize = InitializeMemoryPool();

    EM_Initialize();
    NVIC_Initialize();
    LRT_Initialize();

    EnableInterrupts();

    // Signal about turning on the device
    HW_Vibro_Toggle(false);
    HW_LCD_SetISINKMode(false);
    HW_LCD_SetISINKParameters(ISINK_CH0, IC_8mA, true);

    while (1)
    {
        EM_ProcessEvents();
    }
}
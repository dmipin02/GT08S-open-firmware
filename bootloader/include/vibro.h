#pragma once
#include <systypes.h>
#include <mt6261.h>

#define VIBR_CON0 (*(volatile uint16_t *)(PMU_base + 0x01B0))
#define RG_VIBR_EN (1 << 0)
#define VIBR_ON_SEL (1 << 1) /* 0 - Enable with EXT_SRCLKENA or BT_SRCLKENA or TOPSM_SRCLKENA \
                                1 - Enable with RG_VIBR_EN */
#define RG_VIBR_VOSEL(v) (((v)&0x03) << 4)
#define VIBR_VO18V 0
#define VIBR_VO28V 2
#define VIBR_VO30V 3
#define RG_VIBR_NDIS_EN (1 << 10) // VIBR POWER DOWN NMOS Enable
#define RG_VIBR_SS_BYPASS (1 << 11)
#define QI_VIBR_STATUS (1 << 15)
#define VIBR_CON1 (*(volatile uint16_t *)(PMU_base + 0x01B4))
#define RG_VIBR_CAL(v) (((v)&0x0F) << 4)

#define VIBRVoltage VIBR_VO18V

void HW_VibroToggle(bool enabled);
/* generated configuration header file - do not edit */
#ifndef BSP_PIN_CFG_H_
#define BSP_PIN_CFG_H_
#if __has_include("r_ioport.h")
#include "r_ioport.h"
#endif
#define BLEN (IOPORT_PORT_11_PIN_3)
#define TP_INT (IOPORT_PORT_12_PIN_1)
extern const ioport_cfg_t g_bsp_pin_cfg; /* R9A07G066M04GBG.pincfg */

void BSP_PinConfigSecurityInit();
#endif /* BSP_PIN_CFG_H_ */

/* generated pin source file - do not edit */
#include "bsp_api.h"
#include "r_ioport_api.h"
#if __has_include("r_ioport.h")
#include "r_ioport.h"
#endif

extern const ioport_extend_cfg_t g_ioport_cfg_extend;

const ioport_pin_cfg_t g_bsp_pin_cfg_data[] =
{
{ .pin = BSP_IO_PORT_01_PIN_01, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_B01
        | (uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT_INPUT | (uint32_t) IOPORT_CFG_PORT_OUTPUT_HIGH
        | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST) },
  { .pin = BSP_IO_PORT_04_PIN_03, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_B11 | (uint32_t) IOPORT_CFG_PERIPHERAL_PIN
          | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PERIPHERAL_MODE2) },
  { .pin = BSP_IO_PORT_04_PIN_04, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_B11 | (uint32_t) IOPORT_CFG_PERIPHERAL_PIN
          | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PERIPHERAL_MODE2) },
  { .pin = BSP_IO_PORT_06_PIN_00, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_B11 | (uint32_t) IOPORT_CFG_PERIPHERAL_PIN
          | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PERIPHERAL_MODE2) },
  { .pin = BSP_IO_PORT_06_PIN_01, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_B11 | (uint32_t) IOPORT_CFG_PERIPHERAL_PIN
          | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PERIPHERAL_MODE2) },
  { .pin = BSP_IO_PORT_08_PIN_02, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_B01
          | (uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT_INPUT | (uint32_t) IOPORT_CFG_PORT_OUTPUT_HIGH
          | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST) },
  { .pin = BSP_IO_PORT_08_PIN_03, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_B01
          | (uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT_INPUT | (uint32_t) IOPORT_CFG_PORT_OUTPUT_HIGH
          | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST) },
  { .pin = BSP_IO_PORT_09_PIN_04, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_B01
          | (uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT | (uint32_t) IOPORT_CFG_PORT_OUTPUT_HIGH
          | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST) },
  { .pin = BSP_IO_PORT_10_PIN_00, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_B01
          | (uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT_INPUT | (uint32_t) IOPORT_CFG_PORT_OUTPUT_HIGH
          | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST) },
  { .pin = BSP_IO_PORT_10_PIN_01, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_B01
          | (uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT_INPUT | (uint32_t) IOPORT_CFG_PORT_OUTPUT_HIGH
          | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST) },
  { .pin = BSP_IO_PORT_11_PIN_00, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_B01
          | (uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT_INPUT | (uint32_t) IOPORT_CFG_PORT_OUTPUT_HIGH
          | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST) },
  { .pin = BSP_IO_PORT_11_PIN_01, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_B01
          | (uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT_INPUT | (uint32_t) IOPORT_CFG_PORT_OUTPUT_HIGH
          | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST) }, };

const ioport_cfg_t g_bsp_pin_cfg =
{ .number_of_pins = sizeof(g_bsp_pin_cfg_data) / sizeof(ioport_pin_cfg_t),
  .p_pin_cfg_data = &g_bsp_pin_cfg_data[0],
  .p_extend = &g_ioport_cfg_extend };

/* generated HAL source file - do not edit */
#include "hal_data.h"
#define FSP_NOT_DEFINED (UINT32_MAX)
#if (FSP_NOT_DEFINED) != (FSP_NOT_DEFINED)

/* If the transfer module is DMAC, define a DMAC transfer callback. */
#include "r_dmac.h"
extern void rspi_tx_dmac_callback(rspi_instance_ctrl_t * p_ctrl);

void g_spi0_tx_transfer_callback (dmac_callback_args_t * p_args)
{
    FSP_PARAMETER_NOT_USED(p_args);
    rspi_tx_dmac_callback(&g_spi0_ctrl);
}
#endif

#if (FSP_NOT_DEFINED) != (FSP_NOT_DEFINED)

/* If the transfer module is DMAC, define a DMAC transfer callback. */
#include "r_dmac.h"
extern void rspi_rx_dmac_callback(rspi_instance_ctrl_t * p_ctrl);

void g_spi0_rx_transfer_callback (dmac_callback_args_t * p_args)
{
    FSP_PARAMETER_NOT_USED(p_args);
    rspi_rx_dmac_callback(&g_spi0_ctrl);
}
#endif
#undef FSP_NOT_DEFINED

rspi_instance_ctrl_t g_spi0_ctrl;

/** SPI extended configuration for RSPI HAL driver */
const rspi_extended_cfg_t g_spi0_extend =
{ .ssl_polarity = RSPI_SSLP_LOW,
  .mosi_idle = RSPI_MOSI_IDLE_VALUE_FIXING_DISABLE,
  .spck_div =
  {
  /* Actual calculated bitrate: 7142857. */.spbr = 6,
    .brdv = 0 },
  .spck_delay = RSPI_DELAY_COUNT_1,
  .ssl_negation_delay = RSPI_DELAY_COUNT_1,
  .next_access_delay = RSPI_DELAY_COUNT_1,
  .ssl_level_keep = RSPI_SSL_LEVEL_KEEP_DISABLE,
  .tx_trigger_level = RSPI_TX_TRIGGER_4,
  .rx_trigger_level = RSPI_RX_TRIGGER_24 };

/** SPI configuration for RSPI HAL driver */
const spi_cfg_t g_spi0_cfg =
{ .channel = 1,

#define RSPI1_RX_IRQ_ENABLE  (1)
#if (BSP_IRQ_DISABLED) != RSPI1_RX_IRQ_ENABLE
  .rxi_irq = RSPI1_RX_IRQn,
#else
    .rxi_irq             = FSP_INVALID_VECTOR,
#endif
#define RSPI1_TX_IRQ_ENABLE  (1)
#if (BSP_IRQ_DISABLED) != RSPI1_TX_IRQ_ENABLE
  .txi_irq = RSPI1_TX_IRQn,
#else
    .txi_irq             = FSP_INVALID_VECTOR,
#endif
  .eri_irq = RSPI1_ERR_IRQn,

  .rxi_ipl = 24,
  .txi_ipl = 24,
  .eri_ipl = 24,

  .operating_mode = SPI_MODE_MASTER,

  .clk_phase = SPI_CLK_PHASE_EDGE_ODD,
  .clk_polarity = SPI_CLK_POLARITY_LOW,

  .mode_fault = SPI_MODE_FAULT_ERROR_DISABLE,
  .bit_order = SPI_BIT_ORDER_MSB_FIRST,
  .p_transfer_tx = g_spi0_P_TRANSFER_TX,
  .p_transfer_rx = g_spi0_P_TRANSFER_RX,
  .p_callback = spi_callback,

  .p_context = NULL,
  .p_extend = (void*) &g_spi0_extend, };

/* Instance structure to use this module. */
const spi_instance_t g_spi0 =
{ .p_ctrl = &g_spi0_ctrl, .p_cfg = &g_spi0_cfg, .p_api = &g_spi_on_rspi };
#define FSP_NOT_DEFINED (UINT32_MAX)
#if (FSP_NOT_DEFINED) != (FSP_NOT_DEFINED)

/* If the transfer module is DMAC, define a DMAC transfer callback. */
#include "r_dmac.h"
extern void riic_master_tx_dmac_callback(iic_master_instance_ctrl_t * p_ctrl);

void g_i2c_master0_tx_transfer_callback (dmac_callback_args_t * p_args)
{
    FSP_PARAMETER_NOT_USED(p_args);
    riic_master_tx_dmac_callback(&g_i2c_master0_ctrl);
}
#endif

#if (FSP_NOT_DEFINED) != (FSP_NOT_DEFINED)

/* If the transfer module is DMAC, define a DMAC transfer callback. */
#include "r_dmac.h"
extern void riic_master_rx_dmac_callback(iic_master_instance_ctrl_t * p_ctrl);

void g_i2c_master0_rx_transfer_callback (dmac_callback_args_t * p_args)
{
    FSP_PARAMETER_NOT_USED(p_args);
    riic_master_rx_dmac_callback(&g_i2c_master0_ctrl);
}
#endif
#undef FSP_NOT_DEFINED

iic_master_instance_ctrl_t g_i2c_master0_ctrl;
const riic_master_extended_cfg_t g_i2c_master0_extend =
{ .timeout_mode = IIC_MASTER_TIMEOUT_MODE_SHORT,
  .timeout_scl_low = IIC_MASTER_TIMEOUT_SCL_LOW_ENABLED,
  /* Actual calculated bitrate: 396825. Actual calculated duty cycle: 51%. */.clock_settings.brl_value = 25,
  .clock_settings.brh_value = 26,
  .clock_settings.cks_value = 2,
  .noise_filter_stage = 1,
  .naki_irq = RIIC0_NAKI_IRQn,
  .spi_irq = RIIC0_SPI_IRQn,
  .sti_irq = RIIC0_STI_IRQn,
  .ali_irq = RIIC0_ALI_IRQn,
  .tmoi_irq = RIIC0_TMOI_IRQn };
const i2c_master_cfg_t g_i2c_master0_cfg =
{ .channel = 0, .rate = I2C_MASTER_RATE_FAST, .slave = 0x1D, .addr_mode = I2C_MASTER_ADDR_MODE_7BIT, .p_transfer_tx =
          g_i2c_master0_P_TRANSFER_TX,
  .p_transfer_rx = g_i2c_master0_P_TRANSFER_RX, .p_callback = i2c_master_callback, .p_context = NULL, .rxi_irq =
          RIIC0_RI_IRQn,
  .txi_irq = RIIC0_TI_IRQn, .tei_irq = RIIC0_TEI_IRQn, .ipl = 24, .p_extend = &g_i2c_master0_extend, };
/* Instance structure to use this module. */
const i2c_master_instance_t g_i2c_master0 =
{ .p_ctrl = &g_i2c_master0_ctrl, .p_cfg = &g_i2c_master0_cfg, .p_api = &g_i2c_master_on_iic };
#define FSP_NOT_DEFINED (UINT32_MAX)
#if (FSP_NOT_DEFINED) != (FSP_NOT_DEFINED)

/* If the transfer module is DMAC, define a DMAC transfer callback. */
#include "r_dmac.h"
extern void scif_uart_tx_dmac_callback(scif_uart_instance_ctrl_t const * const p_ctrl);

void g_uart1_tx_transfer_callback (dmac_callback_args_t * p_args)
{
    FSP_PARAMETER_NOT_USED(p_args);
    scif_uart_tx_dmac_callback(&g_uart1_ctrl);
}
#endif

#if (FSP_NOT_DEFINED) != (FSP_NOT_DEFINED)

/* If the transfer module is DMAC, define a DMAC transfer callback. */
#include "r_dmac.h"
extern void scif_uart_rx_dmac_callback(scif_uart_instance_ctrl_t const * const p_ctrl);

void g_uart1_rx_transfer_callback (dmac_callback_args_t * p_args)
{
    FSP_PARAMETER_NOT_USED(p_args);
    scif_uart_rx_dmac_callback(&g_uart1_ctrl);
}
#endif
#undef FSP_NOT_DEFINED

scif_uart_instance_ctrl_t g_uart1_ctrl;

scif_baud_setting_t g_uart1_baud_setting =
        {
        /* Baud rate calculated with 0.014% error. */.semr_baudrate_bits_b.abcs = 0,
          .semr_baudrate_bits_b.bgdm = 1, .semr_baudrate_bits_b.cks = 0, .brr = 38, .mddr = (uint8_t) 184, .semr_baudrate_bits_b.brme =
                  true };

/** UART extended configuration for UARTonSCIF HAL driver */
const scif_uart_extended_cfg_t g_uart1_cfg_extend =
{ .bri_ipl = 24, .bri_irq = SCIF3_BRK_IRQn, .clock = SCIF_UART_CLOCK_INT, .noise_cancel =
          SCIF_UART_NOISE_CANCELLATION_DISABLE,
  .p_baud_setting = &g_uart1_baud_setting, .rx_fifo_trigger = SCIF_UART_RX_FIFO_TRIGGER_MAX, .rts_fifo_trigger =
          SCIF_UART_RTS_TRIGGER_14,
  .uart_mode = SCIF_UART_MODE_RS232, .flow_control = SCIF_UART_FLOW_CONTROL_NONE, .rs485_setting =
  { .enable = (scif_uart_rs485_enable_t) NULL, .polarity = SCIF_UART_RS485_DE_POLARITY_HIGH, .de_control_pin =
            (bsp_io_port_pin_t) SCIF_UART_INVALID_16BIT_PARAM, }, };

/** UART interface configuration */
const uart_cfg_t g_uart1_cfg =
{ .channel = 3,
  .data_bits = UART_DATA_BITS_8,
  .parity = UART_PARITY_OFF,
  .stop_bits = UART_STOP_BITS_1,
  .p_callback = uart_callback_1,
  .p_context = NULL,
  .p_extend = &g_uart1_cfg_extend,
  .p_transfer_tx = g_uart1_P_TRANSFER_TX,
  .p_transfer_rx = g_uart1_P_TRANSFER_RX,
  .rxi_ipl = 24,
  .txi_ipl = 24,
  .tei_ipl = 24,
  .eri_ipl = 24,
  .rxi_irq = SCIF3_RXI_IRQn,
  .txi_irq = SCIF3_TXI_IRQn,
  .tei_irq = SCIF3_TEI_DRI_IRQn,
  .eri_irq = SCIF3_RERR_IRQn, };

/* Instance structure to use this module. */
const uart_instance_t g_uart1 =
{ .p_ctrl = &g_uart1_ctrl, .p_cfg = &g_uart1_cfg, .p_api = &g_uart_on_scif };
#define FSP_NOT_DEFINED (UINT32_MAX)
#if (FSP_NOT_DEFINED) != (FSP_NOT_DEFINED)

/* If the transfer module is DMAC, define a DMAC transfer callback. */
#include "r_dmac.h"
extern void scif_uart_tx_dmac_callback(scif_uart_instance_ctrl_t const * const p_ctrl);

void g_uart0_tx_transfer_callback (dmac_callback_args_t * p_args)
{
    FSP_PARAMETER_NOT_USED(p_args);
    scif_uart_tx_dmac_callback(&g_uart0_ctrl);
}
#endif

#if (FSP_NOT_DEFINED) != (FSP_NOT_DEFINED)

/* If the transfer module is DMAC, define a DMAC transfer callback. */
#include "r_dmac.h"
extern void scif_uart_rx_dmac_callback(scif_uart_instance_ctrl_t const * const p_ctrl);

void g_uart0_rx_transfer_callback (dmac_callback_args_t * p_args)
{
    FSP_PARAMETER_NOT_USED(p_args);
    scif_uart_rx_dmac_callback(&g_uart0_ctrl);
}
#endif
#undef FSP_NOT_DEFINED

scif_uart_instance_ctrl_t g_uart0_ctrl;

scif_baud_setting_t g_uart0_baud_setting =
        {
        /* Baud rate calculated with 0.014% error. */.semr_baudrate_bits_b.abcs = 0,
          .semr_baudrate_bits_b.bgdm = 1, .semr_baudrate_bits_b.cks = 0, .brr = 38, .mddr = (uint8_t) 184, .semr_baudrate_bits_b.brme =
                  true };

/** UART extended configuration for UARTonSCIF HAL driver */
const scif_uart_extended_cfg_t g_uart0_cfg_extend =
{ .bri_ipl = 24, .bri_irq = SCIF0_BRK_IRQn, .clock = SCIF_UART_CLOCK_INT, .noise_cancel =
          SCIF_UART_NOISE_CANCELLATION_DISABLE,
  .p_baud_setting = &g_uart0_baud_setting, .rx_fifo_trigger = SCIF_UART_RX_FIFO_TRIGGER_MAX, .rts_fifo_trigger =
          SCIF_UART_RTS_TRIGGER_14,
  .uart_mode = SCIF_UART_MODE_RS232, .flow_control = SCIF_UART_FLOW_CONTROL_NONE, .rs485_setting =
  { .enable = (scif_uart_rs485_enable_t) NULL, .polarity = SCIF_UART_RS485_DE_POLARITY_HIGH, .de_control_pin =
            (bsp_io_port_pin_t) SCIF_UART_INVALID_16BIT_PARAM, }, };

/** UART interface configuration */
const uart_cfg_t g_uart0_cfg =
{ .channel = 0,
  .data_bits = UART_DATA_BITS_8,
  .parity = UART_PARITY_OFF,
  .stop_bits = UART_STOP_BITS_1,
  .p_callback = uart_callback_0,
  .p_context = NULL,
  .p_extend = &g_uart0_cfg_extend,
  .p_transfer_tx = g_uart0_P_TRANSFER_TX,
  .p_transfer_rx = g_uart0_P_TRANSFER_RX,
  .rxi_ipl = 24,
  .txi_ipl = 24,
  .tei_ipl = 24,
  .eri_ipl = 24,
  .rxi_irq = SCIF0_RXI_IRQn,
  .txi_irq = SCIF0_TXI_IRQn,
  .tei_irq = SCIF0_TEI_DRI_IRQn,
  .eri_irq = SCIF0_RERR_IRQn, };

/* Instance structure to use this module. */
const uart_instance_t g_uart0 =
{ .p_ctrl = &g_uart0_ctrl, .p_cfg = &g_uart0_cfg, .p_api = &g_uart_on_scif };
void g_hal_init(void)
{
    g_common_init ();
}

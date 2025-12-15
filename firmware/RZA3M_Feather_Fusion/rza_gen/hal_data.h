/* generated HAL header file - do not edit */
#ifndef HAL_DATA_H_
#define HAL_DATA_H_
#include <stdint.h>
#include "bsp_api.h"
#include "common_data.h"
#include "r_rspi.h"
#include "r_riic_master.h"
#include "r_i2c_master_api.h"
#include "r_uart_api.h"
#include "r_scif_uart.h"
FSP_HEADER
/** SPI on RSPI Instance. */
extern const spi_instance_t g_spi0;

/** Access the RSPI instance using these structures when calling API functions directly (::p_api is not used). */
extern rspi_instance_ctrl_t g_spi0_ctrl;
extern const spi_cfg_t g_spi0_cfg;

/** Callback used by RSPI Instance. */
void spi_callback(spi_callback_args_t *p_args);

#define FSP_NOT_DEFINED (1)
#if (FSP_NOT_DEFINED == FSP_NOT_DEFINED)
#define g_spi0_P_TRANSFER_TX (NULL)
#else
    #define g_spi0_P_TRANSFER_TX (&FSP_NOT_DEFINED)
#endif
#if (FSP_NOT_DEFINED == FSP_NOT_DEFINED)
#define g_spi0_P_TRANSFER_RX (NULL)
#else
    #define g_spi0_P_TRANSFER_RX (&FSP_NOT_DEFINED)
#endif
#undef FSP_NOT_DEFINED
/* I2C Master on RIIC Instance. */
extern const i2c_master_instance_t g_i2c_master0;

/** Access the I2C Master instance using these structures when calling API functions directly (::p_api is not used). */
extern iic_master_instance_ctrl_t g_i2c_master0_ctrl;
extern const i2c_master_cfg_t g_i2c_master0_cfg;

void i2c_master_callback(i2c_master_callback_args_t *p_args);

#define FSP_NOT_DEFINED (1)
#if (FSP_NOT_DEFINED == FSP_NOT_DEFINED)
#define g_i2c_master0_P_TRANSFER_TX (NULL)
#else
    #define g_i2c_master0_P_TRANSFER_TX (&FSP_NOT_DEFINED)
#endif
#if (FSP_NOT_DEFINED == FSP_NOT_DEFINED)
#define g_i2c_master0_P_TRANSFER_RX (NULL)
#else
    #define g_i2c_master0_P_TRANSFER_RX (&FSP_NOT_DEFINED)
#endif
#undef FSP_NOT_DEFINED
/** UART on SCIF Instance. */
extern const uart_instance_t g_uart1;

/** Access the UART instance using these structures when calling API functions directly (::p_api is not used). */
extern scif_uart_instance_ctrl_t g_uart1_ctrl;
extern const uart_cfg_t g_uart1_cfg;
extern const scif_uart_extended_cfg_t g_uart1_cfg_extend;

void uart_callback_1(uart_callback_args_t *p_args);

#define FSP_NOT_DEFINED (1)
#if (FSP_NOT_DEFINED == FSP_NOT_DEFINED)
#define g_uart1_P_TRANSFER_TX (NULL)
#else
    #define g_uart1_P_TRANSFER_TX (&FSP_NOT_DEFINED)
#endif
#if (FSP_NOT_DEFINED == FSP_NOT_DEFINED)
#define g_uart1_P_TRANSFER_RX (NULL)
#else
    #define g_uart1_P_TRANSFER_RX (&FSP_NOT_DEFINED)
#endif
#undef FSP_NOT_DEFINED
/** UART on SCIF Instance. */
extern const uart_instance_t g_uart0;

/** Access the UART instance using these structures when calling API functions directly (::p_api is not used). */
extern scif_uart_instance_ctrl_t g_uart0_ctrl;
extern const uart_cfg_t g_uart0_cfg;
extern const scif_uart_extended_cfg_t g_uart0_cfg_extend;

void uart_callback_0(uart_callback_args_t *p_args);

#define FSP_NOT_DEFINED (1)
#if (FSP_NOT_DEFINED == FSP_NOT_DEFINED)
#define g_uart0_P_TRANSFER_TX (NULL)
#else
    #define g_uart0_P_TRANSFER_TX (&FSP_NOT_DEFINED)
#endif
#if (FSP_NOT_DEFINED == FSP_NOT_DEFINED)
#define g_uart0_P_TRANSFER_RX (NULL)
#else
    #define g_uart0_P_TRANSFER_RX (&FSP_NOT_DEFINED)
#endif
#undef FSP_NOT_DEFINED
void hal_entry(void);
void g_hal_init(void);
FSP_FOOTER
#endif /* HAL_DATA_H_ */

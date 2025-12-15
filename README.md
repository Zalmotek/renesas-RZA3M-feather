# Renesas RZ/A3M Feather SoM 

Welcome to the <a href="https://zalmotek.com/products/RZA3M-Feather-SoM">Renesas RZ/A3M Feather SoM</a> GitHub repository!

Here you'll find all the resources you need to get up and running quickly.

## 🪶 What is the RZ/A3M Feather SoM?

The <a href="https://www.renesas.com/en/products/microcontrollers-microprocessors/ra-cortex-m-mcus/ra8m1-480mhz-arm-cortex-m85-based-microcontroller-helium-and-trustzone">Renesas RA8M1</a> allows you to achieve the full potential of a real-time operating system (RTOS) while leveraging the performance boost provided by the 64-bit Arm® Cortex®-M85 CPU core with a maximum operating frequency of 360 MHz.

The <a href="https://www.renesas.com/en/products/rz-a3m">RZ/A3M</a> allows you to achieve the full potential of a real-time operating system (RTOS) while leveraging the performance boost provided by the 64-bit Arm® Cortex®-A55 CPU core with a maximum operating frequency of 1 GHz. It features MIPI DSI output for display control, 128 Mbit NOR Flash memory, and built-in 128MB DDR3L-SDRAM, all conveniently packaged in a compact format.

Besides the processor, the Feather SoM contains the classic Feather features: digital GPIOs, I2C and SPI communication pins, UART pins, a LiPo battery power plug, and the USB programming port. The SoM also features a USB Type-C for powering the board and for USB debug upload.

<p align="center">
  <img src="documentation/Images/2.png" height="500">
  <img src="documentation/Images/3.png" height="500">
</p>

## Feather Pinout

The pinout for each port is as follows:

| Pin | Function | Notes |
| :-- | :-- | :-- |
| 1  | RESET |  |
| 2  | VCC (3V3) |  |
| 3  | AREF |  |
| 4  | GND |  |
| 5  | A0/D20 | BSP_IO_PORT_01_PIN_00 |
| 6  | A1/D21 | BSP_IO_PORT_02_PIN_00 |
| 7  | D22 | BSP_IO_PORT_09_PIN_00 |
| 8  | D23 | BSP_IO_PORT_09_PIN_01 |
| 9  | D24 | BSP_IO_PORT_09_PIN_02 |
| 10 | D25 | BSP_IO_PORT_09_PIN_03 |
| 11 | SCK | BSP_IO_PORT_01_PIN_02 |
| 12 | MOSI | BSP_IO_PORT_01_PIN_03 |
| 13 | MISO | BSP_IO_PORT_01_PIN_04 |
| 14 | RX | BSP_IO_PORT_04_PIN_04 |
| 15 | TX | BSP_IO_PORT_04_PIN_03 |
| 16 | D14 | BSP_IO_PORT_01_PIN_01 |
| 17 | VBAT |  |
| 18 | EN |  |
| 19 | BUS |  |
| 20 | D13 | BSP_IO_PORT_09_PIN_04 |
| 21 | D12 | BSP_IO_PORT_08_PIN_02 |
| 22 | D11 | BSP_IO_PORT_08_PIN_03 |
| 23 | D10 | BSP_IO_PORT_10_PIN_01 |
| 24 | D9  | BSP_IO_PORT_10_PIN_00 |
| 25 | D6  | BSP_IO_PORT_11_PIN_01 |
| 26 | D5  | BSP_IO_PORT_11_PIN_00 |
| 27 | SCL | RIIC0 |
| 28 | SDA | RIIC0 |


## 🐣🏁 Quick Start Guide

### 🔌 Hardware Requirements
- USB-C cable
- JTAG Debugger, such as the <a href="https://www.segger.com/products/debug-probes/j-link/">SEGGER J-Link</a>

### 💻 Development Environment Setup

#### Installing Renesas e² studio IDE

The e² studio IDE from Renesas is a comprehensive, user-friendly platform designed to streamline embedded application development. It supports Renesas microcontrollers and combines powerful features with an intuitive interface for coding, debugging, and project management.

First of all, download the latest release of the Flexible Software Package with the e²studio platform installer from the following <a href="https://www.renesas.com/us/en/software-tool/e2studio-information-rz-family">link</a>, according to your OS.

The installer will guide you through the necessary steps. After the installation is finished, launch Renesas e² studio and set up your workspace. This will be the directory where all your projects will be stored.

You will also need to install the J-Link Software pack from <a href="https://www.segger.com/products/debug-probes/j-link/technology/flash-download/">here</a>.

#### Running your first project

Once you have all the tools installed, follow <a href="documentation/Getting%20Started%20with%20the%20RZ_A3M%20Feather%20SoM%20using%20the%20Renesas%20e²%20studio%20IDE.md">this</a> guide to learn how to import, build, and run a project in the e² studio IDE. 

---
Thank you for choosing the Renesas RZ/A3M Feather SoM! 

We can't wait to see what amazing projects you'll create with it! 💻✨

# RZA3M Feather Fusion

A combined demo that fuses peripherals and compute on the Renesas RZA3M Feather platform:
- I2C accelerometer readout
- SPI temperature sensor (MAX31723) readout
- Periodic matrix multiplication workload
- Arduino-style UART logging with simple float printing and colorized OK/NOK status

## Overview

The firmware initializes UART, I2C, SPI, and GPIO, then enters a 1 Hz loop that:
- Reads 6 bytes of acceleration data over I2C (x, y, z)
- Reads temperature over SPI from a MAX31723 sensor
- Runs a 100x100 double-precision matrix multiply as a compute workload
- Prints a status line over UART showing: computation status, SPI status, I2C status, temperature (°C), and acceleration values

If sensor communications fail or values look invalid, the status shows NOK (in red) for the affected interface.

## Features

- I2C sensor init and read (RIIC master driver)
- SPI temperature read (RSPI driver), CS control via GPIO
- Lightweight Serial compatibility layer exposing Serial.begin/print/println
- Formatted status with ANSI color codes
- Timing helpers via `R_BSP_SoftwareDelay`
- MMU and IOPORT initialization via FSP

## Hardware Requirements

- Renesas RZA3M Feather board
- I2C accelerometer (example expects a device with:
  - DEVICE_ID register at 0x00 returning 0xE5
  - POWER_CTL at 0x2D with ENABLE bit 0x08
  - Data registers starting at 0x32 providing 6 bytes XYZ)
- SPI temperature sensor MAX31723 connected to SPI0 and:
  - CS on P10_01 (see Pin Mapping)
- UART connection (115200-8N1) for logs

## Pin Mapping

- SPI MAX31723 CS: BSP_IO_PORT_10_PIN_01 (macro `CS_PIN`)
- Other SPI/I2C pins are configured via FSP (see rza_gen and BSP config)
- UART: SCIF UART channel used by Serial compatibility (115200 baud)

## Software Requirements

- Renesas e² studio IDE
- RZA3M FSP (Flexible Software Package) with modules:
  - RSPI (SPI), RIIC Master (I2C), SCIF UART, IOPORT, MMU
- GCC ARM toolchain

## Project Structure

```
RZA3M_Feather_Fusion/
├── src/
│   ├── hal_entry.cpp          # Main loop: init, read I2C/SPI, compute, print UART
│   ├── i2c_sensor.h/.cpp      # I2C sensor setup and read helpers
│   ├── spi_max31723.h/.cpp    # MAX31723 SPI init and temperature read
│   ├── computation.h/.cpp     # 100x100 matrix multiply workload
│   ├── SerialCompatibility.*  # Arduino-style Serial layer over SCIF UART
│   ├── sections.c, syscalls.c, mmu_page_table.c
├── rza/                       # FSP sources/headers and board config
├── rza_gen/                   # Auto-generated FSP configuration artifacts
└── Debug/                     # Build outputs
```

## Main Flow

The core logic is in `src/hal_entry.cpp`:
1. Initialize IOPORT and enable pin access
2. Start UART at 115200 (Serial.begin)
3. Initialize I2C accelerometer (`init_sensor`) and SPI temperature sensor (`max31723_init`)
4. Loop every 1000 ms:
   - Read accelerometer bytes (`read_sensor_data`), map to x/y/z
   - Read temperature (`get_temperature`)
   - Run `multiplyMatrix()` to stress CPU/memory
   - Print a status line with colorized OK/NOK per interface and measured values

Example output structure (color codes shown literally here):
```
Computation status [\033[0;42mOK\033[0m], SPI status [\033[0;42mOK\033[0m], I2C status [\033[0;42mOK\033[0m], temperature [23.50°C], acceleration(x, y, z) [123.45][67.89][10.11]
```

Notes:
- The code marks I2C as NOK if all x/y/z are 0
- The code marks SPI as NOK if temperature equals 0 or 255 (basic sanity check)
- `print_float` prints two fractional digits using integer math

## Configuration

- UART baud: in `hal_entry.cpp` via `Serial.begin(115200)`
- SPI CS pin: `CS_PIN` in `src/spi_max31723.h` (default P10_01)
- I2C addressing/transactions: `src/i2c_sensor.*` (uses RIIC instance `g_i2c_master0`)
- Compute load: matrix dimensions in `src/computation.h` (R1/C1/R2/C2 = 100)
- Loop period: `delay(1000)` in `hal_entry.cpp`

If your accelerometer differs, adjust:
- DEVICE signature, register addresses, and read sizes in `i2c_sensor.h/.cpp`

## Building and Running

1. Import the project into e² studio:
   - File → Import → Existing Projects into Workspace → Select this folder
2. Build:
   - Project → Build Project (or Ctrl+B)
3. Flash/Debug:
   - Connect the RZA3M Feather board
   - Use the debug launch to program and run
4. Monitor UART:
   - Open a serial terminal at 115200 baud, 8N1
   - Observe periodic status lines

## Troubleshooting

- No UART output
  - Verify terminal speed (115200) and UART wiring
  - Confirm SCIF UART channel instance matches your hardware in FSP config

- I2C status NOK or zeros
  - Check I2C wiring and pull-ups
  - Verify device ID (expected 0xE5 at register 0x00)
  - Ensure POWER_CTL (0x2D) is written with ENABLE (0x08)
  - Confirm FSP RIIC instance and pin routing

- SPI status NOK or temperature 0/255
  - Check CS pin matches `CS_PIN` definition and wiring
  - Verify SPI mode and clock in FSP configuration for MAX31723
  - Ensure MISO/MOSI/SCLK connectivity

- Build/link errors
  - Ensure required FSP modules are enabled (RSPI, RIIC, SCIF UART, IOPORT, MMU)
  - Verify include paths and that `rza_gen` is up to date

## Notes on Performance

- 100x100 double matrix multiply runs every second; adjust size in `computation.h` to tune CPU load
- UART prints occur once per loop; heavy printing can affect timing

## License

Source includes Renesas example-derived components. Refer to the Renesas FSP and example code licenses bundled with this project for terms.


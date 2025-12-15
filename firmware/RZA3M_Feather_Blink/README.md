# RZA3M Feather Blink

A simple LED blink demonstration project for the Renesas RZA3M microcontroller using the Feather form factor board.

## Overview

This project demonstrates basic GPIO control and UART communication on the RZA3M microcontroller. The application continuously blinks an LED connected to pin P9_04 while outputting status messages via UART serial communication.

## Features

- **LED Blinking**: Controls an LED on GPIO pin P9_04 (Port 9, Pin 4)
- **Serial Communication**: UART output at 115200 baud rate for status monitoring
- **Arduino-style API**: Uses a Serial compatibility layer for familiar Arduino-like serial communication
- **300ms Blink Interval**: LED toggles every 300 milliseconds

## Hardware Requirements

- Renesas RZA3M Feather board
- LED connected to pin P9_04 (or use onboard LED if available)
- UART connection for serial monitoring (115200 baud)

## Software Requirements

- Renesas e² studio IDE
- RZA3M FSP (Flexible Software Package)
- GCC ARM toolchain

## Project Structure

```
RZA3M_Feather_Blink/
├── src/
│   ├── hal_entry.cpp          # Main application entry point
│   ├── SerialCompatibility.h  # Arduino-style Serial API implementation
│   ├── sections.c             # Memory sections configuration
│   ├── syscalls.c             # System call implementations
│   └── mmu_page_table.c       # Memory Management Unit configuration
├── rza/                       # RZA3M FSP libraries and board support
│   ├── fsp/                   # FSP framework files
│   └── board/                 # Board-specific configurations
├── Debug/                     # Build output directory
└── .settings/                 # e² studio project settings
```

## Key Components

### Main Application (`hal_entry.cpp`)
- Initializes the system and peripherals
- Sets up MMU (Memory Management Unit)
- Configures GPIO and UART
- Implements the main blink loop with serial output

### Serial Compatibility Layer (`SerialCompatibility.h`)
- Provides Arduino-style Serial API
- Implements UART communication using RZA3M FSP drivers
- Supports both Serial and Serial1 interfaces
- Features buffered I/O with interrupt-driven operation

## Code Walkthrough

The main application loop performs these operations:

1. **System Initialization**:
   - Enable pin access
   - Initialize serial communication at 115200 baud
   - Configure GPIO and UART through FSP

2. **Main Loop**:
   - Set GPIO pin P9_04 to LOW
   - Print "Pin %u LOW" message via UART
   - Wait 300ms
   - Set GPIO pin P9_04 to HIGH  
   - Print "Pin %u HIGH" message via UART
   - Wait 300ms
   - Repeat indefinitely

## Building and Running

1. **Import Project**:
   - Open e² studio IDE
   - Import the project into your workspace

2. **Build**:
   - Select the project in Project Explorer
   - Build using `Project → Build Project` or `Ctrl+B`

3. **Debug/Flash**:
   - Connect your RZA3M Feather board
   - Use the debug configuration to flash and run the program
   - Open a serial terminal at 115200 baud to monitor output

## Serial Output

When running, you should see output similar to:
```
Pin %u LOW
Pin %u HIGH
Pin %u LOW
Pin %u HIGH
...
```

## Configuration

- **Blink Rate**: Modify the `delay(300)` calls in `hal_entry.cpp` to change timing
- **GPIO Pin**: Change `BSP_IO_PORT_09_PIN_04` to use a different pin
- **Serial Baud Rate**: Modify the `Serial.begin(115200)` parameter

## FSP Integration

This project uses the Renesas Flexible Software Package (FSP) for:
- GPIO control via `R_BSP_PinWrite()`
- UART communication via `R_SCIF_UART_*` functions
- Memory management via `R_MMU_*` functions
- System delays via `R_BSP_SoftwareDelay()`

## License

This project is provided as-is for educational and development purposes. Please refer to Renesas FSP license terms for the underlying framework components.

## Contributing

Feel free to submit issues and enhancement requests. This is a basic template that can be extended for more complex RZA3M applications.

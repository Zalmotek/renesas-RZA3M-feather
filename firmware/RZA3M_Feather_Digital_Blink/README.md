# RZA3M Feather Digital Blink

A multi-pin GPIO demonstration project for the Renesas RZA3M microcontroller using the Feather form factor board. This project demonstrates sequential digital pin control with real-time status monitoring via UART serial communication.

## Overview

This project showcases advanced GPIO control on the RZA3M microcontroller by cycling through multiple digital pins (D5-D14) in sequence. Each pin is toggled LOW and HIGH with serial output feedback, making it an excellent example for learning digital pin manipulation, timing control, and serial debugging.

## Features

- **Multi-Pin Sequential Control**: Controls 8 digital pins in sequence (D5, D6, D9, D10, D11, D12, D13, D14)
- **Real-time Status Monitoring**: UART output at 115200 baud showing pin states and numbers
- **Fast Switching**: 50ms intervals for rapid visual feedback
- **Arduino-style Serial API**: Familiar Serial interface for easy debugging
- **Comprehensive Pin Mapping**: Covers multiple GPIO ports (P01, P08, P09, P10, P11)

## Hardware Requirements

- Renesas RZA3M Feather board
- LEDs connected to digital pins D5-D14 (optional, for visual feedback)
- UART connection for serial monitoring (115200 baud)
- Breadboard and jumper wires (if external LEDs are used)

## Pin Mapping

| Digital Pin | GPIO Port/Pin | Physical Port |
|-------------|---------------|---------------|
| D5          | BSP_IO_PORT_11_PIN_00 | P11_00 |
| D6          | BSP_IO_PORT_11_PIN_01 | P11_01 |
| D9          | BSP_IO_PORT_10_PIN_00 | P10_00 |
| D10         | BSP_IO_PORT_10_PIN_01 | P10_01 |
| D11         | BSP_IO_PORT_08_PIN_03 | P08_03 |
| D12         | BSP_IO_PORT_08_PIN_02 | P08_02 |
| D13         | BSP_IO_PORT_09_PIN_04 | P09_04 |
| D14         | BSP_IO_PORT_01_PIN_01 | P01_01 |

## Software Requirements

- Renesas e² studio IDE
- RZA3M FSP (Flexible Software Package)
- GCC ARM toolchain

## Project Structure

```
RZA3M_Feather_Digital_Blink/
├── src/
│   ├── hal_entry.cpp          # Main application with pin control logic
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

## Code Walkthrough

### Main Application Logic (`hal_entry.cpp`)

The application performs these operations in sequence:

1. **System Initialization**:
   - Enable GPIO pin access
   - Initialize serial communication at 115200 baud
   - Configure all pins through FSP

2. **Pin Array Definition**:
   ```cpp
   const bsp_io_port_pin_t pins[] = {
       BSP_IO_PORT_11_PIN_00, // D5
       BSP_IO_PORT_11_PIN_01, // D6
       BSP_IO_PORT_10_PIN_00, // D9
       BSP_IO_PORT_10_PIN_01, // D10
       BSP_IO_PORT_08_PIN_03, // D11
       BSP_IO_PORT_08_PIN_02, // D12
       BSP_IO_PORT_09_PIN_04, // D13
       BSP_IO_PORT_01_PIN_01  // D14
   };
   ```

3. **Sequential Pin Control Loop**:
   - Iterate through each pin in the array
   - Set pin to LOW, print status, wait 50ms
   - Set pin to HIGH, print status, wait 50ms
   - Repeat for all pins, then start over

### Serial Compatibility Layer

- Provides Arduino-style `Serial.println()` functionality
- Implements UART communication using RZA3M FSP drivers
- Features buffered I/O with interrupt-driven operation
- Supports both string and numeric output

## Building and Running

1. **Import Project**:
   - Open e² studio IDE
   - Import the project: `File → Import → Existing Projects into Workspace`

2. **Build**:
   - Select the project in Project Explorer
   - Build using `Project → Build Project` or `Ctrl+B`

3. **Debug/Flash**:
   - Connect your RZA3M Feather board via USB
   - Configure debug settings for your board
   - Flash and run using the debug configuration

4. **Monitor Output**:
   - Open serial terminal (115200 baud, 8N1)
   - Observe pin state changes in real-time

## Serial Output Example

When running, you should see output similar to:
```
Pin %u LOW
0
Pin %u HIGH
0
Pin %u LOW
1
Pin %u HIGH
1
Pin %u LOW
2
Pin %u HIGH
2
...
```

The pattern shows:
- Pin state message ("Pin %u LOW" or "Pin %u HIGH")
- Pin index number (0-7 corresponding to D5-D14)

## Hardware Testing Setup

### Basic LED Test
1. Connect LEDs with appropriate resistors to pins D5-D14
2. Connect LED cathodes to ground
3. Run the program and observe LEDs blinking in sequence

### Oscilloscope Testing
1. Connect oscilloscope probes to any of the digital pins
2. Set timebase to ~100ms/div to see the 50ms timing
3. Observe clean digital transitions between 0V and 3.3V

## Configuration Options

### Timing Adjustment
Modify the delay values in `hal_entry.cpp`:
```cpp
delay(50);  // Change to desired milliseconds
```

### Pin Selection
Add or remove pins from the `pins[]` array:
```cpp
const bsp_io_port_pin_t pins[] = {
    BSP_IO_PORT_XX_PIN_XX,  // Add your pin
    // ... existing pins
};
```

### Serial Baud Rate
Change the baud rate in `hal_entry.cpp`:
```cpp
Serial.begin(115200);  // Change to desired baud rate
```

## Advanced Usage

### Pattern Variations
- **Knight Rider Effect**: Modify loop to go forward then backward
- **Binary Counter**: Use pin states to display binary numbers
- **PWM Simulation**: Vary HIGH/LOW timing ratios per pin

### Multiple Serial Channels
The project supports Serial1 for additional debugging or communication.

## FSP Integration

This project leverages the Renesas FSP for:
- **GPIO Control**: `R_BSP_PinWrite()` for digital output
- **UART Communication**: `R_SCIF_UART_*` functions for serial I/O
- **Memory Management**: `R_MMU_*` functions for system setup
- **Timing Functions**: `R_BSP_SoftwareDelay()` for precise delays
- **Pin Configuration**: `R_IOPORT_*` for GPIO setup

## Troubleshooting

### No Serial Output
- Check UART connections and baud rate settings
- Verify USB driver installation for RZA3M board
- Ensure serial terminal settings match (115200, 8N1)

### Pins Not Toggling
- Verify pin connections and voltages with multimeter
- Check that pins are configured as outputs in FSP configuration
- Ensure proper power supply to the board

### Build Errors
- Verify FSP version compatibility
- Check that all required FSP modules are included
- Ensure proper include paths in project settings

## License

This project is provided as-is for educational and development purposes. Please refer to Renesas FSP license terms for the underlying framework components.

## Contributing

Feel free to submit issues and enhancement requests. This project serves as a foundation for more complex multi-pin GPIO applications on the RZA3M platform.

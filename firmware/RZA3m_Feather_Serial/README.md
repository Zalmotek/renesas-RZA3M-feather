# RZA3m Feather Serial

A basic UART serial communication demonstration project for the Renesas RZA3M microcontroller using the Feather form factor board. This project showcases Arduino-style serial communication with dual UART support and demonstrates the Serial compatibility layer over the RZA3M FSP.

## Overview

This project demonstrates fundamental UART serial communication on the RZA3M microcontroller. The application continuously transmits messages over UART using an Arduino-compatible Serial interface, making it ideal for learning basic serial communication, debugging output, and understanding the UART peripheral on the RZA3M platform.

## Features

- **Arduino-Style Serial API**: Familiar `Serial.begin()`, `Serial.print()`, and `Serial.println()` interface
- **Dual UART Support**: Both `Serial` and `Serial1` interfaces available
- **Buffered I/O**: 512-byte circular buffers for efficient serial communication
- **Interrupt-driven Operation**: UART callbacks for efficient data handling
- **Multiple Data Types**: Support for strings, integers, and floating-point numbers
- **GPIO Control**: LED control on pin P9_04
- **Fast Update Rate**: 250ms message intervals for rapid debugging

## Hardware Requirements

- **Renesas RZA3M Feather board**
- **UART Connection**: USB-to-serial adapter or direct UART connection
- **LED** (optional): Connected to GPIO pin P9_04 or use onboard LED
- **Power Supply**: 3.3V via USB or external power

## Key Components

### Serial Interface Specifications
- **Baud Rate**: 115200 bps (configurable)
- **Data Format**: 8 data bits, no parity, 1 stop bit (8N1)
- **Buffer Size**: 512 bytes per UART channel
- **Error Handling**: Built-in overflow, framing, and parity error detection

### GPIO Configuration
- **LED Pin**: BSP_IO_PORT_09_PIN_04 (Port 9, Pin 4)
- **LED State**: Set to HIGH on initialization

## Software Requirements

- **Renesas e² studio IDE**
- **RZA3M FSP (Flexible Software Package)**
- **GCC ARM toolchain**
- **SCIF UART driver**
- **IOPORT driver**

## Project Structure

```
RZA3m_Feather_Serial/
├── src/
│   ├── hal_entry.cpp          # Main application logic
│   ├── SerialCompatibility.h  # Arduino-style Serial API implementation
│   ├── sections.c             # Memory sections configuration
│   ├── syscalls.c             # System call implementations
│   └── mmu_page_table.c       # Memory Management Unit configuration
├── rza/                       # RZA3M FSP libraries and board support
│   ├── fsp/                   # FSP framework files
│   └── board/                 # Board-specific configurations
├── rza_gen/                   # Auto-generated FSP configuration files
├── Debug/                     # Build output directory
└── .settings/                 # e² studio project settings
```

## Code Walkthrough

### Main Application (`hal_entry.cpp`)

The application performs these operations:

1. **System Initialization**:
   - Initialize IOPORT for GPIO control
   - Enable pin access for GPIO operations
   - Set LED pin (P9_04) to HIGH state
   - Initialize Serial at 115200 baud
   - Initialize Serial1 at 115200 baud

2. **Main Loop** (every 250ms):
   - Print "Heyo ^^" message
   - Print "Heyo ^^" with newline
   - Print integer value (9) and large negative number (-1e9)
   - Wait 250 milliseconds
   - Repeat indefinitely

### Serial Compatibility Layer (`SerialCompatibility.h`)

The Serial compatibility layer provides Arduino-style UART communication:

#### Key Features:
- **Class-based Interface**: `SerialCompatibilityLayer` class with familiar methods
- **Dual Channel Support**: Both Serial and Serial1 instances
- **Buffered I/O**: Circular buffer implementation for smooth data flow
- **Interrupt Handling**: UART event callbacks for efficient operation
- **Data Type Support**: Strings, integers, and numeric values

#### API Methods:
```cpp
Serial.begin(baud_rate);        // Initialize UART
Serial.print(data);             // Print without newline
Serial.println(data);           // Print with newline
Serial.write(byte);             // Write single byte
Serial.available();             // Check available data
Serial.read();                  // Read single byte
Serial.peek();                  // Peek at next byte
```

## Building and Running

### 1. Import Project
- Open e² studio IDE
- Import project: `File → Import → Existing Projects into Workspace`
- Select the `RZA3m_Feather_Serial` directory

### 2. Build Project
- Select the project in Project Explorer
- Build using `Project → Build Project` or `Ctrl+B`

### 3. Flash and Debug
- Connect RZA3M Feather board via USB
- Use debug configuration to flash and run
- Monitor output via serial terminal

### 4. Serial Terminal Setup
- **Baud Rate**: 115200
- **Data Bits**: 8
- **Parity**: None
- **Stop Bits**: 1
- **Flow Control**: None

## Expected Output

When running, you should see continuous output like:
```
Heyo ^^
Heyo ^^

9-1000000000
Heyo ^^
Heyo ^^

9-1000000000
...
```

**Output Pattern**:
- "Heyo ^^" message (first print)
- "Heyo ^^" with additional newline (second print)
- Integer "9" followed by "-1000000000" (large negative number)
- Pattern repeats every 250ms

## Configuration Options

### Serial Settings
Modify baud rate in `hal_entry.cpp`:
```cpp path=/home/alex/e2_studio/workspace RZA3M/RZA3m_Feather_Serial/src/hal_entry.cpp start=23
Serial.begin(115200);   // Change baud rate here
Serial1.begin(115200);  // Change Serial1 baud rate
```

### Timing Configuration
Adjust message interval in `hal_entry.cpp`:
```cpp path=/home/alex/e2_studio/workspace RZA3M/RZA3m_Feather_Serial/src/hal_entry.cpp start=31
delay(250);  // Change delay in milliseconds
```

### GPIO Pin Configuration
LED pin can be changed in `hal_entry.cpp`:
```cpp path=/home/alex/e2_studio/workspace RZA3M/RZA3m_Feather_Serial/src/hal_entry.cpp start=21
R_BSP_PinWrite(BSP_IO_PORT_09_PIN_04, BSP_IO_LEVEL_HIGH);  // Change pin here
```

### Buffer Size
Adjust buffer sizes in `SerialCompatibility.h`:
```cpp path=/home/alex/e2_studio/workspace RZA3M/RZA3m_Feather_Serial/src/SerialCompatibility.h start=4
#define MAX_BUFF_SIZE     512   // Change buffer size
#define TRANSFER_LENGTH   (512u)
```

## Advanced Features

### Dual UART Channels
The project supports two independent UART channels:
- **Serial**: Primary UART channel (g_uart0)
- **Serial1**: Secondary UART channel (g_uart1)

Both channels operate independently with separate:
- Buffer management
- Callback handlers
- Configuration settings

### Error Handling
Built-in error detection for:
- **Buffer Overflow**: Automatic buffer management
- **Framing Errors**: UART protocol error detection
- **Parity Errors**: Data integrity checking
- **Break Detection**: Line break condition handling

### Interrupt-Driven Operation
Efficient UART operation using:
- **TX Complete**: Transmission completion callbacks
- **RX Complete**: Reception completion callbacks
- **Character Reception**: Individual character callbacks

## FSP Integration

This project uses the following RZA3M FSP modules:

- **R_SCIF_UART**: UART communication driver
- **R_IOPORT**: GPIO pin control
- **R_MMU**: Memory Management Unit setup
- **BSP**: Board Support Package for pin configuration

## Troubleshooting

### No Serial Output
- **Check Connections**: Verify UART TX/RX wiring
- **Baud Rate**: Ensure terminal matches 115200 baud
- **Pin Configuration**: Verify FSP pin assignments
- **Power Supply**: Check 3.3V power to board

### Garbled Output
- **Baud Rate Mismatch**: Verify both sides use 115200
- **Clock Configuration**: Check system clock settings
- **Cable Quality**: Use high-quality USB/UART cables

### Build Errors
- **FSP Version**: Ensure compatible FSP version
- **Include Paths**: Verify project include directories
- **Missing Modules**: Check FSP configuration includes SCIF UART

### Runtime Issues
- **Buffer Overflow**: Reduce transmission rate or increase buffer size
- **Assert Failures**: Check UART initialization success
- **Timing Issues**: Verify delay function operation

## Performance Notes

- **Transmission Rate**: ~4 messages per second (250ms interval)
- **Buffer Capacity**: 512 bytes per channel
- **Interrupt Latency**: Minimal due to efficient FSP drivers
- **Memory Usage**: Low footprint suitable for resource-constrained applications

## Example Applications

This project serves as a foundation for:
- **Debug Output**: System status and diagnostic messages
- **Data Logging**: Sensor data transmission
- **Command Interfaces**: Serial command processing
- **Protocol Implementation**: Custom communication protocols
- **Bootloader Communication**: Firmware update interfaces

## License

This project is provided as-is for educational and development purposes. Please refer to Renesas FSP license terms for the underlying framework components.

## Contributing

This project demonstrates basic serial communication concepts. Feel free to extend it with additional features such as:
- **Command parsing**
- **Data formatting**
- **Protocol implementation**
- **Advanced error handling**
- **Performance optimization**

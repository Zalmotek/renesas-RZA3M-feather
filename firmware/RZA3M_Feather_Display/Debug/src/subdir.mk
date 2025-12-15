################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/gt911.c \
../src/hal_entry.c \
../src/mipi_dsi_ep.c \
../src/mmu_page_table.c \
../src/sections.c \
../src/stdio_uart0.c \
../src/syscalls.c 

LST += \
gt911.lst \
hal_entry.lst \
mipi_dsi_ep.lst \
mmu_page_table.lst \
sections.lst \
stdio_uart0.lst \
syscalls.lst 

C_DEPS += \
./src/gt911.d \
./src/hal_entry.d \
./src/mipi_dsi_ep.d \
./src/mmu_page_table.d \
./src/sections.d \
./src/stdio_uart0.d \
./src/syscalls.d 

OBJS += \
./src/gt911.o \
./src/hal_entry.o \
./src/mipi_dsi_ep.o \
./src/mmu_page_table.o \
./src/sections.o \
./src/stdio_uart0.o \
./src/syscalls.o 

MAP += \
RZA3M_Feather_Display.map 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-a55 -mcmodel=large -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -D_RENESAS_RZA_ -D_RZA_CORE=CA55_0 -D_RZA_ORDINAL=1 -I"/home/alex/e2_studio/workspace11/RZA3M_Feather_Display/src" -I"." -I"/home/alex/e2_studio/workspace11/RZA3M_Feather_Display/rza/fsp/inc" -I"/home/alex/e2_studio/workspace11/RZA3M_Feather_Display/rza/fsp/inc/api" -I"/home/alex/e2_studio/workspace11/RZA3M_Feather_Display/rza/fsp/inc/instances" -I"/home/alex/e2_studio/workspace11/RZA3M_Feather_Display/rza/fsp/src/bsp/mcu/rza3m" -I"/home/alex/e2_studio/workspace11/RZA3M_Feather_Display/rza_gen" -I"/home/alex/e2_studio/workspace11/RZA3M_Feather_Display/rza_cfg/fsp_cfg/bsp" -I"/home/alex/e2_studio/workspace11/RZA3M_Feather_Display/rza_cfg/fsp_cfg" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<")
	@aarch64-none-elf-gcc @"$@.in"


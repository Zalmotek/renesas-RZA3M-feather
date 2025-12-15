################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../rza/fsp/src/r_scif_uart/r_scif_uart.c 

LST += \
r_scif_uart.lst 

C_DEPS += \
./rza/fsp/src/r_scif_uart/r_scif_uart.d 

OBJS += \
./rza/fsp/src/r_scif_uart/r_scif_uart.o 

MAP += \
RZA3M_Feather_Fusion.map 


# Each subdirectory must supply rules for building sources it contributes
rza/fsp/src/r_scif_uart/%.o: ../rza/fsp/src/r_scif_uart/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-a55 -mcmodel=large -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -D_RENESAS_RZA_ -D_RZA_CORE=CA55_0 -D_RZA_ORDINAL=1 -I"/home/alex/e2_studio/workspace RZA3M/RZA3M_Feather_Fusion/src" -I"." -I"/home/alex/e2_studio/workspace RZA3M/RZA3M_Feather_Fusion/rza/fsp/inc" -I"/home/alex/e2_studio/workspace RZA3M/RZA3M_Feather_Fusion/rza/fsp/inc/api" -I"/home/alex/e2_studio/workspace RZA3M/RZA3M_Feather_Fusion/rza/fsp/inc/instances" -I"/home/alex/e2_studio/workspace RZA3M/RZA3M_Feather_Fusion/rza/fsp/src/bsp/mcu/rza3m" -I"/home/alex/e2_studio/workspace RZA3M/RZA3M_Feather_Fusion/rza_gen" -I"/home/alex/e2_studio/workspace RZA3M/RZA3M_Feather_Fusion/rza_cfg/fsp_cfg/bsp" -I"/home/alex/e2_studio/workspace RZA3M/RZA3M_Feather_Fusion/rza_cfg/fsp_cfg" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<")
	@aarch64-none-elf-gcc @"$@.in"


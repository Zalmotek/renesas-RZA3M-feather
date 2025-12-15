################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../rza/fsp/src/r_mipi_phy_b/r_mipi_phy_b.c 

LST += \
r_mipi_phy_b.lst 

C_DEPS += \
./rza/fsp/src/r_mipi_phy_b/r_mipi_phy_b.d 

OBJS += \
./rza/fsp/src/r_mipi_phy_b/r_mipi_phy_b.o 

MAP += \
RZA3M_Feather_Display.map 


# Each subdirectory must supply rules for building sources it contributes
rza/fsp/src/r_mipi_phy_b/%.o: ../rza/fsp/src/r_mipi_phy_b/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-a55 -mcmodel=large -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -D_RENESAS_RZA_ -D_RZA_CORE=CA55_0 -D_RZA_ORDINAL=1 -I"/home/alex/e2_studio/workspace11/RZA3M_Feather_Display/src" -I"." -I"/home/alex/e2_studio/workspace11/RZA3M_Feather_Display/rza/fsp/inc" -I"/home/alex/e2_studio/workspace11/RZA3M_Feather_Display/rza/fsp/inc/api" -I"/home/alex/e2_studio/workspace11/RZA3M_Feather_Display/rza/fsp/inc/instances" -I"/home/alex/e2_studio/workspace11/RZA3M_Feather_Display/rza/fsp/src/bsp/mcu/rza3m" -I"/home/alex/e2_studio/workspace11/RZA3M_Feather_Display/rza_gen" -I"/home/alex/e2_studio/workspace11/RZA3M_Feather_Display/rza_cfg/fsp_cfg/bsp" -I"/home/alex/e2_studio/workspace11/RZA3M_Feather_Display/rza_cfg/fsp_cfg" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<")
	@aarch64-none-elf-gcc @"$@.in"


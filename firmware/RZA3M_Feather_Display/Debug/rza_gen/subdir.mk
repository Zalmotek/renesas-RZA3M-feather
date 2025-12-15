################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../rza_gen/common_data.c \
../rza_gen/hal_data.c \
../rza_gen/main.c \
../rza_gen/pin_data.c \
../rza_gen/vector_data.c 

LST += \
common_data.lst \
hal_data.lst \
main.lst \
pin_data.lst \
vector_data.lst 

C_DEPS += \
./rza_gen/common_data.d \
./rza_gen/hal_data.d \
./rza_gen/main.d \
./rza_gen/pin_data.d \
./rza_gen/vector_data.d 

OBJS += \
./rza_gen/common_data.o \
./rza_gen/hal_data.o \
./rza_gen/main.o \
./rza_gen/pin_data.o \
./rza_gen/vector_data.o 

MAP += \
RZA3M_Feather_Display.map 


# Each subdirectory must supply rules for building sources it contributes
rza_gen/%.o: ../rza_gen/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-a55 -mcmodel=large -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -D_RENESAS_RZA_ -D_RZA_CORE=CA55_0 -D_RZA_ORDINAL=1 -I"/home/alex/e2_studio/workspace11/RZA3M_Feather_Display/src" -I"." -I"/home/alex/e2_studio/workspace11/RZA3M_Feather_Display/rza/fsp/inc" -I"/home/alex/e2_studio/workspace11/RZA3M_Feather_Display/rza/fsp/inc/api" -I"/home/alex/e2_studio/workspace11/RZA3M_Feather_Display/rza/fsp/inc/instances" -I"/home/alex/e2_studio/workspace11/RZA3M_Feather_Display/rza/fsp/src/bsp/mcu/rza3m" -I"/home/alex/e2_studio/workspace11/RZA3M_Feather_Display/rza_gen" -I"/home/alex/e2_studio/workspace11/RZA3M_Feather_Display/rza_cfg/fsp_cfg/bsp" -I"/home/alex/e2_studio/workspace11/RZA3M_Feather_Display/rza_cfg/fsp_cfg" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<")
	@aarch64-none-elf-gcc @"$@.in"


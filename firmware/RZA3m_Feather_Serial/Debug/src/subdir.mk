################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/hal_entry.cpp 

C_SRCS += \
../src/mmu_page_table.c \
../src/sections.c \
../src/syscalls.c 

LST += \
hal_entry.lst \
mmu_page_table.lst \
sections.lst \
syscalls.lst 

C_DEPS += \
./src/mmu_page_table.d \
./src/sections.d \
./src/syscalls.d 

OBJS += \
./src/hal_entry.o \
./src/mmu_page_table.o \
./src/sections.o \
./src/syscalls.o 

MAP += \
RZA3m_Feather_Serial.map 

CPP_DEPS += \
./src/hal_entry.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-a55 -mcmodel=large -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -D_RENESAS_RZA_ -D_RZA_CORE=CA55_0 -D_RZA_ORDINAL=1 -I"/home/alex/e2_studio/workspace RZA3M/RZA3m_Feather_Serial/src" -I"." -I"/home/alex/e2_studio/workspace RZA3M/RZA3m_Feather_Serial/rza/fsp/inc" -I"/home/alex/e2_studio/workspace RZA3M/RZA3m_Feather_Serial/rza/fsp/inc/api" -I"/home/alex/e2_studio/workspace RZA3M/RZA3m_Feather_Serial/rza/fsp/inc/instances" -I"/home/alex/e2_studio/workspace RZA3M/RZA3m_Feather_Serial/rza/fsp/src/bsp/mcu/rza3m" -I"/home/alex/e2_studio/workspace RZA3M/RZA3m_Feather_Serial/rza_gen" -I"/home/alex/e2_studio/workspace RZA3M/RZA3m_Feather_Serial/rza_cfg/fsp_cfg/bsp" -I"/home/alex/e2_studio/workspace RZA3M/RZA3m_Feather_Serial/rza_cfg/fsp_cfg" -std=c++11 -fabi-version=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<")
	@aarch64-none-elf-gcc @"$@.in"
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-a55 -mcmodel=large -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -D_RENESAS_RZA_ -D_RZA_CORE=CA55_0 -D_RZA_ORDINAL=1 -I"/home/alex/e2_studio/workspace RZA3M/RZA3m_Feather_Serial/src" -I"." -I"/home/alex/e2_studio/workspace RZA3M/RZA3m_Feather_Serial/rza/fsp/inc" -I"/home/alex/e2_studio/workspace RZA3M/RZA3m_Feather_Serial/rza/fsp/inc/api" -I"/home/alex/e2_studio/workspace RZA3M/RZA3m_Feather_Serial/rza/fsp/inc/instances" -I"/home/alex/e2_studio/workspace RZA3M/RZA3m_Feather_Serial/rza/fsp/src/bsp/mcu/rza3m" -I"/home/alex/e2_studio/workspace RZA3M/RZA3m_Feather_Serial/rza_gen" -I"/home/alex/e2_studio/workspace RZA3M/RZA3m_Feather_Serial/rza_cfg/fsp_cfg/bsp" -I"/home/alex/e2_studio/workspace RZA3M/RZA3m_Feather_Serial/rza_cfg/fsp_cfg" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<")
	@aarch64-none-elf-gcc @"$@.in"


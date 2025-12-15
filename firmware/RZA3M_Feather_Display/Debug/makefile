################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

-include makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include rza_gen/subdir.mk
-include rza/fsp/src/r_scif_uart/subdir.mk
-include rza/fsp/src/r_riic_master/subdir.mk
-include rza/fsp/src/r_mmu/subdir.mk
-include rza/fsp/src/r_mipi_phy_b/subdir.mk
-include rza/fsp/src/r_mipi_dsi_b/subdir.mk
-include rza/fsp/src/r_lcdc/subdir.mk
-include rza/fsp/src/r_ioport/subdir.mk
-include rza/fsp/src/r_intc_irq/subdir.mk
-include rza/fsp/src/r_gtm/subdir.mk
-include rza/fsp/src/bsp/mcu/rza3m/subdir.mk
-include rza/fsp/src/bsp/mcu/all/subdir.mk
-include rza/fsp/src/bsp/cmsis/Device/RENESAS/Source/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(JMP_DEPS)),)
-include $(JMP_DEPS)
endif
ifneq ($(strip $(FSY_DEPS)),)
-include $(FSY_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(SRC_UPPER_DEPS)),)
-include $(SRC_UPPER_DEPS)
endif
ifneq ($(strip $(P_UPPER_DEPS)),)
-include $(P_UPPER_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(PP_UPPER_DEPS)),)
-include $(PP_UPPER_DEPS)
endif
ifneq ($(strip $(P_DEPS)),)
-include $(P_DEPS)
endif
ifneq ($(strip $(FSY_UPPER_DEPS)),)
-include $(FSY_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(SRC_DEPS)),)
-include $(SRC_DEPS)
endif
ifneq ($(strip $(JMP_UPPER_DEPS)),)
-include $(JMP_UPPER_DEPS)
endif
ifneq ($(strip $(PP_DEPS)),)
-include $(PP_DEPS)
endif
ifneq ($(strip $(SX_DEPS)),)
-include $(SX_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(SX_UPPER_DEPS)),)
-include $(SX_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
RZA3M_Feather_Display.srec \

SECONDARY_SIZE += \
RZA3M_Feather_Display.siz \


# All Target
all: RZA3M_Feather_Display.elf secondary-outputs

# Tool invocations
RZA3M_Feather_Display.elf: $(OBJS) $(USER_OBJS) $(LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS) $(LINKER_SCRIPT)
	$(file > RZA3M_Feather_Display.elf.in,-mcpu=cortex-a55 -mcmodel=large -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -o "RZA3M_Feather_Display.elf" $(OBJS) $(USER_OBJS) -T "custom.ld" -L"/home/alex/e2_studio/workspace11/RZA3M_Feather_Display/script" -Wl,--start-group  -Wl,--end-group -nostartfiles -Xlinker --gc-sections -Wl,-Map,"RZA3M_Feather_Display.map")
	@echo Building target: $@ && aarch64-none-elf-gcc @"RZA3M_Feather_Display.elf.in"
RZA3M_Feather_Display.srec: RZA3M_Feather_Display.elf
	aarch64-none-elf-objcopy -O srec "RZA3M_Feather_Display.elf"  "RZA3M_Feather_Display.srec"
RZA3M_Feather_Display.siz: RZA3M_Feather_Display.elf
	aarch64-none-elf-size --format=berkeley "RZA3M_Feather_Display.elf"
# Other Targets
clean:
	-$(file > clean_file.tmp,  $(JMP_DEPS)  $(FSY_DEPS)  $(C_UPPER_DEPS)  $(SECONDARY_SIZE)  $(SRC_UPPER_DEPS)  $(P_UPPER_DEPS)  $(S_DEPS)  $(LST)  $(PP_UPPER_DEPS)  $(P_DEPS)  $(FSY_UPPER_DEPS)  $(C_DEPS)  $(SRC_DEPS)  $(JMP_UPPER_DEPS)  $(PP_DEPS)  $(SX_DEPS)  $(ASM_UPPER_DEPS)  $(SX_UPPER_DEPS)  $(OBJS)  $(SECONDARY_FLASH)  $(ASM_DEPS)  $(S_UPPER_DEPS)  $(MAP) )
	-@ xargs -P 2 -s 32000 -t -a clean_file.tmp $(RM)
	-@$(RM) clean_file.tmp
	-$(RM)  RZA3M_Feather_Display.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents 

-include ../makefile.targets

################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include biblioteki/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Gra_na_monitor_LCD.lss \

FLASH_IMAGE += \
Gra_na_monitor_LCD.hex \

EEPROM_IMAGE += \
Gra_na_monitor_LCD.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Gra_na_monitor_LCD.elf secondary-outputs

# Tool invocations
Gra_na_monitor_LCD.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Gra_na_monitor_LCD.map -mmcu=atmega32 -o "Gra_na_monitor_LCD.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Gra_na_monitor_LCD.lss: Gra_na_monitor_LCD.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Gra_na_monitor_LCD.elf  >"Gra_na_monitor_LCD.lss"
	@echo 'Finished building: $@'
	@echo ' '

Gra_na_monitor_LCD.hex: Gra_na_monitor_LCD.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex Gra_na_monitor_LCD.elf  "Gra_na_monitor_LCD.hex"
	@echo 'Finished building: $@'
	@echo ' '

Gra_na_monitor_LCD.eep: Gra_na_monitor_LCD.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Gra_na_monitor_LCD.elf  "Gra_na_monitor_LCD.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Gra_na_monitor_LCD.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Gra_na_monitor_LCD.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) Gra_na_monitor_LCD.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

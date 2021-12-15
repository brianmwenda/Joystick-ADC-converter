################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include Src/externallibs/util/subdir.mk
-include Src/externallibs/MATH/FIR/subdir.mk
-include Src/externallibs/MATH/subdir.mk
-include Src/externallibs/ECUAL/STEPPER/subdir.mk
-include Src/externallibs/ECUAL/SEVEN_SEGMENTS/subdir.mk
-include Src/externallibs/ECUAL/SERVO/subdir.mk
-include Src/externallibs/ECUAL/LM35/subdir.mk
-include Src/externallibs/ECUAL/LEDS/subdir.mk
-include Src/externallibs/ECUAL/LCD16x2/subdir.mk
-include Src/externallibs/ECUAL/KEYPAD/subdir.mk
-include Src/externallibs/ECUAL/JOYSTICK/subdir.mk
-include Src/externallibs/ECUAL/HCSR04/subdir.mk
-include Src/externallibs/ECUAL/DOT_MATRIX/subdir.mk
-include Src/externallibs/ECUAL/DC_MOTOR/subdir.mk
-include Src/externallibs/ECUAL/BUTTONS/subdir.mk
-include Src/subdir.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
JOYSTICKADC.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
JOYSTICKADC.list \

OBJCOPY_HEX += \
JOYSTICKADC.hex \


# All Target
all: JOYSTICKADC.elf secondary-outputs

# Tool invocations
JOYSTICKADC.elf: $(OBJS) $(USER_OBJS) ../STM32F103C8Tx_FLASH.ld
	arm-none-eabi-gcc -o "JOYSTICKADC.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"../STM32F103C8Tx_FLASH.ld" --specs=nosys.specs -Wl,-Map="JOYSTICKADC.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

JOYSTICKADC.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "JOYSTICKADC.list"
	@echo 'Finished building: $@'
	@echo ' '

JOYSTICKADC.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "JOYSTICKADC.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

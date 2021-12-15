################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/externallibs/ECUAL/LEDS/LEDS.c \
../Src/externallibs/ECUAL/LEDS/LEDS_cfg.c 

OBJS += \
./Src/externallibs/ECUAL/LEDS/LEDS.o \
./Src/externallibs/ECUAL/LEDS/LEDS_cfg.o 

C_DEPS += \
./Src/externallibs/ECUAL/LEDS/LEDS.d \
./Src/externallibs/ECUAL/LEDS/LEDS_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
Src/externallibs/ECUAL/LEDS/LEDS.o: ../Src/externallibs/ECUAL/LEDS/LEDS.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -Og -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Src/externallibs/ECUAL/LEDS/LEDS.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/externallibs/ECUAL/LEDS/LEDS_cfg.o: ../Src/externallibs/ECUAL/LEDS/LEDS_cfg.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -Og -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Src/externallibs/ECUAL/LEDS/LEDS_cfg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"


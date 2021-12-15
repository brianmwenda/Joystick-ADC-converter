################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/externallibs/ECUAL/LM35/LM35.c \
../Src/externallibs/ECUAL/LM35/LM35_cfg.c 

OBJS += \
./Src/externallibs/ECUAL/LM35/LM35.o \
./Src/externallibs/ECUAL/LM35/LM35_cfg.o 

C_DEPS += \
./Src/externallibs/ECUAL/LM35/LM35.d \
./Src/externallibs/ECUAL/LM35/LM35_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
Src/externallibs/ECUAL/LM35/LM35.o: ../Src/externallibs/ECUAL/LM35/LM35.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -Og -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Src/externallibs/ECUAL/LM35/LM35.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/externallibs/ECUAL/LM35/LM35_cfg.o: ../Src/externallibs/ECUAL/LM35/LM35_cfg.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -Og -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Src/externallibs/ECUAL/LM35/LM35_cfg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"


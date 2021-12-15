################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/externallibs/MATH/FIR/FIR.c 

OBJS += \
./Src/externallibs/MATH/FIR/FIR.o 

C_DEPS += \
./Src/externallibs/MATH/FIR/FIR.d 


# Each subdirectory must supply rules for building sources it contributes
Src/externallibs/MATH/FIR/FIR.o: ../Src/externallibs/MATH/FIR/FIR.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -Og -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Src/externallibs/MATH/FIR/FIR.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"


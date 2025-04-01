################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Simulink/TPGCI_2.c 

OBJS += \
./Drivers/Simulink/TPGCI_2.o 

C_DEPS += \
./Drivers/Simulink/TPGCI_2.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Simulink/%.o Drivers/Simulink/%.su Drivers/Simulink/%.cyclo: ../Drivers/Simulink/%.c Drivers/Simulink/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Drivers/Simulink -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Simulink

clean-Drivers-2f-Simulink:
	-$(RM) ./Drivers/Simulink/TPGCI_2.cyclo ./Drivers/Simulink/TPGCI_2.d ./Drivers/Simulink/TPGCI_2.o ./Drivers/Simulink/TPGCI_2.su

.PHONY: clean-Drivers-2f-Simulink


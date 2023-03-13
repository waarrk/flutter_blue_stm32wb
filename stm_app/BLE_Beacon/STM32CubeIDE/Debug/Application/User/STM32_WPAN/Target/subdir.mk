################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/waarrk/Documents/software_prayground/flutter_blue_stm32wb/stm_app/BLE_Beacon/STM32_WPAN/Target/hw_ipcc.c 

OBJS += \
./Application/User/STM32_WPAN/Target/hw_ipcc.o 

C_DEPS += \
./Application/User/STM32_WPAN/Target/hw_ipcc.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/STM32_WPAN/Target/hw_ipcc.o: /Users/waarrk/Documents/software_prayground/flutter_blue_stm32wb/stm_app/BLE_Beacon/STM32_WPAN/Target/hw_ipcc.c Application/User/STM32_WPAN/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DUSE_STM32WBXX_NUCLEO -DDEBUG -DSTM32WB55xx -c -I../../Core/Inc -I../../Utilities/lpm/tiny_lpm -I../../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci -I../../Utilities/sequencer -I../../Drivers/CMSIS/Device/ST/STM32WBxx/Include -I../../Middlewares/ST/STM32_WPAN/ble/svc/Inc -I../../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread -I../../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl -I../../STM32_WPAN/App -I../../Middlewares/ST/STM32_WPAN/ble/svc/Src -I../../Middlewares/ST/STM32_WPAN/ble/core -I../../Middlewares/ST/STM32_WPAN -I../../Middlewares/ST/STM32_WPAN/ble/core/template -I../../Drivers/BSP/P-NUCLEO-WB55.Nucleo -I../../Drivers/STM32WBxx_HAL_Driver/Inc/Legacy -I../../Drivers/STM32WBxx_HAL_Driver/Inc -I../../Middlewares/ST/STM32_WPAN/ble/core/auto -I../../Middlewares/ST/STM32_WPAN/utilities -I../../Middlewares/ST/STM32_WPAN/ble -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-STM32_WPAN-2f-Target

clean-Application-2f-User-2f-STM32_WPAN-2f-Target:
	-$(RM) ./Application/User/STM32_WPAN/Target/hw_ipcc.cyclo ./Application/User/STM32_WPAN/Target/hw_ipcc.d ./Application/User/STM32_WPAN/Target/hw_ipcc.o ./Application/User/STM32_WPAN/Target/hw_ipcc.su

.PHONY: clean-Application-2f-User-2f-STM32_WPAN-2f-Target


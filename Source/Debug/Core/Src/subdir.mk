################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/7Seg.c \
../Core/Src/blinking_led.c \
../Core/Src/error.c \
../Core/Src/fsm.c \
../Core/Src/input_processing.c \
../Core/Src/input_reading.c \
../Core/Src/led_display.c \
../Core/Src/main.c \
../Core/Src/schedule.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c \
../Core/Src/timer.c \
../Core/Src/traffic.c \
../Core/Src/watch_dog.c 

OBJS += \
./Core/Src/7Seg.o \
./Core/Src/blinking_led.o \
./Core/Src/error.o \
./Core/Src/fsm.o \
./Core/Src/input_processing.o \
./Core/Src/input_reading.o \
./Core/Src/led_display.o \
./Core/Src/main.o \
./Core/Src/schedule.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o \
./Core/Src/timer.o \
./Core/Src/traffic.o \
./Core/Src/watch_dog.o 

C_DEPS += \
./Core/Src/7Seg.d \
./Core/Src/blinking_led.d \
./Core/Src/error.d \
./Core/Src/fsm.d \
./Core/Src/input_processing.d \
./Core/Src/input_reading.d \
./Core/Src/led_display.d \
./Core/Src/main.d \
./Core/Src/schedule.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d \
./Core/Src/timer.d \
./Core/Src/traffic.d \
./Core/Src/watch_dog.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/7Seg.cyclo ./Core/Src/7Seg.d ./Core/Src/7Seg.o ./Core/Src/7Seg.su ./Core/Src/blinking_led.cyclo ./Core/Src/blinking_led.d ./Core/Src/blinking_led.o ./Core/Src/blinking_led.su ./Core/Src/error.cyclo ./Core/Src/error.d ./Core/Src/error.o ./Core/Src/error.su ./Core/Src/fsm.cyclo ./Core/Src/fsm.d ./Core/Src/fsm.o ./Core/Src/fsm.su ./Core/Src/input_processing.cyclo ./Core/Src/input_processing.d ./Core/Src/input_processing.o ./Core/Src/input_processing.su ./Core/Src/input_reading.cyclo ./Core/Src/input_reading.d ./Core/Src/input_reading.o ./Core/Src/input_reading.su ./Core/Src/led_display.cyclo ./Core/Src/led_display.d ./Core/Src/led_display.o ./Core/Src/led_display.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/schedule.cyclo ./Core/Src/schedule.d ./Core/Src/schedule.o ./Core/Src/schedule.su ./Core/Src/stm32f1xx_hal_msp.cyclo ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.cyclo ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.cyclo ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su ./Core/Src/timer.cyclo ./Core/Src/timer.d ./Core/Src/timer.o ./Core/Src/timer.su ./Core/Src/traffic.cyclo ./Core/Src/traffic.d ./Core/Src/traffic.o ./Core/Src/traffic.su ./Core/Src/watch_dog.cyclo ./Core/Src/watch_dog.d ./Core/Src/watch_dog.o ./Core/Src/watch_dog.su

.PHONY: clean-Core-2f-Src


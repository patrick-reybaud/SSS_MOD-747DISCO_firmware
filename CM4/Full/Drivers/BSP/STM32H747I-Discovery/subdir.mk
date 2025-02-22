################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_audio.c \
../Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_bus.c \
../Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_qspi.c \
../Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_sdram.c \
../Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_ts.c 

C_DEPS += \
./Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_audio.d \
./Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_bus.d \
./Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_qspi.d \
./Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_sdram.d \
./Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_ts.d 

OBJS += \
./Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_audio.o \
./Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_bus.o \
./Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_qspi.o \
./Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_sdram.o \
./Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_ts.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32H747I-Discovery/%.o Drivers/BSP/STM32H747I-Discovery/%.su: ../Drivers/BSP/STM32H747I-Discovery/%.c Drivers/BSP/STM32H747I-Discovery/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DARM_MATH_CM4 -DUSE_STM32H747I_DISCO -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32H747xx -DSCB_CCR_DC_Msk=0 -c -I"/home/zhonx/Documents/Workspace_Cube_SSS/SSS_MOD-747DISCO/CM4/Application/Inc" -I"/home/zhonx/Documents/Workspace_Cube_SSS/SSS_MOD-747DISCO/CM4/Core/Inc" -I"/home/zhonx/Documents/Workspace_Cube_SSS/SSS_MOD-747DISCO/CM4/Middlewares/Inc" -I"/home/zhonx/Documents/Workspace_Cube_SSS/SSS_MOD-747DISCO/CM4/Peripheral/Inc" -I"/home/zhonx/Documents/Workspace_Cube_SSS/SSS_MOD-747DISCO/CM4/Utilities/Fonts" -I"/home/zhonx/Documents/Workspace_Cube_SSS/SSS_MOD-747DISCO/CM4/Utilities/lcd" -I"/home/zhonx/Documents/Workspace_Cube_SSS/SSS_MOD-747DISCO/Common/Inc" -I"/home/zhonx/Documents/Workspace_Cube_SSS/SSS_MOD-747DISCO/CM4/Drivers/BSP/Components/Common" -I"/home/zhonx/Documents/Workspace_Cube_SSS/SSS_MOD-747DISCO/CM4/Drivers/BSP/Components/ft6x06" -I"/home/zhonx/Documents/Workspace_Cube_SSS/SSS_MOD-747DISCO/CM4/Drivers/BSP/Components/is42s32800j" -I"/home/zhonx/Documents/Workspace_Cube_SSS/SSS_MOD-747DISCO/CM4/Drivers/BSP/Components/otm8009a" -I"/home/zhonx/Documents/Workspace_Cube_SSS/SSS_MOD-747DISCO/CM4/Drivers/BSP/Components/mt25tl01g" -I"/home/zhonx/Documents/Workspace_Cube_SSS/SSS_MOD-747DISCO/CM4/Drivers/BSP/Components/wm8994" -I"/home/zhonx/Documents/Workspace_Cube_SSS/SSS_MOD-747DISCO/CM4/Drivers/BSP/STM32H747I-Discovery" -I"/home/zhonx/Documents/Workspace_Cube_SSS/SSS_MOD-747DISCO/CM4/Drivers/STM32H7xx_HAL_Driver" -I"/home/zhonx/Documents/Workspace_Cube_SSS/SSS_MOD-747DISCO/CM4/TouchGFX/App" -I"/home/zhonx/Documents/Workspace_Cube_SSS/SSS_MOD-747DISCO/CM4/TouchGFX/target" -I"/home/zhonx/Documents/Workspace_Cube_SSS/SSS_MOD-747DISCO/CM4/TouchGFX/target/generated" -I"/home/zhonx/Documents/Workspace_Cube_SSS/SSS_MOD-747DISCO/CM4/TouchGFX/generated/fonts/include" -I"/home/zhonx/Documents/Workspace_Cube_SSS/SSS_MOD-747DISCO/CM4/TouchGFX/generated/gui_generated/include" -I"/home/zhonx/Documents/Workspace_Cube_SSS/SSS_MOD-747DISCO/CM4/TouchGFX/generated/images/include" -I"/home/zhonx/Documents/Workspace_Cube_SSS/SSS_MOD-747DISCO/CM4/TouchGFX/generated/texts/include" -I"/home/zhonx/Documents/Workspace_Cube_SSS/SSS_MOD-747DISCO/CM4/TouchGFX/generated/videos/include" -I"/home/zhonx/Documents/Workspace_Cube_SSS/SSS_MOD-747DISCO/CM4/TouchGFX/gui/include" -I"/home/zhonx/Documents/Workspace_Cube_SSS/SSS_MOD-747DISCO/CM4/Middlewares/ST/touchgfx/framework/include" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/ST/ARM/DSP/Inc -I"/home/zhonx/Documents/Workspace_Cube_SSS/SSS_MOD-747DISCO/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2" -I"/home/zhonx/Documents/Workspace_Cube_SSS/SSS_MOD-747DISCO/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I../../Middlewares/Third_Party/FreeRTOS/Source/include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM32H747I-2d-Discovery

clean-Drivers-2f-BSP-2f-STM32H747I-2d-Discovery:
	-$(RM) ./Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_audio.d ./Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_audio.o ./Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_audio.su ./Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_bus.d ./Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_bus.o ./Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_bus.su ./Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_qspi.d ./Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_qspi.o ./Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_qspi.su ./Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_sdram.d ./Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_sdram.o ./Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_sdram.su ./Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_ts.d ./Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_ts.o ./Drivers/BSP/STM32H747I-Discovery/stm32h747i_discovery_ts.su

.PHONY: clean-Drivers-2f-BSP-2f-STM32H747I-2d-Discovery


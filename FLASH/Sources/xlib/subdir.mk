################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/xlib/ledasync.c" \
"../Sources/xlib/ledhandler.c" \

C_SRCS += \
../Sources/xlib/ledasync.c \
../Sources/xlib/ledhandler.c \

OBJS += \
./Sources/xlib/ledasync.o \
./Sources/xlib/ledhandler.o \

C_DEPS += \
./Sources/xlib/ledasync.d \
./Sources/xlib/ledhandler.d \

OBJS_QUOTED += \
"./Sources/xlib/ledasync.o" \
"./Sources/xlib/ledhandler.o" \

C_DEPS_QUOTED += \
"./Sources/xlib/ledasync.d" \
"./Sources/xlib/ledhandler.d" \

OBJS_OS_FORMAT += \
./Sources/xlib/ledasync.o \
./Sources/xlib/ledhandler.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/xlib/ledasync.o: ../Sources/xlib/ledasync.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/xlib/ledasync.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/xlib/ledasync.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/xlib/ledhandler.o: ../Sources/xlib/ledhandler.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/xlib/ledhandler.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/xlib/ledhandler.o"
	@echo 'Finished building: $<'
	@echo ' '



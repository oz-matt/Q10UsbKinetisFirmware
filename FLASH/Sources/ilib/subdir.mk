################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/ilib/aqua.c" \

C_SRCS += \
../Sources/ilib/aqua.c \

OBJS += \
./Sources/ilib/aqua.o \

C_DEPS += \
./Sources/ilib/aqua.d \

OBJS_QUOTED += \
"./Sources/ilib/aqua.o" \

C_DEPS_QUOTED += \
"./Sources/ilib/aqua.d" \

OBJS_OS_FORMAT += \
./Sources/ilib/aqua.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/ilib/aqua.o: ../Sources/ilib/aqua.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/ilib/aqua.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/ilib/aqua.o"
	@echo 'Finished building: $<'
	@echo ' '



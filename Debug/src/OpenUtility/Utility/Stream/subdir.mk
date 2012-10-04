################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/OpenUtility/Utility/Stream/CBlockStream.cpp \
../src/OpenUtility/Utility/Stream/CGalStream.cpp \
../src/OpenUtility/Utility/Stream/CStream.cpp 

OBJS += \
./src/OpenUtility/Utility/Stream/CBlockStream.o \
./src/OpenUtility/Utility/Stream/CGalStream.o \
./src/OpenUtility/Utility/Stream/CStream.o 

CPP_DEPS += \
./src/OpenUtility/Utility/Stream/CBlockStream.d \
./src/OpenUtility/Utility/Stream/CGalStream.d \
./src/OpenUtility/Utility/Stream/CStream.d 


# Each subdirectory must supply rules for building sources it contributes
src/OpenUtility/Utility/Stream/%.o: ../src/OpenUtility/Utility/Stream/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	arm-linux-gnueabihf-g++ -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/include -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/libc/usr/include -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/lib/gcc/arm-linux-gnueabihf/4.7.2/include-fixed -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/lib/gcc/arm-linux-gnueabihf/4.7.2/include -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/lib/gcc/arm-linux-gnueabihf/4.7.2/finclude -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



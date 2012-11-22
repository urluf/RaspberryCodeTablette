################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/src/OpenUtility/Utility/Stream/CBlockStream.cpp \
../src/src/OpenUtility/Utility/Stream/CGalStream.cpp \
../src/src/OpenUtility/Utility/Stream/CStream.cpp 

OBJS += \
./src/src/OpenUtility/Utility/Stream/CBlockStream.o \
./src/src/OpenUtility/Utility/Stream/CGalStream.o \
./src/src/OpenUtility/Utility/Stream/CStream.o 

CPP_DEPS += \
./src/src/OpenUtility/Utility/Stream/CBlockStream.d \
./src/src/OpenUtility/Utility/Stream/CGalStream.d \
./src/src/OpenUtility/Utility/Stream/CStream.d 


# Each subdirectory must supply rules for building sources it contributes
src/src/OpenUtility/Utility/Stream/%.o: ../src/src/OpenUtility/Utility/Stream/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	arm-linux-gnueabihf-g++ -DGLES2 -DSTANDALONE -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/include -I/home/developpeur/workspace/RaspberryPi/include -I/home/developpeur/workspace/RaspberryPi/src/OpenUtility -I/home/developpeur/workspace/RaspberryPi/include/interface/vcos/pthreads -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/libc/usr/include -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/lib/gcc/arm-linux-gnueabihf/4.7.2/include-fixed -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/lib/gcc/arm-linux-gnueabihf/4.7.2/include -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/lib/gcc/arm-linux-gnueabihf/4.7.2/finclude -O0 -g -I src/OpenUtility -Wall -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" -c "$<"
	@echo 'Finished building: $<'
	@echo ' '



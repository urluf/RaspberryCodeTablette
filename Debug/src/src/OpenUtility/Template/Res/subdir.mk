################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../src/src/OpenUtility/Template/Res/CAllocator.cxx \
../src/src/OpenUtility/Template/Res/CListe.cxx \
../src/src/OpenUtility/Template/Res/CMap.cxx \
../src/src/OpenUtility/Template/Res/CMat4x4.cxx \
../src/src/OpenUtility/Template/Res/CTable.cxx \
../src/src/OpenUtility/Template/Res/CVector.cxx 

OBJS += \
./src/src/OpenUtility/Template/Res/CAllocator.o \
./src/src/OpenUtility/Template/Res/CListe.o \
./src/src/OpenUtility/Template/Res/CMap.o \
./src/src/OpenUtility/Template/Res/CMat4x4.o \
./src/src/OpenUtility/Template/Res/CTable.o \
./src/src/OpenUtility/Template/Res/CVector.o 

CXX_DEPS += \
./src/src/OpenUtility/Template/Res/CAllocator.d \
./src/src/OpenUtility/Template/Res/CListe.d \
./src/src/OpenUtility/Template/Res/CMap.d \
./src/src/OpenUtility/Template/Res/CMat4x4.d \
./src/src/OpenUtility/Template/Res/CTable.d \
./src/src/OpenUtility/Template/Res/CVector.d 


# Each subdirectory must supply rules for building sources it contributes
src/src/OpenUtility/Template/Res/%.o: ../src/src/OpenUtility/Template/Res/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	arm-linux-gnueabihf-g++ -DGLES2 -DSTANDALONE -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/include -I/home/developpeur/workspace/RaspberryPi/include -I/home/developpeur/workspace/RaspberryPi/src/OpenUtility -I/home/developpeur/workspace/RaspberryPi/include/interface/vcos/pthreads -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/libc/usr/include -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/lib/gcc/arm-linux-gnueabihf/4.7.2/include-fixed -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/lib/gcc/arm-linux-gnueabihf/4.7.2/include -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/lib/gcc/arm-linux-gnueabihf/4.7.2/finclude -O0 -g -I src/OpenUtility -Wall -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" -c "$<"
	@echo 'Finished building: $<'
	@echo ' '



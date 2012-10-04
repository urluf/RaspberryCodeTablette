################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/OpenUtility/Utility/3D/3D.cpp \
../src/OpenUtility/Utility/3D/CShaderFile.cpp \
../src/OpenUtility/Utility/3D/CShaderProgram.cpp \
../src/OpenUtility/Utility/3D/CTexture.cpp \
../src/OpenUtility/Utility/3D/CTexturePngLoader.cpp \
../src/OpenUtility/Utility/3D/TextureLoaderInit.cpp 

OBJS += \
./src/OpenUtility/Utility/3D/3D.o \
./src/OpenUtility/Utility/3D/CShaderFile.o \
./src/OpenUtility/Utility/3D/CShaderProgram.o \
./src/OpenUtility/Utility/3D/CTexture.o \
./src/OpenUtility/Utility/3D/CTexturePngLoader.o \
./src/OpenUtility/Utility/3D/TextureLoaderInit.o 

CPP_DEPS += \
./src/OpenUtility/Utility/3D/3D.d \
./src/OpenUtility/Utility/3D/CShaderFile.d \
./src/OpenUtility/Utility/3D/CShaderProgram.d \
./src/OpenUtility/Utility/3D/CTexture.d \
./src/OpenUtility/Utility/3D/CTexturePngLoader.d \
./src/OpenUtility/Utility/3D/TextureLoaderInit.d 


# Each subdirectory must supply rules for building sources it contributes
src/OpenUtility/Utility/3D/%.o: ../src/OpenUtility/Utility/3D/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	arm-linux-gnueabihf-g++ -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/include -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/libc/usr/include -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/lib/gcc/arm-linux-gnueabihf/4.7.2/include-fixed -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/lib/gcc/arm-linux-gnueabihf/4.7.2/include -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/lib/gcc/arm-linux-gnueabihf/4.7.2/finclude -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



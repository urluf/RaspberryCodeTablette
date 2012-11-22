################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/src/OpenUtility/Utility/3D/3D.cpp \
../src/src/OpenUtility/Utility/3D/CShaderFile.cpp \
../src/src/OpenUtility/Utility/3D/CShaderProgram.cpp \
../src/src/OpenUtility/Utility/3D/CTexture.cpp \
../src/src/OpenUtility/Utility/3D/CTexturePngLoader.cpp \
../src/src/OpenUtility/Utility/3D/CTextureQuad.cpp \
../src/src/OpenUtility/Utility/3D/TextureLoaderInit.cpp 

OBJS += \
./src/src/OpenUtility/Utility/3D/3D.o \
./src/src/OpenUtility/Utility/3D/CShaderFile.o \
./src/src/OpenUtility/Utility/3D/CShaderProgram.o \
./src/src/OpenUtility/Utility/3D/CTexture.o \
./src/src/OpenUtility/Utility/3D/CTexturePngLoader.o \
./src/src/OpenUtility/Utility/3D/CTextureQuad.o \
./src/src/OpenUtility/Utility/3D/TextureLoaderInit.o 

CPP_DEPS += \
./src/src/OpenUtility/Utility/3D/3D.d \
./src/src/OpenUtility/Utility/3D/CShaderFile.d \
./src/src/OpenUtility/Utility/3D/CShaderProgram.d \
./src/src/OpenUtility/Utility/3D/CTexture.d \
./src/src/OpenUtility/Utility/3D/CTexturePngLoader.d \
./src/src/OpenUtility/Utility/3D/CTextureQuad.d \
./src/src/OpenUtility/Utility/3D/TextureLoaderInit.d 


# Each subdirectory must supply rules for building sources it contributes
src/src/OpenUtility/Utility/3D/%.o: ../src/src/OpenUtility/Utility/3D/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	arm-linux-gnueabihf-g++ -DGLES2 -DSTANDALONE -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/include -I/home/developpeur/workspace/RaspberryPi/include -I/home/developpeur/workspace/RaspberryPi/src/OpenUtility -I/home/developpeur/workspace/RaspberryPi/include/interface/vcos/pthreads -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/libc/usr/include -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/lib/gcc/arm-linux-gnueabihf/4.7.2/include-fixed -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/lib/gcc/arm-linux-gnueabihf/4.7.2/include -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/lib/gcc/arm-linux-gnueabihf/4.7.2/finclude -O0 -g -I src/OpenUtility -Wall -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" -c "$<"
	@echo 'Finished building: $<'
	@echo ' '



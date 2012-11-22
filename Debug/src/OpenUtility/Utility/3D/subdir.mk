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
../src/OpenUtility/Utility/3D/CTextureQuad.cpp \
../src/OpenUtility/Utility/3D/TextureLoaderInit.cpp 

OBJS += \
./src/OpenUtility/Utility/3D/3D.o \
./src/OpenUtility/Utility/3D/CShaderFile.o \
./src/OpenUtility/Utility/3D/CShaderProgram.o \
./src/OpenUtility/Utility/3D/CTexture.o \
./src/OpenUtility/Utility/3D/CTexturePngLoader.o \
./src/OpenUtility/Utility/3D/CTextureQuad.o \
./src/OpenUtility/Utility/3D/TextureLoaderInit.o 

CPP_DEPS += \
./src/OpenUtility/Utility/3D/3D.d \
./src/OpenUtility/Utility/3D/CShaderFile.d \
./src/OpenUtility/Utility/3D/CShaderProgram.d \
./src/OpenUtility/Utility/3D/CTexture.d \
./src/OpenUtility/Utility/3D/CTexturePngLoader.d \
./src/OpenUtility/Utility/3D/CTextureQuad.d \
./src/OpenUtility/Utility/3D/TextureLoaderInit.d 


# Each subdirectory must supply rules for building sources it contributes
src/OpenUtility/Utility/3D/%.o: ../src/OpenUtility/Utility/3D/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	arm-linux-gnueabihf-g++ -DGLES2 -D__STDC_CONSTANT_MACROS -D__STDC_LIMIT_MACROS -DTARGET_POSIX -D_LINUX -DPIC -D_REENTRANT -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DHAVE_LIBOPENMAX=2 -DOMX -DOMX_SKIP64BIT -DUSE_EXTERNAL_OMX -DHAVE_LIBBCM_HOST -DUSE_EXTERNAL_LIBBCM_HOST -DUSE_VCHIQ_ARM -DSTANDALONE -U_FORTIFY_SOURCE -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/include -I/home/developpeur/workspace/RaspberryPi/include -I/opt/vc/include/ -I/opt/vc/include/interface/vcos/pthreads -I/home/developpeur/workspace/RaspberryPi/include/libpng -I/home/developpeur/workspace/RaspberryPi/src/OpenUtility -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/libc/usr/include -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/lib/gcc/arm-linux-gnueabihf/4.7.2/include-fixed -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/lib/gcc/arm-linux-gnueabihf/4.7.2/include -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/lib/gcc/arm-linux-gnueabihf/4.7.2/finclude -O0 -fPIC -ftree-vectorize -pipe -Wno-psabi -pthread -g -I src/OpenUtility -Wall -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" -c "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BorneInfo-master/src/OpenUtility/Utility/3D/3D.cpp \
../BorneInfo-master/src/OpenUtility/Utility/3D/C3DText.cpp \
../BorneInfo-master/src/OpenUtility/Utility/3D/CFontEngine.cpp \
../BorneInfo-master/src/OpenUtility/Utility/3D/CShaderFile.cpp \
../BorneInfo-master/src/OpenUtility/Utility/3D/CShaderProgram.cpp \
../BorneInfo-master/src/OpenUtility/Utility/3D/CTexture.cpp \
../BorneInfo-master/src/OpenUtility/Utility/3D/CTextureMultiQuad.cpp \
../BorneInfo-master/src/OpenUtility/Utility/3D/CTexturePngLoader.cpp \
../BorneInfo-master/src/OpenUtility/Utility/3D/CTextureQuad.cpp \
../BorneInfo-master/src/OpenUtility/Utility/3D/TextureLoaderInit.cpp 

OBJS += \
./BorneInfo-master/src/OpenUtility/Utility/3D/3D.o \
./BorneInfo-master/src/OpenUtility/Utility/3D/C3DText.o \
./BorneInfo-master/src/OpenUtility/Utility/3D/CFontEngine.o \
./BorneInfo-master/src/OpenUtility/Utility/3D/CShaderFile.o \
./BorneInfo-master/src/OpenUtility/Utility/3D/CShaderProgram.o \
./BorneInfo-master/src/OpenUtility/Utility/3D/CTexture.o \
./BorneInfo-master/src/OpenUtility/Utility/3D/CTextureMultiQuad.o \
./BorneInfo-master/src/OpenUtility/Utility/3D/CTexturePngLoader.o \
./BorneInfo-master/src/OpenUtility/Utility/3D/CTextureQuad.o \
./BorneInfo-master/src/OpenUtility/Utility/3D/TextureLoaderInit.o 

CPP_DEPS += \
./BorneInfo-master/src/OpenUtility/Utility/3D/3D.d \
./BorneInfo-master/src/OpenUtility/Utility/3D/C3DText.d \
./BorneInfo-master/src/OpenUtility/Utility/3D/CFontEngine.d \
./BorneInfo-master/src/OpenUtility/Utility/3D/CShaderFile.d \
./BorneInfo-master/src/OpenUtility/Utility/3D/CShaderProgram.d \
./BorneInfo-master/src/OpenUtility/Utility/3D/CTexture.d \
./BorneInfo-master/src/OpenUtility/Utility/3D/CTextureMultiQuad.d \
./BorneInfo-master/src/OpenUtility/Utility/3D/CTexturePngLoader.d \
./BorneInfo-master/src/OpenUtility/Utility/3D/CTextureQuad.d \
./BorneInfo-master/src/OpenUtility/Utility/3D/TextureLoaderInit.d 


# Each subdirectory must supply rules for building sources it contributes
BorneInfo-master/src/OpenUtility/Utility/3D/%.o: ../BorneInfo-master/src/OpenUtility/Utility/3D/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	arm-linux-gnueabihf-g++ -DGLES2 -D__STDC_CONSTANT_MACROS -D__STDC_LIMIT_MACROS -DTARGET_POSIX -D_LINUX -DPIC -D_REENTRANT -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DHAVE_LIBOPENMAX=2 -DOMX -DOMX_SKIP64BIT -DUSE_EXTERNAL_OMX -DHAVE_LIBBCM_HOST -DUSE_EXTERNAL_LIBBCM_HOST -DUSE_VCHIQ_ARM -DSTANDALONE -U_FORTIFY_SOURCE -I/home/developpeur/workspace/RaspberryPi/include/ -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/include -I/opt/vc/include/ -I/opt/vc/include/interface/vcos/pthreads -I/home/developpeur/workspace/RaspberryPi/include/libpng -I/home/developpeur/workspace/RaspberryPi/src/OpenUtility -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/libc/usr/include -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/lib/gcc/arm-linux-gnueabihf/4.7.2/include-fixed -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/lib/gcc/arm-linux-gnueabihf/4.7.2/include -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/lib/gcc/arm-linux-gnueabihf/4.7.2/finclude -O0 -fPIC -ftree-vectorize -pipe -Wno-psabi -pthread -g -I src/OpenUtility -Wall -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" -c "$<"
	@echo 'Finished building: $<'
	@echo ' '



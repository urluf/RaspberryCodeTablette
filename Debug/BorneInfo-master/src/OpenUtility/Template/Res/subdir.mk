################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../BorneInfo-master/src/OpenUtility/Template/Res/CAllocator.cxx \
../BorneInfo-master/src/OpenUtility/Template/Res/CListe.cxx \
../BorneInfo-master/src/OpenUtility/Template/Res/CMap.cxx \
../BorneInfo-master/src/OpenUtility/Template/Res/CMat4x4.cxx \
../BorneInfo-master/src/OpenUtility/Template/Res/CTable.cxx \
../BorneInfo-master/src/OpenUtility/Template/Res/CVector.cxx 

OBJS += \
./BorneInfo-master/src/OpenUtility/Template/Res/CAllocator.o \
./BorneInfo-master/src/OpenUtility/Template/Res/CListe.o \
./BorneInfo-master/src/OpenUtility/Template/Res/CMap.o \
./BorneInfo-master/src/OpenUtility/Template/Res/CMat4x4.o \
./BorneInfo-master/src/OpenUtility/Template/Res/CTable.o \
./BorneInfo-master/src/OpenUtility/Template/Res/CVector.o 

CXX_DEPS += \
./BorneInfo-master/src/OpenUtility/Template/Res/CAllocator.d \
./BorneInfo-master/src/OpenUtility/Template/Res/CListe.d \
./BorneInfo-master/src/OpenUtility/Template/Res/CMap.d \
./BorneInfo-master/src/OpenUtility/Template/Res/CMat4x4.d \
./BorneInfo-master/src/OpenUtility/Template/Res/CTable.d \
./BorneInfo-master/src/OpenUtility/Template/Res/CVector.d 


# Each subdirectory must supply rules for building sources it contributes
BorneInfo-master/src/OpenUtility/Template/Res/%.o: ../BorneInfo-master/src/OpenUtility/Template/Res/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	arm-linux-gnueabihf-g++ -DGLES2 -D__STDC_CONSTANT_MACROS -D__STDC_LIMIT_MACROS -DTARGET_POSIX -D_LINUX -DPIC -D_REENTRANT -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DHAVE_LIBOPENMAX=2 -DOMX -DOMX_SKIP64BIT -DUSE_EXTERNAL_OMX -DHAVE_LIBBCM_HOST -DUSE_EXTERNAL_LIBBCM_HOST -DUSE_VCHIQ_ARM -DSTANDALONE -U_FORTIFY_SOURCE -I/home/developpeur/workspace/RaspberryPi/include/ -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/include -I/opt/vc/include/ -I/opt/vc/include/interface/vcos/pthreads -I/home/developpeur/workspace/RaspberryPi/include/libpng -I/home/developpeur/workspace/RaspberryPi/src/OpenUtility -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/libc/usr/include -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/lib/gcc/arm-linux-gnueabihf/4.7.2/include-fixed -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/lib/gcc/arm-linux-gnueabihf/4.7.2/include -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/lib/gcc/arm-linux-gnueabihf/4.7.2/finclude -O0 -fPIC -ftree-vectorize -pipe -Wno-psabi -pthread -g -I src/OpenUtility -Wall -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" -c "$<"
	@echo 'Finished building: $<'
	@echo ' '



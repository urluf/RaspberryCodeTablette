################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/model/json_spirit_v4.05/json_test/json_spirit_reader_test.cpp \
../src/model/json_spirit_v4.05/json_test/json_spirit_stream_reader_test.cpp \
../src/model/json_spirit_v4.05/json_test/json_spirit_utils_test.cpp \
../src/model/json_spirit_v4.05/json_test/json_spirit_value_test.cpp \
../src/model/json_spirit_v4.05/json_test/json_spirit_writer_test.cpp \
../src/model/json_spirit_v4.05/json_test/json_test.cpp \
../src/model/json_spirit_v4.05/json_test/utils_test.cpp 

OBJS += \
./src/model/json_spirit_v4.05/json_test/json_spirit_reader_test.o \
./src/model/json_spirit_v4.05/json_test/json_spirit_stream_reader_test.o \
./src/model/json_spirit_v4.05/json_test/json_spirit_utils_test.o \
./src/model/json_spirit_v4.05/json_test/json_spirit_value_test.o \
./src/model/json_spirit_v4.05/json_test/json_spirit_writer_test.o \
./src/model/json_spirit_v4.05/json_test/json_test.o \
./src/model/json_spirit_v4.05/json_test/utils_test.o 

CPP_DEPS += \
./src/model/json_spirit_v4.05/json_test/json_spirit_reader_test.d \
./src/model/json_spirit_v4.05/json_test/json_spirit_stream_reader_test.d \
./src/model/json_spirit_v4.05/json_test/json_spirit_utils_test.d \
./src/model/json_spirit_v4.05/json_test/json_spirit_value_test.d \
./src/model/json_spirit_v4.05/json_test/json_spirit_writer_test.d \
./src/model/json_spirit_v4.05/json_test/json_test.d \
./src/model/json_spirit_v4.05/json_test/utils_test.d 


# Each subdirectory must supply rules for building sources it contributes
src/model/json_spirit_v4.05/json_test/%.o: ../src/model/json_spirit_v4.05/json_test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	arm-linux-gnueabihf-g++ -DGLES2 -D__STDC_CONSTANT_MACROS -D__STDC_LIMIT_MACROS -DTARGET_POSIX -D_LINUX -DPIC -D_REENTRANT -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DHAVE_LIBOPENMAX=2 -DOMX -DOMX_SKIP64BIT -DUSE_EXTERNAL_OMX -DHAVE_LIBBCM_HOST -DUSE_EXTERNAL_LIBBCM_HOST -DUSE_VCHIQ_ARM -DSTANDALONE -U_FORTIFY_SOURCE -I/home/developpeur/workspace/RaspberryPi/include/ -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/include -I/opt/vc/include/ -I/opt/vc/include/interface/vcos/pthreads -I/home/developpeur/workspace/RaspberryPi/include/libpng -I/home/developpeur/workspace/RaspberryPi/src/OpenUtility -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/libc/usr/include -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/lib/gcc/arm-linux-gnueabihf/4.7.2/include-fixed -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/lib/gcc/arm-linux-gnueabihf/4.7.2/include -I/home/raspberry/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/lib/gcc/arm-linux-gnueabihf/4.7.2/finclude -O0 -fPIC -ftree-vectorize -pipe -Wno-psabi -pthread -g -I src/OpenUtility -Wall -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" -c "$<"
	@echo 'Finished building: $<'
	@echo ' '


################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/model/subdir.mk
-include src/graphic/subdir.mk
-include src/controller/subdir.mk
-include src/OpenUtility/Utility/Stream/subdir.mk
-include src/OpenUtility/Utility/Parallelism/subdir.mk
-include src/OpenUtility/Utility/Network/subdir.mk
-include src/OpenUtility/Utility/Math/subdir.mk
-include src/OpenUtility/Utility/Filesystem/subdir.mk
-include src/OpenUtility/Utility/3D/subdir.mk
-include src/OpenUtility/Utility/subdir.mk
-include src/subdir.mk
-include obj/src/OpenUtility/Utility/Stream/subdir.mk
-include obj/src/OpenUtility/Utility/Parallelism/subdir.mk
-include obj/src/OpenUtility/Utility/Network/subdir.mk
-include obj/src/OpenUtility/Utility/Math/subdir.mk
-include obj/src/OpenUtility/Utility/Filesystem/subdir.mk
-include obj/src/OpenUtility/Utility/3D/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: RaspberryPi

# Tool invocations
RaspberryPi: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	arm-linux-gnueabihf-g++ -L/opt/vc/lib -L/home/developpeur/workspace/RaspberryPi/include/libpng -L/home/developpeur/workspace/RaspberryPi/libs -L/home/developpeur/workspace/RaspberryPi/libs/libpng -rdynamic -pthread -Wl,-rpath /opt/vc/lib -Wl,-rpath-link /opt/vc/lib -Wl,-rpath-link /home/developpeur/workspace/RaspberryPi/libs -o "RaspberryPi" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) RaspberryPi
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

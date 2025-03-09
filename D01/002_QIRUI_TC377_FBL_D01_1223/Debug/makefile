################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Swap/UCB_Driver/subdir.mk
-include Swap/subdir.mk
-include MCAL/Wdg_17_Scu/ssc/src/subdir.mk
-include MCAL/Tricore/Cfg_Ssw/TC37A/subdir.mk
-include MCAL/Ssw/TC37A/Tricore/subdir.mk
-include MCAL/Ssw/TC37A/Irq/Traps/subdir.mk
-include MCAL/Ssw/TC37A/Common/subdir.mk
-include MCAL/Spi/ssc/src/subdir.mk
-include MCAL/Pwm_17_GtmCcu6/ssc/src/subdir.mk
-include MCAL/Port/ssc/src/subdir.mk
-include MCAL/Mcu/ssc/src/subdir.mk
-include MCAL/McalLib/ssc/src/subdir.mk
-include MCAL/Irq/ssc/src/subdir.mk
-include MCAL/Integration/subdir.mk
-include MCAL/Icu_17_TimerIp/ssc/src/subdir.mk
-include MCAL/Fls_17_Dmu/ssc/src/subdir.mk
-include MCAL/FlsLoader/Ssc/src/subdir.mk
-include MCAL/Fee/ssc/src/subdir.mk
-include MCAL/Dma/ssc/src/subdir.mk
-include MCAL/Dio/ssc/src/subdir.mk
-include MCAL/Can_17_McmCan/ssc/src/subdir.mk
-include MCAL/Bfx/ssc/src/subdir.mk
-include MCAL/Autosar_Srv/subdir.mk
-include MCAL/Adc/ssc/src/subdir.mk
-include Libraries/Impl/subdir.mk
-include Libraries/Flash/Std/subdir.mk
-include Libraries/Compilers/subdir.mk
-include Libraries/Bsp/subdir.mk
-include Flash_Drv/PFlash/subdir.mk
-include Flash_Drv/DFlash/subdir.mk
-include Config/RTE_Config/subdir.mk
-include Config/Os_Config/subdir.mk
-include Config/Memory_Config/subdir.mk
-include Config/MCAL_Config/src/subdir.mk
-include Config/BSW_Config/subdir.mk
-include CDD/Wdg_17_Scu/subdir.mk
-include CDD/UDS/subdir.mk
-include CDD/TLF35584/subdir.mk
-include CDD/SysVol/subdir.mk
-include CDD/Power/subdir.mk
-include CDD/CddHsm/TestCode/demoapp/src/subdir.mk
-include CDD/CddHsm/TestCode/UserTest_Task/subdir.mk
-include CDD/CddHsm/Hsm_Mcal/subdir.mk
-include CDD/CddHsm/Hsm_Com/subdir.mk
-include CDD/CddHsm/Demo/subdir.mk
-include CDD/CddHsm/Cry/subdir.mk
-include BSW/SystemService/Os/Kernel/subdir.mk
-include BSW/SystemService/Os/Arch/subdir.mk
-include BSW/SystemService/FreeRTimer/subdir.mk
-include BSW/SystemService/EcuM/subdir.mk
-include BSW/SystemService/E2E/subdir.mk
-include BSW/SystemService/Dem/subdir.mk
-include BSW/SystemService/ComM/subdir.mk
-include BSW/SystemService/BswM/subdir.mk
-include BSW/Memmory/NvM/subdir.mk
-include BSW/Memmory/MemIf/subdir.mk
-include BSW/Memmory/Crc/subdir.mk
-include BSW/Communication/XCP/subdir.mk
-include BSW/Communication/Common/PDUR/subdir.mk
-include BSW/Communication/Common/NmIf/subdir.mk
-include BSW/Communication/Common/Dcm/DcmDsp/UDS/subdir.mk
-include BSW/Communication/Common/Dcm/DcmDsp/OBD/subdir.mk
-include BSW/Communication/Common/Dcm/DcmDsp/subdir.mk
-include BSW/Communication/Common/Dcm/DcmDsl/subdir.mk
-include BSW/Communication/Common/Dcm/DcmDsd/subdir.mk
-include BSW/Communication/Common/Dcm/subdir.mk
-include BSW/Communication/Common/Com/subdir.mk
-include BSW/Communication/CAN/CanTp/subdir.mk
-include BSW/Communication/CAN/CanSM/subdir.mk
-include BSW/Communication/CAN/CanNm/subdir.mk
-include BSW/Communication/CAN/CanIf/subdir.mk
-include BSW/CommonInclude/subdir.mk
-include ASW/Time/subdir.mk
-include ASW/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := 002_QIRUI_TC377_FBL
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_SIZE += \
002_QIRUI_TC377_FBL.siz \


# All Target
all: main-build

# Main-build Target
main-build: 002_QIRUI_TC377_FBL.elf secondary-outputs

# Tool invocations
002_QIRUI_TC377_FBL.elf: $(OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: TASKING Linker'
	cctc -lrt -lfp_fpu -lcs_fpu  -Wl-Oc -Wl-OL -Wl-Ot -Wl-OX -Wl-OY -Wl--map-file="002_QIRUI_TC377_FBL.map" -Wl-mc -Wl-mf -Wl-mi -Wl-mk -Wl-ml -Wl-mm -Wl-md -Wl-mr -Wl-mu --no-warnings= -Wl--error-limit=42 --exceptions --strict --anachronisms --force-c++ -Ctc37x   -o"002_QIRUI_TC377_FBL.elf" -Wl-o"002_QIRUI_TC377_FBL.hex:IHEX" --lsl-core=vtc  --lsl-file=../Lcf_Tasking_Tricore_Tc.lsl $(OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

002_QIRUI_TC377_FBL.siz: 002_QIRUI_TC377_FBL.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	elfsize  "002_QIRUI_TC377_FBL.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	find . ! -name "*.mk" ! -name "makefile" ! -name "." -type f -delete 
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents main-build

-include ../makefile.targets

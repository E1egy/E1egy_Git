################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CDD/CddHsm/Demo/Csm_MacVerify.c \
../CDD/CddHsm/Demo/HostCom_Test.c \
../CDD/CddHsm/Demo/SSC_MacVerify.c \
../CDD/CddHsm/Demo/SampleCode.c \
../CDD/CddHsm/Demo/She_Demo.c \
../CDD/CddHsm/Demo/TestApi.c \
../CDD/CddHsm/Demo/TestHsm.c \
../CDD/CddHsm/Demo/TestHsmCom.c \
../CDD/CddHsm/Demo/TestHsmMcal.c \
../CDD/CddHsm/Demo/TestHsm_Cache.c \
../CDD/CddHsm/Demo/TestHsm_CryGetStatus.c \
../CDD/CddHsm/Demo/TestHsm_Debug.c \
../CDD/CddHsm/Demo/TestHsm_Gcm.c \
../CDD/CddHsm/Demo/TestHsm_GetUID.c \
../CDD/CddHsm/Demo/TestHsm_Key.c \
../CDD/CddHsm/Demo/TestHsm_SecureBoot.c \
../CDD/CddHsm/Demo/TestHsm_Xts.c \
../CDD/CddHsm/Demo/TestHsm_cbc.c \
../CDD/CddHsm/Demo/TestHsm_ecb.c \
../CDD/CddHsm/Demo/TestHsm_mac.c \
../CDD/CddHsm/Demo/TestHsm_rng.c 

OBJS += \
./CDD/CddHsm/Demo/Csm_MacVerify.o \
./CDD/CddHsm/Demo/HostCom_Test.o \
./CDD/CddHsm/Demo/SSC_MacVerify.o \
./CDD/CddHsm/Demo/SampleCode.o \
./CDD/CddHsm/Demo/She_Demo.o \
./CDD/CddHsm/Demo/TestApi.o \
./CDD/CddHsm/Demo/TestHsm.o \
./CDD/CddHsm/Demo/TestHsmCom.o \
./CDD/CddHsm/Demo/TestHsmMcal.o \
./CDD/CddHsm/Demo/TestHsm_Cache.o \
./CDD/CddHsm/Demo/TestHsm_CryGetStatus.o \
./CDD/CddHsm/Demo/TestHsm_Debug.o \
./CDD/CddHsm/Demo/TestHsm_Gcm.o \
./CDD/CddHsm/Demo/TestHsm_GetUID.o \
./CDD/CddHsm/Demo/TestHsm_Key.o \
./CDD/CddHsm/Demo/TestHsm_SecureBoot.o \
./CDD/CddHsm/Demo/TestHsm_Xts.o \
./CDD/CddHsm/Demo/TestHsm_cbc.o \
./CDD/CddHsm/Demo/TestHsm_ecb.o \
./CDD/CddHsm/Demo/TestHsm_mac.o \
./CDD/CddHsm/Demo/TestHsm_rng.o 

COMPILED_SRCS += \
./CDD/CddHsm/Demo/Csm_MacVerify.src \
./CDD/CddHsm/Demo/HostCom_Test.src \
./CDD/CddHsm/Demo/SSC_MacVerify.src \
./CDD/CddHsm/Demo/SampleCode.src \
./CDD/CddHsm/Demo/She_Demo.src \
./CDD/CddHsm/Demo/TestApi.src \
./CDD/CddHsm/Demo/TestHsm.src \
./CDD/CddHsm/Demo/TestHsmCom.src \
./CDD/CddHsm/Demo/TestHsmMcal.src \
./CDD/CddHsm/Demo/TestHsm_Cache.src \
./CDD/CddHsm/Demo/TestHsm_CryGetStatus.src \
./CDD/CddHsm/Demo/TestHsm_Debug.src \
./CDD/CddHsm/Demo/TestHsm_Gcm.src \
./CDD/CddHsm/Demo/TestHsm_GetUID.src \
./CDD/CddHsm/Demo/TestHsm_Key.src \
./CDD/CddHsm/Demo/TestHsm_SecureBoot.src \
./CDD/CddHsm/Demo/TestHsm_Xts.src \
./CDD/CddHsm/Demo/TestHsm_cbc.src \
./CDD/CddHsm/Demo/TestHsm_ecb.src \
./CDD/CddHsm/Demo/TestHsm_mac.src \
./CDD/CddHsm/Demo/TestHsm_rng.src 

C_DEPS += \
./CDD/CddHsm/Demo/Csm_MacVerify.d \
./CDD/CddHsm/Demo/HostCom_Test.d \
./CDD/CddHsm/Demo/SSC_MacVerify.d \
./CDD/CddHsm/Demo/SampleCode.d \
./CDD/CddHsm/Demo/She_Demo.d \
./CDD/CddHsm/Demo/TestApi.d \
./CDD/CddHsm/Demo/TestHsm.d \
./CDD/CddHsm/Demo/TestHsmCom.d \
./CDD/CddHsm/Demo/TestHsmMcal.d \
./CDD/CddHsm/Demo/TestHsm_Cache.d \
./CDD/CddHsm/Demo/TestHsm_CryGetStatus.d \
./CDD/CddHsm/Demo/TestHsm_Debug.d \
./CDD/CddHsm/Demo/TestHsm_Gcm.d \
./CDD/CddHsm/Demo/TestHsm_GetUID.d \
./CDD/CddHsm/Demo/TestHsm_Key.d \
./CDD/CddHsm/Demo/TestHsm_SecureBoot.d \
./CDD/CddHsm/Demo/TestHsm_Xts.d \
./CDD/CddHsm/Demo/TestHsm_cbc.d \
./CDD/CddHsm/Demo/TestHsm_ecb.d \
./CDD/CddHsm/Demo/TestHsm_mac.d \
./CDD/CddHsm/Demo/TestHsm_rng.d 


# Each subdirectory must supply rules for building sources it contributes
CDD/CddHsm/Demo/%.src: ../CDD/CddHsm/Demo/%.c CDD/CddHsm/Demo/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D_TASKING_C_TRICORE_=1 -DTEST_APP=1 -DAPP_SW=2 -DDEMO_APP=2 -D_CPU__=tc37x -DENABLE_HSM=1 -DTEST_PRINT=0 "-fE:/SVN/D01/002_QIRUI_TC377_FBL_D01_1223_0116/002_QIRUI_TC377_FBL_D01_1223/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=2 --compact-max-size=200 -Wc-g3 -Wc-w544 -Wc-w557 -Ctc37x -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

CDD/CddHsm/Demo/%.o: ./CDD/CddHsm/Demo/%.src CDD/CddHsm/Demo/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '



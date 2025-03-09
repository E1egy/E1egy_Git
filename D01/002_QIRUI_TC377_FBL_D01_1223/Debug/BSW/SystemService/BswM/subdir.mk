################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/SystemService/BswM/BswM.c \
../BSW/SystemService/BswM/BswM_AvbAction.c \
../BSW/SystemService/BswM/BswM_Bsw.c \
../BSW/SystemService/BswM/BswM_CanSM.c \
../BSW/SystemService/BswM/BswM_ComM.c \
../BSW/SystemService/BswM/BswM_Dcm.c \
../BSW/SystemService/BswM/BswM_DetCheck.c \
../BSW/SystemService/BswM/BswM_EcuM.c \
../BSW/SystemService/BswM/BswM_EthIf.c \
../BSW/SystemService/BswM/BswM_EthSM.c \
../BSW/SystemService/BswM/BswM_FrSM.c \
../BSW/SystemService/BswM/BswM_J1939Dcm.c \
../BSW/SystemService/BswM/BswM_J1939Nm.c \
../BSW/SystemService/BswM/BswM_LinSM.c \
../BSW/SystemService/BswM/BswM_LinTp.c \
../BSW/SystemService/BswM/BswM_Nm.c \
../BSW/SystemService/BswM/BswM_NvM.c \
../BSW/SystemService/BswM/BswM_Sd.c \
../BSW/SystemService/BswM/BswM_Swc.c \
../BSW/SystemService/BswM/BswM_TimerControl.c \
../BSW/SystemService/BswM/BswM_WdgM.c 

OBJS += \
./BSW/SystemService/BswM/BswM.o \
./BSW/SystemService/BswM/BswM_AvbAction.o \
./BSW/SystemService/BswM/BswM_Bsw.o \
./BSW/SystemService/BswM/BswM_CanSM.o \
./BSW/SystemService/BswM/BswM_ComM.o \
./BSW/SystemService/BswM/BswM_Dcm.o \
./BSW/SystemService/BswM/BswM_DetCheck.o \
./BSW/SystemService/BswM/BswM_EcuM.o \
./BSW/SystemService/BswM/BswM_EthIf.o \
./BSW/SystemService/BswM/BswM_EthSM.o \
./BSW/SystemService/BswM/BswM_FrSM.o \
./BSW/SystemService/BswM/BswM_J1939Dcm.o \
./BSW/SystemService/BswM/BswM_J1939Nm.o \
./BSW/SystemService/BswM/BswM_LinSM.o \
./BSW/SystemService/BswM/BswM_LinTp.o \
./BSW/SystemService/BswM/BswM_Nm.o \
./BSW/SystemService/BswM/BswM_NvM.o \
./BSW/SystemService/BswM/BswM_Sd.o \
./BSW/SystemService/BswM/BswM_Swc.o \
./BSW/SystemService/BswM/BswM_TimerControl.o \
./BSW/SystemService/BswM/BswM_WdgM.o 

COMPILED_SRCS += \
./BSW/SystemService/BswM/BswM.src \
./BSW/SystemService/BswM/BswM_AvbAction.src \
./BSW/SystemService/BswM/BswM_Bsw.src \
./BSW/SystemService/BswM/BswM_CanSM.src \
./BSW/SystemService/BswM/BswM_ComM.src \
./BSW/SystemService/BswM/BswM_Dcm.src \
./BSW/SystemService/BswM/BswM_DetCheck.src \
./BSW/SystemService/BswM/BswM_EcuM.src \
./BSW/SystemService/BswM/BswM_EthIf.src \
./BSW/SystemService/BswM/BswM_EthSM.src \
./BSW/SystemService/BswM/BswM_FrSM.src \
./BSW/SystemService/BswM/BswM_J1939Dcm.src \
./BSW/SystemService/BswM/BswM_J1939Nm.src \
./BSW/SystemService/BswM/BswM_LinSM.src \
./BSW/SystemService/BswM/BswM_LinTp.src \
./BSW/SystemService/BswM/BswM_Nm.src \
./BSW/SystemService/BswM/BswM_NvM.src \
./BSW/SystemService/BswM/BswM_Sd.src \
./BSW/SystemService/BswM/BswM_Swc.src \
./BSW/SystemService/BswM/BswM_TimerControl.src \
./BSW/SystemService/BswM/BswM_WdgM.src 

C_DEPS += \
./BSW/SystemService/BswM/BswM.d \
./BSW/SystemService/BswM/BswM_AvbAction.d \
./BSW/SystemService/BswM/BswM_Bsw.d \
./BSW/SystemService/BswM/BswM_CanSM.d \
./BSW/SystemService/BswM/BswM_ComM.d \
./BSW/SystemService/BswM/BswM_Dcm.d \
./BSW/SystemService/BswM/BswM_DetCheck.d \
./BSW/SystemService/BswM/BswM_EcuM.d \
./BSW/SystemService/BswM/BswM_EthIf.d \
./BSW/SystemService/BswM/BswM_EthSM.d \
./BSW/SystemService/BswM/BswM_FrSM.d \
./BSW/SystemService/BswM/BswM_J1939Dcm.d \
./BSW/SystemService/BswM/BswM_J1939Nm.d \
./BSW/SystemService/BswM/BswM_LinSM.d \
./BSW/SystemService/BswM/BswM_LinTp.d \
./BSW/SystemService/BswM/BswM_Nm.d \
./BSW/SystemService/BswM/BswM_NvM.d \
./BSW/SystemService/BswM/BswM_Sd.d \
./BSW/SystemService/BswM/BswM_Swc.d \
./BSW/SystemService/BswM/BswM_TimerControl.d \
./BSW/SystemService/BswM/BswM_WdgM.d 


# Each subdirectory must supply rules for building sources it contributes
BSW/SystemService/BswM/%.src: ../BSW/SystemService/BswM/%.c BSW/SystemService/BswM/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D_TASKING_C_TRICORE_=1 -DTEST_APP=1 -DAPP_SW=2 -DDEMO_APP=2 -D_CPU__=tc37x -DENABLE_HSM=1 -DTEST_PRINT=0 "-fE:/SVN/D01/002_QIRUI_TC377_FBL_D01_1223_0116/002_QIRUI_TC377_FBL_D01_1223/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=2 --compact-max-size=200 -Wc-g3 -Wc-w544 -Wc-w557 -Ctc37x -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

BSW/SystemService/BswM/%.o: ./BSW/SystemService/BswM/%.src BSW/SystemService/BswM/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '



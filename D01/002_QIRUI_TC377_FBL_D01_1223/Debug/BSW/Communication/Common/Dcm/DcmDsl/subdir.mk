################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/Communication/Common/Dcm/DcmDsl/DcmDsl_CommManage.c \
../BSW/Communication/Common/Dcm/DcmDsl/DcmDsl_MsgManage.c \
../BSW/Communication/Common/Dcm/DcmDsl/DcmDsl_PendingManage.c \
../BSW/Communication/Common/Dcm/DcmDsl/DcmDsl_ProtocolManage.c \
../BSW/Communication/Common/Dcm/DcmDsl/DcmDsl_SecurityManage.c \
../BSW/Communication/Common/Dcm/DcmDsl/DcmDsl_SessionManage.c 

OBJS += \
./BSW/Communication/Common/Dcm/DcmDsl/DcmDsl_CommManage.o \
./BSW/Communication/Common/Dcm/DcmDsl/DcmDsl_MsgManage.o \
./BSW/Communication/Common/Dcm/DcmDsl/DcmDsl_PendingManage.o \
./BSW/Communication/Common/Dcm/DcmDsl/DcmDsl_ProtocolManage.o \
./BSW/Communication/Common/Dcm/DcmDsl/DcmDsl_SecurityManage.o \
./BSW/Communication/Common/Dcm/DcmDsl/DcmDsl_SessionManage.o 

COMPILED_SRCS += \
./BSW/Communication/Common/Dcm/DcmDsl/DcmDsl_CommManage.src \
./BSW/Communication/Common/Dcm/DcmDsl/DcmDsl_MsgManage.src \
./BSW/Communication/Common/Dcm/DcmDsl/DcmDsl_PendingManage.src \
./BSW/Communication/Common/Dcm/DcmDsl/DcmDsl_ProtocolManage.src \
./BSW/Communication/Common/Dcm/DcmDsl/DcmDsl_SecurityManage.src \
./BSW/Communication/Common/Dcm/DcmDsl/DcmDsl_SessionManage.src 

C_DEPS += \
./BSW/Communication/Common/Dcm/DcmDsl/DcmDsl_CommManage.d \
./BSW/Communication/Common/Dcm/DcmDsl/DcmDsl_MsgManage.d \
./BSW/Communication/Common/Dcm/DcmDsl/DcmDsl_PendingManage.d \
./BSW/Communication/Common/Dcm/DcmDsl/DcmDsl_ProtocolManage.d \
./BSW/Communication/Common/Dcm/DcmDsl/DcmDsl_SecurityManage.d \
./BSW/Communication/Common/Dcm/DcmDsl/DcmDsl_SessionManage.d 


# Each subdirectory must supply rules for building sources it contributes
BSW/Communication/Common/Dcm/DcmDsl/%.src: ../BSW/Communication/Common/Dcm/DcmDsl/%.c BSW/Communication/Common/Dcm/DcmDsl/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D_TASKING_C_TRICORE_=1 -DTEST_APP=1 -DAPP_SW=2 -DDEMO_APP=2 -D_CPU__=tc37x -DENABLE_HSM=1 -DTEST_PRINT=0 "-fE:/SVN/D01/002_QIRUI_TC377_FBL_D01_1223_0116/002_QIRUI_TC377_FBL_D01_1223/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=2 --compact-max-size=200 -Wc-g3 -Wc-w544 -Wc-w557 -Ctc37x -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

BSW/Communication/Common/Dcm/DcmDsl/%.o: ./BSW/Communication/Common/Dcm/DcmDsl/%.src BSW/Communication/Common/Dcm/DcmDsl/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '



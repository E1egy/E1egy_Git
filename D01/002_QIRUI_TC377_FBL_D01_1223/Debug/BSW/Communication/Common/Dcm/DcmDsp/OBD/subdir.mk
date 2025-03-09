################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x01.c \
../BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x02.c \
../BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x03.c \
../BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x04.c \
../BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x05.c \
../BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x06.c \
../BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x07.c \
../BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x08.c \
../BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x09.c \
../BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x0A.c \
../BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBDInternal.c 

OBJS += \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x01.o \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x02.o \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x03.o \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x04.o \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x05.o \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x06.o \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x07.o \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x08.o \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x09.o \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x0A.o \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBDInternal.o 

COMPILED_SRCS += \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x01.src \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x02.src \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x03.src \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x04.src \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x05.src \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x06.src \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x07.src \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x08.src \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x09.src \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x0A.src \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBDInternal.src 

C_DEPS += \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x01.d \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x02.d \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x03.d \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x04.d \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x05.d \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x06.d \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x07.d \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x08.d \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x09.d \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBD0x0A.d \
./BSW/Communication/Common/Dcm/DcmDsp/OBD/Dcm_OBDInternal.d 


# Each subdirectory must supply rules for building sources it contributes
BSW/Communication/Common/Dcm/DcmDsp/OBD/%.src: ../BSW/Communication/Common/Dcm/DcmDsp/OBD/%.c BSW/Communication/Common/Dcm/DcmDsp/OBD/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D_TASKING_C_TRICORE_=1 -DTEST_APP=1 -DAPP_SW=2 -DDEMO_APP=2 -D_CPU__=tc37x -DENABLE_HSM=1 -DTEST_PRINT=0 "-fE:/SVN/D01/002_QIRUI_TC377_FBL_D01_1223_0116/002_QIRUI_TC377_FBL_D01_1223/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=2 --compact-max-size=200 -Wc-g3 -Wc-w544 -Wc-w557 -Ctc37x -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

BSW/Communication/Common/Dcm/DcmDsp/OBD/%.o: ./BSW/Communication/Common/Dcm/DcmDsp/OBD/%.src BSW/Communication/Common/Dcm/DcmDsp/OBD/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '



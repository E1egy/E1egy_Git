################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/SystemService/Dem/Dem.c \
../BSW/SystemService/Dem/Dem_Dcm.c \
../BSW/SystemService/Dem/Dem_EventDebounce.c \
../BSW/SystemService/Dem/Dem_EventMemory.c \
../BSW/SystemService/Dem/Dem_EventQueue.c \
../BSW/SystemService/Dem/Dem_ExtendedData.c \
../BSW/SystemService/Dem/Dem_FreezeFrame.c \
../BSW/SystemService/Dem/Dem_Internal.c \
../BSW/SystemService/Dem/Dem_J1939.c \
../BSW/SystemService/Dem/Dem_OBD.c 

OBJS += \
./BSW/SystemService/Dem/Dem.o \
./BSW/SystemService/Dem/Dem_Dcm.o \
./BSW/SystemService/Dem/Dem_EventDebounce.o \
./BSW/SystemService/Dem/Dem_EventMemory.o \
./BSW/SystemService/Dem/Dem_EventQueue.o \
./BSW/SystemService/Dem/Dem_ExtendedData.o \
./BSW/SystemService/Dem/Dem_FreezeFrame.o \
./BSW/SystemService/Dem/Dem_Internal.o \
./BSW/SystemService/Dem/Dem_J1939.o \
./BSW/SystemService/Dem/Dem_OBD.o 

COMPILED_SRCS += \
./BSW/SystemService/Dem/Dem.src \
./BSW/SystemService/Dem/Dem_Dcm.src \
./BSW/SystemService/Dem/Dem_EventDebounce.src \
./BSW/SystemService/Dem/Dem_EventMemory.src \
./BSW/SystemService/Dem/Dem_EventQueue.src \
./BSW/SystemService/Dem/Dem_ExtendedData.src \
./BSW/SystemService/Dem/Dem_FreezeFrame.src \
./BSW/SystemService/Dem/Dem_Internal.src \
./BSW/SystemService/Dem/Dem_J1939.src \
./BSW/SystemService/Dem/Dem_OBD.src 

C_DEPS += \
./BSW/SystemService/Dem/Dem.d \
./BSW/SystemService/Dem/Dem_Dcm.d \
./BSW/SystemService/Dem/Dem_EventDebounce.d \
./BSW/SystemService/Dem/Dem_EventMemory.d \
./BSW/SystemService/Dem/Dem_EventQueue.d \
./BSW/SystemService/Dem/Dem_ExtendedData.d \
./BSW/SystemService/Dem/Dem_FreezeFrame.d \
./BSW/SystemService/Dem/Dem_Internal.d \
./BSW/SystemService/Dem/Dem_J1939.d \
./BSW/SystemService/Dem/Dem_OBD.d 


# Each subdirectory must supply rules for building sources it contributes
BSW/SystemService/Dem/%.src: ../BSW/SystemService/Dem/%.c BSW/SystemService/Dem/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D_TASKING_C_TRICORE_=1 -DTEST_APP=1 -DAPP_SW=2 -DDEMO_APP=2 -D_CPU__=tc37x -DENABLE_HSM=1 -DTEST_PRINT=0 "-fE:/SVN/D01/002_QIRUI_TC377_FBL_D01_1223_0116/002_QIRUI_TC377_FBL_D01_1223/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=2 --compact-max-size=200 -Wc-g3 -Wc-w544 -Wc-w557 -Ctc37x -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

BSW/SystemService/Dem/%.o: ./BSW/SystemService/Dem/%.src BSW/SystemService/Dem/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CDD/CddHsm/TestCode/UserTest_Task/UserTestTaskCore0.c \
../CDD/CddHsm/TestCode/UserTest_Task/UserTestTaskCore1.c \
../CDD/CddHsm/TestCode/UserTest_Task/UserTestTaskCore2.c \
../CDD/CddHsm/TestCode/UserTest_Task/UserTestTaskCore3.c \
../CDD/CddHsm/TestCode/UserTest_Task/UserTestTaskCore4.c \
../CDD/CddHsm/TestCode/UserTest_Task/UserTestTaskCore5.c 

OBJS += \
./CDD/CddHsm/TestCode/UserTest_Task/UserTestTaskCore0.o \
./CDD/CddHsm/TestCode/UserTest_Task/UserTestTaskCore1.o \
./CDD/CddHsm/TestCode/UserTest_Task/UserTestTaskCore2.o \
./CDD/CddHsm/TestCode/UserTest_Task/UserTestTaskCore3.o \
./CDD/CddHsm/TestCode/UserTest_Task/UserTestTaskCore4.o \
./CDD/CddHsm/TestCode/UserTest_Task/UserTestTaskCore5.o 

COMPILED_SRCS += \
./CDD/CddHsm/TestCode/UserTest_Task/UserTestTaskCore0.src \
./CDD/CddHsm/TestCode/UserTest_Task/UserTestTaskCore1.src \
./CDD/CddHsm/TestCode/UserTest_Task/UserTestTaskCore2.src \
./CDD/CddHsm/TestCode/UserTest_Task/UserTestTaskCore3.src \
./CDD/CddHsm/TestCode/UserTest_Task/UserTestTaskCore4.src \
./CDD/CddHsm/TestCode/UserTest_Task/UserTestTaskCore5.src 

C_DEPS += \
./CDD/CddHsm/TestCode/UserTest_Task/UserTestTaskCore0.d \
./CDD/CddHsm/TestCode/UserTest_Task/UserTestTaskCore1.d \
./CDD/CddHsm/TestCode/UserTest_Task/UserTestTaskCore2.d \
./CDD/CddHsm/TestCode/UserTest_Task/UserTestTaskCore3.d \
./CDD/CddHsm/TestCode/UserTest_Task/UserTestTaskCore4.d \
./CDD/CddHsm/TestCode/UserTest_Task/UserTestTaskCore5.d 


# Each subdirectory must supply rules for building sources it contributes
CDD/CddHsm/TestCode/UserTest_Task/%.src: ../CDD/CddHsm/TestCode/UserTest_Task/%.c CDD/CddHsm/TestCode/UserTest_Task/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D_TASKING_C_TRICORE_=1 -DTEST_APP=1 -DAPP_SW=2 -DDEMO_APP=2 -D_CPU__=tc37x -DENABLE_HSM=1 -DTEST_PRINT=0 "-fE:/SVN/D01/002_QIRUI_TC377_FBL_D01_1223_0116/002_QIRUI_TC377_FBL_D01_1223/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=2 --compact-max-size=200 -Wc-g3 -Wc-w544 -Wc-w557 -Ctc37x -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

CDD/CddHsm/TestCode/UserTest_Task/%.o: ./CDD/CddHsm/TestCode/UserTest_Task/%.src CDD/CddHsm/TestCode/UserTest_Task/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '



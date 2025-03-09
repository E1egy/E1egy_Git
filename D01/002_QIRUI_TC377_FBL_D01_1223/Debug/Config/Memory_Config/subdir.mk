################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Config/Memory_Config/MemIf_Cfg.c \
../Config/Memory_Config/NvM_Cfg.c 

OBJS += \
./Config/Memory_Config/MemIf_Cfg.o \
./Config/Memory_Config/NvM_Cfg.o 

COMPILED_SRCS += \
./Config/Memory_Config/MemIf_Cfg.src \
./Config/Memory_Config/NvM_Cfg.src 

C_DEPS += \
./Config/Memory_Config/MemIf_Cfg.d \
./Config/Memory_Config/NvM_Cfg.d 


# Each subdirectory must supply rules for building sources it contributes
Config/Memory_Config/%.src: ../Config/Memory_Config/%.c Config/Memory_Config/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D_TASKING_C_TRICORE_=1 -DTEST_APP=1 -DAPP_SW=2 -DDEMO_APP=2 -D_CPU__=tc37x -DENABLE_HSM=1 -DTEST_PRINT=0 "-fE:/SVN/D01/002_QIRUI_TC377_FBL_D01_1223_0116/002_QIRUI_TC377_FBL_D01_1223/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=2 --compact-max-size=200 -Wc-g3 -Wc-w544 -Wc-w557 -Ctc37x -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

Config/Memory_Config/%.o: ./Config/Memory_Config/%.src Config/Memory_Config/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '



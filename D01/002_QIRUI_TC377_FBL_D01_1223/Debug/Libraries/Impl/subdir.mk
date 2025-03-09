################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/Impl/IfxCcu6_cfg.c \
../Libraries/Impl/IfxCpu_cfg.c \
../Libraries/Impl/IfxFlash_cfg.c \
../Libraries/Impl/IfxPort_cfg.c \
../Libraries/Impl/IfxScu_cfg.c \
../Libraries/Impl/IfxSmu_cfg.c 

OBJS += \
./Libraries/Impl/IfxCcu6_cfg.o \
./Libraries/Impl/IfxCpu_cfg.o \
./Libraries/Impl/IfxFlash_cfg.o \
./Libraries/Impl/IfxPort_cfg.o \
./Libraries/Impl/IfxScu_cfg.o \
./Libraries/Impl/IfxSmu_cfg.o 

COMPILED_SRCS += \
./Libraries/Impl/IfxCcu6_cfg.src \
./Libraries/Impl/IfxCpu_cfg.src \
./Libraries/Impl/IfxFlash_cfg.src \
./Libraries/Impl/IfxPort_cfg.src \
./Libraries/Impl/IfxScu_cfg.src \
./Libraries/Impl/IfxSmu_cfg.src 

C_DEPS += \
./Libraries/Impl/IfxCcu6_cfg.d \
./Libraries/Impl/IfxCpu_cfg.d \
./Libraries/Impl/IfxFlash_cfg.d \
./Libraries/Impl/IfxPort_cfg.d \
./Libraries/Impl/IfxScu_cfg.d \
./Libraries/Impl/IfxSmu_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Impl/%.src: ../Libraries/Impl/%.c Libraries/Impl/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D_TASKING_C_TRICORE_=1 -DTEST_APP=1 -DAPP_SW=2 -DDEMO_APP=2 -D_CPU__=tc37x -DENABLE_HSM=1 -DTEST_PRINT=0 "-fE:/SVN/D01/002_QIRUI_TC377_FBL_D01_1223_0116/002_QIRUI_TC377_FBL_D01_1223/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=2 --compact-max-size=200 -Wc-g3 -Wc-w544 -Wc-w557 -Ctc37x -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Impl/%.o: ./Libraries/Impl/%.src Libraries/Impl/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '



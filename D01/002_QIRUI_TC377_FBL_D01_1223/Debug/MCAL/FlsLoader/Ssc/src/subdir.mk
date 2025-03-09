################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/FlsLoader/Ssc/src/FlsLoader.c \
../MCAL/FlsLoader/Ssc/src/FlsLoader_Platform.c 

OBJS += \
./MCAL/FlsLoader/Ssc/src/FlsLoader.o \
./MCAL/FlsLoader/Ssc/src/FlsLoader_Platform.o 

COMPILED_SRCS += \
./MCAL/FlsLoader/Ssc/src/FlsLoader.src \
./MCAL/FlsLoader/Ssc/src/FlsLoader_Platform.src 

C_DEPS += \
./MCAL/FlsLoader/Ssc/src/FlsLoader.d \
./MCAL/FlsLoader/Ssc/src/FlsLoader_Platform.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/FlsLoader/Ssc/src/%.src: ../MCAL/FlsLoader/Ssc/src/%.c MCAL/FlsLoader/Ssc/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D_TASKING_C_TRICORE_=1 -DTEST_APP=1 -DAPP_SW=2 -DDEMO_APP=2 -D_CPU__=tc37x -DENABLE_HSM=1 -DTEST_PRINT=0 "-fE:/SVN/D01/002_QIRUI_TC377_FBL_D01_1223_0116/002_QIRUI_TC377_FBL_D01_1223/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=2 --compact-max-size=200 -Wc-g3 -Wc-w544 -Wc-w557 -Ctc37x -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

MCAL/FlsLoader/Ssc/src/%.o: ./MCAL/FlsLoader/Ssc/src/%.src MCAL/FlsLoader/Ssc/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '



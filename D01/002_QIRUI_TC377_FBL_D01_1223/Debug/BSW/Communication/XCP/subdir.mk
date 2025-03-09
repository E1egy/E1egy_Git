################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/Communication/XCP/Xcp.c \
../BSW/Communication/XCP/XcpOnCan.c \
../BSW/Communication/XCP/XcpOnEth.c \
../BSW/Communication/XCP/Xcp_Cal.c \
../BSW/Communication/XCP/Xcp_Daq.c \
../BSW/Communication/XCP/Xcp_Interface.c \
../BSW/Communication/XCP/Xcp_Pgm.c \
../BSW/Communication/XCP/Xcp_Ram.c \
../BSW/Communication/XCP/Xcp_Std.c 

OBJS += \
./BSW/Communication/XCP/Xcp.o \
./BSW/Communication/XCP/XcpOnCan.o \
./BSW/Communication/XCP/XcpOnEth.o \
./BSW/Communication/XCP/Xcp_Cal.o \
./BSW/Communication/XCP/Xcp_Daq.o \
./BSW/Communication/XCP/Xcp_Interface.o \
./BSW/Communication/XCP/Xcp_Pgm.o \
./BSW/Communication/XCP/Xcp_Ram.o \
./BSW/Communication/XCP/Xcp_Std.o 

COMPILED_SRCS += \
./BSW/Communication/XCP/Xcp.src \
./BSW/Communication/XCP/XcpOnCan.src \
./BSW/Communication/XCP/XcpOnEth.src \
./BSW/Communication/XCP/Xcp_Cal.src \
./BSW/Communication/XCP/Xcp_Daq.src \
./BSW/Communication/XCP/Xcp_Interface.src \
./BSW/Communication/XCP/Xcp_Pgm.src \
./BSW/Communication/XCP/Xcp_Ram.src \
./BSW/Communication/XCP/Xcp_Std.src 

C_DEPS += \
./BSW/Communication/XCP/Xcp.d \
./BSW/Communication/XCP/XcpOnCan.d \
./BSW/Communication/XCP/XcpOnEth.d \
./BSW/Communication/XCP/Xcp_Cal.d \
./BSW/Communication/XCP/Xcp_Daq.d \
./BSW/Communication/XCP/Xcp_Interface.d \
./BSW/Communication/XCP/Xcp_Pgm.d \
./BSW/Communication/XCP/Xcp_Ram.d \
./BSW/Communication/XCP/Xcp_Std.d 


# Each subdirectory must supply rules for building sources it contributes
BSW/Communication/XCP/%.src: ../BSW/Communication/XCP/%.c BSW/Communication/XCP/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D_TASKING_C_TRICORE_=1 -DTEST_APP=1 -DAPP_SW=2 -DDEMO_APP=2 -D_CPU__=tc37x -DENABLE_HSM=1 -DTEST_PRINT=0 "-fE:/SVN/D01/002_QIRUI_TC377_FBL_D01_1223_0116/002_QIRUI_TC377_FBL_D01_1223/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=2 --compact-max-size=200 -Wc-g3 -Wc-w544 -Wc-w557 -Ctc37x -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

BSW/Communication/XCP/%.o: ./BSW/Communication/XCP/%.src BSW/Communication/XCP/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/SystemService/Os/Kernel/Os_Alarm.c \
../BSW/SystemService/Os/Kernel/Os_Appl.c \
../BSW/SystemService/Os/Kernel/Os_Core.c \
../BSW/SystemService/Os/Kernel/Os_Counter.c \
../BSW/SystemService/Os/Kernel/Os_CpuUsageRate.c \
../BSW/SystemService/Os/Kernel/Os_Event.c \
../BSW/SystemService/Os/Kernel/Os_Hook.c \
../BSW/SystemService/Os/Kernel/Os_Interrupt.c \
../BSW/SystemService/Os/Kernel/Os_Ioc.c \
../BSW/SystemService/Os/Kernel/Os_Kernel.c \
../BSW/SystemService/Os/Kernel/Os_Mprot.c \
../BSW/SystemService/Os/Kernel/Os_Resource.c \
../BSW/SystemService/Os/Kernel/Os_ScheduleTable.c \
../BSW/SystemService/Os/Kernel/Os_Spinlock.c \
../BSW/SystemService/Os/Kernel/Os_Sprot.c \
../BSW/SystemService/Os/Kernel/Os_Task.c \
../BSW/SystemService/Os/Kernel/Os_Tprot.c 

OBJS += \
./BSW/SystemService/Os/Kernel/Os_Alarm.o \
./BSW/SystemService/Os/Kernel/Os_Appl.o \
./BSW/SystemService/Os/Kernel/Os_Core.o \
./BSW/SystemService/Os/Kernel/Os_Counter.o \
./BSW/SystemService/Os/Kernel/Os_CpuUsageRate.o \
./BSW/SystemService/Os/Kernel/Os_Event.o \
./BSW/SystemService/Os/Kernel/Os_Hook.o \
./BSW/SystemService/Os/Kernel/Os_Interrupt.o \
./BSW/SystemService/Os/Kernel/Os_Ioc.o \
./BSW/SystemService/Os/Kernel/Os_Kernel.o \
./BSW/SystemService/Os/Kernel/Os_Mprot.o \
./BSW/SystemService/Os/Kernel/Os_Resource.o \
./BSW/SystemService/Os/Kernel/Os_ScheduleTable.o \
./BSW/SystemService/Os/Kernel/Os_Spinlock.o \
./BSW/SystemService/Os/Kernel/Os_Sprot.o \
./BSW/SystemService/Os/Kernel/Os_Task.o \
./BSW/SystemService/Os/Kernel/Os_Tprot.o 

COMPILED_SRCS += \
./BSW/SystemService/Os/Kernel/Os_Alarm.src \
./BSW/SystemService/Os/Kernel/Os_Appl.src \
./BSW/SystemService/Os/Kernel/Os_Core.src \
./BSW/SystemService/Os/Kernel/Os_Counter.src \
./BSW/SystemService/Os/Kernel/Os_CpuUsageRate.src \
./BSW/SystemService/Os/Kernel/Os_Event.src \
./BSW/SystemService/Os/Kernel/Os_Hook.src \
./BSW/SystemService/Os/Kernel/Os_Interrupt.src \
./BSW/SystemService/Os/Kernel/Os_Ioc.src \
./BSW/SystemService/Os/Kernel/Os_Kernel.src \
./BSW/SystemService/Os/Kernel/Os_Mprot.src \
./BSW/SystemService/Os/Kernel/Os_Resource.src \
./BSW/SystemService/Os/Kernel/Os_ScheduleTable.src \
./BSW/SystemService/Os/Kernel/Os_Spinlock.src \
./BSW/SystemService/Os/Kernel/Os_Sprot.src \
./BSW/SystemService/Os/Kernel/Os_Task.src \
./BSW/SystemService/Os/Kernel/Os_Tprot.src 

C_DEPS += \
./BSW/SystemService/Os/Kernel/Os_Alarm.d \
./BSW/SystemService/Os/Kernel/Os_Appl.d \
./BSW/SystemService/Os/Kernel/Os_Core.d \
./BSW/SystemService/Os/Kernel/Os_Counter.d \
./BSW/SystemService/Os/Kernel/Os_CpuUsageRate.d \
./BSW/SystemService/Os/Kernel/Os_Event.d \
./BSW/SystemService/Os/Kernel/Os_Hook.d \
./BSW/SystemService/Os/Kernel/Os_Interrupt.d \
./BSW/SystemService/Os/Kernel/Os_Ioc.d \
./BSW/SystemService/Os/Kernel/Os_Kernel.d \
./BSW/SystemService/Os/Kernel/Os_Mprot.d \
./BSW/SystemService/Os/Kernel/Os_Resource.d \
./BSW/SystemService/Os/Kernel/Os_ScheduleTable.d \
./BSW/SystemService/Os/Kernel/Os_Spinlock.d \
./BSW/SystemService/Os/Kernel/Os_Sprot.d \
./BSW/SystemService/Os/Kernel/Os_Task.d \
./BSW/SystemService/Os/Kernel/Os_Tprot.d 


# Each subdirectory must supply rules for building sources it contributes
BSW/SystemService/Os/Kernel/%.src: ../BSW/SystemService/Os/Kernel/%.c BSW/SystemService/Os/Kernel/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D_TASKING_C_TRICORE_=1 -DTEST_APP=1 -DAPP_SW=2 -DDEMO_APP=2 -D_CPU__=tc37x -DENABLE_HSM=1 -DTEST_PRINT=0 "-fE:/SVN/D01/002_QIRUI_TC377_FBL_D01_1223_0116/002_QIRUI_TC377_FBL_D01_1223/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=2 --compact-max-size=200 -Wc-g3 -Wc-w544 -Wc-w557 -Ctc37x -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

BSW/SystemService/Os/Kernel/%.o: ./BSW/SystemService/Os/Kernel/%.src BSW/SystemService/Os/Kernel/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '



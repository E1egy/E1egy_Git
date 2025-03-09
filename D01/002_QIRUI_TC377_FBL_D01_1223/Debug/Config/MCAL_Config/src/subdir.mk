################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Config/MCAL_Config/src/Adc_PBcfg.c \
../Config/MCAL_Config/src/Can_17_McmCan_PBcfg.c \
../Config/MCAL_Config/src/Dio_Lcfg.c \
../Config/MCAL_Config/src/Dma_PBcfg.c \
../Config/MCAL_Config/src/Fee_PBcfg.c \
../Config/MCAL_Config/src/FlsLoader_Cfg.c \
../Config/MCAL_Config/src/Fls_17_Dmu_PBcfg.c \
../Config/MCAL_Config/src/Icu_17_TimerIp_PBcfg.c \
../Config/MCAL_Config/src/Mcu_17_TimerIp_Cfg.c \
../Config/MCAL_Config/src/Mcu_PBcfg.c \
../Config/MCAL_Config/src/Port_PBcfg.c \
../Config/MCAL_Config/src/Pwm_17_GtmCcu6_PBcfg.c \
../Config/MCAL_Config/src/Spi_PBcfg.c \
../Config/MCAL_Config/src/Wdg_17_Scu_PBcfg.c 

OBJS += \
./Config/MCAL_Config/src/Adc_PBcfg.o \
./Config/MCAL_Config/src/Can_17_McmCan_PBcfg.o \
./Config/MCAL_Config/src/Dio_Lcfg.o \
./Config/MCAL_Config/src/Dma_PBcfg.o \
./Config/MCAL_Config/src/Fee_PBcfg.o \
./Config/MCAL_Config/src/FlsLoader_Cfg.o \
./Config/MCAL_Config/src/Fls_17_Dmu_PBcfg.o \
./Config/MCAL_Config/src/Icu_17_TimerIp_PBcfg.o \
./Config/MCAL_Config/src/Mcu_17_TimerIp_Cfg.o \
./Config/MCAL_Config/src/Mcu_PBcfg.o \
./Config/MCAL_Config/src/Port_PBcfg.o \
./Config/MCAL_Config/src/Pwm_17_GtmCcu6_PBcfg.o \
./Config/MCAL_Config/src/Spi_PBcfg.o \
./Config/MCAL_Config/src/Wdg_17_Scu_PBcfg.o 

COMPILED_SRCS += \
./Config/MCAL_Config/src/Adc_PBcfg.src \
./Config/MCAL_Config/src/Can_17_McmCan_PBcfg.src \
./Config/MCAL_Config/src/Dio_Lcfg.src \
./Config/MCAL_Config/src/Dma_PBcfg.src \
./Config/MCAL_Config/src/Fee_PBcfg.src \
./Config/MCAL_Config/src/FlsLoader_Cfg.src \
./Config/MCAL_Config/src/Fls_17_Dmu_PBcfg.src \
./Config/MCAL_Config/src/Icu_17_TimerIp_PBcfg.src \
./Config/MCAL_Config/src/Mcu_17_TimerIp_Cfg.src \
./Config/MCAL_Config/src/Mcu_PBcfg.src \
./Config/MCAL_Config/src/Port_PBcfg.src \
./Config/MCAL_Config/src/Pwm_17_GtmCcu6_PBcfg.src \
./Config/MCAL_Config/src/Spi_PBcfg.src \
./Config/MCAL_Config/src/Wdg_17_Scu_PBcfg.src 

C_DEPS += \
./Config/MCAL_Config/src/Adc_PBcfg.d \
./Config/MCAL_Config/src/Can_17_McmCan_PBcfg.d \
./Config/MCAL_Config/src/Dio_Lcfg.d \
./Config/MCAL_Config/src/Dma_PBcfg.d \
./Config/MCAL_Config/src/Fee_PBcfg.d \
./Config/MCAL_Config/src/FlsLoader_Cfg.d \
./Config/MCAL_Config/src/Fls_17_Dmu_PBcfg.d \
./Config/MCAL_Config/src/Icu_17_TimerIp_PBcfg.d \
./Config/MCAL_Config/src/Mcu_17_TimerIp_Cfg.d \
./Config/MCAL_Config/src/Mcu_PBcfg.d \
./Config/MCAL_Config/src/Port_PBcfg.d \
./Config/MCAL_Config/src/Pwm_17_GtmCcu6_PBcfg.d \
./Config/MCAL_Config/src/Spi_PBcfg.d \
./Config/MCAL_Config/src/Wdg_17_Scu_PBcfg.d 


# Each subdirectory must supply rules for building sources it contributes
Config/MCAL_Config/src/%.src: ../Config/MCAL_Config/src/%.c Config/MCAL_Config/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D_TASKING_C_TRICORE_=1 -DTEST_APP=1 -DAPP_SW=2 -DDEMO_APP=2 -D_CPU__=tc37x -DENABLE_HSM=1 -DTEST_PRINT=0 "-fE:/SVN/D01/002_QIRUI_TC377_FBL_D01_1223_0116/002_QIRUI_TC377_FBL_D01_1223/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=2 --compact-max-size=200 -Wc-g3 -Wc-w544 -Wc-w557 -Ctc37x -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

Config/MCAL_Config/src/%.o: ./Config/MCAL_Config/src/%.src Config/MCAL_Config/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '



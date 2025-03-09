################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Integration/FlsLdr_ExclArea.c \
../MCAL/Integration/SchM_Adc.c \
../MCAL/Integration/SchM_CanTrcv_17_W9255.c \
../MCAL/Integration/SchM_Can_17_McmCan.c \
../MCAL/Integration/SchM_Crc.c \
../MCAL/Integration/SchM_Dma.c \
../MCAL/Integration/SchM_Dsadc.c \
../MCAL/Integration/SchM_Eth_17_GEthMac.c \
../MCAL/Integration/SchM_Fr_17_Eray.c \
../MCAL/Integration/SchM_Gpt.c \
../MCAL/Integration/SchM_Hssl.c \
../MCAL/Integration/SchM_Icu_17_TimerIp.c \
../MCAL/Integration/SchM_McalLib.c \
../MCAL/Integration/SchM_Mcu.c \
../MCAL/Integration/SchM_Ocu.c \
../MCAL/Integration/SchM_Pwm_17_GtmCcu6.c \
../MCAL/Integration/SchM_Smu.c \
../MCAL/Integration/SchM_Spi.c \
../MCAL/Integration/SchM_Wdg_17_Scu.c 

OBJS += \
./MCAL/Integration/FlsLdr_ExclArea.o \
./MCAL/Integration/SchM_Adc.o \
./MCAL/Integration/SchM_CanTrcv_17_W9255.o \
./MCAL/Integration/SchM_Can_17_McmCan.o \
./MCAL/Integration/SchM_Crc.o \
./MCAL/Integration/SchM_Dma.o \
./MCAL/Integration/SchM_Dsadc.o \
./MCAL/Integration/SchM_Eth_17_GEthMac.o \
./MCAL/Integration/SchM_Fr_17_Eray.o \
./MCAL/Integration/SchM_Gpt.o \
./MCAL/Integration/SchM_Hssl.o \
./MCAL/Integration/SchM_Icu_17_TimerIp.o \
./MCAL/Integration/SchM_McalLib.o \
./MCAL/Integration/SchM_Mcu.o \
./MCAL/Integration/SchM_Ocu.o \
./MCAL/Integration/SchM_Pwm_17_GtmCcu6.o \
./MCAL/Integration/SchM_Smu.o \
./MCAL/Integration/SchM_Spi.o \
./MCAL/Integration/SchM_Wdg_17_Scu.o 

COMPILED_SRCS += \
./MCAL/Integration/FlsLdr_ExclArea.src \
./MCAL/Integration/SchM_Adc.src \
./MCAL/Integration/SchM_CanTrcv_17_W9255.src \
./MCAL/Integration/SchM_Can_17_McmCan.src \
./MCAL/Integration/SchM_Crc.src \
./MCAL/Integration/SchM_Dma.src \
./MCAL/Integration/SchM_Dsadc.src \
./MCAL/Integration/SchM_Eth_17_GEthMac.src \
./MCAL/Integration/SchM_Fr_17_Eray.src \
./MCAL/Integration/SchM_Gpt.src \
./MCAL/Integration/SchM_Hssl.src \
./MCAL/Integration/SchM_Icu_17_TimerIp.src \
./MCAL/Integration/SchM_McalLib.src \
./MCAL/Integration/SchM_Mcu.src \
./MCAL/Integration/SchM_Ocu.src \
./MCAL/Integration/SchM_Pwm_17_GtmCcu6.src \
./MCAL/Integration/SchM_Smu.src \
./MCAL/Integration/SchM_Spi.src \
./MCAL/Integration/SchM_Wdg_17_Scu.src 

C_DEPS += \
./MCAL/Integration/FlsLdr_ExclArea.d \
./MCAL/Integration/SchM_Adc.d \
./MCAL/Integration/SchM_CanTrcv_17_W9255.d \
./MCAL/Integration/SchM_Can_17_McmCan.d \
./MCAL/Integration/SchM_Crc.d \
./MCAL/Integration/SchM_Dma.d \
./MCAL/Integration/SchM_Dsadc.d \
./MCAL/Integration/SchM_Eth_17_GEthMac.d \
./MCAL/Integration/SchM_Fr_17_Eray.d \
./MCAL/Integration/SchM_Gpt.d \
./MCAL/Integration/SchM_Hssl.d \
./MCAL/Integration/SchM_Icu_17_TimerIp.d \
./MCAL/Integration/SchM_McalLib.d \
./MCAL/Integration/SchM_Mcu.d \
./MCAL/Integration/SchM_Ocu.d \
./MCAL/Integration/SchM_Pwm_17_GtmCcu6.d \
./MCAL/Integration/SchM_Smu.d \
./MCAL/Integration/SchM_Spi.d \
./MCAL/Integration/SchM_Wdg_17_Scu.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Integration/%.src: ../MCAL/Integration/%.c MCAL/Integration/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D_TASKING_C_TRICORE_=1 -DTEST_APP=1 -DAPP_SW=2 -DDEMO_APP=2 -D_CPU__=tc37x -DENABLE_HSM=1 -DTEST_PRINT=0 "-fE:/SVN/D01/002_QIRUI_TC377_FBL_D01_1223_0116/002_QIRUI_TC377_FBL_D01_1223/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=2 --compact-max-size=200 -Wc-g3 -Wc-w544 -Wc-w557 -Ctc37x -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

MCAL/Integration/%.o: ./MCAL/Integration/%.src MCAL/Integration/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '



@echo off

REM ROOT folder paths
REM set TOOLCHAIN_LOC = C:\ghs\comp_201517

REM set WS_ROOT=..\..
set APP_BUILD_ROOT = ..\Debug
set HEXVIEW_PATH = ".\HexView\hexview.exe"
set APP_FLASH_START_ADDR=0x80070000
set APP_FLASH_END_ADDR=0x800CFFFF
set FLASH_DRV_START_ADDR=0x7010F000
set FLASH_DRV_END_ADDR=0x7010FFFF

REM APP OUT FILES related paths
set APP_INTPUT_FILE=..\Debug\002_QIRUI_TC377_FBL.elf
echo %..\Debug\002_QIRUI_TC377_FBL.elf%

set APP_OUTPUT_FILE_INT_FLASH=.\TC377_Combine.hex
set APP_OUTPUT_FILE_Abank_APP_FLASH=.\TC377_Abank_FBL_TEMP.hex
set APP_OUTPUT_FILE_Abank_FLASH=.\TC377_Abank_FBL.hex
set APP_OUTPUT_FILE_Bbank_FLASH=.\TC377_Bbank_FBL.hex
set APP_OUTPUT_FILE_Abank_APP_Bin=.\TC377_Abank_FBL.bin

set APP_OUTPUT_FILE_FLASHDriverAll=.\TC377_FlashDriver.hex
set APP_OUTPUT_FILE_FLASHDriver_Fill=.\TC377_FlashDriver_Fill.hex
set APP_OUTPUT_FILE_FlashDriver=.\Flash_Driver.bin
set APP_OUTPUT_FILE_FlashDriver_hex=.\Flash_Driver.hex

echo %APP_OUTPUT_FILE_FLASHDriverAll%

@echo
REM Combine Hex Files
.\gsrec.exe %APP_INTPUT_FILE% -hex386 -warn_overlap -pad1 %FLASH_DRV_START_ADDR% %FLASH_DRV_END_ADDR% 0x00 -o %APP_OUTPUT_FILE_FLASHDriverAll%

REM A Bank Files
.\gsrec.exe %APP_INTPUT_FILE% -warn_overlap -pad1 %FLASH_DRV_START_ADDR% %FLASH_DRV_END_ADDR% 0x00 -start %FLASH_DRV_START_ADDR% -end %FLASH_DRV_END_ADDR% -o %APP_OUTPUT_FILE_FLASHDriver_Fill%

.\gmemfile %APP_INTPUT_FILE% -start %FLASH_DRV_START_ADDR% -end %FLASH_DRV_END_ADDR% -o %APP_OUTPUT_FILE_FlashDriver%

echo Generate Flash_Driver.hex
.\HexView\hexview.exe /MT:.\Flash_Driver.bin;0x7010F000:0x00000000-0x00000FFF /XI /s -o %APP_OUTPUT_FILE_FlashDriver_hex%

echo %APP_OUTPUT_FILE_INT_FLASH%
@echo
REM Combine Hex Files
.\gsrec.exe %APP_INTPUT_FILE% -hex386 -warn_overlap -pad1 %APP_FLASH_START_ADDR% %APP_FLASH_END_ADDR% 0x00 -o %APP_OUTPUT_FILE_INT_FLASH%

REM A Bank Files
.\gsrec.exe %APP_INTPUT_FILE% -warn_overlap -pad1 %APP_FLASH_START_ADDR% %APP_FLASH_END_ADDR% 0x00 -start %APP_FLASH_START_ADDR% -end %APP_FLASH_END_ADDR% -o %APP_OUTPUT_FILE_Abank_APP_FLASH%

REM .\gmemfile %APP_INTPUT_FILE% -start %APP_FLASH_START_ADDR% -end %APP_FLASH_END_ADDR% -o %APP_OUTPUT_FILE_Abank_APP_Bin%


REM ##########################Calc APP CRC##########################################
echo Cale APP CRC(0x80070000-0x800CFFCB)
echo Cut 0x80000000-0x8006FFFF
.\HexView\hexview.exe %APP_OUTPUT_FILE_Abank_APP_FLASH% /CR:0x80000000-0x8006FFFF /XI /s -o TC377_Abank_FBL_TEMP1.hex

echo Cut 0x800CFFCC-0x800CFFFF
.\HexView\hexview.exe TC377_Abank_FBL_TEMP1.hex /CR:0x800CFFCC-0x800CFFFF /XI /s -o TC377_Abank_FBL_TEMP3.hex

REM Calculate CRC for 0x80070000-0x800CFFCB,Fill the CRC to A 0x800CFFCC
.\HexView\hexview.exe TC377_Abank_FBL_TEMP3.hex /CS9:@0x800CFFCC;!0x80070000-0x800CFFCB /XI /s -o TC377_Abank_FBL_TEMP4.hex

REM ##########################Calc APP CRC End######################################

REM ##########################Calc APP Head CMAC##########################################
echo Cale APP CMAC1(0x80070000-0x800703FF) 1K
echo Cut 0x80000000-0x8006FFFF
.\HexView\hexview.exe TC377_Abank_FBL_TEMP4.hex /CR:0x80000000-0x8006FFFF /XI /s -o TC377_Abank_FBL_TEMP5.hex
echo Cut 0x80070400-0x800CFFFF
.\HexView\hexview.exe TC377_Abank_FBL_TEMP5.hex /CR:0x80070400-0x800CFFFF /XI /s -o TC377_Abank_FBL_TEMP6.hex
REM covert hex to bin
.\HexView\hexview.exe TC377_Abank_FBL_TEMP6.hex -o FBL_Temp_CMAC1.bin /XB  /s
REM ##########################Calc APP Head CMAC End######################################

REM ##########################Calc APP Tail CMAC##########################################
echo Cale APP CMAC2(0x800CFBD0-0x800CFFCF) 1K
echo Cut 0x80000000-0x800CFBCF
.\HexView\hexview.exe TC377_Abank_FBL_TEMP4.hex /CR:0x80000000-0x800CFBCF /XI /s -o TC377_Abank_FBL_TEMP7.hex
echo Cut 0x800CFFFD0-0x800CFFFF
.\HexView\hexview.exe TC377_Abank_FBL_TEMP7.hex /CR:0x802FFFFD0-0x800CFFFF /XI /s -o TC377_Abank_FBL_TEMP8.hex
REM covert hex to bin
.\HexView\hexview.exe TC377_Abank_FBL_TEMP8.hex -o FBL_Temp_CMAC2.bin /XB  /s
REM ##########################Calc APP Tail CMAC End######################################

REM ##########################Calc APP CMAC##########################################
echo Cale APP CMAC(0x80070000-0x800CFFCF)
REM covert hex to bin
.\HexView\hexview.exe TC377_Abank_FBL_TEMP4.hex -o FBL_Temp_CMAC3.bin /XB  /s
REM ##########################Calc APP CMAC End######################################

call FBL_CMAC.py


REM merge CMAC value
.\HexView\hexview.exe /MT:TC377_Abank_FBL_TEMP4.hex;0x0000:0x80070000-0x800CFFFCF+FBL_CMAC1.bin;0x800CFFD0:0x00000000-0x0000000F   -o TC377_Abank_FBL_TEMP9.hex /XI  /s
.\HexView\hexview.exe /MT:TC377_Abank_FBL_TEMP9.hex;0x0000:0x80070000-0x800CFFFDF+FBL_CMAC2.bin;0x800CFFE0:0x00000000-0x0000000F   -o TC377_Abank_FBL_TEMP10.hex /XI  /s
.\HexView\hexview.exe /MT:TC377_Abank_FBL_TEMP10.hex;0x0000:0x80070000-0x800CFFFEF+FBL_CMAC3.bin;0x800CFFF0:0x00000000-0x0000000F   -o TC377_Abank_FBL_TEMP11.hex /XI  /s


echo Convert HEX to BIN, Generate TC377_Abank_FBL.bin
.\HexView\hexview.exe TC377_Abank_FBL_TEMP11.hex -o TC377_Abank_FBL.bin /XB /s

echo TC377_Abank_FBL.bin, Generate TC377_Bbank_FBL.bin
copy .\TC377_Abank_FBL.bin .\TC377_Bbank_FBL.bin

echo Generate TC377_Abank_FBL.hex
.\HexView\hexview.exe /MT:.\TC377_Abank_FBL.bin;0xA0070000:0x00000000-0x0005FFFF /XI /s -o %APP_OUTPUT_FILE_Abank_FLASH%

echo Generate TC377_Bbank_FBL.hex
.\HexView\hexview.exe /MT:.\TC377_Bbank_FBL.bin;0xA0370000:0x00000000-0x0005FFFF /XI /s -o %APP_OUTPUT_FILE_Bbank_FLASH%

echo Generate TC377_ABbank_FBL.hex
 .\HexView\hexview.exe /MT:TC377_Abank_FBL.hex;0x0:0xA0070000-0xA00CFFFF+TC377_Bbank_FBL.hex;0x0:0xA0370000-0xA03CFFFF -o .\TC377_ABbank_FBL.hex /XI /s

echo delete tmp files
del %APP_OUTPUT_FILE_FLASHDriverAll%
del %APP_OUTPUT_FILE_FLASHDriver_Fill%
del %APP_OUTPUT_FILE_INT_FLASH%
del %APP_OUTPUT_FILE_Abank_APP_FLASH%
del .\*.prm
del .\FBL_CMAC1.bin
del .\FBL_CMAC2.bin
del .\FBL_CMAC3.bin
del .\FBL_Temp_CMAC1.*
del .\FBL_Temp_CMAC2.*
del .\FBL_Temp_CMAC3.*
del .\TC377_Abank_FBL_TEMP*
pause
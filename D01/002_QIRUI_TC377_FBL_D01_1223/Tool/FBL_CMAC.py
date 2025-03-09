# coding: utf8

from cryptography.hazmat.primitives import cmac
from cryptography.hazmat.primitives.ciphers import algorithms
import os
import shutil
import time
import sys
import re

from distutils.core import setup
#import py2exe

CurrentPath = os.path.dirname(sys.argv[0])
#setup(console=[str(CurrentPath)])

secret_app = [167, 230, 68, 247, 185, 149, 201, 29, 166, 13, 123, 62, 125, 250, 135, 232]
secret_boot = secret_app
secret_flashdrv = secret_app

def readFile(filepath):
    a = 25
    while a>0:
        try:
            with open(filepath, 'rb') as f:
                fr = f.read()
                return fr
        except IOError:
            time.sleep(1)
            a = a-1
            pass
    print("read file error :",filepath)
    sys.exit(1)


###App mac calculate
outBinFile = 'FBL_Temp_CMAC1.bin'
fr = readFile(outBinFile)
fr_bytearray = bytearray(fr)
mac = cmac.CMAC(algorithms.AES(bytes(secret_app)))
mac.update(bytes(fr_bytearray[0:]))
cmacV = mac.finalize()
print(cmacV.hex())
#binfile = open('PRODUCT.bin', 'ab+')
#binfile.seek(0)
#binfile.write(cmacV)
#binfile.close()
binfile = open('FBL_CMAC1.bin', 'wb')
binfile.write(cmacV)
binfile.close()

outBinFile = 'FBL_Temp_CMAC2.bin'
fr = readFile(outBinFile)
fr_bytearray = bytearray(fr)
mac = cmac.CMAC(algorithms.AES(bytes(secret_app)))
mac.update(bytes(fr_bytearray[0:]))
cmacV = mac.finalize()
print(cmacV.hex())
#binfile = open('PRODUCT.bin', 'ab+')
#binfile.seek(0)
#binfile.write(cmacV)
#binfile.close()
binfile = open('FBL_CMAC2.bin', 'wb')
binfile.write(cmacV)
binfile.close()

outBinFile = 'FBL_Temp_CMAC3.bin'
fr = readFile(outBinFile)
fr_bytearray = bytearray(fr)
mac = cmac.CMAC(algorithms.AES(bytes(secret_app)))
mac.update(bytes(fr_bytearray[0:]))
cmacV = mac.finalize()
print(cmacV.hex())
#binfile = open('PRODUCT.bin', 'ab+')
#binfile.seek(0)
#binfile.write(cmacV)
#binfile.close()
binfile = open('FBL_CMAC3.bin', 'wb')
binfile.write(cmacV)
binfile.close()



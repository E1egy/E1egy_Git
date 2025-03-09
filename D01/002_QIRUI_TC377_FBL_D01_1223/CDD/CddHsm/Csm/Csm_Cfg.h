#ifndef CSM_CFG_H
#define CSM_CFG_H 1

#include "Csm_Types.h"


#define     CSM_DEV_ERROR_DETECT   (STD_OFF)
#define     CSM_E_POLICY_VIOLATION  (0U)
#define     CSM_USE_SYNC_JOB_PROCESSING (STD_ON)

#define     CSM_MODULE_ID       (117U)


enum
{
    CSM_E_PARAM_PTR_INVALID         = 0x01,
    CSM_E_SERVICE_NOT_STARTED       = 0x02,
    CSM_E_PARAM_METHOD_INVALID      = 0x03,
    CSM_E_PARAM_KEY_TYPE_INVALID    = 0x04,
    CSM_E_UNINIT                    = 0x05,
    CSM_E_BUFFER_TOO_SMALL          = 0x06
};

enum
{
    CSM_ID_MacGenerateStart         = 0x06,
    CSM_ID_MacGenerateUpdate        = 0x07,
    CSM_ID_MacGenerateFinish        = 0x08,
    CSM_ID_MacVerifyStart           = 0x09,
    CSM_ID_MacVerifyUpdate          = 0x0A,
    CSM_ID_MacVerifyFinish          = 0x0B,
    CSM_ID_RandomSeedStart          = 0x0C,
    CSM_ID_RandomSeedUpdate         = 0x0D,
    CSM_ID_RandomSeedFinish         = 0x0E,
    CSM_ID_RandomGenerate           = 0x0F,
    CSM_ID_SymBlockEncryptStart     = 0x10,
    CSM_ID_SymBlockEncryptUpdate    = 0x11,
    CSM_ID_SymBlockEncryptFinish    = 0x12,
    CSM_ID_SymBlockDecryptStart     = 0x13,
    CSM_ID_SymBlockDecryptUpdate    = 0x14,
    CSM_ID_SymBlockDecryptFinish    = 0x15,
    CSM_ID_SymEncryptStart          = 0x16,
    CSM_ID_SymEncryptUpdate         = 0x17,
    CSM_ID_SymEncryptFinish         = 0x18,
    CSM_ID_SymDecryptStart          = 0x19,
    CSM_ID_SymDecryptUpdate         = 0x1A,
    CSM_ID_SymDecryptFinish         = 0x1B,
    CSM_ID_SymKeyExtractStart       = 0x32,
    CSM_ID_SymKeyExtractUpdate      = 0x33,
    CSM_ID_SymKeyExtractFinish      = 0x34,
    CSM_ID_SymKeyWrapStart          = 0x40,
    CSM_ID_SymKeyWrapUpdate         = 0x41,
    CSM_ID_SymKeyWrapFinish         = 0x42
};


/* CSM_CFG_H */
#endif

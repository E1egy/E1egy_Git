#ifndef CSM_TYPES_H
#define CSM_TYPES_H

#include "Std_Types.h"

/** Traceability    : [$Satisfies $CDS_CDRV 567]                  **/
/* Error code values as defined in the CSM specification: CSM0069 */
typedef enum
{
    CSM_E_OK = 0,
    CSM_E_NOT_OK = 1,
    CSM_E_BUSY = 2,
    CSM_E_SMALL_BUFFER = 3,
    CSM_E_ENTROPY_EXHAUSTION = 4
} Csm_ReturnType;

/* verify result values as defined in the CSM specification: CSM0075 */
typedef enum
{
    CSM_E_VER_OK = 0,
    CSM_E_VER_NOT_OK = 1
} Csm_VerifyResultType;

/* CSM specification: CSM0691 */
typedef uint16 Csm_ConfigIdType;

#define CSM_SYM_KEY_MAX_SIZE 48

#define CSM_PLAIN_KEY_MAX_SIZE 256


/* CSM specification: CSM0728 */
typedef uint8 Csm_AlignType;

/* CSM specification: CSM0082 */
typedef struct
{
    uint32 length;
    Csm_AlignType data[CSM_SYM_KEY_MAX_SIZE];
} Csm_SymKeyType;


typedef struct
{
    uint32 length;
    uint8 data[CSM_PLAIN_KEY_MAX_SIZE];
} Csm_PlainKeyType;


#endif

#include "mbedtls/build_info.h"

#include "mbedtls/platform.h"
#include "mbedtls/mbedtls_config.h"

#if !defined(MBEDTLS_BIGNUM_C) || !defined(MBEDTLS_RSA_C) ||  \
    !defined(MBEDTLS_SHA256_C) || !defined(MBEDTLS_MD_C)
int main( void )
{
    printf("MBEDTLS_BIGNUM_C and/or MBEDTLS_RSA_C and/or "
            "MBEDTLS_MD_C and/or "
            "MBEDTLS_SHA256_C and/or MBEDTLS_FS_IO not defined.\n");
    mbedtls_exit( 0 );
}
#else

#include "mbedtls/rsa.h"
#include "mbedtls/md.h"
#include "public_key.h"
//#include "ota.h"
#include "verify.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool verify_app(uint32_t fw_size)
{
    int ret = 1;
    bool verify_ok = false;
    size_t i;
    mbedtls_rsa_context rsa;
    unsigned char hash[32];
    unsigned char buf[2048];
    
    mbedtls_md_context_t ctx;
    uint8_t buffer_2k[2048];
    int mod;
    
    //printf("verify app......\r\n");

    mbedtls_rsa_init( &rsa );

    if( ( ret = mbedtls_mpi_read_string( &rsa.MBEDTLS_PRIVATE(N), 16, public_key_args_N ) ) != 0 ||
        ( ret = mbedtls_mpi_read_string( &rsa.MBEDTLS_PRIVATE(E), 16, public_key_args_E ) ) != 0 )
    {
        printf( " failed\n  ! mbedtls_mpi_read_string returned %d\n\n", ret );
        goto exit;
    }
    rsa.MBEDTLS_PRIVATE(len) = ( mbedtls_mpi_bitlen( &rsa.MBEDTLS_PRIVATE(N) ) + 7 ) >> 3;

    /*
     * Extract the RSA signature from the text file
     */
    //memcpy(buf, (uint32_t *)APP1_PARTITION_ADDR, sizeof(buf));
    fw_size -= 2048;

    /*
     * Compute the SHA-256 hash of the input file and
     * verify the signature
     */
    //printf( "\n  . Verifying the RSA/SHA-256 signature\r\n" );
    fflush( stdout );

    mbedtls_md_init(&ctx);

    ret = mbedtls_md_setup(&ctx, mbedtls_md_info_from_type(MBEDTLS_MD_SHA256), 0);
    if (ret) 
    {
        //printf("mbedtls_md_setup error: %d\r\n", ret);
        goto exit;
    }
    if ( (ret = mbedtls_md_starts(&ctx)) )
    {
        //printf("mbedtsl_md_starts error: %d\r\n", ret);
        goto exit;
    }
    
    mod = fw_size % 2048;
    for (i = 0; i < fw_size / 2048; i++)
    {
        //memcpy(buffer_2k, (uint32_t *)(APP1_PARTITION_ADDR + 2048 * (i + 1)), sizeof(buffer_2k));
        
//        printf("-------------------part [%d]--------------------------\r\n", i+1);
//        for (int j = 0; j < 2048; j++) 
//        {
//            fprintf( stdout, "%02X%s", buffer_2k[j],
//                 ( j + 1 ) % 16 == 0 ? "\r\n" : " " );
//        }
//        printf("\r\n---------------------------------------------------------\r\n\n\n");
        
        if ( (ret = mbedtls_md_update(&ctx, buffer_2k, sizeof(buffer_2k))) )
        {
            printf("mbedtls_md_update error: %d\r\n", ret);
        }
    }
    
    if (mod) 
    {  
        //memcpy(buffer_2k, (uint32_t *)(APP1_PARTITION_ADDR + 2048 * (i + 1)), mod);
        
//        printf("-------------------part [%d]--------------------------\r\n", i+1);
//        for (int j = 0; j < mod; j++) 
//        {
//            fprintf( stdout, "%02X%s", buffer_2k[j],
//                 ( j + 1 ) % 16 == 0 ? "\r\n" : " " );
//        }
//        printf("\r\n---------------------------------------------------------\r\n\n\n");
        
        if ( (ret = mbedtls_md_update(&ctx, buffer_2k, mod)) )
        {
            //printf("mbedtls_md_update error: %d\r\n", ret);
        }
    }
    
    if ( (ret = mbedtls_md_finish(&ctx, hash)))
    {
        //printf("mbedtls_md_finish error: %d\r\n", ret);
    }

//    printf("---------------------------------------------\r\n");
//    for( i = 0; i < rsa.MBEDTLS_PRIVATE(len); i++ )
//        mbedtls_fprintf( stdout, "%02X%s", buf[i],
//                 ( i + 1 ) % 16 == 0 ? "\r\n" : " " );
//    printf("---------------------------------------------\r\n\n");
//    
//    printf("---------------------------------------------\r\n");
//    for( i = 0; i < 256; i++ )
//        mbedtls_fprintf( stdout, "%02X%s", hash[i],
//                 ( i + 1 ) % 16 == 0 ? "\r\n" : " " );
//    printf("---------------------------------------------\r\n\n");

    if( ( ret = mbedtls_rsa_pkcs1_verify( &rsa, MBEDTLS_MD_SHA256,
                                          32, hash, buf ) ) != 0 )
    {
        //printf( " failed\n  ! mbedtls_rsa_pkcs1_verify returned -0x%0x\n\n", (unsigned int) -ret );
        goto exit;
    }

    //printf( "\n  . OK (the signature is valid)\n\n" );

    verify_ok = true;

exit:
    
    mbedtls_rsa_free( &rsa );
    mbedtls_md_free(&ctx);

    return verify_ok;
}
#endif /* MBEDTLS_BIGNUM_C && MBEDTLS_RSA_C && MBEDTLS_SHA256_C */

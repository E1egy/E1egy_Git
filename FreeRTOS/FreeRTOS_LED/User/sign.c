#if 0

#include "mbedtls/build_info.h"

#include "mbedtls/platform.h"

#if !defined(MBEDTLS_BIGNUM_C) || !defined(MBEDTLS_RSA_C) ||  \
    !defined(MBEDTLS_SHA256_C) || !defined(MBEDTLS_MD_C) || \
    !defined(MBEDTLS_FS_IO)
int main( void )
{
    mbedtls_printf("MBEDTLS_BIGNUM_C and/or MBEDTLS_RSA_C and/or "
            "MBEDTLS_MD_C and/or "
            "MBEDTLS_SHA256_C and/or MBEDTLS_FS_IO not defined.\n");
    mbedtls_exit( 0 );
}
#else

#include "mbedtls/rsa.h"
#include "mbedtls/md.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/entropy.h"
#include "strs.h"

#include <stdio.h>
#include <string.h>

static char key_args[8][8192];
static char args[][8] = {"N", "E", "D", "P", "Q", "DP", "DQ", "QP"};
static char * private_key_args_N;
static char * private_key_args_E;
static char * private_key_args_D;
static char * private_key_args_P;
static char * private_key_args_Q;
static char * private_key_args_DP;
static char * private_key_args_DQ;
static char * private_key_args_QP;


static void keys_args_print(int num)
{
    int i ;
    for (i = 0; i < num; i++)
    {
        printf("%s = %s\r\n\n", args[i], key_args[i]);
    }
}

static int read_private_keys_arg_from_file(const char *private_file)
{
    FILE *f = fopen(private_file, "r");
    if (f == NULL) 
    {
        perror(private_file);
        return -1;
    }

    char buffer[8192];
    int i;
    int num;
    char **str_list;

    for (i = 0; i < 2; i++) 
    {
        fgets(buffer, sizeof(buffer) - 1, f);
    }

    for (i = 0; i < 8; i++)
    {
        fgets(buffer, sizeof(buffer) - 1, f);
        str_list = strs_split(buffer, ":", &num);
        if (str_list != NULL && num == 4) 
        {
            strs_trim(str_list[num-1], "\n");
            strs_trim(str_list[num-1], "\r");
            strncpy(key_args[i], str_list[3], sizeof(key_args[i]) - 1);
            // printf("key_args[%d]: %s\r\n", i, key_args[i]);
        } 
        else 
        {
            fclose(f);
            strs_free2(str_list, num);
            return -1;
        }
        strs_free2(str_list, num);
    }
    fclose(f);
    keys_args_print(8);

    private_key_args_N = key_args[0];
    private_key_args_E = key_args[1];
    private_key_args_D = key_args[2];
    private_key_args_P = key_args[3];
    private_key_args_Q = key_args[4];
    private_key_args_DP = key_args[5];
    private_key_args_DQ = key_args[6];
    private_key_args_QP = key_args[7];
    
    return 0;
}


int main( int argc, char *argv[] )
{
    FILE *f;
    int ret = 1;
    int exit_code = MBEDTLS_EXIT_FAILURE;
    size_t i;
    mbedtls_rsa_context rsa;
    unsigned char hash[32];
    unsigned char buf[2048];
    char filename[512];
    mbedtls_mpi N, P, Q, D, E, DP, DQ, QP;

    if( argc != 3 )
    {
        mbedtls_printf( "usage: rsa_sign <filename> <private.txt>\n" );

#if defined(_WIN32)
        mbedtls_printf( "\n" );
#endif

        goto exit;
    }

    ret = read_private_keys_arg_from_file(argv[2]);
    if (ret) 
    {
        printf("read_private_keys_arg_from_file failed: %d\r\n", ret);
        exit(-1);
    }

    memset(buf, 0, sizeof(buf));
    mbedtls_rsa_init( &rsa );

    mbedtls_mpi_init( &N ); mbedtls_mpi_init( &P ); mbedtls_mpi_init( &Q );
    mbedtls_mpi_init( &D ); mbedtls_mpi_init( &E ); mbedtls_mpi_init( &DP );
    mbedtls_mpi_init( &DQ ); mbedtls_mpi_init( &QP );

    if( ( ret = mbedtls_mpi_read_string( &N , 16, private_key_args_N ) ) != 0 ||
        ( ret = mbedtls_mpi_read_string( &E , 16, private_key_args_E ) ) != 0 ||
        ( ret = mbedtls_mpi_read_string( &D , 16, private_key_args_D ) ) != 0 ||
        ( ret = mbedtls_mpi_read_string( &P , 16, private_key_args_P ) ) != 0 ||
        ( ret = mbedtls_mpi_read_string( &Q , 16, private_key_args_Q ) ) != 0 ||
        ( ret = mbedtls_mpi_read_string( &DP , 16, private_key_args_DP ) ) != 0 ||
        ( ret = mbedtls_mpi_read_string( &DQ , 16, private_key_args_DQ ) ) != 0 ||
        ( ret = mbedtls_mpi_read_string( &QP , 16, private_key_args_QP ) ) != 0 )
    {
        mbedtls_printf( " failed\n  ! mbedtls_mpi_read_string returned %d\n\n", ret );
        goto exit;
    }

    if( ( ret = mbedtls_rsa_import( &rsa, &N, &P, &Q, &D, &E ) ) != 0 )
    {
        mbedtls_printf( " failed\n  ! mbedtls_rsa_import returned %d\n\n",
                        ret );
        goto exit;
    }

    if( ( ret = mbedtls_rsa_complete( &rsa ) ) != 0 )
    {
        mbedtls_printf( " failed\n  ! mbedtls_rsa_complete returned %d\n\n",
                        ret );
        goto exit;
    }

    mbedtls_printf( "\n  . Checking the private key" );
    fflush( stdout );
    if( ( ret = mbedtls_rsa_check_privkey( &rsa ) ) != 0 )
    {
        mbedtls_printf( " failed\n  ! mbedtls_rsa_check_privkey failed with -0x%0x\n", (unsigned int) -ret );
        goto exit;
    }

    /*
     * Compute the SHA-256 hash of the input file,
     * then calculate the RSA signature of the hash.
     */
    mbedtls_printf( "\n  . Generating the RSA/SHA-256 signature" );
    fflush( stdout );

    if( ( ret = mbedtls_md_file(
                    mbedtls_md_info_from_type( MBEDTLS_MD_SHA256 ),
                    argv[1], hash ) ) != 0 )
    {
        mbedtls_printf( " failed\n  ! Could not open or read %s\n\n", argv[1] );
        goto exit;
    }

    mbedtls_ctr_drbg_context ctr_drbg;
    mbedtls_entropy_context entropy;
    const char *pers = "rsa_encrypt";

    mbedtls_ctr_drbg_init( &ctr_drbg );
    mbedtls_entropy_init( &entropy );

    ret = mbedtls_ctr_drbg_seed( &ctr_drbg, mbedtls_entropy_func,
                                 &entropy, (const unsigned char *) pers,
                                 strlen( pers ) );
    if( ret != 0 )
    {
        mbedtls_printf( " failed\n  ! mbedtls_ctr_drbg_seed returned %d\n",
                        ret );
        goto exit;
    }

    if( ( ret = mbedtls_rsa_pkcs1_sign( &rsa, mbedtls_ctr_drbg_random, &ctr_drbg, MBEDTLS_MD_SHA256,
                                32, hash, buf ) ) != 0 )
    {
        mbedtls_printf( " failed\n  ! mbedtls_rsa_pkcs1_sign returned -0x%0x\n\n", (unsigned int) -ret );
        goto exit;
    }

    /*
     * Write the signature into <filename>.sig
     */
    char *source_filename = argv[1];
    char *dest_filename;
    int num = 0;
    int pos;
    
    pos = strs_last_index(source_filename, ".");
    if (pos < 0) 
    {
        snprintf(filename, sizeof(filename) -1, "%s_signed", argv[1]);
    }
    else 
    {
        dest_filename = strs_insert(source_filename, "_signed", pos);
        strncpy(filename, dest_filename, sizeof(filename));
        strs_free(dest_filename);
    }

    if( ( f = fopen( filename, "wb+" ) ) == NULL )
    {
        mbedtls_printf( " failed\n  ! Could not create %s\n\n", argv[1] );
        goto exit;
    }

    fwrite(buf, 1, sizeof(buf), f);
    
    FILE *fw = fopen(source_filename, "rb");
    if (fw == NULL) 
    {
        printf("open %s error\r\n", source_filename);
        goto exit;
    }
    uint8_t buffer_2k[2048];
    uint32_t size;
    while ( (size = fread(buffer_2k, 1, sizeof(buffer_2k), fw) ) == sizeof(buffer_2k))
    {
        fwrite(buffer_2k, 1, sizeof(buffer_2k), f);
    }
    fwrite(buffer_2k, 1, size, f);

    fclose(fw);
    fclose( f );

    mbedtls_printf( "\n  . Done (created \"%s\")\n\n", filename );

    exit_code = MBEDTLS_EXIT_SUCCESS;

exit:
    mbedtls_ctr_drbg_free( &ctr_drbg );
    mbedtls_entropy_free( &entropy );
    mbedtls_rsa_free( &rsa );
    mbedtls_mpi_free( &N ); mbedtls_mpi_free( &P ); mbedtls_mpi_free( &Q );
    mbedtls_mpi_free( &D ); mbedtls_mpi_free( &E ); mbedtls_mpi_free( &DP );
    mbedtls_mpi_free( &DQ ); mbedtls_mpi_free( &QP );

    mbedtls_exit( exit_code );
}
#endif /* MBEDTLS_BIGNUM_C && MBEDTLS_RSA_C && MBEDTLS_SHA256_C &&
          MBEDTLS_FS_IO */
#endif
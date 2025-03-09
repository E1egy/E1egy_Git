#define LCF_CSA0_SIZE 8k
#define LCF_USTACK0_SIZE 2k
#define LCF_ISTACK0_SIZE 1k

#define LCF_CSA1_SIZE 8k
#define LCF_USTACK1_SIZE 2k
#define LCF_ISTACK1_SIZE 1k

#define LCF_CSA2_SIZE 8k
#define LCF_USTACK2_SIZE 2k
#define LCF_ISTACK2_SIZE 1k

#define LCF_HEAP_SIZE  4k

#define LCF_CPU0 0
#define LCF_CPU1 1
#define LCF_CPU2 2

#define CLONE_DSRAM_SIZE	4k
#define PFLASHDRIVER_DSRAM_SIZE	1k
#define NVM_DSRAM_SIZE	    64k

/*Un comment one of the below statements to enable CpuX DMI RAM to hold global variables*/
#define LCF_DEFAULT_HOST LCF_CPU0
/*#define LCF_DEFAULT_HOST LCF_CPU1*/
/*#define LCF_DEFAULT_HOST LCF_CPU2*/



#define LCF_DSPR2_START (0x50000000 + CLONE_DSRAM_SIZE)
#define LCF_DSPR2_SIZE  (96k - CLONE_DSRAM_SIZE - PFLASHDRIVER_DSRAM_SIZE )

#define LCF_DSPR1_START (0x60000000 + CLONE_DSRAM_SIZE)
#define LCF_DSPR1_SIZE  (240k - CLONE_DSRAM_SIZE - 78k)			/*XCP_test*/

#define LCF_DSPR0_START (0x70000000 + CLONE_DSRAM_SIZE)
#define LCF_DSPR0_SIZE  (240k - CLONE_DSRAM_SIZE)			

#define LCF_CSA2_OFFSET     (LCF_DSPR2_SIZE - 1k - LCF_CSA2_SIZE)
#define LCF_ISTACK2_OFFSET  (LCF_CSA2_OFFSET - 256 - LCF_ISTACK2_SIZE)
#define LCF_USTACK2_OFFSET  (LCF_ISTACK2_OFFSET - 256 - LCF_USTACK2_SIZE)

#define LCF_CSA1_OFFSET     (LCF_DSPR1_SIZE - 1k - LCF_CSA1_SIZE)
#define LCF_ISTACK1_OFFSET  (LCF_CSA1_OFFSET - 256 - LCF_ISTACK1_SIZE)
#define LCF_USTACK1_OFFSET  (LCF_ISTACK1_OFFSET - 256 - LCF_USTACK1_SIZE)

#define LCF_CSA0_OFFSET     (LCF_DSPR0_SIZE - 1k - LCF_CSA0_SIZE)
#define LCF_ISTACK0_OFFSET  (LCF_CSA0_OFFSET - 256 - LCF_ISTACK0_SIZE)
#define LCF_USTACK0_OFFSET  (LCF_ISTACK0_OFFSET - 256 - LCF_USTACK0_SIZE)

#define LCF_HEAP0_OFFSET    (LCF_USTACK0_OFFSET - LCF_HEAP_SIZE)
#define LCF_HEAP1_OFFSET    (LCF_USTACK1_OFFSET - LCF_HEAP_SIZE)
#define LCF_HEAP2_OFFSET    (LCF_USTACK2_OFFSET - LCF_HEAP_SIZE)

/** Define the starting address of each core interrupt vector table.
    the starting address of each core interrupt vector table is 8K 
    in the reciprocal of Program Flash space. **/
//#define LCF_INTVEC0_START 0x800F0000
//#define LCF_INTVEC1_START 0x800F2000
//#define LCF_INTVEC2_START 0x800F4000

#define LCF_INTVEC0_START 0x800CEC00 //0x800FE000
#define LCF_INTVEC1_START 0x800CED00 //0x801FC000
#define LCF_INTVEC2_START 0x800CEE00 //0x802FE000

#define LCF_TRAPVEC0_START 0x80070100
#define LCF_TRAPVEC1_START 0x800C8000
#define LCF_TRAPVEC2_START 0x800CA000

#define LCF_STARTPTR_CPU0 0x80070200 //0x80060024
#define LCF_STARTPTR_CPU1 0x800C8200 //0x80100200
#define LCF_STARTPTR_CPU2 0x800CA200 //0x80200220

#define LCF_MCALLIB_CODE  0x80080000
#define LCF_FLSLOADER_CONST  0x800A0000

#define LCF_STARTPTR_NC_CPU0 0xA0070200 //0xA0060024
#define LCF_STARTPTR_NC_CPU1 0xA00C8200 //0xA0100200
#define LCF_STARTPTR_NC_CPU2 0xA00CA200  //0xA0200220

#define LCF_MCALLIB_NC_CODE 0xA0080000
#define LCF_FLSLOADER_NC_CONST  0xA00A0000

#define INTTAB0             (LCF_INTVEC0_START)
#define INTTAB1             (LCF_INTVEC1_START)
#define INTTAB2             (LCF_INTVEC2_START)
#define TRAPTAB0            (LCF_TRAPVEC0_START)
#define TRAPTAB1            (LCF_TRAPVEC1_START)
#define TRAPTAB2            (LCF_TRAPVEC2_START)

/** Define the starting pointer position of the reset bit core0 (no cache access). **/
#define RESET LCF_STARTPTR_CPU0

#include "tc1v1_6_2.lsl"

// Specify a multi-core processor environment (mpe)

processor mpe
{
    derivative = tc37;
}

derivative tc37
{
    core tc0
    {
        architecture = TC1V1.6.2;
        space_id_offset = 100;            // add 100 to all space IDs in the architecture definition
        copytable_space = vtc:linear;     // use the copy table in the virtual core for 'bss' and initialized data sections
    }
    
    core tc1 // core 1 TC16E
    {
        architecture = TC1V1.6.2;
        space_id_offset = 200;            // add 200 to all space IDs in the architecture definition
        copytable_space = vtc:linear;     // use the copy table in the virtual core for 'bss' and initialized data sections
    }
    
    core tc2 // core 2 TC16P
    {
        architecture = TC1V1.6.2;
        space_id_offset = 300;            // add 300 to all space IDs in the architecture definition
        copytable_space = vtc:linear;     // use the copy table in the virtual core for 'bss' and initialized data sections
    }
    
    core vtc
    {
        architecture = TC1V1.6.2;
        import tc0;                     // add all address spaces of core tc0 to core vtc for linking and locating
        import tc1;                     //                                tc1
        import tc2;                     //                                tc2
    }
    
    bus sri
    {
        mau = 8;
        width = 32;
        
        // map shared addresses one-to-one to real cores and virtual cores
        map (dest=bus:tc0:fpi_bus, src_offset=0, dest_offset=0, size=0xc0000000);
        map (dest=bus:tc1:fpi_bus, src_offset=0, dest_offset=0, size=0xc0000000);
        map (dest=bus:tc2:fpi_bus, src_offset=0, dest_offset=0, size=0xc0000000);
        map (dest=bus:vtc:fpi_bus, src_offset=0, dest_offset=0, size=0xc0000000);
    }
    
    memory clone
    {
    	mau = 8;
        size = CLONE_DSRAM_SIZE;
        type = ram;
        
        map (dest=bus:vtc:fpi_bus, dest_offset=0xD0000000, size = CLONE_DSRAM_SIZE, priority=8);
        map (dest=bus:sri, dest_offset=0x70000000, size=CLONE_DSRAM_SIZE);
        map (dest=bus:sri, dest_offset=0x60000000, size=CLONE_DSRAM_SIZE);
        map (dest=bus:sri, dest_offset=0x50000000, size=CLONE_DSRAM_SIZE);
    }
    
    memory dsram2 // Data Scratch Pad Ram
    {
        mau = 8;
        size = 96k - CLONE_DSRAM_SIZE -PFLASHDRIVER_DSRAM_SIZE;
        type = ram;
        map (dest=bus:tc2:fpi_bus, dest_offset=0xd0000000+CLONE_DSRAM_SIZE, size=96k-CLONE_DSRAM_SIZE-PFLASHDRIVER_DSRAM_SIZE, priority=8);
        map (dest=bus:sri, dest_offset=0x50000000+CLONE_DSRAM_SIZE, size=96k-CLONE_DSRAM_SIZE-PFLASHDRIVER_DSRAM_SIZE);
    }
    
    memory psram2 // Program Scratch Pad Ram
    {
        mau = 8;
        size = 64k;
        type = ram;
        map (dest=bus:tc2:fpi_bus, dest_offset=0xc0000000, size=64k, priority=8);
        map (dest=bus:sri, dest_offset=0x50100000, size=64k);
    }
    
    memory dsram1 // Data Scratch Pad Ram
    {
        mau = 8;
        size = 240k-CLONE_DSRAM_SIZE - 78K;
        type = ram;
        map (dest=bus:tc1:fpi_bus, dest_offset=0xd0000000+CLONE_DSRAM_SIZE, size=240k-CLONE_DSRAM_SIZE  -78K, priority=8);
        map (dest=bus:sri, dest_offset=0x60000000+CLONE_DSRAM_SIZE, size=240k-CLONE_DSRAM_SIZE  - 78K);
    }
    
    memory psram1 // Program Scratch Pad Ram
    {
        mau = 8;
        size = 64k;
        type = ram;
        map (dest=bus:tc1:fpi_bus, dest_offset=0xc0000000, size=64k, priority=8);
        map (dest=bus:sri, dest_offset=0x60100000, size=64k);
    }

    memory dsram0 // Data Scratch Pad Ram
    {
        mau = 8;
        size = 240k-CLONE_DSRAM_SIZE;
        type = ram;
        map (dest=bus:tc0:fpi_bus, dest_offset=0xd0000000+CLONE_DSRAM_SIZE, size=240k-CLONE_DSRAM_SIZE, priority=8);
        map (dest=bus:sri, dest_offset=0x70000000+CLONE_DSRAM_SIZE, size=240k-CLONE_DSRAM_SIZE);
    }

    memory dsram2_PFlashDriver // Data Scratch Pad Ram
    {
        mau = 8;
        size = PFLASHDRIVER_DSRAM_SIZE;
        type = ram;
        map (dest=bus:tc2:fpi_bus, dest_offset=0xd0000000+96k-PFLASHDRIVER_DSRAM_SIZE, size=PFLASHDRIVER_DSRAM_SIZE, priority=8);
        map (dest=bus:sri, dest_offset=0x50000000+96k-PFLASHDRIVER_DSRAM_SIZE, size=PFLASHDRIVER_DSRAM_SIZE);
    }
    
    /*XCP_TEST*/		
    memory CalRam // Data Scratch Pad Ram
    {
        mau = 8;
        size = 64K;
        type = ram;
        map (dest=bus:tc1:fpi_bus, dest_offset=0xd0000000 + (240k - 78K), size= 64K, priority=8);
        map (dest=bus:sri, dest_offset=0x60000000 + (240k - 78K), size= 64K);
    }/* 0x60028800 */
    memory MeaRam // Data Scratch Pad Ram
    {
        mau = 8;
        size = 6K;
        type = ram;
        map (dest=bus:tc1:fpi_bus, dest_offset=0xd0000000 + (240k - 14K), size= 6K, priority=8);
        map (dest=bus:sri, dest_offset=0x60000000 + (240k - 14K), size= 6K);
    }/* 0x60038800 */

    
    memory psram0 // Program Scratch Pad Ram
    {
        mau = 8;
        size = 60k;
        type = ram;
        map (dest=bus:tc0:fpi_bus, dest_offset=0xc0000000, size=60k, priority=8);
        map (dest=bus:sri, dest_offset=0x70100000, size=60k);
    }

    memory psram0_flashDrv // Program Scratch Pad Ram for FlashDrv
    {
        mau = 8;
        size = 4k;
        type = ram;
        map (dest=bus:tc0:fpi_bus, dest_offset=0xc0000000 + 60k, size=4k, priority=8);
        map (dest=bus:sri, dest_offset=0x70100000 + 60k, size=4k);
    }

    memory pfls0_hsm
    {
        mau = 8;
        size = 0x60000;
        type = rom;
        map     cached (dest=bus:sri, dest_offset=0x80000000,           size=0x60000);
        map not_cached (dest=bus:sri, dest_offset=0xa0000000, reserved, size=0x60000);
    }
    
    memory pfls0
    {
        mau = 8;
        size = 576K;
        type = rom;
        map     cached (dest=bus:sri, dest_offset=0x80070000,           size=576K);
        map not_cached (dest=bus:sri, dest_offset=0xA0070000, reserved, size=576K);
    }

    memory pfls1_hsm
    {
        mau = 8;
        size = 0x60000;
        type = rom;
        map     cached (dest=bus:sri, dest_offset=0x80300000,           size=0x60000);
        map not_cached (dest=bus:sri, dest_offset=0xa0300000, reserved, size=0x60000);
    }

    memory pfls1
    {
        mau = 8;
        size = 3M - 0x60000;
        type = rom;
        map     cached (dest=bus:sri, dest_offset=0x80300000+0x60000,           size=3M-0x60000);
        map not_cached (dest=bus:sri, dest_offset=0xa0300000+0x60000, reserved, size=3M-0x60000);
    }
    
    memory dfls0
    {
        mau = 8;
        size = 256K;
        type = reserved nvram;
        map (dest=bus:sri, dest_offset=0xaf000000, size=256K);
    }

    memory ucb
    {
        mau = 8;
        size = 24k;
        type = rom;
        map (dest=bus:sri, dest_offset=0xaf400000, reserved, size=24k);
    }
    
    memory cpu_dlmu
    {
        mau = 8;
        size = 192k - NVM_DSRAM_SIZE;
        type = ram;
        map     cached (dest=bus:sri, dest_offset=0x90000000,           size=192k - NVM_DSRAM_SIZE);
        map not_cached (dest=bus:sri, dest_offset=0xb0000000, reserved, size=192k - NVM_DSRAM_SIZE);
    }
        /*NVM USE*/	
    memory NvmRam // Data Scratch Pad Ram
    {
        mau = 8;
        size = NVM_DSRAM_SIZE;
        type = ram;
        map (dest=bus:tc2:fpi_bus, dest_offset=0x90000000 + (192k  - NVM_DSRAM_SIZE), size= NVM_DSRAM_SIZE, priority=8);
        map not_cached (dest=bus:sri, dest_offset=0xb0000000 + (192k - NVM_DSRAM_SIZE), size= NVM_DSRAM_SIZE);
    }/* 0xb0020000 */

//    memory cpu1_dlmu
//    {
//        mau = 8;
//        size = 64k;
//        type = ram;
//        map     cached (dest=bus:sri, dest_offset=0x90010000,           size=64k);
//        map not_cached (dest=bus:sri, dest_offset=0xb0010000, reserved, size=64k);
//    }
//    
//    memory cpu2_dlmu
//    {
//        mau = 8;
//        size = 64k;
//        type = ram;
//        map     cached (dest=bus:sri, dest_offset=0x90020000,           size=64k);
//        map not_cached (dest=bus:sri, dest_offset=0xb0020000, reserved, size=64k);
//    }
    
    
    section_setup :vtc:linear
    {
        start_address
        (
            symbol = "_START"
        );
    }
    
    section_setup :vtc:linear
    {
        stack "ustack_tc0" (min_size = 1k, fixed, align = 8);
        stack "istack_tc0" (min_size = 1k, fixed, align = 8);
        stack "ustack_tc1" (min_size = 1k, fixed, align = 8);
        stack "istack_tc1" (min_size = 1k, fixed, align = 8);
        stack "ustack_tc2" (min_size = 1k, fixed, align = 8);
        stack "istack_tc2" (min_size = 1k, fixed, align = 8);
    }
    
    /*Section setup for the copy table*/
    section_setup :vtc:linear
    {
        copytable
        (
            align = 4,
            dest = linear,
            table
            {
                symbol = "_lc_ub_table_tc0";
                space = :tc0:linear, :tc0:abs24, :tc0:abs18, :tc0:csa;
            },
            table
            {
                symbol = "_lc_ub_table_tc1";
                space = :tc1:linear, :tc1:abs24, :tc1:abs18, :tc1:csa;
            },
            table
            {
                symbol = "_lc_ub_table_tc2";
                space = :tc2:linear, :tc2:abs24, :tc2:abs18, :tc2:csa;
            }
        );
    }
    
    section_layout mpe:vtc:linear
    {
        group  (ordered, attributes=r, run_addr= 0x80000000)
        {
              reserved "RES_FOR_HSM" (size = 0x60000);
        }
        //group (ordered, contiguous,run_addr=0x80060000)
        group (ordered, contiguous,run_addr=0x80070000)
        {
            select "*.Alternate_BootModeHeader0";       
        }
        //group (ordered, contiguous,run_addr=0x800CFFA0)
        //{
        //    select "*.g_F189ManufactureEcuSoftwareVersion";       
        //}
        
        group (ordered, contiguous,run_addr=0x800CFFB0)
        {
            select "*.g_bootSoftwareVersion";       
        }

        group (ordered, contiguous,run_addr=0x800CFFC0)
        {
            select "*.FblTailInfo";       
        }
    }

    section_layout :vtc:linear
    {

		"dsram2_START"      := addressof(mem:dsram2);
		"dsram2_END"        := "dsram2_START" + sizeof(mem:dsram2);

		"dsram2_PFlashDriver_START" := addressof(mem:dsram2_PFlashDriver);
        "dsram2_PFlashDriver_END" := "dsram2_PFlashDriver_START" + sizeof(mem:dsram2_PFlashDriver);

		"dsram1_START"		:= addressof(mem:dsram1);
		"dsram1_END"		:= "dsram1_START" + sizeof(mem:dsram1);
		
		"dsram0_START"		:= addressof(mem:dsram0);
		"dsram0_END"		:= "dsram0_START" + sizeof(mem:dsram0);
		
		"LMU_SRAM_START"	:= 0xb0000000;
		"LMU_SRAM_END"		:= 0xb0000000+128K;
		
		/*Range of DFLASH equal to PMU_DFLASH0 add PMU_DFLASH1.*/
		"__rodata_start"	:= sizeof(mem:pfls0);
		"__rodata_end"		:= "__rodata_start" + sizeof(mem:pfls0);
		
		"DFLASH_START" 		:= addressof(mem:dfls0);
		"DFLASH_END"		:= "DFLASH_START" + sizeof(mem:dfls0);
		
		"DMI_DSPR_START"	:= addressof(mem:clone);
		"DMI_DSPR_END"		:= "DMI_DSPR_START" + sizeof(mem:clone);
		
		"PERIPHERAL_START"	:= 0xF0000000;
		"PERIPHERAL_END"	:= "PERIPHERAL_START" + 256M - 1;
		
		/*Code */ 
		"psram2_START"      := addressof(mem:psram2);
		"psram2_END"        := "psram2_START" + sizeof(mem:psram2);
		
		"psram1_START"		:= addressof(mem:psram1);
		"psram1_END"		:= "psram1_START" + sizeof(mem:psram1);
		
		"psram0_START"		:= addressof(mem:psram0);
		"psram0_END"		:= "psram0_START" + sizeof(mem:psram0);

		"psram0_FLAHSHDRV_START"	:= addressof(mem:psram0_flashDrv);
		"psram0_FLASHDRV_END"		:= "psram0_FLAHSHDRV_START" + sizeof(mem:psram0_flashDrv);

		/*Range of PFLASH equal to PMU_PFLASH0 add PMU_PFLASH1.*/
		"PFLASH_START"		:= addressof(mem:pfls0);
		"PFLASH_END"		:= "PFLASH_START" + sizeof(mem:pfls0);
		
//		"PMI_PSPR_START"	:= addressof(mem:pfls0);
//		"PMI_PSPR_END"		:= "PMI_PSPR_START" + 2M;
    }
    /*Sections located at absolute fixed address*/

    section_layout :vtc:linear
    {
        /*Fixed memory Allocations for stack memory and CSA*/
        group (ordered)
        {
            group ustack2(align = 8, run_addr = mem:dsram2[LCF_USTACK2_OFFSET])
            {
                stack "ustack_tc2" (size = LCF_USTACK2_SIZE);
            }
            "__USTACK2":= sizeof(group:ustack2) > 0  ? "_lc_ue_ustack_tc2" : 0;
            "__USTACK2_END"="_lc_gb_ustack2";
            
            group istack2(align = 8, run_addr = mem:dsram2[LCF_ISTACK2_OFFSET])
            {
                stack "istack_tc2" (size = LCF_ISTACK2_SIZE);
            }
            "__ISTACK2":= sizeof(group:istack2) > 0  ? "_lc_ue_istack_tc2" : 0;
            "__ISTACK2_END"="_lc_gb_istack2";
            
            group (align = 64, attributes=rw, run_addr=mem:dsram2[LCF_CSA2_OFFSET]) 
                reserved "csa_tc2" (size = LCF_CSA2_SIZE);
            "__CSA2":=        "_lc_ub_csa_tc2";
            "__CSA2_END":=    "_lc_ue_csa_tc2";        
        }
        group (ordered)
        {
            group ustack1(align = 8, run_addr = mem:dsram1[LCF_USTACK1_OFFSET])
            {
                stack "ustack_tc1" (size = LCF_USTACK1_SIZE);
            }
            "__USTACK1":= sizeof(group:ustack1) > 0  ? "_lc_ue_ustack_tc1" : 0;
            "__USTACK1_END"="_lc_gb_ustack1";
            
            group istack1(align = 8, run_addr = mem:dsram1[LCF_ISTACK1_OFFSET])
            {
                stack "istack_tc1" (size = LCF_ISTACK1_SIZE);
            }
            "__ISTACK1":= sizeof(group:istack1) > 0  ? "_lc_ue_istack_tc1" : 0;
            "__ISTACK1_END"="_lc_gb_istack1";
            
            group (align = 64, attributes=rw, run_addr=mem:dsram1[LCF_CSA1_OFFSET]) 
                reserved "csa_tc1" (size = LCF_CSA1_SIZE);
            "__CSA1":=        "_lc_ub_csa_tc1";
            "__CSA1_END":=    "_lc_ue_csa_tc1";
        }
        group (ordered)
        {
            group ustack0(align = 8, run_addr = mem:dsram0[LCF_USTACK0_OFFSET])
            {
                stack "ustack_tc0" (size = LCF_USTACK0_SIZE);
            }
            "__USTACK0":= sizeof(group:ustack0) > 0  ? "_lc_ue_ustack_tc0" : 0;
            "__USTACK0_END"="_lc_gb_ustack0";
            
            group istack0(align = 8, run_addr = mem:dsram0[LCF_ISTACK0_OFFSET])
            {
                stack "istack_tc0" (size = LCF_ISTACK0_SIZE);
            }
            "__ISTACK0":= sizeof(group:istack0) > 0  ? "_lc_ue_istack_tc0" : 0;
            "__ISTACK0_END"="_lc_gb_istack0";
            
            group (align = 64, attributes=rw, run_addr=mem:dsram0[LCF_CSA0_OFFSET]) 
                reserved "csa_tc0" (size = LCF_CSA0_SIZE);
            "__CSA0":=        "_lc_ub_csa_tc0";
            "__CSA0_END":=    "_lc_ue_csa_tc0";
        }
        
        /*Fixed memory Allocations for _START*/
        group (ordered)
        {
            group  reset (run_addr=RESET)
            {
                section "reset" ( size = 0x20, fill = 0x0800, attributes = r )
                {
                    select ".text.start";
                }
            }
            group  interface_const (run_addr=mem:pfls0[0x0020])
            {
                select "*.interface_const";
            }
            "__IF_CONST" := addressof(group:interface_const);
            "__START0" := LCF_STARTPTR_CPU0;
            "__START1" := LCF_STARTPTR_CPU1;
            "__START2" := LCF_STARTPTR_CPU2;
        }
        
        /*Fixed memory Allocations for Trap Vector Table*/
        group (ordered)
        {
            group trapvec_tc0 (align = 8, run_addr=LCF_TRAPVEC0_START)
            {
                section "trapvec_tc0" (size=0x100, attributes=rx, fill=0)
                {
                    select "(.text.traptab_cpu0*)";
                }
            }
            group trapvec_tc1 (align = 8, run_addr=LCF_TRAPVEC1_START)
            {
                section "trapvec_tc1" (size=0x100, attributes=rx, fill=0)
                {
                    select "(.text.traptab_cpu1*)";
                }
            }
            group trapvec_tc2 (align = 8, run_addr=LCF_TRAPVEC2_START)
            {
                section "trapvec_tc2" (size=0x100, attributes=rx, fill=0)
                {
                    select "(.text.traptab_cpu2*)";
                }
            }
            "__TRAPTAB_CPU0" := TRAPTAB0;
            "__TRAPTAB_CPU1" := TRAPTAB1;
            "__TRAPTAB_CPU2" := TRAPTAB2;
        }
        
        /*Fixed memory Allocations for Start up code*/
        group (ordered)
        {
            group start_tc0 (run_addr=LCF_STARTPTR_CPU0)
            {
                select "(.text.start_cpu0*)";
            }
            group start_tc1 (run_addr=LCF_STARTPTR_CPU1)
            {
                section "start_tc1" (size=0x20, attributes=rx, fill=0)
                {
                    select "(.text.start_cpu1*)";
                }
            }
            group start_tc2 (run_addr=LCF_STARTPTR_CPU2)
            {
                select "(.text.start_cpu2*)";
            }
            "__ENABLE_INDIVIDUAL_C_INIT_CPU0" := 0; /* Not used */
            "__ENABLE_INDIVIDUAL_C_INIT_CPU1" := 0;
            "__ENABLE_INDIVIDUAL_C_INIT_CPU2" := 0;
        }
        
        /*Fixed memory Allocations for Interrupt Vector Table*/
        group (ordered)
        {
            group int_tab_tc0 (ordered)
            {
#                include "inttab0.lsl"
            }
            group int_tab_tc1 (ordered)
            {
#                include "inttab1.lsl"
            }
            group int_tab_tc2 (ordered)
            {
#                include "inttab2.lsl"
            }
            "_lc_u_int_tab" = (LCF_INTVEC0_START);
            "__INTTAB_CPU0" = (LCF_INTVEC0_START);
            "__INTTAB_CPU1" = (LCF_INTVEC0_START);
            "__INTTAB_CPU2" = (LCF_INTVEC0_START);
        }
        
        /*Fixed memory Allocations for BMHD*/
        group (ordered)
        {
            group  bmh_0_orig (run_addr=mem:ucb[0x0000])
            {
                select ".rodata.bmhd_0_orig";
            }
            group  bmh_1_orig (run_addr=mem:ucb[0x0200])
            {
                select ".rodata.bmhd_1_orig";
            }
            group  bmh_2_orig (run_addr=mem:ucb[0x0400])
            {
                select ".rodata.bmhd_2_orig";
            }
            group  bmh_3_orig (run_addr=mem:ucb[0x0600])
            {
                select ".rodata.bmhd_3_orig";
            }
            group  bmh_blank (run_addr=mem:ucb[0x0800])
            {
            }
            group  bmh_0_copy (run_addr=mem:ucb[0x1000])
            {
                select ".rodata.bmhd_0_copy";
            }
            group  bmh_1_copy (run_addr=mem:ucb[0x1200])
            {
                select ".rodata.bmhd_1_copy";
            }
            group  bmh_2_copy (run_addr=mem:ucb[0x1400])
            {
                select ".rodata.bmhd_2_copy";
            }
            group  bmh_3_copy (run_addr=mem:ucb[0x1600])
            {
                select ".rodata.bmhd_3_copy";
            }
        }
    }
    
#if 1 /*ltc E121: relocation error*/
    /*Fixed memory Allocations for MCALLIB and FLSLOADER CONST*/
    section_layout :vtc:linear
    {
         group (ordered, align = 4, run_addr=LCF_MCALLIB_CODE)
        {
           select "*Code.MCALLIB_CODE*";
        }
        
        group (ordered, align = 4, run_addr=LCF_FLSLOADER_CONST)
        {
           select "*Const.FlsCpu0.32bit*";
        }
        
	}
#endif


    

        
    /*Near Abbsolute Addressable Data Sections*/
    section_layout :vtc:abs18
    {
        /*Near Absolute Data, selectable with patterns and user defined sections*/
        group
        {
            group (ordered, contiguous, align = 4, attributes=rw, run_addr = mem:dsram2)
            {
                select "(.zdata.zdata_cpu2|.zdata.zdata_cpu2.*)";
                select "(.zbss.zbss_cpu2|.zbss.zbss_cpu2.*)";
            }
            
            group (ordered, contiguous, align = 4, attributes=rw, run_addr = mem:dsram1)
            {
                select "(.zdata.zdata_cpu1|.zdata.zdata_cpu1.*)";
                select "(.zbss.zbss_cpu1|.zbss.zbss_cpu1.*)";
               
            }
            
            group (ordered, contiguous, align = 4, attributes=rw, run_addr = mem:dsram0)
            {
                select "(.zdata.zdata_cpu0|.zdata.zdata_cpu0.*)";
                select "(.zbss.zbss_cpu0|.zbss.zbss_cpu0.*)";
            }
            
            group (ordered, attributes=rw, run_addr = mem:cpu_dlmu)
            {
                select "(.zdata.zlmudata|.zdata.zlmudata.*)";
                select "(.zbss.zlmubss|.zbss.zlmubss.*)";
            } 
        }

        /*Near Absolute Data, selectable by toolchain*/
#        if LCF_DEFAULT_HOST == LCF_CPU2
        group (ordered, contiguous, align = 4, attributes=rw, run_addr = mem:dsram2)
#        endif
#        if LCF_DEFAULT_HOST == LCF_CPU1
        group (ordered, contiguous, align = 4, attributes=rw, run_addr = mem:dsram1)
#        endif
#        if LCF_DEFAULT_HOST == LCF_CPU0
        group (ordered, contiguous, align = 4, attributes=rw, run_addr = mem:dsram0)
#        endif
        {
            group zdata_mcal(attributes=rw)
            {
                select ".zdata.dsprInit.cpu0.32bit";
                select ".zdata.dsprInit.cpu0.16bit";
                select ".zdata.dsprInit.cpu0.8bit";
            }
            
            group zdata_powerOn(attributes=rw)
            {
                select ".zdata.dsprPowerOnInit.cpu0.32bit";
                select ".zdata.dsprPowerOnInit.cpu0.16bit";
                select ".zdata.dsprPowerOnInit.cpu0.8bit";
            }
            
            group zbss_mcal(attributes=rw)
            {
                select ".zbss.dsprClearOnInit.cpu0.32bit";
                select ".zbss.dsprClearOnInit.cpu0.16bit";
                select ".zbss.dsprClearOnInit.cpu0.8bit";
            }
            
            group zbss_noClear(attributes=rw)
            {
                select ".zbss.dsprNoInit.cpu0.32bit";
                select ".zbss.dsprNoInit.cpu0.16bit";
                select ".zbss.dsprNoInit.cpu0.8bit";
            }
            
            group zbss_powerOn(attributes=rw)
            {
                select ".zbss.dsprPowerOnClear.cpu0.32bit";
                select ".zbss.dsprPowerOnClear.cpu0.16bit";
                select ".zbss.dsprPowerOnClear.cpu0.8bit";
            }
            
//            group zdata(attributes=rw)
//            {
//                select "(.zdata|.zdata.*)";
//                select "(.zbss|.zbss.*)";
//            }
        }
        
        /*Near Absolute Const, selectable with patterns and user defined sections*/
        group
        {
            group (ordered, align = 4, contiguous, run_addr=mem:pfls0)
            {
                select ".zrodata.Ifx_Ssw_Tc0.*";
                select ".zrodata.Ifx_Ssw_Tc1.*";
                select ".zrodata.Ifx_Ssw_Tc2.*";
                select ".zrodata.Cpu0_Main.*";
                select ".zrodata.Cpu1_Main.*";
                select ".zrodata.Cpu2_Main.*";
                
                /*Near Absolute Const, selectable by toolchain*/
                select ".zrodata.const.cpu0.32bit";
                select ".zrodata.const.cpu0.16bit";
                select ".zrodata.const.cpu0.8bit";
                select ".zrodata.config.cpu0.32bit";
                select ".zrodata.config.cpu0.16bit";
                select ".zrodata.config.cpu0.8bit";
                select "(.zrodata|.zrodata.*)";
            }
        }
    }
        
    /*Relative A0/A1/A8/A9 Addressable Sections*/
    section_layout :vtc:linear
    {
        /*Relative A0 Addressable Data, selectable by toolchain*/
#        if LCF_DEFAULT_HOST == LCF_CPU2
        group a0 (ordered, contiguous, align = 4, attributes=rw, run_addr = mem:dsram2)
#        endif
#        if LCF_DEFAULT_HOST == LCF_CPU1
        group a0 (ordered, contiguous, align = 4, attributes=rw, run_addr = mem:dsram1)
#        endif
#        if LCF_DEFAULT_HOST == LCF_CPU0
        group a0 (ordered, contiguous, align = 4, attributes=rw, run_addr = mem:dsram0)
#        endif
        {
            select "(.data_a0.sdata|.data_a0.sdata.*)";
            select "(.bss_a0.sbss|.bss_a0.sbss.*)";
        }
        "_SMALL_DATA_" := sizeof(group:a0) > 0 ? addressof(group:a0) : addressof(group:a0) & 0xF0000000 + 32k;
        "__A0_MEM" = "_SMALL_DATA_";
        
        /*Relative A1 Addressable Const, selectable by toolchain*/
        /*Small constant sections, No option given for CPU specific user sections to make generated code portable across Cpus*/
#        if LCF_DEFAULT_HOST == LCF_CPU2
        group  a1 (ordered, align = 4, run_addr=mem:pfls1)
#        endif
#        if LCF_DEFAULT_HOST == LCF_CPU1
        group  a1 (ordered, align = 4, run_addr=mem:pfls1)
#        endif
#        if LCF_DEFAULT_HOST == LCF_CPU0
        group  a1 (ordered, align = 4, run_addr=mem:pfls0)
#        endif
        {
            select "(.rodata_a1.srodata|.rodata_a1.srodata.*)";
            select "(.ldata|.ldata.*)";
        }
        "_LITERAL_DATA_" := sizeof(group:a1) > 0 ? addressof(group:a1) : addressof(group:a1) & 0xF0000000 + 32k;
        "__A1_MEM" = "_LITERAL_DATA_";
        
        /*Relative A9 Addressable Data, selectable with patterns and user defined sections*/
        group a9 (ordered, align = 4, run_addr=mem:cpu_dlmu)
        {
            select "(.data_a9.a9sdata|.data_a9.a9sdata.*)";
            select "(.bss_a9.a9sbss|.bss_a9.a9sbss.*)";
        }
        "_A9_DATA_" := sizeof(group:a9) > 0 ? addressof(group:a9) : addressof(group:a9) & 0xF0000000 + 32k;
        "__A9_MEM" = "_A9_DATA_";

        /*Relative A8 Addressable Const, selectable with patterns and user defined sections*/
#        if LCF_DEFAULT_HOST == LCF_CPU2
        group  a8 (ordered, align = 4, run_addr=mem:pfls1)
#        endif
#        if LCF_DEFAULT_HOST == LCF_CPU1
        group  a8 (ordered, align = 4, run_addr=mem:pfls1)
#        endif
#        if LCF_DEFAULT_HOST == LCF_CPU0
        group  a8 (ordered, align = 4, run_addr=mem:pfls0)
#        endif
        {
            select "(.rodata_a8.a8srodata|.rodata_a8.a8srodata.*)";
        }
        "_A8_DATA_" := sizeof(group:a8) > 0 ? addressof(group:a8) : addressof(group:a8) & 0xF0000000 + 32k;
        "__A8_MEM" = "_A8_DATA_";
    }
        
    /*Far Data / Far Const Sections, selectable with patterns and user defined sections*/
    section_layout :vtc:linear
    {
        /*Far Data Sections, selectable with patterns and user defined sections*/
        group
        {
            /*DSRAM sections*/
            group
            {
                group (ordered, attributes=rw, run_addr=mem:dsram2)
                {
                    select ".data.Ifx_Ssw_Tc2.*";
                    select ".data.Cpu2_Main.*";
                         select "(.data.data_cpu2|.data.data_cpu2.*)";
                  /* Initialized Data */
                   select "*InitData.Cpu2.8bit";
                   select "*InitData.Cpu2.16bit";
                   select "*InitData.Cpu2.32bit";
                   select "*InitData.Cpu2.256bit";
                   select "*InitData.Cpu2.Unspecified";
                   select "*InitData.Fast.Cpu2.8bit";
                   select "*InitData.Fast.Cpu2.16bit";
                   select "*InitData.Fast.Cpu2.32bit";
                   select "*InitData.Fast.Cpu2.256bit";
                   select "*InitData.Fast.Cpu2.Unspecified";
                    select ".bss.Ifx_Ssw_Tc2.*";
                    select ".bss.Cpu2_Main.*";
                    select "(.bss.bss_cpu2|.bss.bss_cpu2.*)";
               /* UnInitialized Data */
                   select "*ClearedData.Cpu2.8bit";
                   select "*ClearedData.Cpu2.16bit";
                   select "*ClearedData.Cpu2.32bit";
                   select "*ClearedData.Cpu2.256bit";
                   select "*ClearedData.Cpu2.Unspecified";
                   select "*ClearedData.Fast.Cpu2.8bit";
                   select "*ClearedData.Fast.Cpu2.16bit";
                   select "*ClearedData.Fast.Cpu2.32bit";
                   select "*ClearedData.Fast.Cpu2.256bit";
                   select "*ClearedData.Fast.Cpu2.Unspecified";
                }
                group (ordered, attributes=rw, run_addr=mem:dsram1)
                {
                    select ".data.Ifx_Ssw_Tc1.*";
                    select ".data.Cpu1_Main.*";
                    select "(.data.data_cpu1|.data.data_cpu1.*)";
                    
                   	select "(.data.DicTotalModelCDCASV3QR0104|.data.DicTotalModelCDCASV3QR0104.*)";
                    select "(.data.DicTotalModelCDCASV3QR0104_data|.data.DicTotalModelCDCASV3QR0104_data.*)";
                   	             
                  /* Initialized Data */
                    select "*InitData.Cpu1.8bit";
                    select "*InitData.Cpu1.16bit";
                    select "*InitData.Cpu1.32bit";
                    select "*InitData.Cpu1.256bit";
                    select "*InitData.Cpu1.Unspecified";
                    select "*InitData.Fast.Cpu1.8bit";
                    select "*InitData.Fast.Cpu1.16bit";
                    select "*InitData.Fast.Cpu1.32bit";
                    select "*InitData.Fast.Cpu1.256bit";
                   	select "*InitData.Fast.Cpu1.Unspecified";
                    select ".bss.Ifx_Ssw_Tc1.*";
                    select ".bss.Cpu1_Main.*";
                    select "(.bss.bss_cpu1|.bss.bss_cpu1.*)";
                    
					select "(.bss.DicTotalModelCDCASV3QR0104|.bss.DicTotalModelCDCASV3QR0104.*)";
                    select "(.bss.DicTotalModelCDCASV3QR0104_data|.bss.DicTotalModelCDCASV3QR0104_data.*)";
                 /* UnInitialized Data */
                    select "*ClearedData.Cpu1.8bit";
                    select "*ClearedData.Cpu1.16bit";
                    select "*ClearedData.Cpu1.32bit";
                    select "*ClearedData.Cpu1.256bit";
                    select "*ClearedData.Cpu1.Unspecified";
                    select "*ClearedData.Fast.Cpu1.8bit";
                    select "*ClearedData.Fast.Cpu1.16bit";
                    select "*ClearedData.Fast.Cpu1.32bit";
                    select "*ClearedData.Fast.Cpu1.256bit";
                    select "*ClearedData.Fast.Cpu1.Unspecified";
                }
                group (ordered, attributes=rw, run_addr=mem:dsram0)
                {
                    select ".data.Ifx_Ssw_Tc0.*";
                    select ".data.Cpu0_Main.*";
                    select "(.data.data_cpu0|.data.data_cpu0.*)";
                    
                    select "(..data.Rte_UDS|.data.Rte_UDS.*)";
                    select "(.bss.Rte_UDS|.bss.Rte_UDS.*)";
                    
                    select "(..data.AccelSensor|.data.AccelSensor.*)";
                    select "(.bss.AccelSensor|.bss.AccelSensor.*)";
                    
                    select "(..data.HeightSensor|.data.HeightSensor.*)";
                    select "(.bss.HeightSensor|.bss.HeightSensor.*)";
                    
                    select "(..data.L9301Driver|.data.L9301Driver.*)";
                    select "(.bss.L9301Driver|.bss.L9301Driver.*)";
                    
                    select "(..data.L9305Driver|.data.L9305Driver.*)";
                    select "(.bss.L9305Driver|.bss.L9305Driver.*)";
                    
                    select "(.data.PowerDriver|.data.PowerDriver.*)";
                    select "(.bss.PowerDriver|.bss.PowerDriver.*)";
                    
                    select "(..data.SysVol|.data.SysVol.*)";
                    select "(.bss.SysVol|.bss.SysVol.*)";
                    
                    select "(..data.TPSensor|.data.TPSensor.*)";
                    select "(.bss.TPSensor|.bss.TPSensor.*)";
                    
                    select "(..data.Tlf35584_Driver|.data.Tlf35584_Driver.*)";
                    select "(.bss.Tlf35584_Driver|.bss.Tlf35584_Driver.*)";

                     /* Initialized Data */
                    select "*InitData.Cpu0.8bit";
                    select "*InitData.Cpu0.16bit";
                    select "*InitData.Cpu0.32bit";
                    select "*InitData.Cpu0.256bit";
                    select "*InitData.Cpu0.Unspecified";
                    select "*InitData.Fast.Cpu0.8bit";
                    select "*InitData.Fast.Cpu0.16bit";
                    select "*InitData.Fast.Cpu0.32bit";
                    select "*InitData.Fast.Cpu0.256bit";
                    select "*InitData.Fast.Cpu0.Unspecified";
                    select ".bss.Ifx_Ssw_Tc0.*";
                    select ".bss.Cpu0_Main.*";
                    select "(.bss.bss_cpu0|.bss.bss_cpu0.*)";
                   /* UnInitialized Data */
                     select "*ClearedData.Cpu0.8bit";
                     select "*ClearedData.Cpu0.16bit";
                     select "*ClearedData.Cpu0.32bit";
                     select "*ClearedData.Cpu0.256bit";
                     select "*ClearedData.Cpu0.Unspecified";
                     select "*ClearedData.Fast.Cpu0.8bit";
                     select "*ClearedData.Fast.Cpu0.16bit";
                     select "*ClearedData.Fast.Cpu0.32bit";
                     select "*ClearedData.Fast.Cpu0.256bit";
                     select "*ClearedData.Fast.Cpu0.Unspecified";
                }
            }

            /*LMU Data sections*/
            group
            {
                group (ordered, attributes=rw, run_addr = mem:cpu_dlmu/not_cached)
                {
                    select "(.data.lmudata_cpu0|.data.lmudata_cpu0.*|.data.*.lmudata_cpu0)";
                    select "(.bss.lmubss_cpu0|.bss.lmubss_cpu0.*|.bss.*.lmubss_cpu0)";
                    select "(.data.lmudata|.data.lmudata.*)";
                    select "(.bss.lmubss|.bss.lmubss.*)";
                    
                    select "(*.bsslmuData)";

                    select "(.data.Rte_BodyAccBSW|.data.Rte_BodyAccBSW.*)";
                    select "(.bss.Rte_BodyAccBSW|.bss.Rte_BodyAccBSW.*)";

                    select "(.data.Rte_BodyHeight|.data.Rte_BodyHeight.*)";
                    select "(.bss.Rte_BodyHeight|.bss.Rte_BodyHeight.*)";

                    select "(.data.Rte_Cbk|.data.Rte_Cbk.*)";
                    select "(.bss.Rte_Cbk|.bss.Rte_Cbk.*)";

                    select "(.data.Rte_Data|.data.Rte_Data.*)";
                    select "(.bss.Rte_Data|.bss.Rte_Data.*)";

                    select "(.data.Rte_DicTotalModelCDCASV3QR0104|.data.Rte_DicTotalModelCDCASV3QR0104.*)";
                    select "(.bss.Rte_DicTotalModelCDCASV3QR0104|.bss.Rte_DicTotalModelCDCASV3QR0104.*)";

                    select "(.data.Rte_EnviroMonitor|.data.Rte_EnviroMonitor.*)";
                    select "(.bss.Rte_EnviroMonitor|.bss.Rte_EnviroMonitor.*)";

                    select "(.data.Rte_L9301Ctrl|.data.Rte_L9301Ctrl.*)";
                    select "(.bss.Rte_L9301Ctrl|.bss.Rte_L9301Ctrl.*)";

                    select "(.data.Rte_L9305Ctrl|.data.Rte_L9305Ctrl.*)";
                    select "(.bss.Rte_L9305Ctrl|.bss.Rte_L9305Ctrl.*)";

                    select "(.data.Rte_MemModeBSW|.data.Rte_MemModeBSW.*)";
                    select "(.bss.Rte_MemModeBSW|.bss.Rte_MemModeBSW.*)";

                    select "(.data.Rte|.data.Rte.*)";
                    select "(.bss.Rte|.bss.Rte.*)";
                }
                group (ordered, attributes=rw, run_addr = mem:cpu_dlmu/not_cached)
                {
                    select "(.data.lmudata_cpu1|.data.lmudata_cpu1.*|.data.*.lmudata_cpu1)";
                    select "(.bss.lmubss_cpu1|.bss.lmubss_cpu1.*|.bss.*.lmubss_cpu1)";
                }
                group (ordered, attributes=rw, run_addr = mem:cpu_dlmu/not_cached)
                {
                    select "(.data.lmudata_cpu2|.data.lmudata_cpu2.*|.data.*.lmudata_cpu2)";
                    select "(.bss.lmubss_cpu2|.bss.lmubss_cpu2.*|.bss.*.lmubss_cpu2)";
                }
          group (ordered, attributes=rw, run_addr = mem:cpu_dlmu/not_cached)
          {
            /* Initialized Data */
            select "*InitData.LmuNC.8bit";
            select "*InitData.LmuNC.16bit";
            select "*InitData.LmuNC.32bit";
            select "*InitData.LmuNC.256bit";
            select "*InitData.LmuNC.Unspecified";
            select "*InitData.Fast.LmuNC.8bit";
            select "*InitData.Fast.LmuNC.16bit";
            select "*InitData.Fast.LmuNC.32bit";
            select "*InitData.Fast.LmuNC.256bit";
            select "*InitData.Fast.LmuNC.Unspecified";      
            /* UnInitialized Data */
            select "*ClearedData.LmuNC.8bit";
            select "*ClearedData.LmuNC.16bit";
            select "*ClearedData.LmuNC.32bit";
            select "*ClearedData.LmuNC.256bit";
            select "*ClearedData.LmuNC.Unspecified";
            select "*ClearedData.Fast.LmuNC.8bit";
            select "*ClearedData.Fast.LmuNC.16bit";
            select "*ClearedData.Fast.LmuNC.32bit";
            select "*ClearedData.Fast.LmuNC.256bit";
            select "*ClearedData.Fast.LmuNC.Unspecified";     
          }
            }
        }
        
        /*Far Data Sections, selectable by toolchain*/
#        if LCF_DEFAULT_HOST == LCF_CPU2
        group (ordered, contiguous, align = 4, attributes=rw, run_addr = mem:dsram2)
#        endif
#        if LCF_DEFAULT_HOST == LCF_CPU1
        group (ordered, contiguous, align = 4, attributes=rw, run_addr = mem:dsram1)
#        endif
#        if LCF_DEFAULT_HOST == LCF_CPU0
        group (ordered, contiguous, align = 4, attributes=rw, run_addr = mem:dsram0)
#        endif
        {
            group data_mcal(attributes=rw)
            {
                select ".data.farDsprInit.cpu0.32bit";
                select ".data.farDsprInit.cpu0.16bit";
                select ".data.farDsprInit.cpu0.8bit";
            }
            
            group bss_mcal(attributes=rw)
            {
                select ".bss.farDsprClearOnInit.cpu0.32bit";
                select ".bss.farDsprClearOnInit.cpu0.16bit";
                select ".bss.farDsprClearOnInit.cpu0.8bit";
            }
            
            group bss_noInit(attributes=rw)
            {
                select ".bss.farDsprNoInit.cpu0.32bit";
                select ".bss.farDsprNoInit.cpu0.16bit";
                select ".bss.farDsprNoInit.cpu0.8bit";                
            }
            
//            group data(attributes=rw)
//            {
//                select "(.data|.data.*)";
//                select "(.bss|.bss.*)";
//            }
        }
        
        /*Heap allocation*/
#        if LCF_DEFAULT_HOST == LCF_CPU2
        group (ordered, align = 4, run_addr = mem:dsram2[LCF_HEAP2_OFFSET])
#        endif
#        if LCF_DEFAULT_HOST == LCF_CPU1
        group (ordered, align = 4, run_addr = mem:dsram1[LCF_HEAP1_OFFSET])
#        endif
#        if LCF_DEFAULT_HOST == LCF_CPU0
        group (ordered, align = 4, run_addr = mem:dsram0[LCF_HEAP0_OFFSET])
#        endif
        {
//            heap "heap" (size = LCF_HEAP_SIZE);
        }
        
        /*Far Const Sections, selectable with patterns and user defined sections*/
        group
        {
            group (ordered, align = 4, run_addr=mem:pfls0)
            {
                select ".rodata.Ifx_Ssw_Tc0.*";
                select ".rodata.Cpu0_Main.*";
          /* Const Data */        
          select "*Const.Cpu0.8bit";
          select "*Const.Cpu0.16bit";
          select "*Const.Cpu0.32bit";
          select "*Const.Cpu0.Unspecified";
          select "*Const.Cpu0.256bit";
          /* Config Data */      
          select "*Config.Cpu0.8bit";
          select "*Config.Cpu0.16bit";
          select "*Config.Cpu0.32bit";
          select "*Config.Cpu0.Unspecified";
          select "*Config.Cpu0.256bit";
                select "(.rodata.rodata_cpu0|.rodata.rodata_cpu0.*)";
            }
            group (ordered, align = 4, run_addr=mem:pfls0)
            {
                select ".rodata.Cpu1_Main.*";
                select ".rodata.Ifx_Ssw_Tc1.*";
          /* Const Data */        
          select "*Const.Cpu1.8bit";
          select "*Const.Cpu1.16bit";
          select "*Const.Cpu1.32bit";
          select "*Const.Cpu1.Unspecified";
          select "*Const.Cpu1.256bit";
          /* Config Data */      
          select "*Config.Cpu1.8bit";
          select "*Config.Cpu1.16bit";
          select "*Config.Cpu1.32bit";
          select "*Config.Cpu1.Unspecified";
          select "*Config.Cpu1.256bit";
                select "(.rodata.rodata_cpu1|.rodata.rodata_cpu1.*)";
            }
            group (ordered, align = 4, run_addr=mem:pfls0)
            {
                select ".rodata.Ifx_Ssw_Tc2.*";
                select ".rodata.Cpu2_Main.*";
          /* Const Data */        
          select "*Const.Cpu2.8bit";
          select "*Const.Cpu2.16bit";
          select "*Const.Cpu2.32bit";
          select "*Const.Cpu2.Unspecified";
          select "*Const.Cpu2.256bit";
          /* Config Data */      
          select "*Config.Cpu2.8bit";
          select "*Config.Cpu2.16bit";
          select "*Config.Cpu2.32bit";
          select "*Config.Cpu2.Unspecified";
          select "*Config.Cpu2.256bit";
                select "(.rodata.rodata_cpu2|.rodata.rodata_cpu2.*)";
            }
        }

        /*Far Const Sections, selectable by toolchain*/
#        if LCF_DEFAULT_HOST == LCF_CPU2
        group (ordered, align = 4, run_addr=mem:pfls1)
#        endif
#        if LCF_DEFAULT_HOST == LCF_CPU1
        group (ordered, align = 4, run_addr=mem:pfls1)
#        endif
#        if LCF_DEFAULT_HOST == LCF_CPU0
        group (ordered, align = 4, run_addr=mem:pfls0)
#        endif
        {
            select ".rodata.farConst.cpu0.32bit";
            select ".rodata.farConst.cpu0.16bit";
            select ".rodata.farConst.cpu0.8bit";
            select "(.rodata|.rodata.*)";
        }
    }

    section_layout :vtc:linear
    { 
#if 1 /*ltc E121: relocation error*/       
        group FLSLOADER_CODE (ordered, attributes=rwx, copy, run_addr=mem:psram0)
        {
           select ".text.FLSLOADERRAMCODE*";
        }
#endif 
        group FLASHDRV_CODE (ordered, align = 16, fill=0, attributes=rwx, run_addr=mem:psram0_flashDrv)
        {
           select ".text.FLASHDRVCODE*";
        }
    }
    
    /* PSRAM Code selections*/
    section_layout :vtc:linear
    {
        /*Code Sections, selectable with patterns and user defined sections*/
        group
        {
            /*Program Scratchpad Sections*/
            group
            {
                group code_psram0 (ordered, attributes=rwx, copy, run_addr=mem:psram0)
                {
                    select "(.text.cpu0_psram|.text.cpu0_psram.*)";
                    select "(.text.psram_text_cpu0|.text.psram_text_cpu0.*)";
                }
                group code_psram1 (ordered, attributes=rwx, copy, run_addr=mem:psram1)
                {
                    select "(.text.cpu1_psram|.text.cpu1_psram.*)";
                    select "(.text.psram_text_cpu1|.text.psram_text_cpu1.*)";
                }
                group code_psram2 (ordered, attributes=rwx, copy, run_addr=mem:psram2)
                {
                    select "(.text.cpu2_psram|.text.cpu2_psram.*)";
                    select "(.text.psram_text_cpu2|.text.psram_text_cpu2.*)";
                }
            }
        }
    }

    section_layout :vtc:linear
    {
        /*Code Sections, selectable with patterns and user defined sections*/
        group
        {    
            /*Cpu specific PFLASH Sections*/
            group
            {
                group (ordered, align = 4, run_addr=mem:pfls0)
                {
                    select ".text.Ifx_Ssw_Tc0.*";
                    select ".text.Cpu0_Main.*";
                    select ".text.CompilerTasking.Ifx_C_Init";
                    select "(.text.text_cpu0|.text.text_cpu0.*)";
                    select "*Code.Cpu0";
                    select "*Code.Fast.Cpu0";
                }
                group (ordered, align = 4, run_addr=mem:pfls0)
                {
                    select ".text.Ifx_Ssw_Tc1.*";
                    select ".text.Cpu1_Main.*";
                    select "(.text.text_cpu1|.text.text_cpu1.*)";
                    select "*Code.Cpu1";
                    select "*Code.Fast.Cpu1";
                }
                group (ordered, align = 4, run_addr=mem:pfls0)
                {
                    select ".text.Ifx_Ssw_Tc2.*";
                    select ".text.Cpu2_Main.*";
                    select "(.text.text_cpu2|.text.text_cpu2.*)";
                    select "*Code.Cpu2";
                    select "*Code.Fast.Cpu2";
                }
            }
        }
        
        /*Code Sections, selectable by toolchain*/
#        if LCF_DEFAULT_HOST == LCF_CPU2
        group (ordered, run_addr=mem:pfls1)
#        endif
#        if LCF_DEFAULT_HOST == LCF_CPU1
        group (ordered, run_addr=mem:pfls1)
#        endif
#        if LCF_DEFAULT_HOST == LCF_CPU0
        group (ordered, run_addr=mem:pfls0)
#        endif
        {
            select ".text.fast.pfls.cpu0";
            select ".text.slow.pfls.cpu0";
            select ".text.5ms.pfls.cpu0";
            select ".text.10ms.pfls.cpu0";
            select ".text.callout.pfls.cpu0";
            select "(.text|.text.*)";
        }
    }
    
    #include "TC377_OS_APP.lsl"
    
    section_layout :vtc:linear
    {
		
    	group bsw_global(attributes=rw, align = 4, run_addr=mem:cpu_dlmu/not_cached)
		{
			select "*.bsw_global";
		}
		
		group default_section(attributes=rw, align = 4, run_addr=mem:cpu_dlmu/not_cached)
		{
			select "*.default_section";
		}
		
		group bsw_clone(attributes=rw, align = 4, run_addr=mem:clone)
		{
			select "*.bsw_clone";
		}
		
		group bsw_clone_32(attributes=rw, align = 4, run_addr=mem:clone)
		{
			select "*.bsw_clone_32";
		}
		
		group bsw_clone_512(attributes=rw, align = 64, run_addr=mem:clone)
		{
			select "*.bsw_clone_512";
		}
	
		group cpu0_stack(align = 4, attributes=rw, run_addr=mem:dsram0)
        {
        	select "*.STACK_CORE0";
        }
        
        group cpu1_stack(align = 4, attributes=rw, run_addr=mem:dsram1)
        {
        	select "*.STACK_CORE1";
        }
        
        group cpu2_stack(align = 4, attributes=rw, run_addr=mem:dsram2)
        {
        	select "*.STACK_CORE2";
        }
        
    }
	
	section_layout :vtc:linear
    {

        group (attributes=rw, align = 4,run_addr=mem:dsram2_PFlashDriver)
        {
            select ".bss.PFlashDriver.*";
        }
    }

	section_layout :vtc:linear
    {
		group (attributes=rw, align = 4,run_addr=mem:dsram0)
        {
        	select ".data.*";
            select ".zdata.*";
        }
        
        group (attributes=rw, align = 4,run_addr=mem:dsram0)
        {
        	select ".bss.*";
            select ".zbss.*";
        }
        
        group (attributes=rw, align = 4,run_addr=mem:dsram0)
        {
        	select ".InitData.*";
            select ".ClearedData.*";
        }

    }
}

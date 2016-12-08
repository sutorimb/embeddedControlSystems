
/*
 *
 * FILE : MPC5643L_HWInit.c
 *
 * DESCRIPTION:
 *  This file contains all MPC5643L derivative needed initializations, 
 *  and all initializations for the MPC5643L boards which are supported.
 *  This includes setting up the External Bus Interface to allow access
 *  to memory on the external bus, and ensuring there is a valid entry in
 *  the MMU for the external memory access.
 */

/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/

#include "mpc5643l.h"       /* MPC55xx platform development header            */
#include "MPC5643L_HWInit.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************/
/* MPC5643L derivative specific hardware initialization */
/*******************************************************/

/*----------------------------------------------------------------------------*/
/* Function declarations                                                      */
/*----------------------------------------------------------------------------*/

/* All these functions must be located in the initial 4KB memory window (.init) 
	and implemented "nofralloc" so as to not use the stack */

/* Memory initialization */
__declspec(section ".init") __asm void INIT_Derivative(void);

/* Write one MMU Table Entry */
__declspec(section ".init") __asm void WriteMMUTableEntry( void );

/* Initialize the needed MMU Table entries */
__declspec(section ".init") __asm void __initMMU(void);


/* This macro allows to use C defined address with the inline assembler */
#define MAKE_HLI_COMPATIBLE(hli_name, c_expr) enum { hli_name=/*lint -e30*/((int)(c_expr)) };


/*----------------------------------------------------------------------------*/
/* Function implementations                                                   */
/*----------------------------------------------------------------------------*/

/* Symbol L2SRAM_LOCATION is defined in the application linker command file (.lcf) 
   It is defined to the start of the L2SRAM of the MPC5643L. 
*/
/*lint -esym(752, L2SRAM_LOCATION) */
extern long L2SRAM_LOCATION; 
#ifndef LOCKSTEP_MODE 
extern long L2SRAM_LOCATION_P1;
#endif

__asm void INIT_Derivative(void) 
{
nofralloc
#ifdef LOCKSTEP_MODE // e200 register init needed for LSM mode
	/* until now, the code has used(set) the following registers LR, R1, R2, R13, R3, R31, R30
	 and they should not altered */
	xor  r0, r0, r0
	evmergelo r0,r0,r0

	evmergelo r1,r0,r1 //used by runtime - should preserve lower 32bits
	evmergelo r2,r0,r2 //used by runtime - should preserve lower 32bits
	evmergelo r3,r0,r3 //used by runtime - should preserve lower 32bits
	
	evmergelo r4,r0,r0
	evmergelo r5,r0,r0
	evmergelo r6,r0,r0
	evmergelo r7,r0,r0
	evmergelo r8,r0,r0
	evmergelo r9,r0,r0
	evmergelo r10,r0,r0
	evmergelo r11,r0,r0
	evmergelo r12,r0,r0
	
	evmergelo r13,r0,r13 //used by runtime - should preserve lower 32bits

	evmergelo r14,r0,r0
	evmergelo r15,r0,r0
	evmergelo r16,r0,r0
	evmergelo r17,r0,r0
	evmergelo r18,r0,r0
	evmergelo r19,r0,r0
	evmergelo r20,r0,r0
	evmergelo r21,r0,r0
	evmergelo r22,r0,r0
	evmergelo r23,r0,r0
	evmergelo r24,r0,r0
	evmergelo r25,r0,r0
	evmergelo r26,r0,r0
	evmergelo r27,r0,r0
	evmergelo r28,r0,r0
	evmergelo r29,r0,r0
	
	evmergelo r30,r0,r30 //used by runtime - should preserve lower 32bits
	evmergelo r31,r0,r31 //used by runtime - should preserve lower 32bits

	// 2.  32-bit DEAR (spr 61)
	mtspr 61,r0         //DEAR

	//3.  32-bit SPRG0-9 (spr 272-279, 604 & 605)

	mtspr 272,r0        //SPRG0-7
	mtspr 273,r0
	mtspr 274,r0
	mtspr 275,r0
	mtspr 276,r0
	mtspr 277,r0
	mtspr 278,r0
	mtspr 279,r0

	mtspr 604,r0         //SPRG8-9
	mtspr 605,r0

	//4.  32-bit USPRG0 (spr 256)

	mtspr 256,r0         //USPRG0

	//5.  32-bit SRR0 (spr 26), SRR1 (spr 27), CSRR0 (spr58), CSRR1 (spr59),
	//		DSRR0 (spr 574), DSRR1 (spr 575), MCSRR0 (spr570), MCSRR1 (spr571)

	mtspr 26,r0          //SRR0-1
	mtspr 27,r0
	mtspr 58,r0          //CSRR0-1
	mtspr 59,r0
	mtspr 570,r0         //MCSRR0-1
	mtspr 571,r0 
	mtspr 574,r0         //DSRR0-1 
	mtspr 575,r0      
    
	//6.  32-bit IVPR (spr 63)

	mtspr 63,r0          //IVPR
	mtspr 62,r0          //ESR
	mtspr 340,r0         //TCR
	mtspr 512,r0         //SPEFSCR
	mtspr 1,r0           //XER
	mtspr 256,r0         //USPRG0 
 

	//32-bit IVOR0-15 (spr 400 - 415), IVOR 32-35 (spr 528 - 531)

	mtspr 400,r0         //IVOR0-15
	mtspr 401,r0
	mtspr 402,r0
	mtspr 403,r0   
	mtspr 404,r0
	mtspr 405,r0
	mtspr 406,r0
	mtspr 407,r0
	mtspr 408,r0
	mtspr 409,r0
	mtspr 410,r0
	mtspr 411,r0
	mtspr 412,r0
	mtspr 413,r0
	mtspr 414,r0
	mtspr 415,r0

	mtspr 528,r0         //IVOR32-34 (IVOR35 not in Leopard)
	mtspr 529,r0
	mtspr 530,r0
	
	//mtspr 531,r0		 //IVOR35 KOMODO ONLY

	//8.  32-bit MCAR (spr 573)

	mtspr 573,r0         //MCAR
 
	//9. 32-bit TBL, TBU (spr 284, 285)

	mtspr 284,r0         //TBL
	mtspr 285,r0         //TBU
 
	//10. 32-bit DEC, DECAR (spr 22, 54)

	mtspr 22,r0          //DEC
	mtspr 54,r0          //DECAR

	//11. 64-bit DVC1, DVC2 (spr 318, 319)
	//Note most debug registers are reset by POR so initialization is not required.

	mtspr 318,r0         //DVC1
	mtspr 319,r0         //DVC2

	//12. 32-bit DBCNT (spr 562)

	mtspr 562,r0         //DBCNT
	
	// initialize MAS0 - MAS6; actual TLB configuration done later
	mtmas0 r0
	mtmas1 r0
	mtmas2 r0
	mtmas3 r0
	mtmas4 r0
	// no MAS5
	mtmas6 r0
	
	// init ACC
	evmra r0, r4
	evmra r0, r4
	
	mtcrf 0xFF,r0 // CFR
	mtspr 9,r0 // COUNT
#endif // e200 register init not needed for DPM mode

	/* Don't have a stack yet, save the return address in a register */
	mflr     r26;
	bl __initMMU;
	mtlr r26;

    
    lis r11,L2SRAM_LOCATION@h /* Base address of the L2SRAM, 64-bit word aligned */
    ori r11,r11,L2SRAM_LOCATION@l
	
#ifdef LOCKSTEP_MODE
    li r12,1024 /* Loop cover low SRAM, LSM mode; 128k/4 bytes/32 GPRs = 1024 */
#else
	li r12,512  /* Loop cover low SRAM, DPM mode; 64k/4 bytes/32 GPRs = 512 */
#endif
    mtctr r12

    init_l2sram_loop:
        stmw r0,0(r11)        /* Write all 32 GPRs to L2SRAM */
        addi r11,r11,128      /* Inc the ram ptr; 32 GPRs * 4 bytes = 128 */
        bdnz init_l2sram_loop /* Loop for 64k of L2SRAM */
        
#ifndef LOCKSTEP_MODE // If DPM, then do high SRAM too.
    lis r11,L2SRAM_LOCATION_P1@h /* Base address of the L2SRAM, 64-bit word aligned */
    ori r11,r11,L2SRAM_LOCATION_P1@l

	li r12,512  /* Loop cover low SRAM, DPM mode; 64k/4 bytes/32 GPRs = 512 */
    mtctr r12

    init_l2sram_loop2:
        stmw r0,0(r11)        /* Write all 32 GPRs to L2SRAM */
        addi r11,r11,128      /* Inc the ram ptr; 32 GPRs * 4 bytes = 128 */
        bdnz init_l2sram_loop2 /* Loop for 64k of L2SRAM */
        
#endif       

    blr
}


/*----------------------------------------------------------------------------*/
/* Writing to MMU Table Entries                                               */
/*----------------------------------------------------------------------------*/

/* Initialize the needed MMU Table entries */

/* Set up MMU for internal memory just like the debugger: a single window, 4GB wide
   Base address = 0x0000_0000
   4 GByte Memory Space, Not Guarded, Cachable, All Access
*/

__asm void __initMMU(void)
{
nofralloc

    //# MMU Entry First 1MB FLASH    //# MAS0 : ESEL=1
    //# MAS1 : TSIZ=1MB
    //# MAS2 : EPN=0x000000000, W=0, I=0, M=0, G=0, E=big 
    //# MAS3 : RPN=0x000000000, PERMIS=all
    
 	lis     r3, 0x1000
    mtMAS0  r3

    lis     r4, 0xC000
    ori     r4, r4, 0x0500
    mtMAS1  r4

#if __option(vle) 
    lis     r5, 0x0000
    ori     r5, r5, 0x0020
#else
    lis     r5, 0x0000
    ori     r5, r5, 0x0000
#endif
    mtMAS2  r5

    lis     r6, 0x0000
    ori     r6, r6, 0x003f
    mtMAS3  r6

    msync
    tlbwe
    isync

	// MMU Entry Shadow Flash
	// MAS0 : ESEL=1
	// MAS1 : TSIZE=1MB
	// MAS2 : EPN=0x00F00000, I=1, guarded
	// MAS3 : RPN=0x00F00000, readonly
	lis     r3, 0x1001
    mtMAS0  r3
 
    lis     r4, 0xC000
    ori     r4, r4, 0x0500
    mtMAS1  r4
 
    lis     r5, 0x00F0
    ori     r5, r5, 0x000A   
    mtMAS2  r5
 
    lis     r6, 0x00F0
    ori     r6, r6, 0x002F
    mtMAS3  r6
 
	tlbwe

#ifdef LOCKSTEP_MODE // Init MMU for LSM

    //# MMU Entry First 128K SRAM in LSM - No Translation
    //# MAS0 : ESEL=2
    //# MAS1 : TSIZ=128Kbytes
    //# MAS2 : EPN=0x400000000, W=0, I=1, M=0, G=0, E=big 
    //# MAS3 : RPN=0x400000000, PERMIS=all 

    lis     r3, 0x1002
    mtMAS0  r3

    lis     r4, 0xC000
    ori     r4, r4, 0x0380
    mtMAS1  r4

#if __option(vle)
    lis     r5, 0x4000
    ori     r5, r5, 0x0028
#else
    lis     r5, 0x4000
    ori     r5, r5, 0x0008
#endif
    mtMAS2  r5

    lis     r6, 0x4000
    ori     r6, r6, 0x003f
    mtMAS3  r6

    tlbwe
#else                 // Init MMU for DPM

    //# MMU Entry First 64K SRAM in DPM - No Translation
    //# MAS0 : ESEL=2
    //# MAS1 : TSIZ=64Kbytes
    //# MAS2 : EPN=0x400000000, W=0, I=1, M=0, G=0, E=big 
    //# MAS3 : RPN=0x400000000, PERMIS=all 

    lis     r3, 0x1002
    mtMAS0  r3

    lis     r4, 0xC000
    ori     r4, r4, 0x0300
    mtMAS1  r4
#if __option(vle)
    lis     r5, 0x4000
    ori     r5, r5, 0x0028
#else
	lis     r5, 0x4000
    ori     r5, r5, 0x0008
#endif
    mtMAS2  r5

    lis     r6, 0x4000
    ori     r6, r6, 0x003f
    mtMAS3  r6

    tlbwe

    //# MMU Entry Second 64K SRAM in DPM Mode
    //# MAS0 : ESEL=3
    //# MAS1 : TSIZ=64Kbytes
    //# MAS2 : EPN=0x50000000, W=0, I=0, M=0, G=0, E=big 
    //# MAS3 : RPN=0x50000000, PERMIS=all 

    lis     r3, 0x1003
    mtMAS0  r3

    lis     r4, 0xC000
    ori     r4, r4, 0x0300
    mtMAS1  r4
#if __option(vle)
    lis     r5, 0x5000
    ori     r5, r5, 0x0028
#else
	lis     r5, 0x5000
    ori     r5, r5, 0x0008
#endif
    mtMAS2  r5

    lis     r6, 0x5000
    ori     r6, r6, 0x003f
    mtMAS3  r6

    tlbwe

    //# Peripheral Space in DPM mode things start at 0x8ff0_0000
    //# will start at 0x8ff0_0000 and extend 1M
    //# MAS0 : ESEL=4
    //# MAS1 : TSIZ=1MB
    //# MAS2 : EPN=0x8ff00000, W=0, I=1, M=0, G=1, E=big 
    //# MAS3 : RPN=0x8ff00000, PERMIS=all 

    lis     r3, 0x1004
    mtMAS0  r3

    lis     r4, 0xC000
    ori     r4, r4, 0x0500
    mtMAS1  r4

    lis     r5, 0x8ff0
    ori     r5, r5, 0x000A
    mtMAS2  r5

    lis     r6,0x8ff0
    ori     r6, r6, 0x003f
    mtMAS3  r6

    tlbwe

#endif

	//# common to both LSM and DPM
    //# MMU Entry Peripheral A 
    //# MAS0 : ESEL=5
    //# MAS1 : TSIZ=1Mbytes
    //# MAS2 : EPN=0xC3F00000, W=0, I=1, M=0, G=1, E=big 
    //# MAS3 : RPN=0xC3F00000, PERMIS=all 

    lis     r3, 0x1005
    mtMAS0  r3

    lis     r4, 0xC000
    ori     r4, r4, 0x0500
    mtMAS1  r4

    lis     r5, 0xC3F0
    ori     r5, r5, 0x000A   
    mtMAS2  r5

    lis     r6, 0xC3F0
    ori     r6, r6, 0x003F
    mtMAS3  r6

    tlbwe

    //# MMU Entry Peripheral B 
    //# MAS0 : ESEL=6
    //# MAS1 : TSIZ=1Mbytes
    //# MAS2 : EPN=0xFFE00000, W=0, I=1, M=0, G=0, E=big 
    //# MAS3 : RPN=0xFFE00000, PERMIS=all 

    lis     r3, 0x1006
    mtMAS0  r3
 
    lis     r4, 0xC000
    ori     r4, r4, 0x0500
    mtMAS1  r4
 
    lis     r5, 0xFFE0
    ori     r5, r5, 0x0008   
    mtMAS2  r5
 
    lis     r6, 0xFFE0
    ori     r6, r6, 0x003F
    mtMAS3  r6
 
    tlbwe

	//# MMU On-Platform 0 Peripherals 
    //# MAS0 : ESEL=7
    //# MAS1 : TSIZ=512 Kbytes
    //# MAS2 : EPN=0xFFF00000, W=0, I=1, M=0, G=0, E=big 
    //# MAS3 : RPN=0xFFF00000, PERMIS=all 

    lis     r3, 0x1007
    mtMAS0  r3
 
    lis     r4, 0xC000
    ori     r4, r4, 0x0480
    mtMAS1  r4
 
    lis     r5, 0xFFF0
    ori     r5, r5, 0x0008   
    mtMAS2  r5
 
    lis     r6, 0xFFF0
    ori     r6, r6, 0x003F
    mtMAS3  r6
 
    tlbwe

	//# MMU  Off-Platform Peripherals 2
    //# MAS0 : ESEL=8
    //# MAS1 : TSIZ=64 Kbytes
    //# MAS2 : EPN=0xFFF90000, W=0, I=1, M=0, G=0, E=big 
    //# MAS3 : RPN=0xFFF90000, PERMIS=all 

    lis     r3, 0x1008
    mtMAS0  r3
 
    lis     r4, 0xC000
    ori     r4, r4, 0x0300
    mtMAS1  r4
 
    lis     r5, 0xFFF9
    ori     r5, r5, 0x0008   
    mtMAS2  r5
 
    lis     r6, 0xFFF9
    ori     r6, r6, 0x003F
    mtMAS3  r6
 
    tlbwe

	//# MMU  Off-Platform Peripherals 2
    //# MAS0 : ESEL=8
    //# MAS1 : TSIZ=256 Kbytes
    //# MAS2 : EPN=0xFFFC0000, W=0, I=1, M=0, G=0, E=big 
    //# MAS3 : RPN=0xFFFC0000, PERMIS=all 

    lis     r3, 0x1009
    mtMAS0  r3
 
    lis     r4, 0xC000
    ori     r4, r4, 0x0400
    mtMAS1  r4
 
    lis     r5, 0xFFFC
    ori     r5, r5, 0x0008   
    mtMAS2  r5
 
    lis     r6, 0xFFFC
    ori     r6, r6, 0x003F
    mtMAS3  r6
 
    tlbwe


    blr
}

#ifdef __cplusplus
}
#endif

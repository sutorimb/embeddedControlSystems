/*
   eecs461.h
   University of Michigan
   EECS 461, Embedded Control Systems
 */

#include "MPC5643L.h"

/* Init EECS461 Parameters */
#define FCCU_CFK_Key  0x618B7A50 // Critical fault key
#define FCCU_NCFK_Key 0xAB3498FE // Non-Critical fault key

#define IDF_DIV  9               // Input Division Factor: 10
#define ODF_DIV  0               // Output Division Factor: 2
#define NDIV_DIV 60              // Loop Division Factor:  60

#define FRAY_DIV 1    // FlexRay Clock Prescalar
#define FCAN_DIV 1    // FlexCAN Clock Prescalar

#define PLL_IDF_0     (unsigned long)(((unsigned long)IDF_0) << 26)
#define PLL_ODF_0     (unsigned long)(((unsigned long)ODF_0) << 24)
#define PLL_NDIV_0    (unsigned long)(((unsigned long)NDIV_0) << 16)
#define PLL_VALUE_0   PLL_IDF_0 | PLL_ODF_0 | PLL_NDIV_0

#define PLL_IDF_1     (unsigned long)(((unsigned long)IDF_1) << 26)
#define PLL_ODF_1     (unsigned long)(((unsigned long)ODF_1) << 24)
#define PLL_NDIV_1    (unsigned long)(((unsigned long)NDIV_1) << 16)
#define PLL_VALUE_1   PLL_IDF_1 | PLL_ODF_1 | PLL_NDIV_1

#define IDF_0         10 - 1   /* Input Division Factor: 10   */
#define ODF_0         0        /* Output Division Factor: 2   */
#define NDIV_0        60       /* Loop Division Factor: 60    */

/* XTAL_40MHz / 10 / 2 * 60 = 120MHz  */
#define IDF_1         10 - 1   /* Input Division Factor: 10   */
#define ODF_1         0        /* Output Division Factor: 2   */
#define NDIV_1        60       /* Loop Division Factor: 60    */

/* XTAL_40MHz / 10 / 2 * 60 = 120MHz  */
#define MC_DIV        11       /* Motor Control Clock Divider Value: 12,
                                  Frequency 10 MHz */
#define SW_DIV        5

void initEECS461(void);

int getSysFreq(void);

void preInit(void);
void initModeEntry(void);
void initSysClk(void);
void initCMU(void);
void modeEntryPostConfig(void);

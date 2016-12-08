/*
   adc.c
   University of Michigan
   EECS 461, Embedded Control Systems
   Analog to Digital Converter module
   Read Chapter 8 in MPC5643 User's Manual
 */

#include "adc.h"

#define ONE_SHOT  0 //Fill in value associated with one-shot mode
#define SCAN_MODE 1 //Fill in value associated with scan mode

/******************************************************************************
 * Function:    initSIUADC0
 * Description: Configure Pads for each Channel (ADC0)
 ******************************************************************************/
/* 1. */
void initSIUADC0(char numChannels, char channelArray[])
{
  /* Note channels 8-15 are not valid sampling channels */
  int ADC0_PCR[16] = {23,24,33,34,70,66,71,68,0,0,0,0,0,0,0,0};
  int PCR_IDX, i;

  for(i=0; i<numChannels; i++)
  {
    PCR_IDX = ADC0_PCR[channelArray[i]];
    SIU.PCR[PCR_IDX].R = 0b0010000000000000;            
  }
}

/******************************************************************************
 * Function:    initADC0_oneshot
 * Description: Initializes ADC 0 for one-shot mode
 ******************************************************************************/
/* 2. */
void initADC0_oneshot(char numChannels, char channelArray[])
{
  int i;
  
  /* Main Configuration Register */
  ADC0.MCR.B.OWREN = 1;    // Enable converted data to be overwritten by a
                             // new conversion
  ADC0.MCR.B.WLSIDE = 0;   // Right-aligned
  ADC0.MCR.B.MODE = ONE_SHOT;     // One-shot Mode
  ADC0.MCR.B.ADCLKSEL = 1; // AD_clk frequency is equal to system clock
                             // frequency
  ADC0.MCR.B.PWDN = 0;     // ADC is in normal mode (Not power down)       
  ADC0.MCR.B.ACKO = 1;     // Auto clock off is enabled
        
  /* Conversion Timing Register */
  ADC0.CTR0.B.INPLATCH = 0;
  ADC0.CTR0.B.OFFSHIFT = 0;
  ADC0.CTR0.B.INPCMP = 0b01;
  ADC0.CTR0.B.INSAMP = 8;

  /* Normal Conversion Mask Register */
  for(i=0; i<numChannels; i++)
  {
    ADC_0.NCMR0.R |= 0b1 << channelArray[i];
  }       
  
  /* Configure Pads for each Channel */
  initSIUADC0(numChannels, channelArray);         
  
  
}

/******************************************************************************
 * Function:    initADC0_scan
 * Description: Initializes ADC 0 for continuous scan
 ******************************************************************************/
/* 3. */
void initADC0_scan(char numChannels, char channelArray[])
{
  int i;
  
  /* Main Configuration Register */
  ADC0.MCR.B.OWREN = 1;    // Enable converted data to be overwritten by a
                             // new conversion
  ADC0.MCR.B.WLSIDE = 0;   // Right-aligned
  ADC0.MCR.B.MODE = SCAN_MODE;     // Scan Mode
  ADC0.MCR.B.ADCLKSEL = 1; // AD_clk frequency is equal to system clock
                             // frequency
  ADC0.MCR.B.PWDN = 0;     // ADC is in normal mode (Not power down)       
  ADC0.MCR.B.ACKO = 1;     // Auto clock off is enabled
        
  /* Conversion Timing Register */
  ADC0.CTR0.B.INPLATCH = 0;
  ADC0.CTR0.B.OFFSHIFT = 0;
  ADC0.CTR0.B.INPCMP = 0b01;
  ADC0.CTR0.B.INSAMP = 8;

  /* Normal Conversion Mask Register */
  for(i=0; i<numChannels; i++)
  {
    ADC_0.NCMR0.R |= 0b1 << channelArray[i];
  }       
  
  /* Configure Pads for each Channel */
  initSIUADC0(numChannels, channelArray);         
  
  ADC0.MCR.B.NSTART = 1;   // Start Conversions
}

/******************************************************************************
 * Function:    readADC0_oneshot
 * Description:         Read conversion
 ******************************************************************************/
/* 4. */
vuint16_t readADC0_oneshot(int channel)
{
  // Start conversion.
  ADC0.MCR.B.NSTART = 1;
  /* Wait until conversion completes */
  while(ADC0.CDR[channel].B.VALID == 0)
  {
    /* Do Nothing */
  }
  
  /* Return conversion */
  return ADC0.CDR[channel].B.CDATA;
}

/******************************************************************************
 * Function:    readADC0_scan
 * Description:         Read conversion
 ******************************************************************************/
/* 5. */
vuint16_t readADC0_scan(int channel)
{
  /* Return conversion */
  return ADC0.CDR[channel].B.CDATA;
}

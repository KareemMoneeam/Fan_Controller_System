 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega32 ADC driver
 *
 * Author: Kareem Abd El-Moneam
 *
 *******************************************************************************/

#include "avr/io.h" /* To use the ADC Registers */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType *Config_Ptr)
{
	/* ADMUX Register Bits Description:
	 * REFS1:0 = 11 to choose to connect internal 2.56V reference voltage
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr->ref_volt) << 6);

	ADCSRA = (ADCSRA & 0xF8) | ((Config_Ptr->prescaler) & 0x07) | (1 << ADEN);
	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt as initialization
	 * ADATE   = 0 Disable Auto Trigger as initialization
	 * ADPS2:0 = ??? to choose ADC_Clock ( Configurable )
	 */
}
/*
 * Description :
 * Function to set the ADC pre-scaler
 * */
void ADC_setPrescaler(const ADC_Prescaler divisionFactor)
{
	ADCSRA = (ADCSRA & 0xF8) | (divisionFactor & 0x07);
}
/*
 * Description :
 * Function to set the ADC Reference Volt
 * */
void ADC_setReferenceVolt(const ADC_ReferenceVolatge ref)
{
	ADMUX = (ADMUX & 0x3F) | (ref << 6);
}
uint16 ADC_readChannel(uint8 channel_num)
{
	ADMUX = (ADMUX & 0xE0) | (0x07 & channel_num); /* channel number must be from 0 to 7 */
	SET_BIT(ADCSRA,ADSC);						   /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); 			   /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF);						   /* Clear ADIF by write '1' to it :) */
	return ADC; 								   /* Read the digital value from the data register */
}
/*
 * Description :
 * Function to disable ADC and reset its registers
 */
void ADC_deInit(void)
{
	ADMUX = 0;
	ADCSRA = 0;
}
/*
 * Description :
 * Function to enable ADC interrupt
 */
void ADC_interruptsEnable(void)
{
	ADCSRA = (ADCSRA & 0xF7) | (1<<ADIE);
}

/*
 * Description :
 * Function to enable ADC Auto Trigger
 */
void ADC_autoTriggerEnable(void)
{
	ADCSRA = (ADCSRA & 0xDF) | (1<<ADATE);
}



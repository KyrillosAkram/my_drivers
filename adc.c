/*
 * TODO documenting adc.c
 *
 *  Created on: Oct 16, 2021
 *      Author: Kyrillos
 */


#include "adc.h"

#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
volatile uint16 g_adcLastRead=0;

ISR(ADC_vect){
//	_delay_ms(1);
//	g_adcLastRead=ADC;
//	PORTA=ADCL&(~(1<<2));
	/*to avoid ADC regester lock*/
	/*problem discription :
	 * ADC result register is 16 bit double buffered register. When you read the ADCL (low byte), the 16bit register update is locked until you read the ADCH (high byte).
	If you read ADCH first and then ADCL, the register will stay locked, preventing any new conversion to be written in the result register.
(And do not use variable names like "ADC", that may already be reserved).
*/
	g_adcLastRead=ADCL;
	g_adcLastRead+=(ADCH<<8);

}

void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	/* ADMUX Register Bits Description:
	 * REFS1:0 = 00 to choose to connect external reference voltage by input this voltage through AREF pin
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	ADMUX = (Config_Ptr->ref_volt)<<REFS0;

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 1 Enable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 = 011 to choose ADC_Clock=F_CPU/8=1Mhz/8=125Khz --> ADC must operate in range 50-200Khz
	 */
	ADCSRA =
			(1<<ADEN)|
#if ADC_INTERRUPT
			(1<<ADIE)|
#endif
			((Config_Ptr->prescaler)<<ADPS0);
}

void ADC_startConversion(ADC_ChannelType a_channel_num){
	//ADMUX = (ADMUX&(~((1<<((MUX4)+1))-1)))|a_channel_num;
	REGESTER_INSERT_SUCCESSIVE_BITS(ADMUX,MUX0,5,a_channel_num);
	ADCSRA|=(1<<ADSC);		/*start reading proccess or conversion*/

}

void ADC_readChannel(ADC_ChannelType a_channel_num){

	/*
	 *
	REGESTER_INSERT_SUCCESSIVE_BITS(ADMUX,MUX0,5,a_channel_num);
	ADCSRA|=(1<<ADSC);		start reading proccess or conversion
	TODO ADC_WAIT_CONVERSION()	waits until the conversion to be finished


#if !ADC_INTERRUPT
	ADCSRA|=(1<<ADIF);
	g_adcLastRead=ADC;
#endif
*/

	a_channel_num &= 0x07; /* Input channel number must be from 0 --> 7 */
	ADMUX &= 0xE0; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | a_channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	ADMUX |= 	(1<<REFS0)|(1<<REFS1);
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */

}


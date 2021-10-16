/*
 * TODO documenting adc.c
 *
 *  Created on: Oct 16, 2021
 *      Author: Kyrillos
 */


#include "adc.h"

volatile g_adcLastRead=0;

ISR(ADC_vect){
	g_adcLastRead=ADC;
}

void ADC_init(){
	ADCSRA|=
			(ADC_DEFAULT_PRESCALER)|
#if ADC_INTERRUPT
			(1<<ADIE)|
#endif
			(1<<ADEN);
}

void ADC_startConversion(ADC_ChannelType a_channel_num){
	ADMUX = (ADMUX&(~((1<<((MUX4)+1))-1)))|a_channel_num;
	ADCSRA|=(1<<ADSC);		/*start reading proccess or conversion*/

}

void ADC_readChannel(ADC_ChannelType a_channel_num){
	ADMUX = (ADMUX&(~((1<<((MUX4)+1))-1)))|a_channel_num;
	ADCSRA|=(1<<ADSC);		/*start reading proccess or conversion*/
	while((ADCSRA>>ADSC));	/*waits until the conversion to be finished*/
	g_adcLastRead=ADC;
}


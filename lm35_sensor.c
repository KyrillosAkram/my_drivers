/*
 * lm35_sensor.c
 *
 *  Created on: Oct 16, 2021
 *      Author: Kyrillos
 */


#include "lm35_sensor.h"
#include "avr/io.h"
#include <util/delay.h>
#include "adc.h"
#include "common_macros.h"
#include "std_types.h"

const ADC_ConfigType g_LM35_ADC_Config={
		ADC_REF_INTERNAL_2_56V,
		ADC_FACTOR_8
};

void LM35_init(void){
	GPIO_setupPinDirection(LM35_PORT_ID,LM35_CHANNEL_ID,PIN_INPUT);
	ADC_init(&g_LM35_ADC_Config);
}
uint8 LM35_getTemperature(void){
	ADC_startConversion(LM35_CHANNEL_ID);
	//TODO ADC_WAIT_CONVERSION();
	_delay_ms(5);
	//temp=
	return (uint8)(((uint32)(256)*g_adcLastRead) /(ADC_MAX_VALUE));;
}

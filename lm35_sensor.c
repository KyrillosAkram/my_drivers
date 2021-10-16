/*
 * lm35_sensor.c
 *
 *  Created on: Oct 16, 2021
 *      Author: Kyrillos
 */


#include "lm35_sensor.h"

uint8 LM35_getTemperature(void){
	ADC_startConversion(LM35_CHANNEL_ID);
	ADC_WAIT_CONVERSION();
	return ((uint8)	(((uint32)10*(ADC_REF_VALUE_X10)*g_adcLastRead))/((uint32)ADC_MAX_VALUE));
}

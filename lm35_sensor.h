/*
 * lm35_sensor.h
 *
 *  Created on: Oct 16, 2021
 *      Author: Kyrillos
 */

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "adc.h"
#include "std_types.h"

#define LM35_PORT_ID			  PORTA_ID
#define LM35_CHANNEL_ID 2
#define LM35_MAX_TEMP (150)
#define LM35_MAX_M_VOLT_VALUE (1500)

extern const ADC_ConfigType g_LM35_ADC_Config;

void LM35_init(void);

uint8 LM35_getTemperature(void);
#endif /* LM35_SENSOR_H_ */

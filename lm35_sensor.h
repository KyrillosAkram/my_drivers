/*
 * lm35_sensor.h
 *
 *  Created on: Oct 16, 2021
 *      Author: Kyrillos
 */

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "adc.h"

#define LM35_CHANNEL_ID 0
#define LM35_MAX_TEMP (150)
#define LM35_MAX_M_VOLT_VALUE (1500)



uint8 LM35_getTemperature(void);
#endif /* LM35_SENSOR_H_ */

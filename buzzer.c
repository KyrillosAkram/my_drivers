/*
 * buzzer.c
 *
 *  Created on: Nov 5, 2021
 *      Author: Kyrillos
 */

#include "buzzer.h"


PWM_ConfigType es_buzzerConfig={
		{/*generate 500Hz */
				0,
				124,
				TIMER_MODE_CTC,
				BUZZER_TIMER_ID,
				BUZZER_TIMEOUT_CALLBACK,
				TIMER0_PRESCALER_CLK_64

		},
		PWM_NORMAL,
		BUZZER_PWM_ID
};

void BUZZER_init(PWM_ConfigType* buzzerConfig_ptr){
	PWM_init(&buzzerConfig_ptr);
	PWM_disconnect(buzzerConfig_ptr->a_pwmID);
}

void (*BUZZER_deinit)(PWM_IDType a_pwmID)=PWM_deinit;



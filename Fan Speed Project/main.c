/*
 * main.c
 *
 *  Created on: Oct 10, 2021
 *      Author: M.Eltokhy
 */
#include "MCAL/DIO/dio.h"
#include "MCAL/Timer/timer.h"
#include "MCAL/ADC/ADC.h"
#include "HAL/LCD/lcd.h"
#include "HAL/DC_Motor/DC_Motor.h"


int main(){
	dio_init();
	lcd_init();
	timer0_init();
	adc_init();
	uint16 temp=adc_read(ADC0);
	lcd_start_program(temp);
	while(1){
		dc_motor_speed(temp, cw);
		lcd_display_data(temp);
		temp=adc_read(ADC0);
	}
	return 0;
}

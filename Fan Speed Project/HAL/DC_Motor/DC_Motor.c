/*
 * DC_Motor.c
 *
 *  Created on: Oct 14, 2021
 *      Author: M.Eltokhy
 */

#include "DC_Motor.h"

void dc_motor_speed(uint8 temp,motor_state state){
	uint8 speed;
	if(temp<30){
		speed=0;
	}else if(temp>=30 && temp<60){
		speed=25;
	}else if(temp>=60 && temp<90){
		speed=50;
	}else if(temp>=90 && temp<120){
		speed=75;
	}else if(temp>=120){
		speed=100;
	}
	OCR0=((speed*255)/100);
	switch(state){
	case cw:
		dio_write(IN1, high);
		dio_write(IN2, low);
		break;
	case ccw:
		dio_write(IN1, low);
		dio_write(IN2, high);
		break;
	case stop:
		dio_write(IN1, low);
		dio_write(IN2, low);
		break;
	}
}

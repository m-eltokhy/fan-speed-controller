/*
 * DC_Motor.h
 *
 *  Created on: Oct 14, 2021
 *      Author: M.Eltokhy
 */

#ifndef HAL_DC_MOTOR_DC_MOTOR_H_
#define HAL_DC_MOTOR_DC_MOTOR_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"
#include "../../MCAL/DIO/dio.h"

typedef enum{
	cw,ccw,stop
}motor_state;

void dc_motor_speed(uint8,motor_state);

#endif /* HAL_DC_MOTOR_DC_MOTOR_H_ */

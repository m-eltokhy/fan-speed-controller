/*
 * dio_types.h
 *
 *  Created on: Sep 30, 2021
 *      Author: M.Eltokhy
 */

#ifndef MCAL_DIO_DIO_TYPES_H_
#define MCAL_DIO_DIO_TYPES_H_

#include "../../STD_TYPES.h"

typedef enum {
	low,high
}Dio_Status;

typedef enum {
	input,output
}Dio_Direction;

typedef enum {
	port_A,port_B,port_C,port_D
}Dio_Ports;

typedef enum {
	temprature,RS=9,E,FAN,IN1,IN2,D0=24,D1,D2,D3,D4,D5,D6,D7
}Dio_Pins;

typedef struct {
	Dio_Ports port;
	unsigned char pin;
	Dio_Direction direction;
}Dio_init_types;


#endif /* MCAL_DIO_DIO_TYPES_H_ */

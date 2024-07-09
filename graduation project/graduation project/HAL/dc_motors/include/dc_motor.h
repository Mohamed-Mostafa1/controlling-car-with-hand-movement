/*
 * dc_motor.h
 *
 * Created: 2/21/2024 1:41:35 AM
 *  Author: mohamed mostafa
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "../../../Libarary/STD_TYPES.h"
#include "../../../MCAL/DIO/Include/DIO.h"


 
 void DC_forward();
 void DC_left();
 void DC_right();
 void DC_backward();

 void DC_stop();


#endif /* DC_MOTOR_H_ */
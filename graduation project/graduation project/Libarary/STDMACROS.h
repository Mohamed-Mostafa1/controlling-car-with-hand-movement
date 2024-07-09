/*
 * STDMACROS.h
 *
 * Created: 9/9/2023 5:02:06 PM
 *  Author: mohamed mostafa
 */ 


#ifndef STDMACROS_H_
#define STDMACROS_H_


#define set_bit(reg,bit)  reg = reg | (1<<bit)
#define toggle_bit(reg,bit) reg = reg ^ (1<<bit)
#define clear_bit(reg,bit) reg = reg & (~(1<<bit)) 
#define read_bit(reg,bit)  ((reg>>bit)&1)




#endif /* STDMACROS_H_ */
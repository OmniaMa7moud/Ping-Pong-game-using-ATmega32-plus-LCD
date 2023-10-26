/*
 * std_macros.h
 *
 * Created: 10/17/2023 12:42:03 PM
 *  Author: omnia
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_

#define REGISTER_SIZE 8
#define SET_BIT(reg,bit)    reg|=(1<<bit)
#define CLR_BIT(reg,bit)    reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)    reg^=(1<<bit)
#define READ_BIT(reg,bit)   ((reg&(1<<bit))>>bit)
#define IS_BIT_SET(reg,bit)  (reg&(1<<bit))>>bit
#define IS_BIT_CLR(reg,bit)  !((reg&(1<<bit))>>bit)
#define ROR(reg,num)         reg=(reg<<(REGISTER_SIZE-num))|(reg>>(num))
#define ROL(reg,num)         reg=(reg>>(REGISTER_SIZE-num))|(reg<<(num))
#define helper(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0
#define conc_Bits(b7,b6,b5,b4,b3,b2,b1,b0)   helper(b7,b6,b5,b4,b3,b2,b1,b0) 


//////Pins////////////
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define PA 0
#define PB 1
#define PC 2
#define PD 3

#define high 1
#define HIGH 1
#define low 1
#define LOW 1

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef unsigned long long u64;
typedef  float f32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef signed long long int s64;
typedef  double f64;



#endif /* STD_MACROS_H_ */
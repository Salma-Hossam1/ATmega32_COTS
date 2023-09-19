#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_
#include "DIO_interface.h"

//PORT OF DATA PINS
//#define CLCD_DATA_PORT   DIO_u8PORTA

#define CLCD_8_BIT_MODE     8
#define CLCD_4_BIT_MODE     4

//#define CLCD_BIT_MODE    CLCD_8_BIT_MODE

//PORT CONNECTED TO CTRL PINS AND THE PINS ON IT
#define CLCD_CTRL_PORT   DIO_u8PORTC
#define CLCD_RS_PIN      DIO_u8PIN0
#define CLCD_RW_PIN      DIO_u8PIN1
#define CLCD_E_PIN       DIO_u8PIN2

#define CLCD_BIT_MODE    CLCD_8_BIT_MODE

#if     (CLCD_BIT_MODE == CLCD_8_BIT_MODE)
//for 8 bit mode
#define CLCD_DATA_PORT   DIO_u8PORTD

#elif   (CLCD_BIT_MODE == CLCD_4_BIT_MODE)
//for 4 bit mode
#define CLCD_BIT4        DIO_u8PIN3
#define CLCD_BIT5        DIO_u8PIN4
#define CLCD_BIT6        DIO_u8PIN5
#define CLCD_BIT7        DIO_u8PIN6
#define CLCD_DATA_PORT   DIO_u8PORTA

#endif

#endif

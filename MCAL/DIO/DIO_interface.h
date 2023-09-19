#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*
//to set pin as output
#define DIO_u8PIN_OUTPUT     1
//to set pin as input
#define DIO_u8PIN_INPUT      0
*/


//to set pin with high
#define DIO_u8PIN_HIGH       1
//to set pin  with low
#define DIO_u8PIN_LOW        0

/*
//to set all port as output
#define DIO_u8PORT_OUTPUT    0xFF
//to set all port as input
#define DIO_u8PORT_INPUT     0
*/

//to set all port with high
#define DIO_u8PORT_HIGH      0xFF
//to set all port with low
#define DIO_u8PORT_LOW       0

//passing the port
#define DIO_u8PORTA          0
#define DIO_u8PORTB          1
#define DIO_u8PORTC          2
#define DIO_u8PORTD          3


//passing the pin number
#define DIO_u8PIN0          0
#define DIO_u8PIN1          1
#define DIO_u8PIN2          2
#define DIO_u8PIN3          3
#define DIO_u8PIN4          4
#define DIO_u8PIN5          5
#define DIO_u8PIN6          6
#define DIO_u8PIN7          7



//u8 DIO_u8SetPinDirection (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Direction);

///u8 DIO_u8SetPortDirection (u8 Copy_u8Port , u8 Copy_u8Direction);

u8 DIO_u8SetPinValue (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value);

u8 DIO_u8SetPortValue (u8 Copy_u8Port , u8 Copy_u8Value);

u8 DIO_u8GetPinValue (u8 Copy_u8Port , u8 Copy_u8Pin ,u8* Copy_pu8Value);





/*********************************************************/
typedef enum{
	PINA0=0,
	PINA1=1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	TOTAL_PINS
}DIO_Pin_type;

typedef enum{
	OUTPUT,
	INFREE,
	INLLUP,
	INPUT
}DIO_PinStatus_type;

typedef enum{
	PA=0,
	PB,
	PC,
	PD
}DIO_Port_type;

typedef enum{
	LOW=0,
	HIGH

}DIO_Voltage_type;

#endif

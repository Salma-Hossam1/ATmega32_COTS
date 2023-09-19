
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"


/*u8 DIO_u8SetPinDirection (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState = 0;

	if(Copy_u8Pin <= DIO_u8PIN7)
	{
		if(Copy_u8Direction == DIO_u8PIN_INPUT)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA:
				CLEAR_BIT(DDRA,Copy_u8Pin);
				break;
			case DIO_u8PORTB:
				CLEAR_BIT(DDRB,Copy_u8Pin);
				break;
			case DIO_u8PORTC:
				CLEAR_BIT(DDRC,Copy_u8Pin);
				break;
			case DIO_u8PORTD:
				CLEAR_BIT(DDRD,Copy_u8Pin);
				break;
			default :
				Local_u8ErrorState = 1;
				break;
			}
		}
		else if(Copy_u8Direction == DIO_u8PIN_OUTPUT)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA:
				SET_BIT(DDRA,Copy_u8Pin);
				break;
			case DIO_u8PORTB:
				SET_BIT(DDRB,Copy_u8Pin);
				break;
			case DIO_u8PORTC:
				SET_BIT(DDRC,Copy_u8Pin);
				break;
			case DIO_u8PORTD:
				SET_BIT(DDRD,Copy_u8Pin);
				break;
			default :
				Local_u8ErrorState = 1;
				break;
			}
		}
		else
		{
			Local_u8ErrorState = 1;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}
*/


/*u8 DIO_u8SetPortDirection (u8 Copy_u8Port , u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState = 0;
	switch(Copy_u8Port)
	{
	case DIO_u8PORTA:
		DDRA =  Copy_u8Direction;
		break;
	case DIO_u8PORTB:
		DDRB =  Copy_u8Direction;
		break;
	case DIO_u8PORTC:
		DDRC =  Copy_u8Direction;
		break;
	case DIO_u8PORTD:
		DDRD =  Copy_u8Direction;
		break;
	default :
		Local_u8ErrorState = 1;
		break;
	}

	return Local_u8ErrorState;
}*/



u8 DIO_u8SetPinValue (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
{
	u8 Local_u8ErrorState = 0;
	if(Copy_u8Pin <= DIO_u8PIN7)
	{
		if(Copy_u8Value == DIO_u8PIN_LOW)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA:
				CLEAR_BIT(PORTA,Copy_u8Pin);
				break;
			case DIO_u8PORTB:
				CLEAR_BIT(PORTB,Copy_u8Pin);
				break;
			case DIO_u8PORTC:
				CLEAR_BIT(PORTC,Copy_u8Pin);
				break;
			case DIO_u8PORTD:
				CLEAR_BIT(PORTD,Copy_u8Pin);
				break;
			default :
				Local_u8ErrorState = 1;
				break;
			}
		}
		else if(Copy_u8Value == DIO_u8PIN_HIGH)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA:
				SET_BIT(PORTA,Copy_u8Pin);
				break;
			case DIO_u8PORTB:
				SET_BIT(PORTB,Copy_u8Pin);
				break;
			case DIO_u8PORTC:
				SET_BIT(PORTC,Copy_u8Pin);
				break;
			case DIO_u8PORTD:
				SET_BIT(PORTD,Copy_u8Pin);
				break;
			default :
				Local_u8ErrorState = 1;
				break;
			}
		}
		else
		{
			Local_u8ErrorState = 1;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}

	return Local_u8ErrorState;
}


u8 DIO_u8SetPortValue (u8 Copy_u8Port , u8 Copy_u8Value)
{
	u8 Local_u8ErrorState = 0;
	switch(Copy_u8Port)
	{
	case DIO_u8PORTA:
		PORTA =  Copy_u8Value;
		break;
	case DIO_u8PORTB:
		PORTB =  Copy_u8Value;
		break;
	case DIO_u8PORTC:
		PORTC =  Copy_u8Value;
		break;
	case DIO_u8PORTD:
		PORTD =  Copy_u8Value;
		break;
	default :
		Local_u8ErrorState = 1;
		break;
	}


	return Local_u8ErrorState;
}


u8 DIO_u8GetPinValue (u8 Copy_u8Port , u8 Copy_u8Pin ,u8* Copy_pu8Value)
{
	u8 Local_u8ErrorState = 0;
	if(Copy_pu8Value != NULL && (Copy_u8Pin<= DIO_u8PIN7))
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA:
			*Copy_pu8Value = GET_BIT(PINA,Copy_u8Pin);
			break;
		case DIO_u8PORTB:
			*Copy_pu8Value = GET_BIT(PINB,Copy_u8Pin);;
			break;
		case DIO_u8PORTC:
			*Copy_pu8Value = GET_BIT(PINC,Copy_u8Pin);;
			break;
		case DIO_u8PORTD:
			*Copy_pu8Value = GET_BIT(PIND,Copy_u8Pin);;
			break;
		default :
			Local_u8ErrorState = 1;
			break;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

















/*void DIO_Set_Pin_Direction(DIO_Pin_type pin , DIO_PinStatus_type status)
{
	DIO_Port_type port =pin/8;
	u8 pin_num=pin%8;
	switch(status)
	{
		case INFREE:
		switch(port)
		{
			case PA:
			CLEAR_BIT(DDRA,pin_num);
			break;
			case PB:
			CLEAR_BIT(DDRB,pin_num);
			break;
			case PC:
			CLEAR_BIT(DDRC,pin_num);
			break;
			case PD:
			CLEAR_BIT(DDRD,pin_num);
			break;
		}
		break;
		case INLLUP :
		switch(port)
		{
			case PA:
			CLEAR_BIT(DDRA,pin_num);
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			CLEAR_BIT(DDRB,pin_num);
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			CLEAR_BIT(DDRC,pin_num);
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			CLEAR_BIT(DDRD,pin_num);
			SET_BIT(PORTD,pin_num);
			break;
		}
		break;
		case OUTPUT :
		switch(port)
		{
			case PA:
			SET_BIT(DDRA,pin_num);
			break;
			case PB:
			SET_BIT(DDRB,pin_num);
			break;
			case PC:
			SET_BIT(DDRC,pin_num);
			break;
			case PD:
			SET_BIT(DDRD,pin_num);
			break;
		}
		break;
		case INPUT :
			switch(port)
			{
				case PA:
				SET_BIT(DDRA,pin_num);
				break;
				case PB:
				SET_BIT(DDRB,pin_num);
				break;
				case PC:
				SET_BIT(DDRC,pin_num);
				break;
				case PD:
				SET_BIT(DDRD,pin_num);
				break;
			}
		break;
	}

}


Bool_t DIO_WritePin(DIO_Pin_type pin ,DIO_Voltage_type volt)
{
	Bool_t ret = False;
	DIO_Port_type port =pin/8;
	u8 pin_num=pin%8;
	if (volt == HIGH)
	{
		switch(port)
		{
			case PA:
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			SET_BIT(PORTD,pin_num);
			break;
		}
	}
	else if(volt == LOW)
	{
		switch(port)
		{
			case PA:
			CLEAR_BIT(PORTA,pin_num);
			break;
			case PB:
			CLEAR_BIT(PORTB,pin_num);
			break;
			case PC:
			CLEAR_BIT(PORTC,pin_num);
			break;
			case PD:
			CLEAR_BIT(PORTD,pin_num);
			break;
		}
	}

}


DIO_Voltage_type DIO_ReadPin(DIO_Pin_type pin)
{
	DIO_Port_type port =pin/8;
	u8 pin_num=pin%8;
	DIO_Voltage_type volt ;
	switch(port)
	{
		case PA:
		volt=GET_BIT(PINA,pin_num);
		break;
		case PB:
		volt=GET_BIT(PINB,pin_num);
		break;
		case PC:
		volt=GET_BIT(PINC,pin_num);
		break;
		case PD:
		volt=GET_BIT(PIND,pin_num);
		break;
	}
	return volt;
}

void DIO_TogglePin(DIO_Pin_type pin)
{
	DIO_Port_type port =pin/8;
	u8 pin_num=pin%8;

	switch(port)
	{
		case PA:
		TOGGle_BIT(PORTA,pin_num);
		break;
		case PB:
		TOGGle_BIT(PORTB,pin_num);
		break;
		case PC:
		TOGGle_BIT(PORTC,pin_num);
		break;
		case PD:
		TOGGle_BIT(PORTD,pin_num);
		break;
	}

}


void DIO_WritePort(DIO_Port_type port , u8 data)
{
	switch(port)
	{
		case PA:
		PORTA = data ;
		break;
		case PB:
		PORTB = data ;
		break;
		case PC:
		PORTC = data ;
		break;
		case PD:
		PORTD = data ;
		break;

	}
}


u8 DIO_ReadPort(DIO_Port_type port)
{
	u8 data;
	switch(port)
	{
		case PA:
		data =PINA ;
		break;
		case PB:
		data =PINB ;
		break;
		case PC:
		data =PINC ;
		break;
		case PD:
		data =PIND ;
		break;
	}return data;
}
 */

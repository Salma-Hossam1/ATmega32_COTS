#include "STD_TYPES.h"
#include "DIO_interface.h"
#include <util/delay.h>

#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"

#if     (CLCD_BIT_MODE == CLCD_8_BIT_MODE)
void CLCD_voidSendCommand (u8 Copy_u8Command)
{
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}


void CLCD_voidSendData (u8 Copy_u8Data)
{
	//static u8 Local_u8Counter =0;
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
	//CLCD_voidCheckCount();
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}


void CLCD_voidInit (void)
{
	//some commands from datasheet page 13

	//for 8 bit mode :

	/*1-wait for more than 30 micro sec*/
	_delay_ms(40);

	/*2- Function set -> command as RS is 0 -> 2 lines , 5*8 font size*/
	CLCD_voidSendCommand(0b00111000);

	/*3- wait for more than 39 micro sec -> in func SendCommand already we have delay*/

	/*4- Display on off control , display enable , disable cursor , no blink cursor*/
	CLCD_voidSendCommand(0b00001100);


	/*5- wait for more than 39 micro sec -> in func SendCommand already we have delay*/

	/*6- Display Clear*/
	CLCD_voidSendCommand(1);

	/*7- wait for more than 1.53 micro sec -> in func SendCommand already we have delay*/

	/*8- Entry mode set .. advanced */

}
#elif   (CLCD_BIT_MODE == CLCD_4_BIT_MODE)

void CLCD_voidSendCommand (u8 Copy_u8Command)
{
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_BIT4,  ((Copy_u8Command>>4)&1) );
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_BIT5,  ((Copy_u8Command>>5)&1) );
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_BIT6,  ((Copy_u8Command>>6)&1) );
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_BIT7,  ((Copy_u8Command>>7)&1) );
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_BIT4,  ((Copy_u8Command>>0)&1) );
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_BIT5,  ((Copy_u8Command>>1)&1) );
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_BIT6,  ((Copy_u8Command>>2)&1) );
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_BIT7,  ((Copy_u8Command>>3)&1) );
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}

void CLCD_voidSendData (u8 Copy_u8Data)
{
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	//CLCD_voidCheckCount ();
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_BIT4,  ((Copy_u8Data>>4)&1) );
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_BIT5,  ((Copy_u8Data>>5)&1) );
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_BIT6,  ((Copy_u8Data>>6)&1) );
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_BIT7,  ((Copy_u8Data>>7)&1) );
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_BIT4,  ((Copy_u8Data>>0)&1) );
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_BIT5,  ((Copy_u8Data>>1)&1) );
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_BIT6,  ((Copy_u8Data>>2)&1) );
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_BIT7,  ((Copy_u8Data>>3)&1) );
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}


void CLCD_voidInit(void)  /* LCD Initialize function */
{
	_delay_ms(50);
	CLCD_voidSendCommand(0x02);
	CLCD_voidSendCommand(0x28); //2 lines , 5*7 ,4 bit mode
	CLCD_voidSendCommand(0x0c); //cursor hidden , no blink ,LCD ON
	CLCD_voidSendCommand(0x01); // clear display
	CLCD_voidSendCommand(0x06); // shift disabled , DDRAM address increase
}
#endif

void CLCD_voidSendString(const char* Copy_pcString)
{
	u8 Local_u8LoopCounter =0;
	while( (Copy_pcString[Local_u8LoopCounter]) !='\0')
	{
		CLCD_voidSendData(Copy_pcString[Local_u8LoopCounter]);
		Local_u8LoopCounter++;
	}

}

void CLCD_voidGoToXY (u8 Copy_u8XPos , u8 Copy_u8YPos)
{
	u8 Local_u8Address =0;
	if(Copy_u8XPos == 0)
	{
		Local_u8Address = Copy_u8YPos ;
	}
	else if(Copy_u8XPos == 1)
	{
		Local_u8Address = 0x40 + Copy_u8YPos;
	}
	CLCD_voidSendCommand((Local_u8Address+128));
}

void CLCD_voidWriteSpecialCharacter(u8* Copy_pu8Pttern,u8 Copy_u8PatternNumber , u8 Copy_u8PosX,u8 Copy_u8PosY)
{
	u8 Local_u8CGRAMAddress =0;
	u8 Local_u8LoopCounter =0;


	Local_u8CGRAMAddress = Copy_u8PatternNumber *8;
	CLCD_voidSendCommand(Local_u8CGRAMAddress + 64);

	for(Local_u8LoopCounter =0 ; Local_u8LoopCounter < 8;Local_u8LoopCounter ++ )
	{
		CLCD_voidSendData(Copy_pu8Pttern[Local_u8LoopCounter]);
	}

	CLCD_voidGoToXY(Copy_u8PosX,Copy_u8PosY);
	CLCD_voidCheckCount ();
	CLCD_voidSendData(Copy_u8PatternNumber);

}

void CLCD_voidWriteNumber(s64 Copy_s64Number)
{
	u8 Local_u8NumberArray [16]={0};
	u8 Local_u8LoopCounter1 =0;
	s8 Local_u8LoopCounter2=0;
	if(Copy_s64Number==0)
	{
		CLCD_voidSendData('0');
	}
	if(Copy_s64Number<0)
	{
		CLCD_voidSendData('-');
		Copy_s64Number*=-1;
	}
	while(Copy_s64Number>0)
	{
		Local_u8NumberArray[Local_u8LoopCounter1]=Copy_s64Number%10;
		Local_u8LoopCounter1++;
		Copy_s64Number/=10;
	}
	Local_u8LoopCounter1--;
	for(Local_u8LoopCounter2=Local_u8LoopCounter1;Local_u8LoopCounter2>=0;Local_u8LoopCounter2--)
	{
		CLCD_voidSendData(Local_u8NumberArray[Local_u8LoopCounter2]+'0');
	}
}

void CLCD_voidClear(void)
{
	CLCD_voidSendCommand(0x01);
}

void CLCD_voidCheckCount (void)
{
	static s8 Local_u8Counter = -1;
	if(Local_u8Counter < 16)
	{
		Local_u8Counter++;
	}
	else if(Local_u8Counter == 16)
	{
		CLCD_voidGoToXY(1,0);
		Local_u8Counter++;
	}
	else if (Local_u8Counter <= 32)
	{
		Local_u8Counter++;
	}
	else if(Local_u8Counter > 32)
	{
		CLCD_voidGoToXY(0,0);
		Local_u8Counter =0;
	}
}

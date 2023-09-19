#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "KEYPAD_interface.h"
#include "kEYPAD_config.h"
#include "kEYPAD_private.h"

u8 KEYPAD_u8GetPressedKey(void)
{
    u8 Local_u8PressedKey=KPD_NO_PRESSED_KEY;
    u8 Local_u8ColumnIndex;
	u8 Local_u8RowIndex;
	u8 Local_u8PinState;
    static u8 Local_u8KPDArray [ROW_NUM][COLUMN_NUM]= KPD_ARR_VAL;
    static u8 Local_u8KPDColumnArr [COLUMN_NUM]={KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN,KPD_COLUMN3_PIN};
    static u8 Local_u8KPDRowArr [ROW_NUM]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};

	for(Local_u8ColumnIndex=0;Local_u8ColumnIndex<COLUMN_NUM;Local_u8ColumnIndex++)
	{
		/*Activate current column*/
		DIO_u8SetPinValue(KPD_PORT,Local_u8KPDColumnArr[Local_u8ColumnIndex],DIO_u8PIN_LOW);
		for(Local_u8RowIndex=0;Local_u8RowIndex<ROW_NUM;Local_u8RowIndex++)
		{
			/*read the current row*/
			DIO_u8GetPinValue(KPD_PORT,Local_u8KPDRowArr[Local_u8RowIndex],&Local_u8PinState);

			/*Check if switch is pressed*/
			if(Local_u8PinState == DIO_u8PIN_LOW)
			{
				Local_u8PressedKey = Local_u8KPDArray[Local_u8RowIndex][Local_u8ColumnIndex];

				//polling
                while(Local_u8PinState == DIO_u8PIN_LOW)
                {
                	DIO_u8GetPinValue(KPD_PORT,Local_u8KPDRowArr[Local_u8RowIndex],&Local_u8PinState);
                }
				//if user pressed 2 buttons , I will end imp for the first one -> to solve bouncing and there is no meaning to continue searching
				return Local_u8PressedKey;
			}
		}
		/*Deactivate current column*/
		DIO_u8SetPinValue(KPD_PORT,Local_u8KPDColumnArr[Local_u8ColumnIndex],DIO_u8PIN_HIGH);
	}
	return Local_u8PressedKey;
}

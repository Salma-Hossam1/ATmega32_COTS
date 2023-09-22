#include "STD_TYPES.h"
#include "SSD_config.h"
#include "SSD_interface.h"
#include "SSD_private.h"
#include "DIO_interface.h"

void SSD_voidSetNumber (u8 Copy_u8Number)
{
	u8 Local_u8LoopCounter=0;
	u8 SSD_ARR_NUMBERS [MAX_SSD_ARR_SIZE]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

    #if (SSD_COMMON_TYPE == SSD_COMMON_CATHODE)
	//SSD_ARR_NUMBERS [MAX_SSD_ARR_SIZE] = SSD_NUMBER_SET;
    #elif (SSD_COMMON_TYPE == SSD_COMMON_ANODE)
	for( Local_u8LoopCounter=0; Local_u8LoopCounter<MAX_SSD_ARR_SIZE;Local_u8LoopCounter++)
	{
		SSD_ARR_NUMBERS [Local_u8LoopCounter] = ~(SSD_ARR_NUMBERS[Local_u8LoopCounter]);
	}
    #endif
	DIO_u8SetPortValue (SSD_PORT , SSD_ARR_NUMBERS [Copy_u8Number]);
}


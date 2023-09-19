#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_register.h"
#include "ADC_config.h"
#include "ADC_private.h"
#include "ADC_interface.h"

static u16* ADC_pu16DigitalRead =NULL;
static u32 *ADC_pu32mVolt = NULL;
static u8 *ADC_pu8Gain =0;
static void (*ADC_pvCallBackNotificationFun)(void)=NULL;
u8 ADC_u8BusyState = IDLE;

void ADC_voidInit (void)
{
	/* Refrence Selection Bits*/
#if (ADC_REFERENCE_VOLTAGE == AREF)
	CLEAR_BIT(ADMUX,ADMUX_REFS0);
	CLEAR_BIT(ADMUX,ADMUX_REFS1);

#elif (ADC_REFERENCE_VOLTAGE == AVCC)
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLEAR_BIT(ADMUX,ADMUX_REFS1);

#elif (ADC_REFERENCE_VOLTAGE == INTERNAL_2.56V)
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);

#endif

	/*Needed resolution*/
#if (ADC_RESOLUTION == 8)
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif (ADC_RESOLUTION == 10)
	CLEAR_BIT(ADMUX,ADMUX_ADLAR);
#endif

	/*Select Prescaler*/
	ADCSRA &= PRESCALER_MASK;
	ADCSRA |= ADC_PRESCALER;

	/*Conversion Mode*/
#if(ADC_CONVERSION_MODE == SINGLE_CONVERSION_MODE)
	CLEAR_BIT(ADCSRA,ADCSRA_ADATE);
#elif (ADC_CONVERSION_MODE == AUTO_TRIGGER)
	SET_BIT(ADCSRA,ADCSRA_ADATE);

	/*Select mode of Auto Trigger*/
	SFIOR &= AUTO_TRIGGER_MASK ;
	SFIOR |= AUTO_TRIGGER ;

#endif
	/*Enable ADC*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

u8 ADC_u8StartConversionSynch (u8 Copy_u8Channel,u8 Copy_u8Gain ,u16* Copy_pu16DigitalRead,u32 *Copy_pu32mVolt)
{
	u8 Local_u8ErrorState = OK;
	u32 Local_u32Counter =0;
	u32 *Local_pu32mVolt;
	if(ADC_u8BusyState ==IDLE)
	{
		ADC_u8BusyState =Busy;
		if((NULL_POINTER != Copy_pu32mVolt) && (NULL_POINTER != Copy_pu16DigitalRead)  )
		{
			/*Clear the MUX bits in ADMUX register*/
			ADMUX &= CHANNEL_MASK;

			/*Set the required channel into the MUX bits*/
			ADMUX |= Copy_u8Channel;

			/*Start conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*Polling (busy waiting) until the conversion complete flag is set or counter reaching timeout val*/
			while(((GET_BIT(ADCSRA,ADCSRA_ADIF))==0) && (Local_u32Counter !=ADC_u32TIMEOUT))
			{
				Local_u32Counter++;
			}
			if(Local_u32Counter == ADC_u32TIMEOUT)
			{
				//Loop is broken because the timeout is reached
				Local_u8ErrorState = NOK;
			}
			else
			{
				//Loop is broken because Flag is raised
				/*Clear the conversion complete flag*/
				SET_BIT(ADCSRA,ADCSRA_ADIF);

				/*Return reading*/
#if (ADC_RESOLUTION == 8)
				*Local_pu32mVolt = ADCH;
				*Local_pu32mVolt =(u32)(((u32)*Local_pu32mVolt * ADC_REFERENCE_VOLTAGE *1000UL)/256UL);
				*Local_pu32mVolt /= (u32)Copy_u8Gain;
				*Copy_pu16DigitalRead =ADCH;
				ADC_u8BusyState =IDLE;
#elif (ADC_RESOLUTION == 10)
				*Local_pu32mVolt = ADC;
				*Local_pu32mVolt =(u32)(((u32)*Local_pu32mVolt * ADC_REFERENCE_VOLTAGE *1000UL)/1024UL);
				*Local_pu32mVolt /= (u32)Copy_u8Gain;
				*Copy_pu16DigitalRead =ADCH;
				ADC_u8BusyState =IDLE;
#endif
			}
		}
		else
		{
			Local_u8ErrorState = NULL_POINTER;
		}}
	else
	{
		Local_u8ErrorState=BUSY_FUNC;
	}
	return Local_u8ErrorState;
}

u8 ADC_u8StartConversionASynch (u8 Copy_u8Channel,u8 Copy_u8Gain ,u16* Copy_pu16DigitalRead,u32 *Copy_pu32mVolt,void (*Copy_pvNotification)(void))
{
	u8 Local_u8ErrorState = OK;
	if(ADC_u8BusyState==IDLE)
	{
		if((NULL_POINTER == Copy_pu32mVolt) || (NULL_POINTER == Copy_pu16DigitalRead) || (NULL_POINTER == Copy_pvNotification) )
		{
			Local_u8ErrorState = NULL_POINTER;
		}
		else
		{
			/*Make ADC busy in order not to work until being IDLE*/
			ADC_u8BusyState =Busy;
			/*Initialize the reading variables globally*/
			ADC_pu16DigitalRead= Copy_pu16DigitalRead;
			ADC_pu32mVolt=Copy_pu32mVolt;
			ADC_pu8Gain = &Copy_u8Gain;
			/*Initialize the Call back Notification function globally*/
			ADC_pvCallBackNotificationFun = Copy_pvNotification;

			/*Clear the MUX bits in ADMUX register*/
			ADMUX &= CHANNEL_MASK;

			/*Set the required channel into the MUX bits*/
			ADMUX |= Copy_u8Channel;

			/*Start conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*Enable ADC interrupt*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
	}
	else
	{
		Local_u8ErrorState=BUSY_FUNC;
	}
	return Local_u8ErrorState;
}

void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
	/*Read ADC result*/
	if(ADC_RESOLUTION == 8)
	{
		*ADC_pu32mVolt = ADCH;
		*ADC_pu32mVolt =(u32)(((u32)*ADC_pu32mVolt * ADC_REFERENCE_VOLTAGE *1000UL)/256UL);
		*ADC_pu32mVolt /= (u32)ADC_pu8Gain;
		*ADC_pu16DigitalRead=ADCH;
	}
	else if(ADC_RESOLUTION == 10)
	{
		*ADC_pu32mVolt = ADC;
		*ADC_pu32mVolt =(u32)(((u32)*ADC_pu32mVolt * ADC_REFERENCE_VOLTAGE *1000UL)/1024UL);
		*ADC_pu32mVolt /= (u32)ADC_pu8Gain;
		*ADC_pu16DigitalRead=ADC;
	}

	/*Make ADC state IDLE*/
	ADC_u8BusyState = IDLE;
	/*Invoke the callback notification function */
	ADC_pvCallBackNotificationFun();

	/*Disable ADC Conversion Complete Interrupt*/
	CLEAR_BIT(ADCSRA,ADCSRA_ADIE);
}

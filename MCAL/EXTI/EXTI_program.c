#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"
#include "EXTI_register.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include <util/delay.h>

/*Global pointer to function to hold INT0_ISR address*/
void (*EXTI_pvINT0Func) (void) = NULL;
/*Global pointer to function to hold INT1_ISR address*/
void (*EXTI_pvINT1Func) (void) = NULL;
/*Global pointer to function to hold INT2_ISR address*/
void (*EXTI_pvINT2Func) (void) = NULL;

void EXTI_voidINT0Init (void)
{
	/*Check sense*/
#if (INT0_SENSE == LOW_LEVEL)
	/*SET SENSE CONTROL FOR INT0 TO LOW LEVEL */
	CLEAR_BIT(MCUCR,MCUCR_ISC01);
	CLEAR_BIT(MCUCR,MCUCR_ISC00);

#elif (INT0_SENSE == ON_CHANGE)
	/*SET SENSE CONTROL FOR INT0 TO ON CHANGE */
	CLEAR_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);

#elif (INT0_SENSE == FALLING_EDGE )
	/*SET SENSE CONTROL FOR INT0 TO FALLING EDGE */
	SET_BIT(MCUCR,MCUCR_ISC01);
	CLEAR_BIT(MCUCR,MCUCR_ISC00);

#elif (INT0_SENSE == RISING_EDGE )
	/*SET SENSE CONTROL FOR INT0 TO RISING EDGE */
	SET_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);

#else
#error "Wrong INT0_SENSE configuration option"

#endif

	/*Check peripheral interrupt enable initial state*/
#if  (INT0_INIT_STATE == ENABLED)
	/*PERIPHERAL INTERRUPT ENABLE FOR INT0*/
	SET_BIT(GICR,GICR_INT0);

#elif  (INT0_INIT_STATE == DISABLED)
	CLEAR_BIT(GICR,GICR_INT0);

#error "Wrong INT0_INIT_STATE configuration option"

#endif
}

void EXTI_voidINT1Init (void)
{
	/*Check sense*/
#if (INT1_SENSE == LOW_LEVEL)
	/*SET SENSE CONTROL FOR INT1 TO LOW LEVEL */
	CLEAR_BIT(MCUCR,MCUCR_ISC11);
	CLEAR_BIT(MCUCR,MCUCR_ISC10);

#elif (INT1_SENSE == ON_CHANGE)
	/*SET SENSE CONTROL FOR INT1 TO ON CHANGE */
	CLEAR_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);

#elif (INT1_SENSE == FALLING_EDGE )
	/*SET SENSE CONTROL FOR INT1 TO FALLING EDGE */
	SET_BIT(MCUCR,MCUCR_ISC11);
	CLEAR_BIT(MCUCR,MCUCR_ISC10);

#elif (INT1_SENSE == RISING_EDGE )
	/*SET SENSE CONTROL FOR INT1 TO RISING EDGE */
	SET_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);

#else
#error "Wrong INT1_SENSE configuration option"

#endif

	/*Check peripheral interrupt enable initial state*/
#if  (INT1_INIT_STATE == ENABLED)
	/*PERIPHERAL INTERRUPT ENABLE FOR INT0*/
	SET_BIT(GICR,GICR_INT1);

#elif  (INT1_INIT_STATE == DISABLED)
	CLEAR_BIT(GICR,GICR_INT1);

#error "Wrong INT0_INIT_STATE configuration option"

#endif
}


void EXTI_voidINT2Init (void)
{
	/*Check sense*/
#if (INT2_SENSE == FALLING_EDGE )
	/*SET SENSE CONTROL FOR INT2 TO FALLING EDGE */
	CLEAR_BIT(MCUCSR,MCUCSR_ISC2);

#elif (INT0_SENSE == RISING_EDGE )
	/*SET SENSE CONTROL FOR INT2 TO RISING EDGE */
	SET_BIT(MCUCSR,MCUCSR_ISC2);

#else
#error "Wrong INT1_SENSE configuration option"

#endif

	/*Check peripheral interrupt enable initial state*/
#if  (INT2_INIT_STATE == ENABLED)
	/*PERIPHERAL INTERRUPT ENABLE FOR INT0*/
	SET_BIT(GICR,GICR_INT2);

#elif  (INT2_INIT_STATE == DISABLED)
	CLEAR_BIT(GICR,GICR_INT2);

#error "Wrong INT0_INIT_STATE configuration option"

#endif
}


u8 EXTI_u8INT0SetSenseControl  (u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Sense)
	{
	case LOW_LEVEL:
		CLEAR_BIT(MCUCR,MCUCR_ISC01);
		CLEAR_BIT(MCUCR,MCUCR_ISC00);
		break;
	case ON_CHANGE:
		CLEAR_BIT(MCUCR,MCUCR_ISC01);
		SET_BIT(MCUCR,MCUCR_ISC00);
		break;
	case FALLING_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC01);
		CLEAR_BIT(MCUCR,MCUCR_ISC00);
		break;
	case RISING_EDGE :
		SET_BIT(MCUCR,MCUCR_ISC01);
		SET_BIT(MCUCR,MCUCR_ISC00);
		break;
	default : Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8INT1SetSenseControl  (u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Sense)
	{
	case LOW_LEVEL:
		CLEAR_BIT(MCUCR,MCUCR_ISC11);
		CLEAR_BIT(MCUCR,MCUCR_ISC10);
		break;
	case ON_CHANGE:
		CLEAR_BIT(MCUCR,MCUCR_ISC11);
		SET_BIT(MCUCR,MCUCR_ISC10);
		break;
	case FALLING_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC11);
		CLEAR_BIT(MCUCR,MCUCR_ISC10);
		break;
	case RISING_EDGE :
		SET_BIT(MCUCR,MCUCR_ISC11);
		SET_BIT(MCUCR,MCUCR_ISC10);
		break;
	default : Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}
u8 EXTI_u8INT2SetSenseControl  (u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Sense)
	{
	case FALLING_EDGE:
		CLEAR_BIT(MCUCSR,MCUCSR_ISC2);
		break;
	case RISING_EDGE :
		SET_BIT(MCUCSR,MCUCSR_ISC2);
		break;
	default : Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}

u8 EXTI_u8INTEnabled  (u8 Copy_u8INT)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8INT)
	{
	case INT0 :
		SET_BIT(GICR,GICR_INT0);
		break;
	case INT1 :
		SET_BIT(GICR,GICR_INT1);
		break;
	case INT2 :
		SET_BIT(GICR,GICR_INT2);
		break;
	default : Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8INT0SetCallBack (void (*Copy_u8pvINT0Func) (void))
{
	u8 Local_u8ErrorState = OK;
	if(Copy_u8pvINT0Func!=NULL)
	{
		EXTI_pvINT0Func = Copy_u8pvINT0Func;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}

/*ISR of INT0*/
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_pvINT0Func != NULL)
	{
		EXTI_pvINT0Func();
	}
	else
	{
		/*DO nothing*/
	}
}

u8 EXTI_u8INT1SetCallBack (void (*Copy_u8pvINT1Func) (void))
{
	u8 Local_u8ErrorState = OK;
	if(Copy_u8pvINT1Func!=NULL)
	{
		EXTI_pvINT1Func = Copy_u8pvINT1Func;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}
/*ISR of INT1*/
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if(EXTI_pvINT1Func != NULL)
	{
		EXTI_pvINT1Func();
	}
	else
	{
		/*DO nothing*/
	}
}


u8 EXTI_u8INT2SetCallBack (void (*Copy_u8pvINT2Func) (void))
{
	u8 Local_u8ErrorState = OK;
	if(Copy_u8pvINT2Func!=NULL)
	{
		EXTI_pvINT2Func = Copy_u8pvINT2Func;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}
/*ISR of INT2*/
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if(EXTI_pvINT2Func != NULL)
	{
		EXTI_pvINT2Func();
	}
	else
	{
		/*DO nothing*/
	}
}
/*u8 EXTI_u8INTSetSenseControl   (u8 Copy_u8INIType ,u8 Copy_u8Sense )
{
	u8 Local_u8ErrorState = OK;
	if(Copy_u8INIType == INIT0)
	{
		switch(Copy_u8Sense)
		{
		case LOW_LEVEL:
			CLEAR_BIT(MCUCR,MCUCR_ISC01);
			CLEAR_BIT(MCUCR,MCUCR_ISC00);
			break;
		case ON_CHANGE:
			CLEAR_BIT(MCUCR,MCUCR_ISC01);
			SET_BIT(MCUCR,MCUCR_ISC00);
			break;
		case FALLING_EDGE:
			SET_BIT(MCUCR,MCUCR_ISC01);
			CLEAR_BIT(MCUCR,MCUCR_ISC00);
			break;
		case RISING_EDGE :
			SET_BIT(MCUCR,MCUCR_ISC01);
			SET_BIT()_BIT(MCUCR,MCUCR_ISC00);
			break;
		default : Local_u8ErrorState = NOK;

		}
	}
}*/

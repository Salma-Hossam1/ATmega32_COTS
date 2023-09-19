#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


#define LOW_LEVEL      1
#define ON_CHANGE      2
#define FALLING_EDGE   3
#define RISING_EDGE    4

/*prebuild*/
void EXTI_voidINT0Init (void);
void EXTI_voidINT1Init (void);
void EXTI_voidINT2Init (void);

/*Description : function to set the required sense control of INT0 using post build configuration
 *param : u8 Copy_u8Sense -> options are 1-LOW_LEVEL
                                         2-ON_CHANGE
                                         3-FALLING_EDGE
                                         4-RISING_EDGE
      note : for INT2 choose FALLING_EDGE or RISING_EDGE
  *param : u8 Copy_u8INIType -> options are 1-INIT0
                                            2-INIT1
                                            3-INIT2
  *ret : Error state with type u8
 */
u8 EXTI_u8INT0SetSenseControl  (u8 Copy_u8Sense);
u8 EXTI_u8INT1SetSenseControl  (u8 Copy_u8Sense);
u8 EXTI_u8INT2SetSenseControl  (u8 Copy_u8Sense);




/*********************************************/
/*
 * options :  INIT0
              INIT1
              INIT2
 * postbuild */
u8 EXTI_u8INTEnabled  (u8 Copy_u8INT);
u8 EXTI_u8INTDisabled  (u8 Copy_u8INT);
/*********************************************/

u8 EXTI_u8INT0SetCallBack (void (*Copy_u8pvINT0Func) (void));
u8 EXTI_u8INT1SetCallBack (void (*Copy_u8pvINT1Func) (void));
u8 EXTI_u8INT2SetCallBack (void (*Copy_u8pvINT2Func) (void));





/*param : u8 Copy_u8INIType -> options are 1-INIT0
                                            2-INIT1
                                            3-INIT2
//u8 EXTI_u8INTSetSenseControl   (u8 Copy_u8INIType ,u8 Copy_u8Sense );
*/
#define INT0          1
#define INT1          2
#define INT2          3
#endif

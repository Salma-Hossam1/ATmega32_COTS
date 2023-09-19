#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_
 /*options :
  * LOW_LEVEL
  * ON_CHANGE
  * FALLING_EDGE
  * RISING_EDGE
  * */
#define INT0_SENSE     FALLING_EDGE
#define INT1_SENSE     FALLING_EDGE
#define INT2_SENSE     FALLING_EDGE

/*options :
  * FALLING_EDGE
  * RISING_EDGE
  * */
#define INT2_SENSE     FALLING_EDGE


/*options:
 * ENABLED
 * DISABLED
 */
#define INT0_INIT_STATE  ENABLED
#define INT1_INIT_STATE  ENABLED
#define INT2_INIT_STATE  ENABLED

#endif

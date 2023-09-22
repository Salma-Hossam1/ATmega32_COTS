#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_

#define INPUT        0
#define OUTPUT       1



/*All pins initialized as input pins until user changes it in this file*/
#define PORTA_PIN0_DIR     INPUT
#define PORTA_PIN1_DIR     OUTPUT
#define PORTA_PIN2_DIR     OUTPUT
#define PORTA_PIN3_DIR     OUTPUT
#define PORTA_PIN4_DIR     OUTPUT
#define PORTA_PIN5_DIR     OUTPUT
#define PORTA_PIN6_DIR     OUTPUT
#define PORTA_PIN7_DIR     OUTPUT


#define PORTB_PIN0_DIR     OUTPUT
#define PORTB_PIN1_DIR     OUTPUT
#define PORTB_PIN2_DIR     OUTPUT
#define PORTB_PIN3_DIR     OUTPUT
#define PORTB_PIN4_DIR     OUTPUT
#define PORTB_PIN5_DIR     OUTPUT
#define PORTB_PIN6_DIR     OUTPUT
#define PORTB_PIN7_DIR     OUTPUT


#define PORTC_PIN0_DIR     OUTPUT
#define PORTC_PIN1_DIR     OUTPUT
#define PORTC_PIN2_DIR     OUTPUT
#define PORTC_PIN3_DIR     OUTPUT
#define PORTC_PIN4_DIR     OUTPUT
#define PORTC_PIN5_DIR     OUTPUT
#define PORTC_PIN6_DIR     OUTPUT
#define PORTC_PIN7_DIR     OUTPUT


#define PORTD_PIN0_DIR     OUTPUT
#define PORTD_PIN1_DIR     OUTPUT
#define PORTD_PIN2_DIR     OUTPUT
#define PORTD_PIN3_DIR     INPUT
#define PORTD_PIN4_DIR     OUTPUT
#define PORTD_PIN5_DIR     OUTPUT
#define PORTD_PIN6_DIR     OUTPUT
#define PORTD_PIN7_DIR     OUTPUT

/*************************************************************/
/*for input pins choose init values of PORT register */
#define FLOATING     0
#define PULLEDUP       1


/*for output pins choose init values of port register */
#define LOW          0
#define HIGH         1



#define PORTA_PIN0_INIT_VAL     FLOATING
#define PORTA_PIN1_INIT_VAL     LOW
#define PORTA_PIN2_INIT_VAL     LOW
#define PORTA_PIN3_INIT_VAL     LOW
#define PORTA_PIN4_INIT_VAL     LOW
#define PORTA_PIN5_INIT_VAL     LOW
#define PORTA_PIN6_INIT_VAL     LOW
#define PORTA_PIN7_INIT_VAL     LOW


#define PORTB_PIN0_INIT_VAL     LOW
#define PORTB_PIN1_INIT_VAL     LOW
#define PORTB_PIN2_INIT_VAL     LOW
#define PORTB_PIN3_INIT_VAL     LOW
#define PORTB_PIN4_INIT_VAL     LOW
#define PORTB_PIN5_INIT_VAL     LOW
#define PORTB_PIN6_INIT_VAL     LOW
#define PORTB_PIN7_INIT_VAL     LOW


#define PORTC_PIN0_INIT_VAL     LOW
#define PORTC_PIN1_INIT_VAL     LOW
#define PORTC_PIN2_INIT_VAL     LOW
#define PORTC_PIN3_INIT_VAL     LOW
#define PORTC_PIN4_INIT_VAL     LOW
#define PORTC_PIN5_INIT_VAL     LOW
#define PORTC_PIN6_INIT_VAL     LOW
#define PORTC_PIN7_INIT_VAL     LOW



#define PORTD_PIN0_INIT_VAL     LOW
#define PORTD_PIN1_INIT_VAL     LOW
#define PORTD_PIN2_INIT_VAL     LOW
#define PORTD_PIN3_INIT_VAL     PULLEDUP
#define PORTD_PIN4_INIT_VAL     LOW
#define PORTD_PIN5_INIT_VAL     LOW
#define PORTD_PIN6_INIT_VAL     LOW
#define PORTD_PIN7_INIT_VAL     LOW

#endif

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define AVCC                   5
#define INTERNAL_2.56V         INTERNAL_2.56V

#define DIV_BY_2         0
#define DIV_BY_4         2
#define DIV_BY_8         3
#define DIV_BY_16        4
#define DIV_BY_32        5
#define DIV_BY_64        6
#define DIV_BY_128       7

#define PRESCALER_MASK   0b11111000


#define SINGLE_ENDED_INPUT_ADC0                                 0
#define SINGLE_ENDED_INPUT_ADC1                                 1
#define SINGLE_ENDED_INPUT_ADC2                                 2
#define SINGLE_ENDED_INPUT_ADC3                                 3
#define SINGLE_ENDED_INPUT_ADC4                                 4
#define SINGLE_ENDED_INPUT_ADC5                                 5
#define SINGLE_ENDED_INPUT_ADC6                                 6
#define SINGLE_ENDED_INPUT_ADC7                                 7
#define DIFFERENTIAL_INPUT_POSITIVE_ADC0_NEGATIVE_ADC0_10X      8
#define DIFFERENTIAL_INPUT_POSITIVE_ADC1_NEGATIVE_ADC0_10X      9
#define DIFFERENTIAL_INPUT_POSITIVE_ADC0_NEGATIVE_ADC0_200X     10
#define DIFFERENTIAL_INPUT_POSITIVE_ADC1_NEGATIVE_ADC0_200X     11
#define DIFFERENTIAL_INPUT_POSITIVE_ADC2_NEGATIVE_ADC2_10X      12
#define DIFFERENTIAL_INPUT_POSITIVE_ADC3_NEGATIVE_ADC2_10X      13
#define DIFFERENTIAL_INPUT_POSITIVE_ADC2_NEGATIVE_ADC2_200X     14
#define DIFFERENTIAL_INPUT_POSITIVE_ADC3_NEGATIVE_ADC2_200X     15
#define DIFFERENTIAL_INPUT_POSITIVE_ADC0_NEGATIVE_ADC1_1X       16
#define DIFFERENTIAL_INPUT_POSITIVE_ADC1_NEGATIVE_ADC1_1X       17
#define DIFFERENTIAL_INPUT_POSITIVE_ADC2_NEGATIVE_ADC1_1X       18
#define DIFFERENTIAL_INPUT_POSITIVE_ADC3_NEGATIVE_ADC1_1X       19
#define DIFFERENTIAL_INPUT_POSITIVE_ADC4_NEGATIVE_ADC1_1X       20
#define DIFFERENTIAL_INPUT_POSITIVE_ADC5_NEGATIVE_ADC1_1X       21
#define DIFFERENTIAL_INPUT_POSITIVE_ADC6_NEGATIVE_ADC1_1X       22
#define DIFFERENTIAL_INPUT_POSITIVE_ADC7_NEGATIVE_ADC1_1X       23
#define DIFFERENTIAL_INPUT_POSITIVE_ADC0_NEGATIVE_ADC2_1X       24
#define DIFFERENTIAL_INPUT_POSITIVE_ADC1_NEGATIVE_ADC2_1X       25
#define DIFFERENTIAL_INPUT_POSITIVE_ADC2_NEGATIVE_ADC2_1X       26
#define DIFFERENTIAL_INPUT_POSITIVE_ADC3_NEGATIVE_ADC2_1X       27
#define DIFFERENTIAL_INPUT_POSITIVE_ADC4_NEGATIVE_ADC2_1X       28
#define DIFFERENTIAL_INPUT_POSITIVE_ADC5_NEGATIVE_ADC2_1X       29
#define SINGLE_ENDED_INPUT_1.22V                                30
#define SINGLE_ENDED_INPUT_0V                                   31
#define CHANNEL_MASK                                            0b11100000

#define AUTO_TRIGGER_MASK                                       0b00011111
#define FREE_RUNNING_MODE                                       0
#define ANALOG_COMPARATOR                                       32
#define EXTERNAL_INTRRUPT_REQUEST_0                             64
#define TIMER_COUNTER0_COMPARE_MATCH                            96
#define TIMER_COUNTER0_OVERFLOW                                 128
#define TIMER_COUNTER_COMPARE_MATCH_B                           160
#define TIMER_COUNTER1_OVERFLOW                                 192
#define TIMER_COUNTER1_CAPTURE_EVENT                            224


#define IDLE             1
#define Busy             2

#endif

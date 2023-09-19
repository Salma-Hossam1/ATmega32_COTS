#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg,bit)   (reg=reg|(1<<bit))
#define CLEAR_BIT(reg,bit) (reg=reg&(~(1<<bit)))
#define GET_BIT(reg,bit)  ((reg>>bit)&1)
#define TOGGle_BIT(reg,bit) (reg=reg^(1<<bit))

#endif // BIT_MATH_H_INCLUDED

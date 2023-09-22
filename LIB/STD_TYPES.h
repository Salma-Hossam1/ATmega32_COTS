#ifndef STD_TYPES_H_
#define STD_TYPES_H_

// unsigned char (0 -> 255)
typedef unsigned char u8;

// signed char (-128 -> 127)
typedef signed char s8;

// unsigned short (0 -> 65535)
typedef unsigned short u16;

// signed short (-32768 -> 32767)
typedef signed short s16;

// unsigned long (0 -> 4294967296)
typedef unsigned long u32;

// signed long (-2147483648 -> 2147483647)
typedef signed long s32;
typedef signed long long s64;

typedef float f32;
typedef double f64;

#define NULL 0
typedef enum{
    False,
    True
}Bool_t;

#define OK   1
#define NOK  0
#define NULL_POINTER  3
#define BUSY_FUNC     4

#endif // STD_TYPES_H_INCLUDED

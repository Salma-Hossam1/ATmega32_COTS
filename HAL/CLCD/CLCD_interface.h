#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_





void CLCD_voidSendCommand (u8 Copy_u8Command);

void CLCD_voidSendData (u8 Copy_u8Data);

void CLCD_voidInit (void);

void CLCD_voidSendString(const char* Copy_pcString);

void CLCD_voidGoToXY (u8 Copy_u8XPos , u8 Copy_u8YPos);

void CLCD_voidWriteSpecialCharacter(u8* Copy_pu8Pttern,u8 Copy_u8PatternNumber , u8 Copy_u8PosX,u8 Copy_u8PosY);

void CLCD_voidWriteNumber(s64 Copy_s64Number);

void CLCD_voidClear(void);

void CLCD_voidCheckCount(void);

#endif

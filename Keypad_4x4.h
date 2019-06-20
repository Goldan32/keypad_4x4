/*
Library:				4x4 keypad drive for STM32 MCUs
Written by:				Daniel Arany
Date written:				20/06/2019
Description:				The pins of the keypad must be set up in the user's code.
					Pin numbers (from right to left) are: OUT 0-3,IN 0-3.
					The input pins must be set to Pull-Down in configuration
					(without such option use external resistors ~1k-10k).
Functions:				Keypad_Init:		Initializes the library. A user defined variable
								must be passed with Keypad_WiresTypeDef type.
					Keypad_ReadKey:		Returns number of buttons pressed and sets 
								the bool array correctly.
					Keypad_GetNumber:	Returns the number (HEX) pressed as int.
					Keypad_GetCharacter:	Returns the character pressed as char.
*/

//Header includes
#include "stm32f4xx_hal.h"
#include <stdbool.h>

//Typedefs

typedef struct 
{
	GPIO_TypeDef* INPort[4];
	GPIO_TypeDef* OUTPort[4];
	uint16_t INPin[4];
	uint16_t OUTPin[4];

}Keypad_WiresTypeDef;

//Initializing the keypad
void Keypad_Init(Keypad_WiresTypeDef* userWires);

//modifies the bool array according to buttons pressed
int Keypad_ReadKey(bool* keys);

//return the only hex number pressed
int Keypad_GetNumber(bool* keys);

//returns the only character pressed
char Keypad_GetCharacter(bool* keys);



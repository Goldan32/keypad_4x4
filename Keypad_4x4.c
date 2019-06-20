#include "Keypad_4x4.h"

//Variables,constants
Keypad_WiresTypeDef wires;

int key_matrix_numbers[16]=
{
	1,2,3,10,
	4,5,6,11,
	7,8,9,12,
	14,0,15,13
};

char key_matrix_characters[16] =
{
	'1','2','3','A',
	'4','5','6','B',
	'7','8','9','C',
	'*','0','#','D'
};

void Keypad_Init(Keypad_WiresTypeDef* userWires)
{
	int i;
	wires = *userWires;
	for (i = 0; i < 4; i = i + 1)
	{
		HAL_GPIO_WritePin(wires.OUTPort[i], wires.OUTPin[i],GPIO_PIN_RESET);
	}
}

int Keypad_ReadKey(bool* keys)
{
	int i, j, counter=0;
	for (i = 0; i < 4; i = i + 1)
	{
		HAL_GPIO_WritePin(wires.OUTPort[i], wires.OUTPin[i], GPIO_PIN_SET);
		for (j = 0; j < 4; j = j + 1)
		{
			if ((HAL_GPIO_ReadPin(wires.INPort[j], wires.INPin[j])) == GPIO_PIN_SET)
			{
				counter++;
				keys[((3-j)*4)+(3-i)] = true;
			}
			else if ((HAL_GPIO_ReadPin(wires.INPort[j], wires.INPin[j])) == GPIO_PIN_RESET)
			{
				keys[((3-j)*4)+(3-i)] = false;
			}
		}
		HAL_GPIO_WritePin(wires.OUTPort[i], wires.OUTPin[i], GPIO_PIN_RESET);
	}
	return counter;
}

int Keypad_GetNumber(bool* keys)
{
	if(Keypad_ReadKey(keys)==1)
	{
		int x;
		for (x = 0; x < 16; x++)
		{
			if (keys[x] == true)
				break;
		}
		return key_matrix_numbers[x];
	}
	return -1;
}

char Keypad_GetCharacter(bool* keys)
{
	if (Keypad_ReadKey(keys) == 1)
	{
		int x;
		for (x = 0; x < 16; x++)
		{
			if (keys[x] == true)
				break;
		}
		return key_matrix_characters[x];
	}
	return '\0';
}

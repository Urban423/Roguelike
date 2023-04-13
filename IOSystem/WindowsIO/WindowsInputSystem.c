#include "WindowsInputSystem.h"
#include <windows.h>
#include <stdio.h>

void createWindowsKeyBoard(KeyBoardState* this)
{
	GetKeyState(0);
	GetKeyboardState(this->key_board_state);
	for(int i = 0; i < 256; i++)
	{
		if((this->key_board_state[i] & 0x8000) == 0x8000)
		{
			this->key_board_state[i] = 2;
		}
		else 
		{
			this->key_board_state[i] = 1;
		}
		this->old_key_board_state[i] = this->key_board_state[i];      
	}
}

void updateWindowsKeyBoard(KeyBoardState* this)
{    
	for (int i = 0; i < 256; i++)
    {       
		this->old_key_board_state[i] = this->key_board_state[i];       
    }
	GetKeyState(0);
	GetKeyboardState(this->key_board_state);
	for(int i = 0; i < 256; i++)
	{
		if((this->key_board_state[i] & 0x8000) == 0x8000)
		{
			this->key_board_state[i] = 2;
		}
		else 
		{
			this->key_board_state[i] = 1;
		}
	}
}

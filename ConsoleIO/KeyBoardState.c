#include "KeyBoardState.h"
#include <windows.h>
#include <stdio.h>


	char* key_board_state;
	char* old_key_board_state;

void CreateKeyBoard(KeyBoardState* this)
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
	key_board_state = this->key_board_state;
	old_key_board_state = this->old_key_board_state;
}

void UpdateKeyBoard(KeyBoardState* this)
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

char GetKey(char key_code)
{
	if(key_board_state[key_code] == old_key_board_state[key_code] && key_board_state[key_code] == 2)
	{
		return 1;
	}
	return 0;
}


char GetKeyDown(char key_code)
{
	if(key_board_state[key_code] != old_key_board_state[key_code] && key_board_state[key_code] == 2)
	{
		return 1;
	}
	return 0;
}


char GetKeyUp(char key_code)
{
	if(key_board_state[key_code] != old_key_board_state[key_code] && old_key_board_state[key_code] == 2)
	{
		return 1;
	}
	return 0;
}
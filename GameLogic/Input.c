#include "Input.h"

char* keyBoardState;
char* oldKeyBoardState;

char GetKey(char key_code)
{
	if(keyBoardState[key_code] == oldKeyBoardState[key_code] && keyBoardState[key_code] == 2)
	{
		return 1;
	}
	return 0;
}

char GetKeyDown(char key_code)
{
	if(keyBoardState[key_code] != oldKeyBoardState[key_code] && keyBoardState[key_code] == 2)
	{
		return 1;
	}
	return 0;
}

char GetKeyUp(char key_code)
{
	if(keyBoardState[key_code] != oldKeyBoardState[key_code] && oldKeyBoardState[key_code] == 2)
	{
		return 1;
	}
	return 0;
}
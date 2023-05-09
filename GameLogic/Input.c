#include "Input.h"


KeyCodes KeyCode;

void CreateKeyCode()
{
	KeyCode.A = 65;
	KeyCode.S = 83;
	KeyCode.D = 68;
	KeyCode.W = 87;
	KeyCode.Escape = 27;
}

char* keyBoardState;
char* oldKeyBoardState;

char setKeyBoard(char* keyBoardStatePointer, char* oldKeyBoardStatePointer)
{
	keyBoardState = keyBoardStatePointer;
	oldKeyBoardState = oldKeyBoardStatePointer;
	CreateKeyCode();
}

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
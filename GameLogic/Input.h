#pragma once
#include "GameMessages.h"

typedef struct KeyCodes
{
	char A;
	char S;
	char D;
	char W;
	char Escape;
}KeyCodes;

char setKeyBoard(char* keyBoardStatePointer, char* oldKeyBoardStatePointer);

char GetKey(char key_code);
char GetKeyDown(char key_code);
char GetKeyUp(char key_code);
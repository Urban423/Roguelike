#pragma once
#include "GameMessages.h"

char setKeyBoard(char* keyBoardStatePointer, char* oldKeyBoardStatePointer);

char GetKey(char key_code);
char GetKeyDown(char key_code);
char GetKeyUp(char key_code);
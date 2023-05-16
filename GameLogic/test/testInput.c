#include "testInput.h"
#include "Input.h"
#include <malloc.h>

extern char* keyBoardState;
extern char* oldKeyBoardState;

char testSetKeyBoard()
{
	char res = keyBoardState == 0 && oldKeyBoardState == 0;
	char* keyBoardState = (char*)malloc(1);
	char* oldKeyBoardState = (char*)malloc(1);
	
	setKeyBoard(keyBoardState, oldKeyBoardState);
	
	char res1 = keyBoardState != 0 && oldKeyBoardState != 0;
	if(res && res1)
	{
		return 0;
	}
	return 1;
}
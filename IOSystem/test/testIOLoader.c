#include "testIOLoader.h"
#define updateKeyBoard() 0

char test_createWindow(Renderer* renderer)
{
	return 0;
}

char test_updateWindow(Renderer* renderer)
{
	if(!updateKeyBoard())
	{
		return 1;
	}
	return 0;
}

char test_createKeyBoard(KeyBoardState* keyBoard)
{
	return 0;
}

char test_updateKeyBoard(KeyBoardState* keyBoard)
{
	return 0;
}
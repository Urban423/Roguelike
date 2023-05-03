#include "testIOLoader.h"
#define updateKeyBoard() 0

char test_createWindow()
{
	return 0;
}

char test_updateWindow()
{
	//char updateKeyBoard(KeyBoardState* keyBoard);
	if(!updateKeyBoard())
	{
		return 1;
	}
	return 0;
}

char test_createKeyBoard()
{
	return 0;
}

char test_updateKeyBoard()
{
	return 0;
}






char testShowError(){
	return 0;
}

char testShowMenu()
{
	return 0;
}
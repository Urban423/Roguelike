#include "IOLoader.h"

char createWindow(Renderer* renderer)
{
	#ifdef WIN32
		return createWindowsWindow(renderer);
	#elif defined __linux__
		return createLinuxWindow(renderer);
	#endif

}


char updateWindow(Renderer* renderer)
{
	#ifdef WIN32
		return updateWindowsWindow(renderer);
	#elif defined __linux__
		return updateLinuxWindow(renderer);
	#endif
}


char createKeyBoard(KeyBoardState* keyBoard)
{
	#ifdef WIN32
		createWindowsKeyBoard(keyBoard);
	#elif defined __linux__
		createLinuxKeyBoardState(keyBoard);
	#endif
	return 0;
}


char updateKeyBoard(KeyBoardState* keyBoard)
{
	#ifdef WIN32
		updateWindowsKeyBoard(keyBoard);
	#elif defined __linux__
		updateLinuxKeyBoardState(keyBoard);
	#endif
	return 0;
}
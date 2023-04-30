#ifndef _IOLOADER_H_
#define _IOLOADER_H_

#ifdef WIN32
	#include "../Window.h"
	#include "../WindowsInputSystem.h"
#elif defined __linux__
	#include "../LinuxWindow.h"
#endif

char test_createWindow(Renderer* renderer);
char test_updateWindow(Renderer* renderer);

char test_createKeyBoard(KeyBoardState* keyBoard);
char test_updateKeyBoard(KeyBoardState* keyBoard);

#endif
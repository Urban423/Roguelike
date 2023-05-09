#ifndef _IOLOADER_H_
#define _IOLOADER_H_

#ifdef WIN32
	#include "Window.h"
	#include "WindowsInputSystem.h"
#elif defined __linux__
	#include "LinuxWindow.h"
#endif

char createWindow(Renderer* renderer);
char updateWindow(Renderer* renderer, unsigned long time_of_begin);

char createKeyBoard(KeyBoardState* keyBoard);
char updateKeyBoard(KeyBoardState* keyBoard);

#endif
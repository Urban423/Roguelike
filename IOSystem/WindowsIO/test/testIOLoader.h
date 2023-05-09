#ifndef _IOLOADER_H_
#define _IOLOADER_H_

#ifdef WIN32
	#include "Window.h"
	#include "WindowsInputSystem.h"
#elif defined __linux__
	#include "LinuxWindow.h"
#endif

char test_createWindow();
char test_updateWindow();

char test_createKeyBoard();
char test_updateKeyBoard();



char testShowError();
char testShowMenu();

#endif
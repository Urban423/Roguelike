#pragma once

#ifdef WIN32
#include <Windows.h>
#include "Vector2.h"


typedef struct Renderer
{
	Buffer buffer;
	HWND hwnd;
	HBITMAP map;
	char* pointer;
	void* void_pointer;
}Renderer;

char createWindowsWindow(Renderer* renderer);
char updateWindowsWindow(Renderer* renderer);
char drawImage(Renderer* renderer);

#endif
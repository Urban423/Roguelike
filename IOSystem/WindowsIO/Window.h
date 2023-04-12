#pragma once

#ifdef WIN32
#include <Windows.h>
#include "Vector2.h"


typedef struct Renderer
{
	Buffer buffer;
	HWND hwnd;
}Renderer;

char createWindowsWindow(Renderer* renderer);
char updateWindowsWindow(Renderer* renderer);

#endif
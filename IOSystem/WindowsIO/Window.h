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

char createWindowsWindow(Renderer* renderer, int width, int height);
char updateWindowsWindow(Renderer* renderer);
char drawImage(Renderer* renderer);

Vector2 getSize(Renderer* renderer);

#endif
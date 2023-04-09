#pragma once
#include <Windows.h>

typedef struct Buffer
{
	unsigned int width;
	unsigned int height;
	char* buffer;
	HWND hwnd;
}Buffer;

char createWindow(Buffer* buffer);
char updateWindow(Buffer* buffer);
char setImage();
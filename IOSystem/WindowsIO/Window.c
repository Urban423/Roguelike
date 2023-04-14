#ifdef WIN32
#include "Window.h"
#include <stdio.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
		case WM_CREATE:
		{
			break;
		}
		case WM_SIZE:
		{
			break;
		}
		case WM_MOUSEWHEEL:
		{
			break;
		}
		case WM_MOVE:
		{
			break;
		}
		case WM_SETFOCUS:
		{
			break;
		}
		case WM_KILLFOCUS:
		{
			break;
		}
		case WM_POWERBROADCAST:
		{
			break;
		}
		case WM_DESTROY:
		{
			PostQuitMessage(0); 
			break;
		}

		default:
		
			return DefWindowProc(hwnd, msg, wparam, lparam);
	}
	return DefWindowProcA(hwnd, msg, wparam, lparam);
}

char createWindowsWindow(Renderer* renderer)
{
	WNDCLASS wcl;
	memset(&wcl, 0, sizeof(WNDCLASSA));
    wcl.cbClsExtra = 0;
    wcl.cbWndExtra = 0;
	wcl.lpszClassName = "Roguelike";
	wcl.lpfnWndProc = &WndProc;
	
	RegisterClass(&wcl);
	
	renderer->hwnd = CreateWindow(
	"Roguelike", "Roguelike", 
	WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
	renderer->buffer.width, renderer->buffer.height, NULL, NULL, NULL, NULL);
	
	ShowWindow(renderer->hwnd, SW_SHOWNORMAL);
	
	return 0;
}

char drawImage(Renderer* renderer)
{
	HDC hdc = GetDC(renderer->hwnd);
	
	char temp = 0;
	int index = 0;
	for(int i = 0; i < renderer->buffer.height * renderer->buffer.width; i++)
	{
		temp = renderer->buffer.buffer[index];
		renderer->buffer.buffer[index] = renderer->buffer.buffer[index + 2];
		renderer->buffer.buffer[index + 2] = temp;
		index+=4;
	}
	Sleep(1);
	HBITMAP map = CreateBitmap(renderer->buffer.width, renderer->buffer.height,
	1, 8 * 4, renderer->buffer.buffer);


	HDC src = CreateCompatibleDC(hdc);
	SelectObject(src, map);
	BitBlt(hdc, 0, 0, renderer->buffer.width, renderer->buffer.height, src, 0, 0, SRCCOPY);
	DeleteDC(src);
	DeleteObject(map);
	ReleaseDC(renderer->hwnd, hdc);
}

char updateWindowsWindow(Renderer* renderer)
{
	MSG msg;
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)
	{
		if(msg.message == WM_QUIT)
		{
			return 1;
		}
		DispatchMessage(&msg);
	}
	drawImage(renderer);
	
	return 0;
}
#endif
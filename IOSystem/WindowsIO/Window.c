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
		{			break;
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

char createWindowsWindow(Buffer* buffer, HWND* this)
{
	WNDCLASS wcl;
	memset(&wcl, 0, sizeof(WNDCLASSA));
    wcl.cbClsExtra = 0;
    wcl.cbWndExtra = 0;
	wcl.lpszClassName = "Roguelike";
	wcl.lpfnWndProc = &DefWindowProcA;
	
	RegisterClass(&wcl);
	
	*this = CreateWindow(
	"Roguelike", "Roguelike", 
	WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
	buffer->width, buffer->height, NULL, NULL, NULL, NULL);
	
	ShowWindow(*this, SW_SHOWNORMAL);
	
	return 0;
}

char updateWindow(Buffer* buffer, HWND* this)
{
	MSG msg;
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)
	{
		DispatchMessage(&msg);
	}

	
	HDC hdc = GetDC(*this);
	
	HBITMAP map = CreateBitmap(buffer->width, buffer->height,
	1, 8 * 4, buffer->buffer);


	HDC src = CreateCompatibleDC(hdc);
	SelectObject(src, map);
	BitBlt(hdc, 0, 0, buffer->width, buffer->height, src, 0, 0, SRCCOPY);
	DeleteDC(src);
	DeleteObject(map);
	ReleaseDC(*this, hdc);
	
	
	if(msg.message == 161 && msg.wParam == 20)
	{
		return 1;
	}
	
	return 0;
}
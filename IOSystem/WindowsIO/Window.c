#ifdef WIN32
#include "Window.h"
#include <stdio.h>
#include <unistd.h>

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

char createWindowsWindow(Renderer* renderer, int width, int height)
{
	WNDCLASSEX wcl;
	memset(&wcl, 0, sizeof(WNDCLASSEX));
	wcl.cbSize = sizeof(WNDCLASSEX);
    wcl.cbClsExtra = 0;
    wcl.cbWndExtra = 0;
	wcl.hCursor = LoadCursor (NULL, IDC_ARROW);
	wcl.lpszClassName = "Roguelike";
	wcl.lpfnWndProc = &WndProc;
	//wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	//wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	//wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wcl.hInstance = 0;
	wcl.style = 0;
	
	
	int max_width = GetSystemMetrics(SM_CXSCREEN);
	int max_height= GetSystemMetrics(SM_CYSCREEN);
	if(width > max_width)
	{
		width = max_width;
	}
	if(height > max_height)
	{
		height = max_height;
	}
	
	RegisterClassEx(&wcl);
	
	renderer->hwnd = CreateWindowEx(WS_EX_APPWINDOW,
	"Roguelike", "Roguelike", 
	WS_POPUP | WS_EX_TOPMOST,
	CW_USEDEFAULT, CW_USEDEFAULT,
	width, height, NULL, NULL, NULL, NULL);
	
	ShowWindow(renderer->hwnd, SW_SHOWNORMAL);
	
	renderer->map = CreateBitmap(
	width, height,
	1, 8 * 4, renderer->buffer.buffer);
	
	return 0;
}

Vector2 getSize(Renderer* renderer)
{
	RECT rect;
    GetWindowRect(renderer->hwnd, &rect);
	
	Vector2 ret = {rect.right - rect.left, rect.bottom - rect.top};
	return ret;
}

char drawImage(Renderer* renderer)
{
	HDC hdc = GetDC(renderer->hwnd);
	//HBITMAP map = CreateBitmap(renderer->buffer.width, renderer->buffer.height, 1, 8 * 4, renderer->buffer.buffer);

	SetBitmapBits(renderer->map, renderer->buffer.height * 4 * renderer->buffer.width, renderer->buffer.buffer);
	HDC src = CreateCompatibleDC(hdc);
	SelectObject(src, renderer->map);
	BitBlt(hdc, 0, 0, renderer->buffer.width, renderer->buffer.height, src, 0, 0, SRCCOPY);
	DeleteDC(src);
	//DeleteObject(map);
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

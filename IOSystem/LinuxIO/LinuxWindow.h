#pragma onces


#ifdef __linux__
#include <X11/Xlib.h>
#include "Vector2.h"

struct Renderer
{
	Buffer buffer;
	Window window;
	Display* display;
};

char createLinuxWindow(Renderer* renderer);
char updateLinuxWindow(Renderer* renderer);


#endif
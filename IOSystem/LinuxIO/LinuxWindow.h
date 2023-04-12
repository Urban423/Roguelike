#pragma onces


#ifdef __linux__
#include <X11/Xlib.h>

typedef struct Buffer
{
    unsigned int width;
    unsigned int height;
    char* buffer;
    Window window;
    Display* display;
} Buffer;

char createWindow(Buffer* buffer);
char updateWindow(Buffer* buffer);


#endif
#ifdef __linux__
#include "LinuxWindow.h"
#include <stdio.h>


char createLinuxWindow(Renderer* renderer)
{
    buffer->display = XOpenDisplay(NULL);
    if (buffer->display == NULL) {
        return 1;
    }

    int screen = DefaultScreen(buffer->display);
    buffer->window = XCreateSimpleWindow(
        buffer->display, RootWindow(buffer->display, screen),
        0, 0, buffer->width, buffer->height, 0, BlackPixel(buffer->display, screen), WhitePixel(buffer->display, screen)
    );
    XSelectInput(buffer->display, buffer->window, ExposureMask | KeyPressMask);
    XMapWindow(buffer->display, buffer->window);

    return 0;
}

char updateLinuxWindow(Renderer* renderer)
{
    XEvent event;
    while (XPending(buffer->display) > 0) {
        XNextEvent(buffer->display, &event);
        switch (event.type) {
        case Expose:
            // Отрисовка содержимого окна
            XSetForeground(buffer->display, DefaultGC(buffer->display, DefaultScreen(buffer->display)), 0xFF9999);
            XFillRectangle(buffer->display, buffer->window, DefaultGC(buffer->display, DefaultScreen(buffer->display)), 0, 0, buffer->width, buffer->height);
            break;
        case KeyPress:
            printf("Нажата клавиша с кодом %d\n", event.xkey.keycode);
            break;
        }
    }

    return 0;
}

#endif
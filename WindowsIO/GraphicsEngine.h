#pragma once
#include "Window.h"
#include "Object.h"

void DrawLine(Buffer* buffer,
int x1, int y1, 
int x2, int y2,
char r, char g, char b);

void BufferConstructor(Buffer* buffer, unsigned int width, unsigned int height, char sprite);
void BufferClear(Buffer* buffer, char r, char g, char b);
void BufferDrawObject(Buffer* buffer, Transfrom transform, char r, char g, char b);
char BufferDraw(Buffer* buffer);


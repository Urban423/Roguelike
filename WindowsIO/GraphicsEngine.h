#pragma once
#include "Window.h"
#include "Object.h"
#include "Matrix3x3.h"
#include "VertexMesh.h"
#include "Color.h"

void DrawLine(Buffer* buffer,
int x1, int y1, 
int x2, int y2,
char r, char g, char b);

void DrawTriangle(Buffer* buffer, 
int x1, int y1, 
int x2, int y2, 
int x3, int y3,
Color color1,
Color color2,
Color color3);

void BufferConstructor(Buffer* buffer, unsigned int width, unsigned int height, char sprite);
void BufferClear(Buffer* buffer, char r, char g, char b);
void BufferDrawObject(Buffer* buffer, Transfrom transform, VertexMesh* mesh, char r, char g, char b, Matrix3x3 camera);
char BufferDraw(Buffer* buffer);

#pragma once
#include <Vector2.h>
#include "Matrix3x3.h"
#include "VertexMesh.h"
#include "Color.h"
#include "Texture.h"

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

void DrawTriangleByTexture(Buffer* buffer, 
int x1, int y1, 
int x2, int y2, 
int x3, int y3,
Texture* texture, 
Vector2 uv1,
Vector2 uv2,
Vector2 uv3);

void BufferConstructor(Buffer* buffer, unsigned int width, unsigned int height);
void BufferClear(Buffer* buffer, char r, char g, char b);
void BufferDrawObject(Buffer* buffer, Matrix3x3 world_pos, VertexMesh* mesh, Texture* texture);
void BufferDrawText(Buffer* buffer, Matrix3x3 world_pos, VertexMesh* mesh, Texture* texture, char* text, unsigned int text_size);


void BufferDrawObject1(Buffer* buffer, Transfrom transform, VertexMesh* mesh, char r, char g, char b, Matrix3x3 camera);
void SetImage(Buffer* buffer, Texture* texture);

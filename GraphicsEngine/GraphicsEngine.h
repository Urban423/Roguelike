#pragma once
#include <Vector2.h>
#include "Matrix3x3.h"
#include "VertexMesh.h"
#include "Color.h"
#include "Texture.h"

void BufferConstructor(Buffer* buffer, unsigned int width, unsigned int height);
void BufferClear(Buffer* buffer, char r, char g, char b);
void BufferDrawObject(Buffer* buffer, Matrix3x3* world_pos, Matrix3x3* cam_view, Matrix3x3* cam_proj, VertexMesh* mesh, Texture* texture);
void BufferDrawText(  Buffer* buffer, Matrix3x3* world_pos, Matrix3x3* cam_view, Matrix3x3* cam_proj, VertexMesh* mesh, Texture* texture, char* text, unsigned int text_size);


void SetImage(Buffer* buffer, Texture* texture);

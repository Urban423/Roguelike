#pragma once
#include "Vector2.h"
#include "Texture.h"

void DrawTriangleByTexture(Buffer* buffer, 
Vector2 p1, Vector2 p2, Vector2 p3,
Texture* texture, 
Vector2 uv1, Vector2 uv2, Vector2 uv3);

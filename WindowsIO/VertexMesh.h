#pragma once
#include "Vector2.h"

typedef struct VertexMesh
{
	Vector2* verticles;
	unsigned int verticles_size;
	unsigned int* faces;
	unsigned int faces_size;
}VertexMesh;

void CreateVertexMeshInside(VertexMesh* this,
Vector2* verticles, unsigned int verticles_size,
unsigned int* faces, unsigned int faces_size);

void CreateVertexMeshFromFile(VertexMesh* this, const char* filename);


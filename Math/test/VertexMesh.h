#pragma once
#include "Vector2.h"

typedef struct VertexMesh
{
	Vector2* verticles;
	unsigned int verticles_size;
	
	unsigned int* faces;
	unsigned int faces_size;
	
	Vector2* UV_map;
	unsigned int UV_map_size;
}VertexMesh;

void CreateVertexMeshInside(VertexMesh* this,
Vector2* verticles, unsigned int verticles_size,
unsigned int* faces, unsigned int faces_size,
Vector2* UV_map, unsigned int UV_map_size);

void CreateVertexMeshFromFile(VertexMesh* this, const char* filename);
void CreateVertexBox(VertexMesh* this);


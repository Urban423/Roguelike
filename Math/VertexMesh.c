#include "VertexMesh.h"
#include <malloc.h>
#include <string.h>

void CreateVertexMeshInside(VertexMesh* this,
Vector2* verticles, unsigned int verticles_size,
unsigned int* faces, unsigned int faces_size,
Vector2* UV_map, unsigned int UV_map_size)
{
	this->verticles_size = verticles_size;
	this->verticles = (Vector2*)malloc(sizeof(Vector2) * verticles_size);
	this->faces_size = faces_size;
	this->faces = (unsigned int*)malloc(sizeof(unsigned int) * faces_size);
	this->UV_map_size = UV_map_size;
	this->UV_map = (Vector2*)malloc(sizeof(Vector2) * UV_map_size);
	
	memcpy(this->verticles, verticles, verticles_size * sizeof(Vector2));
	memcpy(this->faces, faces, faces_size * sizeof(unsigned int));
	memcpy(this->UV_map, UV_map, UV_map_size * sizeof(Vector2));
}

void CreateVertexMeshFromFile(VertexMesh* this, const char* filename)
{
	this->verticles_size = 4;
	this->verticles = (Vector2*)malloc(sizeof(Vector2) * this->verticles_size);
	this->faces_size = 2 * 3;
	this->faces = (unsigned int*)malloc(sizeof(unsigned int) * this->faces_size );
	this->UV_map_size = 4;
	this->UV_map = (Vector2*)malloc(sizeof(Vector2) * this->UV_map_size);
	
	CreateVector2(&this->verticles[0], -0.5f,  0.5f);
	CreateVector2(&this->verticles[1],  0.5f,  0.5f);
	CreateVector2(&this->verticles[2],  0.5f, -0.5f);
	CreateVector2(&this->verticles[3], -0.5f, -0.5f);
	
	CreateVector2(&this->UV_map[0], 0, 1);
	CreateVector2(&this->UV_map[1], 1, 1);
	CreateVector2(&this->UV_map[2], 1, 0);
	CreateVector2(&this->UV_map[3], 0, 0);
	
	this->faces[0] = 0;
	this->faces[1] = 1;
	this->faces[2] = 2;
	
	this->faces[3] = 0;
	this->faces[4] = 2;
	this->faces[5] = 3;
}

void CreateVertexBox(VertexMesh* this)
{
	this->verticles_size = 4;
	this->verticles = (Vector2*)malloc(sizeof(Vector2) * this->verticles_size);
	this->faces_size = 2 * 3;
	this->faces = (unsigned int*)malloc(sizeof(unsigned int) * this->faces_size );
	this->UV_map_size = 4;
	this->UV_map = (Vector2*)malloc(sizeof(Vector2) * this->UV_map_size);
	
	CreateVector2(&this->verticles[0], -0.5f,  0.5f);
	CreateVector2(&this->verticles[1],  0.5f,  0.5f);
	CreateVector2(&this->verticles[2],  0.5f, -0.5f);
	CreateVector2(&this->verticles[3], -0.5f, -0.5f);
	
	CreateVector2(&this->UV_map[0], 0, 1);
	CreateVector2(&this->UV_map[1], 1, 1);
	CreateVector2(&this->UV_map[2], 1, 0);
	CreateVector2(&this->UV_map[3], 0, 0);
	
	this->faces[0] = 0;
	this->faces[1] = 1;
	this->faces[2] = 2;
	
	this->faces[3] = 0;
	this->faces[4] = 2;
	this->faces[5] = 3;
}
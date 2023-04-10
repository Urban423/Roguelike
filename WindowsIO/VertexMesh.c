#include "VertexMesh.h"
#include <malloc.h>
#include <string.h>

void CreateVertexMeshInside(VertexMesh* this,
Vector2* verticles, unsigned int verticles_size,
unsigned int* faces, unsigned int faces_size)
{
	this->verticles_size = verticles_size;
	this->verticles = (Vector2*)malloc(sizeof(Vector2) * verticles_size);
	this->faces_size = faces_size;
	this->faces = (unsigned int*)malloc(sizeof(unsigned int) * faces_size);
	
	memcpy(this->verticles, verticles, verticles_size);
	memcpy(this->faces, faces, faces_size);
}

void CreateVertexMeshFromFile(VertexMesh* this, const char* filename)
{
	this->verticles = (Vector2*)malloc(sizeof(Vector2) * 4);
	this->verticles_size = 4;
	this->faces = (unsigned int*)malloc(sizeof(unsigned int) * 2 * 3);
	this->faces_size = 2 * 3;
	
	CreateVector2(&this->verticles[0], -0.5f,  0.5f);
	CreateVector2(&this->verticles[1],  0.5f,  0.5f);
	CreateVector2(&this->verticles[2],  0.5f, -0.5f);
	CreateVector2(&this->verticles[3], -0.5f, -0.5f);
	this->faces[0] = 0;
	this->faces[1] = 1;
	this->faces[2] = 2;
	
	this->faces[3] = 0;
	this->faces[4] = 2;
	this->faces[5] = 3;
}
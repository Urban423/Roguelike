#pragma once
#include "ObjectHelper.h"
#include "Matrix3x3.h"
#include "VertexMesh.h"
#include "Texture.h"
#include "IOLoader.h"

typedef struct Scene
{
	ObjectManager objectManager;
	
	KeyBoardState keyBoard;
	Renderer renderer;
	char is_running;
	
	Matrix3x3 world_cam;
	Matrix3x3 view_proj;
	
	Transfrom* camera_tf;
	
	VertexMesh meshes[5];
	unsigned int meshes_size;
	
	Texture alphabet[36];
	Texture textures[20];
	unsigned int textures_size;
}Scene;

void onCreate(Scene* scene);
void onUpdate(Scene* scene);
char render(Scene* scene);
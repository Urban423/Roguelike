#include "Scene.h"
#include "ObjectHelper.h"
#include "Vector2.h"
#include <math.h>
#include "Physics.h"
#include "BMPImage.h"
#include "GraphicsEngine.h"
#include "Input.h"
#include "SceneLoader.h"
#include <stdio.h>
includeTime

void onCreate(Scene* scene)
{
	BufferConstructor(&scene->renderer.buffer, 640, 480);
	createWindow(&scene->renderer);
	createKeyBoard(&(scene->keyBoard));
	setKeyBoard(scene->keyBoard.key_board_state, scene->keyBoard.old_key_board_state);
	scene->is_running = 1;
	scene->time = 0;
	CreateVertexBox(&scene->meshes[0]);
	scene->meshes_size = 5;
	scene->textures_size = 5;
	ReadBMPFile(&scene->textures[0], "./Assets/0012.bmp");
	ReadBMPFile(&scene->textures[1], "./Assets/Mercury.bmp");
	ReadBMPFile(&scene->textures[2], "./Assets/Wall.bmp");
	ReadBMPFile(&scene->textures[3], "./Assets/Roguelike.bmp");
	ReadBMPFile(&scene->textures[4], "./Assets/WhiteBlock.bmp");
	ReadBMPFile(&scene->textures[5], "./Assets/BlueBlock.bmp");
	ReadBMPFile(&scene->textures[6], "./Assets/Exit.bmp");
	ReadBMPFile(&scene->textures[7], "./Assets/Statistic.bmp");
	ReadBMPFile(&scene->textures[8], "./Assets/NewGame.bmp");
	
	const char* alphabetDir = "./Asstets/alphabet/A.bmp";
	int size = 0;
	while(1)
	{
		if(alphabetDir[size] == 0)
		{
			break;
		}
		size++;
	}
	int index = 0;
	char* alDir = (char*)malloc(size  + 1);
	for(int i = 0; i < size; i++)
	{
		alDir[i] = alphabetDir[i];
	}
	alDir[size] = 0;
	for(int i = 0; i < 26; i++)
	{
		alDir[19] = 65 + i;
		ReadBMPFile(&scene->alphabet[index], alDir);
		index++;
	}
	for(int i = 0; i < 10; i++)
	{
		alDir[19] = 48 + i;
		ReadBMPFile(&scene->alphabet[index], alDir);
		index++;
	}
	
	memset(&scene->objectManager, 0, sizeof(ObjectManager));
	CreateSceneMenu(scene);
	scene->camera_tf = &scene->objectManager.list->object->transform;
	CreateTime(&Time);
	setOrthoLH(&scene->view_proj, scene->renderer.buffer.width, scene->renderer.buffer.height, 10, 40);
}

void UpdateCamera(Scene* scene, Transfrom* tf)
{
	Matrix3x3 m_view, temp;
	setIdentity(&m_view);
	SetRotation(&m_view, tf->rotation);


	setIdentity(&temp);
	setTranslation(&temp, tf->position);
	m_view = MultipleMatrixMatrix(m_view, temp);
	
	scene->world_cam = inverse(m_view);
}

void onUpdate(Scene* scene)
{
	UpdateTime(&Time);
	scene->time += 1.1f;
	updateKeyBoard(&scene->keyBoard);
	
	Object* obj;
	ObjectList* list = scene->objectManager.list;
	
	for(int i = 0; i < scene->objectManager.size; i++)
	{
		obj = list->object;
		list = list->next;
		UpdateObject(obj);
	}
	
	CalculatePhysic(&scene->objectManager);
	UpdateCamera(scene, scene->camera_tf);
	
	if(render(scene))
	{
		scene->is_running = 0;
	}
};


char render(Scene* scene)
{
	BufferClear(&scene->renderer.buffer, 255, 0, 0);
	
	TextMesh* text = NULL;
	MeshRenderer* mesh = NULL;
	Object* obj;
	ObjectList* list = scene->objectManager.list;
	Matrix3x3 temp;
	
	for(int i = 0; i < scene->objectManager.size; i++)
	{
		obj = list->object;
		list = list->next;
		ProcessWorldPos(obj);
		temp = MultipleMatrixMatrix(obj->world_pos, scene->world_cam);
		temp = MultipleMatrixMatrix(temp, scene->view_proj);
		
		TEMPLATE(GetComponent, MeshRenderer)(obj, &mesh);
		if(mesh == NULL || mesh->inherited_class.enabled == 0) 
		{ 
			continue;
		}
		
		BufferDrawObject(&scene->renderer.buffer, temp, &scene->meshes[0], &scene->textures[mesh->textureNumber]);
	}
	
	//SetImage(&scene->renderer.buffer, &scene->textures[0]);
	
	if(updateWindow(&scene->renderer))
	{
		return 1;
	}
	return 0;
}

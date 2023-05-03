#include "Scene.h"
#include "ObjectHelper.h"
#include "Vector2.h"
#include <math.h>
#include "Physics.h"
#include "BMPImage.h"
#include "GraphicsEngine.h"
#include "Input.h"
#include "SceneLoader.h"
#include "GameMessages.h"
#include <stdio.h>
includeTime

void onCreate(Scene* scene)
{
	CreateMessageList();
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
	ReadBMPFile(&scene->textures[6], "./Assets\\Exit.bmp");
	ReadBMPFile(&scene->textures[7], "./Assets/Statistic.bmp");
	ReadBMPFile(&scene->textures[8], "./Assets/NewGame.bmp");
	ReadBMPFile(&scene->textures[9], "./Assets/Statistic.bmp");
	ReadBMPFile(&scene->textures[10], "./Assets/RedBlock.bmp");
	ReadBMPFile(&scene->textures[11], "./Assets/Pause.bmp");
	ReadBMPFile(&scene->textures[12], "./Assets/Quit.bmp");
	ReadBMPFile(&scene->textures[13], "./Assets/Continue.bmp");
	
	
	const char* alphabetDir = "./Assets\\alphabet\\A.bmp";
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
		alDir[18] = 65 + i;
		ReadBMPFile(&scene->alphabet[index], alDir);
		index++;
	}
	for(int i = 0; i < 10; i++)
	{
		alDir[18] = 48 + i;
		ReadBMPFile(&scene->alphabet[index], alDir);
		index++;
	}
	
	memset(&scene->objectManager, 0, sizeof(ObjectManager));
	CreateSceneMenu(scene);
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
	char galka = 0;
	
	for(int i = 0; i < scene->objectManager.size; i++)
	{
		obj = list->object;
		list = list->next;
		if(galka == 1)
		{
			if(obj->parent == NULL)
			{
				galka = 0;
			}
			continue;
		}
		if(obj->enabled == 0)
		{
			galka = 1;
			continue;
		}
		UpdateObject(obj);
	}
	
	CalculatePhysic(&scene->objectManager);
	UpdateCamera(scene, scene->camera_tf);
	
	char msg;
	while(1)
	{
		msg = getFirstMessageWithDelete();
		if(msg == 0)
		{
			break;
		}
		
		if(msg == 1)
		{
			scene->is_running = 0;
			return;
		}
		
		if(msg == 2)
		{
			CreateSceneMenu(scene);
			continue;
		}
		
		if(msg == 3)
		{
			CreateSceneGame(scene);
			continue;
		}
	}
	
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
	char galka = 0;
	
	for(int i = 0; i < scene->objectManager.size; i++)
	{
		obj = list->object;
		list = list->next;
		if(galka == 1)
		{
			if(obj->parent == NULL)
			{
				galka = 0;
			}
			continue;
		}
		if(obj->enabled == 0)
		{
			galka = 1;
			continue;
		}
		ProcessWorldPos(obj);
		temp = MultipleMatrixMatrix(obj->world_pos, scene->world_cam);
		temp = MultipleMatrixMatrix(temp, scene->view_proj);
		
		TEMPLATE(GetComponent, MeshRenderer)(obj, &mesh);
		if((mesh == NULL || mesh->inherited_class.enabled == 0) == 0) 
		{ 
			BufferDrawObject(&scene->renderer.buffer, temp, &scene->meshes[0], &scene->textures[mesh->textureNumber]);
		}
		
		TEMPLATE(GetComponent, TextMesh)(obj, &text);
		if((text == NULL || text->inherited_class.enabled == 0) == 0) 
		{ 
			BufferDrawText(&scene->renderer.buffer, temp, &scene->meshes[0], (Texture*)&scene->alphabet, text->text, text->size);
		}
	}
	
	//SetImage(&scene->renderer.buffer, &scene->textures[0]);
	
	if(updateWindow(&scene->renderer))
	{
		return 1;
	}
	return 0;
}

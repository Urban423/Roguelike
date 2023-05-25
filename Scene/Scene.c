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
#include <statistic.h>
includeTime

void onCreate(Scene* scene)
{
	CreateMessageList();
	createWindow(&scene->renderer, 10800, 5400);
	Vector2 windowSize = getSize(&scene->renderer);
	BufferConstructor(&scene->renderer.buffer, windowSize.x, windowSize.y);
	
	createKeyBoard(&(scene->keyBoard));
	setKeyBoard(scene->keyBoard.key_board_state, scene->keyBoard.old_key_board_state);
	scene->is_running = 1;
	CreateVertexBox(&scene->meshes[0]);
	scene->meshes_size = 5;
	scene->textures_size = 22;
	//scene->textures = (Texture*)malloc(sizeof(Texture) * scene->textures_size);
	ReadBMPFile(&scene->textures[0], "./Assets/0012.bmp");
	ReadBMPFile(&scene->textures[1], "./Assets/Door.bmp");
	ReadBMPFile(&scene->textures[2], "./Assets/Wall.bmp");
	ReadBMPFile(&scene->textures[3], "./Assets/Roguelike.bmp");
	ReadBMPFile(&scene->textures[4], "./Assets/WhiteBlock.bmp");
	ReadBMPFile(&scene->textures[5], "./Assets/BlueBlock.bmp");
	ReadBMPFile(&scene->textures[6], "./Assets\\Exit.bmp");
	ReadBMPFile(&scene->textures[7], "./Assets/Statistic.bmp");
	ReadBMPFile(&scene->textures[8], "./Assets/NewGame.bmp");
	ReadBMPFile(&scene->textures[9], "./Assets/heart.bmp");
	ReadBMPFile(&scene->textures[10], "./Assets/RedBlock.bmp");
	ReadBMPFile(&scene->textures[11], "./Assets/Pause.bmp");
	ReadBMPFile(&scene->textures[12], "./Assets/Quit.bmp");
	ReadBMPFile(&scene->textures[13], "./Assets/Continue.bmp");
	ReadBMPFile(&scene->textures[14], "./Assets/YouWin.bmp");
	ReadBMPFile(&scene->textures[15], "./Assets/YourScore.bmp");
	ReadBMPFile(&scene->textures[16], "./Assets/WriteYourName.bmp");
	ReadBMPFile(&scene->textures[17], "./Assets/Coin.bmp");
	ReadBMPFile(&scene->textures[18], "./Assets/Pain.bmp");
	ReadBMPFile(&scene->textures[19], "./Assets/uLose.bmp");
	ReadBMPFile(&scene->textures[20], "./Assets/key.bmp");
	ReadBMPFile(&scene->textures[21], "./Assets/ghost2.bmp");
	//ReadBMPFile(&scene->textures[22], "./Assets/key.bmp");
	
	
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
	
	
	//SaveStatistic("Leo: 30000\n", "./Assets/statistic.txt");
	memset(&scene->objectManager, 0, sizeof(ObjectManager));
	CreateSceneMenu(scene);
	CreateTime(&Time);
	setOrthoLH(&scene->view_proj, scene->renderer.buffer.width, scene->renderer.buffer.height, 57, 80);
}

void UpdateCamera(Scene* scene, Transfrom* tf)
{
	Matrix3x3 m_view, temp;
	setIdentity(&m_view);


	setIdentity(&temp);
	setTranslation(&temp, tf->position);
	m_view = MultipleMatrixMatrix(m_view, temp);
	
	scene->world_cam = inverse(m_view);
}

void onUpdate(Scene* scene)
{
	UpdateTime(&Time);
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
			else{
				continue;
			}
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
	BufferClear(&scene->renderer.buffer, 0, 0, 0);

	TextMesh* text = NULL;
	MeshRenderer* mesh = NULL;
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
			else{
				continue;
			}
		}
		if(obj->enabled == 0)
		{
			galka = 1;
			continue;
		}
		ProcessWorldPos(obj);
		
		TEMPLATE(GetComponent, MeshRenderer)(obj, &mesh);
		if((mesh == NULL || mesh->inherited_class.enabled == 0) == 0) 
		{ 
			BufferDrawObject(&scene->renderer.buffer, 
			&obj->world_pos,
			&scene->world_cam,
			&scene->view_proj,
			&scene->meshes[0], &scene->textures[mesh->textureNumber]);
		}
		
		TEMPLATE(GetComponent, TextMesh)(obj, &text);
		if((text == NULL || text->inherited_class.enabled == 0) == 0) 
		{ 
			BufferDrawText(&scene->renderer.buffer,
			&obj->world_pos,
			&scene->world_cam,
			&scene->view_proj,
			&scene->meshes[0], (Texture*)&scene->alphabet, text->text, text->size);
		}
	}
	
	//SetImage(&scene->renderer.buffer, &scene->textures[1]);
	
	if(updateWindow(&scene->renderer, Time.old_delta))
	{
		return 1;
	}
	return 0;
}

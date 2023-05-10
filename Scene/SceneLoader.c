#include "SceneLoader.h"
#include <ObjectHelper.h>
#include "LevelGenerator.h"
#include <malloc.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

void CreateSceneMenu(Scene* scene)
{
	ClearManager(&scene->objectManager);
	Object* object;
	Object* parent;
	Object* switcherObj;
	
	
	Vector2 vect;
	CreateVector2(&vect, 0, 0);
	Vector2 sca;
	CreateVector2(&sca, 2, 2);
	
	TextMesh* textMesh;
	MeshRenderer* meshRenderer;
	Switcher* switcher;
	
	CreateVector2(&sca, 88, 44);
	object = (Object*)malloc(sizeof(Object));
	CreateVector2(&vect, 0, 0);
	ObjectConstructor(object, vect, sca);
	TEMPLATE(AddComponent, MeshRenderer)(object, &meshRenderer);
	AddObject(&scene->objectManager, object);
	meshRenderer->textureNumber = 10;
	
	
	object = (Object*)malloc(sizeof(Object));
	ObjectConstructor(object, vect, sca);
	AddObject(&scene->objectManager, object);
	scene->camera_tf = &object->transform;
	switcherObj = object;
	
	CreateVector2(&sca, 33, 5);
	CreateVector2(&vect, -7, -9 + 4 * 4);
	object = (Object*)malloc(sizeof(Object));
	ObjectConstructor(object, vect, sca);
	TEMPLATE(AddComponent, MeshRenderer)(object, &meshRenderer);
	AddObject(&scene->objectManager, object);
	meshRenderer->textureNumber = 3;
	
	for(int i = 0; i < 3; i++)
	{
		CreateVector2(&sca, 10, 3);
		object = (Object*)malloc(sizeof(Object));
		CreateVector2(&vect, 0, -7 + i * 5);
		ObjectConstructor(object, vect, sca);
		TEMPLATE(AddComponent, MeshRenderer)(object, &meshRenderer);
		AddObject(&scene->objectManager, object);
		meshRenderer->textureNumber = 4;
	}
	
	CreateVector2(&sca, 10, 3);
	object = (Object*)malloc(sizeof(Object));
	ObjectConstructor(object, vect, sca);
	TEMPLATE(AddComponent, MeshRenderer)(object, &meshRenderer);
	TEMPLATE(AddComponent, Switcher)(object, &switcher);
	AddObject(&scene->objectManager, object);
	meshRenderer->textureNumber = 5;
	
	for(int i = 0; i < 3; i++)
	{
		CreateVector2(&sca, 22, 3);
		object = (Object*)malloc(sizeof(Object));
		CreateVector2(&vect, 0, -7 + i * 5);
		ObjectConstructor(object, vect, sca);
		TEMPLATE(AddComponent, MeshRenderer)(object, &meshRenderer);
		AddObject(&scene->objectManager, object);
		meshRenderer->textureNumber = 6 + i;
	}
	
	CreateVector2(&sca, 30, 30);
	CreateVector2(&vect, 0, 0);
	object = (Object*)malloc(sizeof(Object));
	ObjectConstructor(object, vect, sca);
	TEMPLATE(AddComponent, MeshRenderer)(object, &meshRenderer);
	switcher->statistic = object;
	AddObject(&scene->objectManager, object);
	meshRenderer->textureNumber = 4;
	object->enabled = 0;
	parent = object;
	
	CreateVector2(&sca, 22, 3);
	CreateVector2(&vect, 0, 9);
	object = (Object*)malloc(sizeof(Object));
	ObjectConstructor(object, vect, sca);
	TEMPLATE(AddComponent, MeshRenderer)(object, &meshRenderer);
	AddObject(&scene->objectManager, object);
	meshRenderer->textureNumber = 9;
	object->parent = parent;
	
	CreateVector2(&sca, 3, 3);
	CreateVector2(&vect, -13, 7);
	object = (Object*)malloc(sizeof(Object));
	ObjectConstructor(object, vect, sca);
	TEMPLATE(AddComponent, TextMesh)(object, &textMesh);
	AddObject(&scene->objectManager, object);
	SetText(textMesh, "Danya: 109\nTima: 0\nLeo: 30000\nIvanich: 132", 45);
	object->parent = parent;
}





void CreateSceneGame(Scene* scene)
{
	ClearManager(&scene->objectManager);
	
	Object* object;
	Object* parent;
	Object* cam;
	Object* exit;
	
	
	Vector2 vect;
	CreateVector2(&vect, 0, 0);
	Vector2 sca;
	CreateVector2(&sca, 2, 2);
	
	TextMesh* textMesh;
	Pause* pause;
	ExitTrigger* exitTrigger;
	MeshRenderer* meshRenderer;
	Player* pl;
	BoxCollider* box;
	Rigidbody* rigidbody;
	TextMesh* text;
	
	CreateVector2(&sca, 88, 44);
	object = (Object*)malloc(sizeof(Object));
	CreateVector2(&vect, 0, 0);
	ObjectConstructor(object, vect, sca);
	TEMPLATE(AddComponent, BoxCollider)(object, &box);
	TEMPLATE(AddComponent, Pause)(object, &pause);
	AddObject(&scene->objectManager, object);
	box->isTrigger = 1;
	scene->camera_tf = &object->transform;
	
	
	CreateVector2(&sca, 2, 2);
	CreateVector2(&vect, 12, 12);
	object = (Object*)malloc(sizeof(Object));
	ObjectConstructor(object, vect, sca);
	TEMPLATE(AddComponent, MeshRenderer)(object, &meshRenderer);
	TEMPLATE(AddComponent, BoxCollider)(object, &box);
	TEMPLATE(AddComponent, ExitTrigger)(object, &exitTrigger);
	AddObject(&scene->objectManager, object);
	box->isTrigger = 1;
	box->size.x = 1;
	box->size.y = 1;
	exit = object;
	meshRenderer->textureNumber = 5;
	
	
	CreateVector2(&sca, 2, 2);
	CreateVector2(&vect, 12, 12);
	object = (Object*)malloc(sizeof(Object));
	ObjectConstructor(object, vect, sca);
	TEMPLATE(AddComponent, MeshRenderer)(object, &meshRenderer);
	TEMPLATE(AddComponent, Player)(object, &pl);
	TEMPLATE(AddComponent, BoxCollider)(object, &box);
	TEMPLATE(AddComponent, Rigidbody)(object, &rigidbody);
	TEMPLATE(AddComponent, TextMesh)(object, &text);
	AddObject(&scene->objectManager, object);
	meshRenderer->textureNumber = 0;
	cam = object;
	scene->camera_tf = &object->transform;
	
	int b_index = 0;
	int block_size = 4;
	Buffer b = GenerateLevel(33, 33, time(NULL));
	for(int y = 0; y < b.height; y++)
	{
		for(int x = 0; x < b.width; x++)
		{
			if(b.buffer[b_index] == 'e')
			{
				exit->transform.position = newVector2(block_size * x, block_size * y);
				b_index++;
				continue;
			}
			else if(b.buffer[b_index] == 'p')
			{
				cam->transform.position = newVector2(block_size * x, block_size * y);
				b_index++;
				continue;
			}
			else if(b.buffer[b_index] == '#')
			{
				b_index++;
				continue;
			}
			b_index++;
			CreateVector2(&sca, block_size, block_size);
			object = (Object*)malloc(sizeof(Object));
			CreateVector2(&vect, block_size * x, block_size * y);
			ObjectConstructor(object, vect, sca);
			TEMPLATE(AddComponent, MeshRenderer)(object, &meshRenderer);
			TEMPLATE(AddComponent, BoxCollider)(object, &box);
			AddObject(&scene->objectManager, object);
			box->size.x = 2;
			box->size.y = 2;
			meshRenderer->textureNumber = 2;
		}
	}
	
	//Pause menu
	CreateVector2(&sca, 12, 12);
	CreateVector2(&vect, 0, 0);
	object = (Object*)malloc(sizeof(Object));
	ObjectConstructor(object, vect, sca);
	TEMPLATE(AddComponent, MeshRenderer)(object, &meshRenderer);
	AddObject(&scene->objectManager, object);
	meshRenderer->textureNumber = 10;
	object->enabled = 0;
	object->parent = cam;
	pause->PauseBody = object;
	parent = object;
	
	CreateVector2(&sca, 22, 3);
	CreateVector2(&vect, 0, 5);
	object = (Object*)malloc(sizeof(Object));
	ObjectConstructor(object, vect, sca);
	TEMPLATE(AddComponent, MeshRenderer)(object, &meshRenderer);
	AddObject(&scene->objectManager, object);
	meshRenderer->textureNumber = 11;
	object->parent = parent;
	
	
	for(int i = 0; i < 2; i++)
	{
		CreateVector2(&sca, 10, 3);
		object = (Object*)malloc(sizeof(Object));
		CreateVector2(&vect, 0, -3 + i * 5);
		ObjectConstructor(object, vect, sca);
		TEMPLATE(AddComponent, MeshRenderer)(object, &meshRenderer);
		AddObject(&scene->objectManager, object);
		meshRenderer->textureNumber = 4;
		object->parent = parent;
	}
	
	CreateVector2(&sca, 10, 3);
	object = (Object*)malloc(sizeof(Object));
	ObjectConstructor(object, vect, sca);
	TEMPLATE(AddComponent, MeshRenderer)(object, &meshRenderer);
	AddObject(&scene->objectManager, object);
	meshRenderer->textureNumber = 5;
	object->parent = parent;
	pause->switcher = object;
	
	for(int i = 0; i < 2; i++)
	{
		CreateVector2(&sca, 22, 3);
		object = (Object*)malloc(sizeof(Object));
		CreateVector2(&vect, 0, -3 + i * 5);
		ObjectConstructor(object, vect, sca);
		TEMPLATE(AddComponent, MeshRenderer)(object, &meshRenderer);
		AddObject(&scene->objectManager, object);
		meshRenderer->textureNumber = i + 12;
		object->parent = parent;
	}
	
	
	object = (Object*)malloc(sizeof(Object));
	ObjectConstructor(object, vect, sca);
	AddObject(&scene->objectManager, object);
	
	
	
	//Win text
	CreateVector2(&sca, 30, 30);
	CreateVector2(&vect, 0, 0);
	object = (Object*)malloc(sizeof(Object));
	ObjectConstructor(object, vect, sca);
	TEMPLATE(AddComponent, MeshRenderer)(object, &meshRenderer);
	exitTrigger->win_menu = object;
	AddObject(&scene->objectManager, object);
	meshRenderer->textureNumber = 10;
	object->enabled = 0;
	object->parent = cam;
	parent = object;
	
	CreateVector2(&sca, 44, 6);
	CreateVector2(&vect, 0, 7);
	object = (Object*)malloc(sizeof(Object));
	ObjectConstructor(object, vect, sca);
	TEMPLATE(AddComponent, MeshRenderer)(object, &meshRenderer);
	AddObject(&scene->objectManager, object);
	meshRenderer->textureNumber = 14;
	object->parent = parent;
	
	CreateVector2(&sca, 22, 3);
	CreateVector2(&vect, -9, 3);
	object = (Object*)malloc(sizeof(Object));
	ObjectConstructor(object, vect, sca);
	TEMPLATE(AddComponent, MeshRenderer)(object, &meshRenderer);
	AddObject(&scene->objectManager, object);
	meshRenderer->textureNumber = 15;
	object->parent = parent;
	
	CreateVector2(&sca, 3, 3);
	CreateVector2(&vect, -5, 3.3f);
	object = (Object*)malloc(sizeof(Object));
	ObjectConstructor(object, vect, sca);
	TEMPLATE(AddComponent, TextMesh)(object, &textMesh);
	AddObject(&scene->objectManager, object);
	SetText(textMesh, "123", 3);
	object->parent = parent;
	
	CreateVector2(&sca, 22, 3);
	CreateVector2(&vect, -7.2f, 1);
	object = (Object*)malloc(sizeof(Object));
	ObjectConstructor(object, vect, sca);
	TEMPLATE(AddComponent, MeshRenderer)(object, &meshRenderer);
	AddObject(&scene->objectManager, object);
	meshRenderer->textureNumber = 16;
	object->parent = parent;
	
	CreateVector2(&sca, 3, 3);
	CreateVector2(&vect, -1, 1.3f);
	object = (Object*)malloc(sizeof(Object));
	ObjectConstructor(object, vect, sca);
	TEMPLATE(AddComponent, TextMesh)(object, &textMesh);
	AddObject(&scene->objectManager, object);
	SetText(textMesh, "", 0);
	object->parent = parent;
}
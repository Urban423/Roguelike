#include "SceneLoader.h"
#include <ObjectHelper.h>
#include <malloc.h>
#include <unistd.h>
#include <stdio.h>

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
	
	
	MeshRenderer* meshRenderer;
	Switcher* switcher;
	
	object = (Object*)malloc(sizeof(Object));
	ObjectConstructor(object, vect, sca);
	AddObject(&scene->objectManager, object);
	scene->camera_tf = &object->transform;
	
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
	switcherObj = object;
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
	CreateVector2(&vect, 0, 3);
	object = (Object*)malloc(sizeof(Object));
	ObjectConstructor(object, vect, sca);
	TEMPLATE(AddComponent, MeshRenderer)(object, &meshRenderer);
	AddObject(&scene->objectManager, object);
	meshRenderer->textureNumber = 9;
	object->parent = parent;
	
	object = (Object*)malloc(sizeof(Object));
	ObjectConstructor(object, {0, -3}, {22, 3});
	TEMPLATE(AddComponent, MeshRenderer)(object, &meshRenderer);
	AddObject(&scene->objectManager, object);
	meshRenderer->textureNumber = 9;
	object->parent = parent;
}

void CreateSceneGame(Scene* scene)
{
	ClearManager(&scene->objectManager);
	
	Object* object;
	Object* parent;
	
	
	Vector2 vect;
	CreateVector2(&vect, 0, 0);
	Vector2 sca;
	CreateVector2(&sca, 2, 2);
	
	
	MeshRenderer* meshRenderer;
	Player* pl;
	BoxCollider* box;
	Rigidbody* rigidbody;
	TextMesh* text;
	
	CreateVector2(&sca, 88, 44);
	object = (Object*)malloc(sizeof(Object));
	CreateVector2(&vect, 1, -3);
	ObjectConstructor(object, vect, sca);
	TEMPLATE(AddComponent, MeshRenderer)(object, &meshRenderer);
	TEMPLATE(AddComponent, BoxCollider)(object, &box);
	AddObject(&scene->objectManager, object);
	box->isTrigger = 1;
	meshRenderer->textureNumber = 1;
	scene->camera_tf = &object->transform;
	
	CreateVector2(&sca, 2, 2);
	object = (Object*)malloc(sizeof(Object));
	ObjectConstructor(object, vect, sca);
	TEMPLATE(AddComponent, MeshRenderer)(object, &meshRenderer);
	TEMPLATE(AddComponent, Player)(object, &pl);
	TEMPLATE(AddComponent, BoxCollider)(object, &box);
	TEMPLATE(AddComponent, Rigidbody)(object, &rigidbody);
	TEMPLATE(AddComponent, TextMesh)(object, &text);
	AddObject(&scene->objectManager, object);
	meshRenderer->textureNumber = 0;
	parent = object;
	
	CreateVector2(&sca, 1, 1);
	CreateVector2(&vect, 0, -1);
	object = (Object*)malloc(sizeof(Object));
	ObjectConstructor(object, vect, sca);
	TEMPLATE(AddComponent, MeshRenderer)(object, &meshRenderer);
	AddObject(&scene->objectManager, object);
	object->parent = parent;
	meshRenderer->textureNumber = 0;
	
	
	for(int i = 0; i < 5; i++)
	{
		CreateVector2(&sca, 2, 2);
		object = (Object*)malloc(sizeof(Object));
		CreateVector2(&vect, 1 + i * 2, -1);
		ObjectConstructor(object, vect, sca);
		TEMPLATE(AddComponent, MeshRenderer)(object, &meshRenderer);
		TEMPLATE(AddComponent, BoxCollider)(object, &box);
		TEMPLATE(AddComponent, Rigidbody)(object, &rigidbody);
		rigidbody->isKinematic = 1;
		AddObject(&scene->objectManager, object);
		meshRenderer->inherited_class.enabled = 1;
		meshRenderer->textureNumber = 2;
	}
}
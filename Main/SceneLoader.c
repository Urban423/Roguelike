#include "SceneLoader.h"
#include <ObjectHelper.h>
#include <malloc.h>
#include <unistd.h>
#include <stdio.h>

void CreateSceneMenu(Scene* scene)
{
	ClearManager(&scene->objectManager);
	Object* object;
	
	
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

void CreateSceneGame(Scene* scene)
{
	scene->objectManager.size = 0;
	Object* object;
	
	
	Vector2 vect;
	CreateVector2(&vect, 0, 0);
	Vector2 sca;
	CreateVector2(&sca, 2, 2);
	
	
	Player* res2;
	BoxCollider* box;
	
	
	object = (Object*)malloc(sizeof(Object));
	ObjectConstructor(object, vect, sca);
	TEMPLATE(AddComponent, Player)(object, &res2);
	TEMPLATE(AddComponent, BoxCollider)(object, &box);
	AddObject(&scene->objectManager, object);
	
	
	object = (Object*)malloc(sizeof(Object));
	CreateVector2(&vect, 1, -1);
	BoxCollider* boxCollider;
	ObjectConstructor(object, vect, sca);
	TEMPLATE(AddComponent, BoxCollider)(object, &boxCollider);
	AddObject(&scene->objectManager, object);
	
	
	object = (Object*)malloc(sizeof(Object));
	CreateVector2(&vect, 1, -3);
	ObjectConstructor(object, vect, sca);
	TEMPLATE(AddComponent, BoxCollider)(object, &boxCollider);
	AddObject(&scene->objectManager, object);
}
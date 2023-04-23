#include "SceneLoader.h"
#include <ObjectHelper.h>
#include <malloc.h>
#include <unistd.h>
#include <stdio.h>

void CreateSceneMenu(Scene* scene)
{
	scene->objectManager.size = 0;
	Object* object;
	
	
	Vector2 vect;
	CreateVector2(&vect, 0, 0);
	Vector2 sca;
	CreateVector2(&sca, 2, 2);
	
	
	Player* res2;
	BoxCollider* box;
	Rigidbody* rigidbody;
	
	
	object = (Object*)malloc(sizeof(Object));
	ObjectConstructor(object, vect, sca);
	TEMPLATE(AddComponent, Player)(object, &res2);
	TEMPLATE(AddComponent, BoxCollider)(object, &box);
	TEMPLATE(AddComponent, Rigidbody)(object, &rigidbody);
	AddObject(&scene->objectManager, object);
	
	object = (Object*)malloc(sizeof(Object));
	CreateVector2(&vect, 1, -1);
	BoxCollider* boxCollider;
	ObjectConstructor(object, vect, sca);
	TEMPLATE(AddComponent, BoxCollider)(object, &boxCollider);
	boxCollider->isTrigger = 1;
	TEMPLATE(AddComponent, Rigidbody)(object, &rigidbody);
	rigidbody->isKinematic = 1;
	AddObject(&scene->objectManager, object);
	
	
	object = (Object*)malloc(sizeof(Object));
	CreateVector2(&vect, 1, -3);
	ObjectConstructor(object, vect, sca);
	TEMPLATE(AddComponent, BoxCollider)(object, &boxCollider);
	AddObject(&scene->objectManager, object);
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
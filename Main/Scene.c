#include "Scene.h"
#include "InputSystem.h"
#include "ExampleClass.h"
#include "Player.h"
#include "ObjectHelper.h"
#include "Vector2.h"
#include <stdio.h>

void onCreate(Scene* scene)
{
	BufferConstructor(&scene->renderer, 6, 6, '-');
	CreateKeyBoard(&(scene->keyBoard));
	scene->is_running = 1;
	
	
	Vector2 vect;
	CreateVector2(&vect, 1, 1);
	ExampleClass* res;
	Player* res2;
	ObjectConstructor(&scene->obj, vect, vect);
	TEMPLATE(AddComponent, ExampleClass)(&scene->obj, &res);
	TEMPLATE(AddComponent, Player)(&scene->obj, &res2);
}

void onUpdate(Scene* scene)
{
	UpdateKeyBoard(&(scene->keyBoard));
	
	Object obj2;
	Vector2 vect;
	ExampleClass* res;
	
	CreateVector2(&vect, 1, 1);
	ObjectConstructor(&obj2, vect, vect);
	TEMPLATE(AddComponent, ExampleClass)(&obj2, &res);
	
	UpdateAll(&scene->obj);
	TEMPLATE(GetComponent, ExampleClass)(&scene->obj, &res);
	UpdateAll(&obj2);
	
	render(scene);
};


void render(Scene* scene)
{
	BufferClear(&scene->renderer, '-');
	
	
	BufferDrawObject(&scene->renderer, scene->obj.transform.position.x, scene->obj.transform.position.y, 2);
	
	
	BufferDraw(&scene->renderer);
}

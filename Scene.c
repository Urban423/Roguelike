#include "Scene.h"
#include "ExampleClass.h"
#include "ObjectHelper.h"
#include "Vector2.h"
#include <stdio.h>
#include <unistd.h>

void onCreate(Scene* scene)
{
	BufferConstructor(&scene->renderer, 6, 6, '-');
	scene->is_running = 1;
}

void onUpdate(Scene* scene)
{
	UpdateKeyBoard(&(scene->keyBoard));
	systemPause();
	
	//sleep(1);
	
	Object obj;
	Object obj2;
	Vector2 vect;
	ExampleClass* res;
	
	CreateVector2(&vect, 1, 1);
	ObjectConstructor(&obj, vect, vect);
	ObjectConstructor(&obj2, vect, vect);
	TEMPLATE(AddComponent, ExampleClass)(&obj, &res);
	TEMPLATE(AddComponent, ExampleClass)(&obj2, &res);
	
	UpdateAll(&obj);
	TEMPLATE(GetComponent, ExampleClass)(&obj, &res);
	lol(res, &obj2);
	UpdateAll(&obj2);
	
	//render(scene);
};
void render(Scene* scene)
{
	BufferClear(&scene->renderer, '-');
	
	
	BufferDrawObject(&scene->renderer, 2, 1, 2);
	
	
	BufferDraw(&scene->renderer);
}

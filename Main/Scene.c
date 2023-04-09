#include "Scene.h"
#include "ExampleClass.h"
#include "BoxCollider.h"
#include "Player.h"
#include "ObjectHelper.h"
#include "Vector2.h"
#include <stdio.h>
#include "Physics.h"

void onCreate(Scene* scene)
{
	BufferConstructor(&scene->renderer, 640, 480, '-');
	CreateKeyBoard(&(scene->keyBoard));
	scene->is_running = 1;
	scene->time = 0;
	
	Vector2 vect;
	CreateVector2(&vect, 100, 120);
	Vector2 sca;
	CreateVector2(&sca, 100, 100);
	ExampleClass* res;
	Player* res2;
	ObjectConstructor(&scene->player, vect, sca);
	TEMPLATE(AddComponent, ExampleClass)(&scene->player, &res);
	TEMPLATE(AddComponent, Player)(&scene->player, &res2);
	
	CreateVector2(&vect, 3.5f, 3.5f);
	BoxCollider* boxCollider;
	ObjectConstructor(&scene->wall1, vect, vect);
	TEMPLATE(AddComponent, BoxCollider)(&scene->wall1, &boxCollider);
	
	CreateVector2(&vect, 4.5f, 3.5f);
	ObjectConstructor(&scene->wall2, vect, vect);
	TEMPLATE(AddComponent, BoxCollider)(&scene->wall2, &boxCollider);
}

void onUpdate(Scene* scene)
{
	scene->time += 0.5f;
	UpdateKeyBoard(&(scene->keyBoard));
	
	scene->player.transform.rotation = 0;
	scene->camera = scene->player.transform;
	setOrthoLH(&scene->mat_cam, scene->renderer.width, scene->renderer.height, 0.3f, 10);
	UpdateAll(&scene->wall1);
	UpdateAll(&scene->player);
	
	BoxCollider* b1;
	BoxCollider* b2;
	TEMPLATE(GetComponent, BoxCollider)(&scene->wall1, &b1);
	TEMPLATE(GetComponent, BoxCollider)(&scene->wall1, &b2);
	Vector2 collision = BoxVsBox(
		scene->wall1.transform.position,
		scene->player.transform.position,
		b1,
		b2);
		
	scene->player.transform.position = add(collision, scene->player.transform.position);	
	
	TEMPLATE(GetComponent, BoxCollider)(&scene->wall2, &b2);
	collision = BoxVsBox(
		scene->wall2.transform.position,
		scene->player.transform.position,
		b1,
		b2);
		
	scene->player.transform.position = add(collision, scene->player.transform.position);	
	
	
	if(render(scene))
	{
		scene->is_running = 0;
	}
};


char render(Scene* scene)
{
	BufferClear(&scene->renderer, 255, 0, 0);
	
	//DrawLine(&scene->renderer, 120, 120 + scene->time,  133, 50 + scene->time, 0, 0, 0);
	
	BufferDrawObject(&scene->renderer, scene->player.transform, 0, 0, 0, scene->mat_cam);
	//BufferDrawObject(&scene->renderer, scene->wall1.transform,  0, 0, 0);
	//BufferDrawObject(&scene->renderer, scene->wall2.transform,  0, 0, 0);
	
	if(BufferDraw(&scene->renderer))
	{
		return 1;
	}
	return 0;
}

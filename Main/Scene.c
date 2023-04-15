#include "Scene.h"
#include "ExampleClass.h"
#include "BoxCollider.h"
#include "Player.h"
#include "ObjectHelper.h"
#include "Vector2.h"
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include "Physics.h"
#include "BMPImage.h"
#include "GraphicsEngine.h"
#include "Input.h"

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
	ReadBMPFile(&scene->textures[0], "./Assets/0034.bmp");
	
	Vector2 vect;
	CreateVector2(&vect, 100, -120);
	Vector2 sca;
	CreateVector2(&sca, 111, 111);
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
	scene->time += 1.1f;
	updateKeyBoard(&scene->keyBoard);
	
	
	scene->player.transform.rotation = sin(0.07 * scene->time) * 14;
	scene->camera = scene->player.transform;
	//setOrthoLH(&scene->mat_cam, scene->renderer.width, scene->renderer.height, 0.3f, 10);
	//UpdateAll(&scene->wall1);
	UpdateAll(&scene->player);
	
	BoxCollider* b1;
	BoxCollider* b2;
	TEMPLATE(GetComponent, BoxCollider)(&scene->wall1, &b1);
	TEMPLATE(GetComponent, BoxCollider)(&scene->wall2, &b2);
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
	BufferClear(&scene->renderer.buffer, 200, 0, 0);
	
	BufferDrawObject(&scene->renderer.buffer, scene->player.transform, &scene->meshes[0], &scene->textures[0]);
	
	SetImage(&scene->renderer.buffer, &scene->textures[0]);
	
	if(updateWindow(&scene->renderer))
	{
		return 1;
	}
	return 0;
}

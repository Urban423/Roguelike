#include "Physics.h"
#include <stdlib.h>
#include <stdio.h>

char Equality(float a, float b)
{
	if(abs(a - b) > 0.01f)
	{
		return 1;
	}
	return 0;
}

float min(float a, float b)
{
	if(a < b)
	{
		return a;
	}
	return b;
}

float max(float a, float b)
{
	if(a > b)
	{
		return a;
	}
	return b;
}


	/*
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
	*/

Vector2 BoxVsBox(
Vector2 center1, Vector2 center2,
BoxCollider* box1, BoxCollider* box2)
{
	float min_dl = 100000000;
	Vector2 ret;
	Vector2 proj1Box1;
	Vector2 proj1Box2;
	
	CreateVector2(&proj1Box1, center1.x - box1->size.x / 2, center1.x + box1->size.x / 2);
	CreateVector2(&proj1Box2, center2.x - box2->size.x / 2, center2.x + box2->size.x / 2);
	
	float min_x = min(proj1Box1.x, proj1Box2.x);
	float max_x = max(proj1Box1.y, proj1Box2.y);
	float dl1 = proj1Box1.x - proj1Box2.y;
	float dl2 = proj1Box1.y - proj1Box2.x;
	float abs_dl1 = abs(dl1);
    float abs_dl2 = abs(dl2);
	float sum = abs( proj1Box1.x - proj1Box1.y) + abs(proj1Box2.x - proj1Box2.y);
    float len = abs(min_x - max_x);
	
	
	//printf("%f, %f\n", abs_dl1, abs_dl2);
	//printf("%f, %f\n", proj1Box2.x, proj1Box2.y);
	if (sum <= len)
	{
		CreateVector2(&proj1Box2, 0, 0);
		return proj1Box2;
	}
	if (Equality(abs_dl1, abs_dl2))
	{
		if (Equality(abs_dl1, min_dl))
		{
			min_dl = abs_dl1;
			CreateVector2(&ret, -1, 0);
		}
	}
	else {
		if (Equality(abs_dl2, min_dl))
		{
			min_dl = abs_dl2;
			CreateVector2(&ret, 1, 0);
		}
	}
	//printf("%e\n", min_dl);
	
	CreateVector2(&proj1Box1, center1.y - box1->size.y / 2, center1.y + box1->size.y / 2);
	CreateVector2(&proj1Box2, center2.y - box2->size.y / 2, center2.y + box2->size.y / 2);

	min_x = min(proj1Box1.x, proj1Box2.x);
	max_x = max(proj1Box1.y, proj1Box2.y);
	dl1 = proj1Box1.x - proj1Box2.y;
	dl2 = proj1Box1.y - proj1Box2.x;
	abs_dl1 = abs(dl1);
    abs_dl2 = abs(dl2);
	sum = abs(proj1Box1.x - proj1Box1.y) + abs(proj1Box2.x - proj1Box2.y);
    len = abs(min_x - max_x);
	if (sum <= len)
	{
		CreateVector2(&proj1Box2, 0, 0);
		return proj1Box2;
	}
	if (Equality(abs_dl1, abs_dl2))
	{
		if (Equality(abs_dl1, min_dl))
		{
			min_dl = abs_dl1;
			CreateVector2(&ret, 0, -1);
		}
	}
	else {
		if (Equality(abs_dl2, min_dl))
		{
			min_dl = abs_dl2;
			CreateVector2(&ret, 0, 1);
		}
	}

	Vector2 t = multiple(ret, min_dl);
	return t;
}
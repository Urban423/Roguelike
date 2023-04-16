#include "Player.h"
#include "ObjectHelper.h"
#include "Input.h"
#include <stdio.h>
#include <math.h>

#undef T
#define T Player

template(T, functiontable) template(T, table) = {
	Player_constructor,
	Player_Start,
	Player_Update
};

void template(T, constructor)(T *this) 
{
    Component_constructor((Component*)this);
    this->inherited_class.virtual_table = (component_functiontable*)&template(T, table);
}

void template(T, Start)(T *this)
{
	this->t = 0;
}

void template(T, Update)(T *this)
{
	float speed = 1.3f * 0.033f;
		//this->t += 0.1f;
	if(GetKey(87))
	{
		this->t += 0.1f;
		this->inherited_class.object->transform.position.y += speed;
		//printf("w");
	}
	if(GetKey(83))
	{
		this->t += 0.1f;
		this->inherited_class.object->transform.position.y -= speed;
		//printf("s");
	}
	if(GetKey(68))
	{
		this->t += 0.1f;
		this->inherited_class.object->transform.position.x += speed;
		//printf("d");
	}
	if(GetKey(65))
	{
		this->t += 0.1f;
		this->inherited_class.object->transform.position.x -= speed;
		//printf("a");
	}
	//this->inherited_class.object->transform.rotation = this->t * 14;
}
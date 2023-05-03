#include "Player.h"
#include "ObjectHelper.h"
#include "Input.h"
#include <stdio.h>
#include <math.h>
includeTime

#undef T
#define T Player

template(T, functiontable) template(T, table) = {
	template(T, constructor),
	template(T, Start),
	template(T, Update),
	template(T, OnTriggerStay)
};

void template(T, constructor)(T *this) 
{
    Component_constructor((Component*)this);
    this->inherited_class.virtual_table = (component_functiontable*)&template(T, table);
}

void template(T, Start)(T *this)
{
	this->walkSpeed = 8.3f;
}

void template(T, Update)(T *this)
{
	float speed = this->walkSpeed * Time.deltaTime;
	if(GetKey(87))
	{
		this->inherited_class.object->transform.position.y += speed;
		//printf("w");
	}
	if(GetKey(83))
	{
		this->inherited_class.object->transform.position.y -= speed;
		//printf("s");
	}
	if(GetKey(68))
	{
		this->inherited_class.object->transform.position.x += speed;
		//printf("d");
	}
	if(GetKey(65))
	{
		this->inherited_class.object->transform.position.x -= speed;
		//printf("a");
	}
	//this->inherited_class.object->transform.rotation = this->t * 14;
}

void template(T, OnTriggerStay)(T* this, Object* entered)
{
	printf("Player entered a trigger\n");
}
#include "Player.h"
#include "ObjectHelper.h"
#include "Input.h"
#include <stdio.h>
#include <math.h>
includeTime
includeInput

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
	Vector2 moveDirection = {0, 0};
	if(GetKey(KeyCode.W))
	{
		moveDirection.y = 1;
	}
	if(GetKey(KeyCode.S))
	{
		moveDirection.y = -1;
	}
	if(GetKey(KeyCode.D))
	{
		moveDirection.x = 1;
	}
	if(GetKey(KeyCode.A))
	{
		moveDirection.x = -1;
	}
	this->inherited_class.object->transform.position = add(this->inherited_class.object->transform.position, multiple(moveDirection, speed));
	//this->inherited_class.object->transform.rotation = this->t * 14;
}

void template(T, OnTriggerStay)(T* this, Object* entered)
{
	printf("Player entered a trigger\n");
}
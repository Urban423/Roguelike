#include "Player.h"
#include "ObjectHelper.h"
#include "KeyBoardState.h"
#include <stdio.h>

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
	
}

void template(T, Update)(T *this)
{
	if(GetKey(87))
	{
		this->inherited_class.object->transform.position.y -= 0.1f;
		//printf("w");
	}
	if(GetKey(83))
	{
		this->inherited_class.object->transform.position.y += 0.1f;
		//printf("s");
	}
	if(GetKey(68))
	{
		this->inherited_class.object->transform.position.x += 0.1f;
		//printf("d");
	}
	if(GetKey(65))
	{
		this->inherited_class.object->transform.position.x -= 0.1f;
		//printf("a");
	}
}
#include "Door.h"
#include "ObjectHelper.h"
#include "Input.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
includeTime
includeInput

#undef T
#define T Door

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
	
}

void template(T, Update)(T *this)
{
	if(this->player->key == 1)
	{
		BoxCollider* box;
		TEMPLATE(GetComponent, BoxCollider)(this->inherited_class.object, &box);
		box->isTrigger = 1;
	}
}

void template(T, OnTriggerStay)(T* this, Object* entered)
{
	Player* player;
	TEMPLATE(GetComponent, Player)(entered, &player);
	if(player != NULL)
	{
		addScore(player, 1);
		this->inherited_class.object->enabled = 0;
	}
}
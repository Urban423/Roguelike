#include "PainMaker.h"
#include "ObjectHelper.h"
#include "Input.h"
#include <stdio.h>
#include <math.h>
includeTime
includeInput

#undef T
#define T PainMaker

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
	this->inherited_class.object->transform.rotation += Time.deltaTime * 180;
}

void template(T, OnTriggerStay)(T* this, Object* entered)
{
	Player* player;
	TEMPLATE(GetComponent, Player)(entered, &player);
	if(player != NULL)
	{
		Kill(player);
	}
}
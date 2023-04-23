#include "BoxCollider.h"
#include "ObjectHelper.h"

#undef T
#define T BoxCollider

template(T, functiontable) template(T, table) = {
	BoxCollider_constructor,
	BoxCollider_Start,
	BoxCollider_Update,
	template(T, OnTriggerStay)
};

void template(T, constructor)(T *this) 
{
    Component_constructor((Component*)this);
    this->inherited_class.virtual_table = (component_functiontable*)&template(T, table);
	this->size.x = 1;
	this->size.y = 1;
	this->isTrigger = 0;
}

void template(T, Start)(T *this)
{
	
}

void template(T, Update)(T *this)
{
	
}

void template(T, OnTriggerStay)(T* this, Object* object)
{
	
}
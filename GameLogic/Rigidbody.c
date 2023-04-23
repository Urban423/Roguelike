#include "Rigidbody.h"
#include "ObjectHelper.h"
#include "Input.h"
#include <math.h>

#undef T
#define T Rigidbody

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
	this->isKinematic = 0;
}

void template(T, Update)(T *this)
{
	
}

void template(T, OnTriggerStay)(T* this, Object* object)
{
	
}
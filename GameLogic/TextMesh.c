#include "TextMesh.h"
#include "ObjectHelper.h"
#include "Input.h"
#include <math.h>
#include <malloc.h>
#include <stddef.h>

#undef T
#define T TextMesh

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
	this->text = NULL;
	this->size = 0;
}

void SetText(T* this, char* text, unsigned int size)
{
	if(this->text != NULL)
	{
		free(this->text);
	}
	this->text = (char*)malloc(size);
	this->size = size;
	for(int i = 0; i < size; i++)
	{
		this->text[i] = text[i];
	}
}

void template(T, Update)(T *this)
{
	
}

void template(T, OnTriggerStay)(T* this, Object* object)
{
	
}
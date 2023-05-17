#include "TextMesh.h"
#include "ObjectHelper.h"
#include "Input.h"
#include <math.h>
#include <malloc.h>
#include <stddef.h>
includeTime

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

void AddSymbol(T* this, char symbol)
{
	char* new_one = (char*)malloc(this->size + 1);
	for(int i = 0; i < this->size; i++)
	{
		new_one[i] = this->text[i];
	}
	new_one[this->size] = symbol;
	free(this->text);
	this->text = new_one;
	this->size++;
}

void template(T, Update)(T *this)
{
	this->inherited_class.object->transform.rotation += 0.1f;
}

void template(T, OnTriggerStay)(T* this, Object* object)
{
	
}
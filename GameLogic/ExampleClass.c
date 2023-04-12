#include "ExampleClass.h"
#include "ObjectHelper.h"
#include <stdio.h>

#undef T
#define T ExampleClass

template(T, functiontable) template(T, table) = {
	ExampleClass_constructor,
	ExampleClass_Start,
	ExampleClass_Update
};

void template(T, constructor)(T *this) 
{
    Component_constructor((Component*)this);
    this->inherited_class.virtual_table = (component_functiontable*)&template(T, table);
}

void template(T, Start)(T *this) {
}

void template(T, Update)(T *this)
{
	
}
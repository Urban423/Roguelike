#include "ExampleClass.h"
#include <stdio.h>

#define T ExampleClass

template(T, functiontable) table = {
	ExampleClass_constructor,
	ExampleClass_Start,
	ExampleClass_Update
};

void template(T, constructor)(T *this) 
{
    Component_constructor((Component*)this);
    this->inherited_class.virtual_table = (component_functiontable*)&table;
	this->ex = 0;
}

void template(T, Start)(T *this) {
    printf("ExampleClass Started\n");
}

void template(T, Update)(T *this)
{
	printf("ExampleClass %f\n", this->ex);
	this->ex++;
}

#ifdef T

void lol(T* this, Object* second)
{
	T* res;
	TEMPLATE(GetComponent, ExampleClass)(&second, &res);
	res->ex=12;
}

#endif
#pragma once
#include "Component.h"
#include "Object.h"
#include "templates.h"

#undef T
#define T ExampleClass

struct T;

typedef struct
{
	void (*T)(struct T*);
	void (*Start)(struct T*);
	void (*Update)(struct T*);
}ExampleClass_functiontable;

typedef struct T
{
    Component inherited_class;
}T;

void template(T, constructor)(T* this);
void template(T, Start)(T* this);
void template(T, Update)(T* this);
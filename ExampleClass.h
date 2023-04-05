#pragma once
#include "Component.h"
#include "Object.h"
#include "templates.h"

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
	float ex;
}T;

#ifdef T

void lol(T* this, Object* second);

#endif

void template(T, constructor)(T* this);
void template(T, Start)(T* this);
void template(T, Update)(T* this);
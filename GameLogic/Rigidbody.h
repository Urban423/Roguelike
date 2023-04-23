#pragma once
#include "Component.h"
#include "Object.h"
#include "templates.h"

#undef T
#define T Rigidbody

struct T;

typedef struct
{
	void (*T)(struct T*);
	void (*Start)(struct T*);
	void (*Update)(struct T*);
	void (*OnTriggerStay)(struct T*, Object*);
}Rigidbody_functiontable;

typedef struct T
{
    Component inherited_class;
	char isKinematic;
}T;

void template(T, constructor)(T* this);
void template(T, Start)(T* this);
void template(T, Update)(T* this);
void template(T, OnTriggerStay)(T* this, Object* object);
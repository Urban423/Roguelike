#pragma once
#include "Component.h"
#include "Object.h"
#include "templates.h"
#include "Vector2.h"

#undef T
#define T BoxCollider

struct T;

typedef struct
{
	void (*T)(struct T*);
	void (*Start)(struct T*);
	void (*Update)(struct T*);
	void (*OnTriggerStay)(struct T*, Object*);
}BoxCollider_functiontable;

typedef struct T
{
    Component inherited_class;
	Vector2 size;
	char isTrigger;
}T;

void template(T, constructor)(T* this);
void template(T, Start)(T* this);
void template(T, Update)(T* this);
void template(T, OnTriggerStay)(T* this, Object* object);
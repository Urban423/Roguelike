#pragma once
#include "Component.h"
#include "Object.h"
#include "Vector2.h"
#include "TextMesh.h"
#include "templates.h"

#undef T
#define T Enemy

struct T;

typedef struct
{
	void (*T)(struct T*);
	void (*Start)(struct T*);
	void (*Update)(struct T*);
	void (*OnTriggerStay)(struct T*, Object*);
}template(T, functiontable);

typedef struct T
{
    Component inherited_class;
	float walkSpeed;
	Transfrom* player;
}T;

void template(T, constructor)(T* this);
void template(T, Start)(T* this);
void template(T, Update)(T* this);
void template(T, OnTriggerStay)(T* this, Object* entered);
#pragma once
#include "Component.h"
#include "Object.h"
#include "templates.h"
#include "TextMesh.h"

#undef T
#define T Switcher

struct T;

typedef struct
{
	void (*T)(struct T*);
	void (*Start)(struct T*);
	void (*Update)(struct T*);
	void (*OnTriggerStay)(struct T*, Object*);
}Switcher_functiontable;

typedef struct T
{
    Component inherited_class;
	int pos;
	int flag;
	Object* statistic;
	TextMesh* textMesh;
}T;

void template(T, constructor)(T* this);
void template(T, Start)(T* this);
void template(T, Update)(T* this);
void template(T, OnTriggerStay)(T* this, Object* entered);
#pragma once
#include "Component.h"
#include "Object.h"
#include "Player.h"
#include "BoxCollider.h"
#include "templates.h"

#undef T
#define T Key

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
	Player* player;
}T;

void template(T, constructor)(T* this);
void template(T, Start)(T* this);
void template(T, Update)(T* this);
void template(T, OnTriggerStay)(T* this, Object* entered);
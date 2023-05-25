#pragma once
#include "Component.h"
#include "Object.h"
#include "TextMesh.h"
#include "MeshRenderer.h"
#include "templates.h"

#undef T
#define T Player

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
	float RunSpeed;
	int score;
	int key;
	MeshRenderer* keyObj;
	MeshRenderer* loseMenu;
	TextMesh* text;
	int hearts_count;
	MeshRenderer* Heart1;
}T;

void getKey(Player* this);
void addScore(Player* this, int add);
void Kill(Player* this, Object* killer);

void template(T, constructor)(T* this);
void template(T, Start)(T* this);
void template(T, Update)(T* this);
void template(T, OnTriggerStay)(T* this, Object* entered);
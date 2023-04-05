#pragma once

struct Component;

typedef struct
{
	void (*Component)(struct Component*);
	void (*Start)(struct Component*);
	void (*Update)(struct Component*);
}component_functiontable;

typedef struct Component
{
	char enabled;
	struct Object* object;
	component_functiontable* virtual_table;
}Component;

void Component_constructor(Component* this);
void Start(Component* this);
void Update(Component* this);
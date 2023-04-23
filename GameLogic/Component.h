#pragma once

struct Component;
struct Object;

typedef struct
{
	void (*Component)(struct Component*);
	void (*Start)(struct Component*);
	void (*Update)(struct Component*);
	void (*OnTriggerStay)(struct Component*, struct Object*);
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
void OnTriggerStay(Component* this, struct Object* entered_one);
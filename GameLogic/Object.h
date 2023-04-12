#ifndef OBJECT_H_
#define OBJECT_H_

#include "Vector2.h"
#include "Component.h"
#include "templates.h" 

struct ComponentManager;
typedef struct ComponentManager
{
	struct ComponentManager* next;
	Component* component;
}ComponentManager;

void AddComponentToComponentManager(ComponentManager* this, Component* add);

typedef struct Object
{
	Transfrom transform;
	unsigned int number_of_components;
	unsigned int  index_of_figure;
	ComponentManager componentManager;
}Object;

void ObjectConstructor(Object* this, Vector2 start_pos, Vector2 start_scale);
void UpdateAll(Object* this);
#endif 





#ifdef T 
void TEMPLATE(AddComponent, T)(Object* this, T** result);
void TEMPLATE(GetComponent, T)(Object* this, T** result);
#endif 

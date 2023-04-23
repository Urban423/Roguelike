#ifndef OBJECT_H_
#define OBJECT_H_

#include "Vector2.h"
#include "Component.h"
#include "templates.h" 
#include "Matrix3x3.h"

typedef struct ComponentManager
{
	struct ComponentManager* next;
	const char* name;
	Component* component;
}ComponentManager;

void AddComponentToComponentManager(ComponentManager* this, Component* add, const char* name);

typedef struct Object
{
	Transfrom transform;
	unsigned int number_of_components;
	int  index_of_figure;
	Matrix3x3 world_pos;
	ComponentManager componentManager;
}Object;

void ProcessWorldPos(Object* this);
void ObjectConstructor(Object* this, Vector2 start_pos, Vector2 start_scale);
void UpdateObject(Object* this);
void TriggerStayObject(Object* this, Object* enter_one);

typedef struct ObjectList
{
	struct ObjectList* next;
	Object* object;
}ObjectList;

typedef struct ObjectManager
{
	ObjectList* list;
	unsigned int size;
}ObjectManager;

void AddObject(ObjectManager* this, Object* add);
#endif 


#ifdef T 
void TEMPLATE(AddComponent, T)(Object* this, T** result);
void TEMPLATE(GetComponent, T)(Object* this, T** result);
#endif 

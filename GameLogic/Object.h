#ifndef OBJECT_H_
#define OBJECT_H_

#include "Vector2.h"
#include "Component.h"
#include "templates.h" 
#include "Matrix3x3.h"

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
	int  index_of_figure;
	Matrix3x3 world_pos;
	ComponentManager componentManager;
}Object;

void ProcessWorldPos(Object* this, Matrix3x3 camera_pos, Matrix3x3 cam_world_pos);
void ObjectConstructor(Object* this, Vector2 start_pos, Vector2 start_scale);
void UpdateObject(Object* this);

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

#include <stdlib.h>
#include <stdio.h>
#include "templates.h" 

#ifndef OBJECT_H_
#include "Object.h"
void AddComponentToComponentManager(ComponentManager* this, Component* add)
{
	if(this->next != NULL)
	{
			AddComponentToComponentManager(this->next, add);
			return;
	}
	this->component = add;
}

void ObjectConstructor(Object* this, Vector2 start_pos, Vector2 start_scale)
{
	this->componentManager.next = NULL;
	this->transform.position = start_pos;
	this->transform.rotation = 0;
	this->transform.scale.x = start_scale.x;
	this->transform.scale.y = start_scale.y;
}

void ProcessWorldPos(Object* this, Matrix3x3 camera_pos, Matrix3x3 cam_world_pos)
{
	setIdentity(&this->world_pos);
	SetRotation(&this->world_pos, this->transform.rotation);
	
	Matrix3x3 temp;
	setIdentity(&temp);
	SetScale(&temp, this->transform.scale);
	this->world_pos = MultipleMatrixMatrix(this->world_pos, temp);
	
	setIdentity(&temp);
	setTranslation(&temp, this->transform.position);
	this->world_pos = MultipleMatrixMatrix(this->world_pos, temp);
	
	this->world_pos = MultipleMatrixMatrix(this->world_pos, cam_world_pos);
	this->world_pos = MultipleMatrixMatrix(this->world_pos, camera_pos);
}

void UpdateAll(Object* this)
{
	this->componentManager.component->virtual_table->Update(this->componentManager.component);
}

void AddObject(ObjectManager* this, Object* add)
{
	if(this->size == 0)
	{
		this->size++;
		this->list = (ObjectList*)malloc(sizeof(ObjectList));
		this->list->object = add;
		this->list->next = NULL;
		return;
	}
	
	ObjectList* list = this->list;
	for(int i = 0; i < this->size - 1; i++)
	{
		list = list->next;
	}
	this->size++;
	list->next = (ObjectList*)malloc(sizeof(ObjectList));
	list->next->object = add;
	list->next->next = NULL;
}
#endif



#ifdef T 
void TEMPLATE(AddComponent, T)(Object* this, T** result)
{
	(*result) = malloc(sizeof(T));
	TEMPLATE(T, constructor)((*result));
	TEMPLATE(T, Start)((*result));
	(*result)->inherited_class.object = this;
	this->number_of_components ++;
	AddComponentToComponentManager(&this->componentManager, (Component*)(*result)); 
}
   
void TEMPLATE(GetComponent, T)(Object* this, T** result)
{        
	(*result) = NULL;
	for(unsigned int i = 0; i < this->number_of_components; i++)
	{
		(*result) = (T*)this->componentManager.component;
		break;
	}
}  

#endif
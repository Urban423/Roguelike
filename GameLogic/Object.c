#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "templates.h" 

#ifndef OBJECT_H_
#include "Object.h"
void AddComponentToComponentManager(ComponentManager* this, Component* add, const char* name)
{
	if(this->next != NULL)
	{
			AddComponentToComponentManager(this->next, add, name);
			return;
	}
	ComponentManager* newNext = (ComponentManager*)malloc(sizeof(ComponentManager));
	newNext->next = NULL;
	newNext->component = NULL;
	newNext->name = NULL;
	
	this->next = newNext;
	this->component = add;
	this->name = name;
}

void ObjectConstructor(Object* this, Vector2 start_pos, Vector2 start_scale)
{
	this->componentManager.next = NULL;
	this->transform.position = start_pos;
	this->transform.rotation = 0;
	this->number_of_components = 0;
	this->transform.scale.x = start_scale.x;
	this->transform.scale.y = start_scale.y;
}

void ProcessWorldPos(Object* this)
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
	
	//this->world_pos = MultipleMatrixMatrix(this->world_pos, cam_world_pos);
	//this->world_pos = MultipleMatrixMatrix(this->world_pos, camera_pos);
}

void UpdateObject(Object* this)
{
	ComponentManager* comManager = &this->componentManager;
	for(unsigned int i = 0; i < this->number_of_components; i++)
	{
		comManager->component->virtual_table->Update(comManager->component);
		comManager = comManager->next;
	}
}

void TriggerStayObject(Object* this, Object* enter_one)
{
	ComponentManager* comManager = &this->componentManager;
	for(unsigned int i = 0; i < this->number_of_components; i++)
	{
		comManager->component->virtual_table->OnTriggerStay(comManager->component, enter_one);
		comManager = comManager->next;
	}
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

void DeleteObjectWithInit(Object* this)
{
	ComponentManager* comManager = &this->componentManager;
	ComponentManager* comManagerToDelete = comManager;
	for(unsigned int i = 0; i < this->number_of_components; i++)
	{
		comManagerToDelete = comManager;
		free(comManager->component);
		comManager = comManager->next;
		
		free(comManagerToDelete);
	}
	free(this);
}

void ClearManager(ObjectManager* this)
{
	ObjectList* list = this->list;
	ObjectList* listToDelete = this->list;
	for(int i = 0; i < this->size; i++)
	{
		listToDelete = list;
		DeleteObjectWithInit(list->object);
		list = list->next;
		
		free(listToDelete);
	}
	this->size = 0;
}

#endif



#ifdef T 
void TEMPLATE(AddComponent, T)(Object* this, T** result)
{
	(*result) = malloc(sizeof(T));
	TEMPLATE(T, constructor)((*result));
	
	(*result)->inherited_class.virtual_table->Start((Component*)*result);
	(*result)->inherited_class.object = this;
	this->number_of_components ++;
	
	const char* st = __FUNCTION__;
	
	AddComponentToComponentManager(&this->componentManager, (Component*)(*result), st); 
}

void TEMPLATE(GetComponent, T)(Object* this, T** result)
{
	const char* st = __FUNCTION__;
	ComponentManager* comManager = &this->componentManager;
	(*result) = NULL;
	for(unsigned int i = 0; i < this->number_of_components; i++)
	{
		int index = 13;
		char flag = 1;
		while(1)
		{
			if(comManager->name[index] != st[index])
			{
				flag = 0;
				break;
			}
			if(st[index] == 0)
			{
				break;
			}
			index++;
		}
		if(flag)
		{
			(*result) = (T*)comManager->component;
			break;
		}
		comManager = comManager->next;
	}
}  

#endif
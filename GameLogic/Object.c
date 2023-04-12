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

void UpdateAll(Object* this)
{
	this->componentManager.component->virtual_table->Update(this->componentManager.component);
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
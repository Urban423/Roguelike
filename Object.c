#ifdef T 
#include "Object.h"
#include <stdlib.h>
#include <stdio.h>
#include "templates.h" 

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
	this->transform.scale = start_scale;
}

void UpdateAll(Object* this)
{
	this->componentManager.component->virtual_table->Update(this->componentManager.component);
}

void TEMPLATE(AddComponent, T)(Object* this, T** result)
{
	(*result) = malloc(sizeof(T));
	TEMPLATE(T, constructor)((*result));
	TEMPLATE(T, Start)((*result));
	(*result)->inherited_class.object = this;
	AddComponentToComponentManager(&this->componentManager, (Component*)(*result)); 
}
   
void TEMPLATE(GetComponent, T)(Object* this, T** result)
{          
	for(int i = 0; i < this->number_of_components; i++)
	{
		(*result) = (T*)this->componentManager.component;
		break;
	}
}  

#endif
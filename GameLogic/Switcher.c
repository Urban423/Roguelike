#include "Switcher.h"
#include "ObjectHelper.h"
#include "Input.h"
#include <stdio.h>
#include <math.h>
includeTime

#undef T
#define T Switcher

template(T, functiontable) template(T, table) = {
	Switcher_constructor,
	template(T, Start),
	template(T, Update),
	template(T, OnTriggerStay)
};

void template(T, constructor)(T *this) 
{
    Component_constructor((Component*)this);
    this->inherited_class.virtual_table = (component_functiontable*)&template(T, table);
}

void template(T, Start)(T *this)
{
	this->pos = 2;
}

void template(T, Update)(T *this)
{
	if(GetKeyDown(87))
	{
		this->pos  += 1;
		if(this->pos > 2)
		{
			this->pos = 0;
		}
	}
	if(GetKeyDown(83))
	{
		this->pos  -= 1;
		if(this->pos < 0)
		{
			this->pos = 2;
		}
	}
	if(GetKeyDown(13))
	{
		if(this->pos == 2)
		{
			addMessage(3); //new Game
		}
		else if(this->pos == 1)
		{
			this->inherited_class.enabled = 0;
			this->statistic->enabled = 1; //statistic
		}
		else if(this->pos == 0)
		{
			addMessage(1); //exit
		}
	}
	this->inherited_class.object->transform.position.y = -7 + this->pos * 5;
}

void template(T, OnTriggerStay)(T* this, Object* entered)
{
	
}
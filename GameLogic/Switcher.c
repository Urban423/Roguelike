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
	this->flag = 0;
}

void template(T, Update)(T *this)
{
	//this->inherited_class.object->transform.rotation += 1;
	if(this->flag == 1)
	{
		for(int i = 0; i < 256; i++)
		{
			if(GetKeyDown(i))
			{
				this->statistic->enabled = 0;
				this->flag = 0;
			}
		}
		return;
	}
	
	
	
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
			LoadScene(3); //new Game
		}
		else if(this->pos == 1)
		{
			this->statistic->enabled = 1; //statistic
			this->flag = 1;
		}
		else if(this->pos == 0)
		{
			QuitMessage();
		}
	}
	const int y_offset = -7;
	const int y_size = 5;
	this->inherited_class.object->transform.position.y = y_offset + this->pos * y_size;
}

void template(T, OnTriggerStay)(T* this, Object* entered)
{
	
}
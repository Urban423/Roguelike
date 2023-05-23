#include "Pause.h"
#include "ObjectHelper.h"
#include "Input.h"
#include <stdio.h>
#include <math.h>
includeTime
includeInput

#undef T
#define T Pause

template(T, functiontable) template(T, table) = {
	template(T, constructor),
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
	this->pause = 0;
	this->pos = 1;
	Time.timescale = !this->pause;
}

void template(T, Update)(T *this)
{
	if(GetKeyDown(KeyCode.Escape))
	{
		//printf("escape");
		this->pause = !this->pause;
		Time.timescale = !this->pause;
		this->PauseBody->enabled = this->pause;
	}
	
	if(this->pause == 0)
	{
		return;
	}
	
	if(GetKeyDownMoveUp())
	{
		this->pos  += 1;
		if(this->pos > 1)
		{
			this->pos = 0;
		}
	}
	if(GetKeyDownMoveDown())
	{
		this->pos  -= 1;
		if(this->pos < 0)
		{
			this->pos = 1;
		}
	}
	
	if(GetKeyDown(KeyCode.Enter))
	{
		if(this->pos == 1)
		{
			this->pause = !this->pause;
			Time.timescale = !this->pause;
			this->PauseBody->enabled = this->pause;
		}
		else if(this->pos == 0)
		{	
			LoadScene(2); //LoadMenu
		}
	}
	const int y_offset = -3;
	const int y_size = 5;
	this->switcher->transform.position.y = y_offset + this->pos * y_size;
}

void template(T, OnTriggerStay)(T* this, Object* entered)
{
	
}
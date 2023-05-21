#include "WriteYourText.h"
#include "ObjectHelper.h"
#include "Input.h"
#include "TextMesh.h"
#include "statistic.h"
#include <stdio.h>
#include <math.h>
includeTime
includeInput

#undef T
#define T WriteYourText

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
	
}

char Codes()
{
	if(GetKeyDown(32))
	{
		return 32;
	}
	for(int i = 48; i < 58; i++)
	{
		if(GetKeyDown(i))
		{
			return i;
		}
	}
	for(int i = 65; i < 91; i++)
	{
		if(GetKeyDown(i))
		{
			return i;
		}
	}
	return -1;
}

void template(T, Update)(T *this)
{
	if(GetKeyDown(KeyCode.Enter))
	{
		if(this->text->size != 0)
		{
			AddSymbol(this->text, ':');
			AddSymbol(this->text, ' ');
			for(int i = 0; i < this->player->text->size; i++)
			{
				AddSymbol(this->text, this->player->text->text[i]);
			}
			AddSymbol(this->text, '\n');
			AddSymbol(this->text, 0);
			SaveStatistic(this->text->text, "./Assets/statistic.txt");
		}
		LoadScene(2);
		return;
	}
	
	char c = Codes();
	if(c == -1)
	{
		return;
	}
	
	AddSymbol(this->text, c);
}

void template(T, OnTriggerStay)(T* this, Object* entered)
{
	
}
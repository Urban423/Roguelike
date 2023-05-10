#include "WriteYourText.h"
#include "ObjectHelper.h"
#include "Input.h"
#include "TextMesh.h"
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
		LoadScene(2);
	}
	
	char c = Codes();
	if(c == -1)
	{
		return;
	}
	
	TextMesh* textMesh;

	TEMPLATE(GetComponent, TextMesh)(this->inherited_class.object, textMesh);
	
}

void template(T, OnTriggerStay)(T* this, Object* entered)
{
	
}
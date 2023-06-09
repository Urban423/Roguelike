#include "Player.h"
#include "ObjectHelper.h"
#include "Input.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
includeTime
includeInput

#undef T
#define T Player

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
	this->walkSpeed = 8.3f;
	this->score = 0;
	this->key = 0;
	this->hearts_count = 2;
}

void template(T, Update)(T *this)
{
	if(this->hearts_count <= 0)
	{
		this->loseMenu->inherited_class.object->enabled = 1;
		Time.timescale = 0;
		if(GetKeyDown(KeyCode.Enter))
		{
			LoadScene(2);
		}
		return;
	}
	float speed = this->walkSpeed * Time.deltaTime;
	Vector2 moveDirection = {0, 0};
	if(GetKeyMoveUp())
	{
		moveDirection.y = 1;
	}
	if(GetKeyMoveDown())
	{
		moveDirection.y = -1;
	}
	if(GetKeyMoveRight())
	{
		moveDirection.x = 1;
	}
	if(GetKeyMoveLeft())
	{
		moveDirection.x = -1;
	}
	this->inherited_class.object->transform.position = add(this->inherited_class.object->transform.position, multiple(moveDirection, speed));
	//this->inherited_class.object->transform.rotation = this->t * 14;
}


void getKey(Player* this)
{
	this->key = 1;
	this->keyObj->inherited_class.object->enabled = 1;
}

void addScore(Player* this, int add)
{
	this->score += add;
	if(this->score > 999)
	{
		this->score = 999;
	}
	
	char* number_to_sting;
	int size = 0;
	int temp_score = this->score;
	while(temp_score != 0)
	{
		temp_score /= 10;
		size++;
	}

	number_to_sting = (char*)malloc(sizeof(char) * size);
	
	temp_score = this->score;
	for(int i = 0; i< size; i++)
	{
		number_to_sting[i] = 48 + temp_score % 10;
		temp_score /= 10;
	}
	
	for(int i = 0, j = size - 1; i < j; i++, j--)
	{
		char temper = number_to_sting[i];
		number_to_sting[i] = number_to_sting[j];
		number_to_sting[j] = temper;
	}
	
	SetText(this->text, number_to_sting, size);
}

void Kill(Player* this, Object* killer)
{
	this->hearts_count--;
	if(this->hearts_count == 1)
	{
		this->Heart1->inherited_class.object->enabled = 0;
	}
	killer->enabled = 0;
}

void template(T, OnTriggerStay)(T* this, Object* entered)
{
	printf("Player entered a trigger\n");
}
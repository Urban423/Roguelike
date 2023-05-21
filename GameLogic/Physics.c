#include "Physics.h"
#include <stdlib.h>
#include <stdio.h>
#include "ObjectHelper.h"

char Equality(float a, float b)
{
	if(b - a > 0.01f)
	{
		return 1;
	}
	return 0;
}

float min(float a, float b)
{
	if(a < b)
	{
		return a;
	}
	return b;
}

float max(float a, float b)
{
	if(a > b)
	{
		return a;
	}
	return b;
}

void CalculatePhysic(ObjectManager* manager)
{
	unsigned int size = manager->size;
	if(size < 2)
	{
		return;
	}
	int st = min(manager->size - 1, 3);
	
	char staticpos1 = 0;
	char staticpos2 = 0;
	BoxCollider* b1;
	BoxCollider* b2;
	Rigidbody* r1;
	Rigidbody* r2;
	ObjectList* firstlist = manager->list;
	ObjectList* secondlist = NULL;
	for(int i = 0; i < st; i++)
	{
		TEMPLATE(GetComponent, BoxCollider)(firstlist->object, &b1);
		TEMPLATE(GetComponent, Rigidbody)(firstlist->object, &r1);
		secondlist = firstlist->next;
		staticpos1 = (r1 == NULL || (r1 != NULL && r1->isKinematic == 1)) && firstlist->object->enabled ? 1 : 0;
		for(int j = i + 1; j < size; j++)
		{
			TEMPLATE(GetComponent, BoxCollider)(secondlist->object, &b2);
			TEMPLATE(GetComponent, Rigidbody)(secondlist->object, &r2);
			staticpos2 = (r2 == NULL || (r2 != NULL && r2->isKinematic == 1)) && secondlist->object->enabled ? 1 : 0;
			if((staticpos1 != 0 || staticpos2 != 0) && (b1 != NULL && b2 != NULL))
			{
				Vector2 collision = BoxVsBox(
				firstlist->object->transform,
				secondlist->object->transform,
				b1,
				b2);
				
				if(collision.x == 0 && collision.y == 0)
				{
					secondlist = secondlist->next;
					continue;
				}
				//printf("%d:%d\n", staticpos1, staticpos2);
				if(staticpos1 == 0 && staticpos2 == 0)
				{
					firstlist->object->transform.position = add(multiple(collision, 0.5f), firstlist->object->transform.position);	
					secondlist->object->transform.position = add(multiple(collision, -0.5f), secondlist->object->transform.position);	
				}
				else if(staticpos1 == 0 && staticpos2 == 1)
				{
					if(b2->isTrigger == 1)
					{
						TriggerStayObject(secondlist->object, firstlist->object);
					}else{
						firstlist->object->transform.position = add(collision, firstlist->object->transform.position);	
					}
				}
				else if(staticpos1 == 1 && staticpos2 == 0)
				{
					if(b1->isTrigger == 1)
					{
						TriggerStayObject(firstlist->object, secondlist->object);
					}else{
						secondlist->object->transform.position = add(multiple(collision, -1), secondlist->object->transform.position);	
					}
				}
			}
			
			secondlist = secondlist->next;
		}
		firstlist = firstlist->next;
	}
}

Vector2 BoxVsBox(
Transfrom transform1, Transfrom transform2,
BoxCollider* box1, BoxCollider* box2)
{
	Vector2 empty = newVector2(0, 0);
	float min_dl = 100000000;
	Vector2 ret;
	Vector2 proj1Box1;
	Vector2 proj1Box2;
	
	CreateVector2(&proj1Box1, 
	(float)transform1.position.x - (float)box1->size.x * (float)transform1.scale.x / 2,
	(float)transform1.position.x + (float)box1->size.x * (float)transform1.scale.x / 2);
	
	CreateVector2(&proj1Box2, 
	(float)transform2.position.x - (float)box2->size.x * (float)transform1.scale.x / 2,
	(float)transform2.position.x + (float)box2->size.x * (float)transform1.scale.x / 2);
	
	float min_x = min(proj1Box1.x, proj1Box2.x);
	float max_x = max(proj1Box1.y, proj1Box2.y);
	float dl1 = proj1Box1.x - proj1Box2.y;
	float dl2 = proj1Box1.y - proj1Box2.x;
	float abs_dl1 = dl1;
	if(abs_dl1 < 0)
	{
		abs_dl1 = -abs_dl1;
	}
    float abs_dl2 = dl2;
	if(abs_dl2 < 0)
	{
		abs_dl2 = -abs_dl2;
	}
	float sum = abs( proj1Box1.x - proj1Box1.y) + abs(proj1Box2.x - proj1Box2.y);
    float len = abs(min_x - max_x);
	
	
	if (sum <= len)
	{
		return empty;
	}
	
	if (Equality(abs_dl1, abs_dl2))
	{
		if (Equality(abs_dl1, min_dl))
		{
			min_dl = abs_dl1;
			CreateVector2(&ret, 1, 0);
		}
	}
	else {
		if (Equality(abs_dl2, min_dl))
		{
			min_dl = abs_dl2;
			CreateVector2(&ret, -1, 0);
		}
	}
	//printf("%f\n", min_dl / 2);
	
	
	

	CreateVector2(&proj1Box1, 
	(float)transform1.position.y - (float)box1->size.y * (float)transform1.scale.y / 2,
	(float)transform1.position.y + (float)box1->size.y * (float)transform1.scale.y / 2);
	
	CreateVector2(&proj1Box2, 
	(float)transform2.position.y - (float)box2->size.y * (float)transform1.scale.y / 2,
	(float)transform2.position.y + (float)box2->size.y * (float)transform1.scale.y / 2);
	
	min_x = min(proj1Box1.x, proj1Box2.x);
	max_x = max(proj1Box1.y, proj1Box2.y);
	dl1 = proj1Box1.x - proj1Box2.y;
	dl2 = proj1Box1.y - proj1Box2.x;
	abs_dl1 = dl1;
	if(abs_dl1 < 0)
	{
		abs_dl1 = -abs_dl1;
	}
    abs_dl2 = dl2;
	if(abs_dl2 < 0)
	{
		abs_dl2 = -abs_dl2;
	}
	sum = abs( proj1Box1.x - proj1Box1.y) + abs(proj1Box2.x - proj1Box2.y);
    len = abs(min_x - max_x);
	
	
	if (sum <= len)
	{
		return empty;
	}
	
	if (Equality(abs_dl1, abs_dl2))
	{
		if (Equality(abs_dl1, min_dl))
		{
			min_dl = abs_dl1;
			CreateVector2(&ret, 0, 1);
		}
	}
	else {
		if (Equality(abs_dl2, min_dl))
		{
			min_dl = abs_dl2;
			CreateVector2(&ret, 0, -1);
		}
	}

	Vector2 t = multiple(ret, min_dl);
	return t;
}
#include "Vector2.h"
#include <math.h>

void CreateVector2(Vector2* vector, float x, float y)
{
	vector->x = x;
	vector->y = y;
}


void swap_Vector2(Vector2* a, Vector2* b)
{
	Vector2 temp = *a;
	*a = *b;
	*b = temp;
}

Vector2 newVector2(float x, float y)
{
	Vector2 res = {x, y};
	return res;
}

Vector2 add(Vector2 a, Vector2 b)
{
	Vector2 ret = a;
	ret.x += b.x;
	ret.y += b.y;
	return ret;
}

Vector2 multiple(Vector2 vector, float number)
{
	Vector2 ret = vector;
	ret.x *= number;
	ret.y *= number;
	return ret;
}

Vector2 MoveTowards(Vector2 start, Vector2 target, float MaxDeltaLength)
{
	Vector2 res = {target.x - start.x, target.y - start.y};
	float l = length(res);
	if(MaxDeltaLength > l)
	{
		return target;
	}
	res = add(start, multiple(res, MaxDeltaLength / l));
	return res;
}

float length(Vector2 a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}

float lengthSquare(Vector2 a)
{
	return a.x * a.x + a.y * a.y;
}


void swap_float(float* a, float* b)
{
	float temp = *a;
	*a = *b;
	*b = temp;
}

void swap_int(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap_double(double* a, double* b)
{
	double temp = *a;
	*a = *b;
	*b = temp;
}
#include "Vector2.h"

void CreateVector2(Vector2* vector, float x, float y)
{
	vector->x = x;
	vector->y = y;
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
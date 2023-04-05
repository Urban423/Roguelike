#ifndef VECTOR2_H_
#define VECTOR2_H_

struct Vector2;

typedef struct Vector2
{
	float x;
	float y;
}Vector2;

void CreateVector2(Vector2* vector, float x, float y);
Vector2 add(Vector2 a, Vector2 b);
Vector2 multiple(Vector2 vector, float number);
#endif
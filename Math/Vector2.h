#ifndef VECTOR2_H_
#define VECTOR2_H_

struct Vector2;

typedef struct Vector2
{
	float x;
	float y;
}Vector2;

Vector2 newVector2(float x, float y);
void CreateVector2(Vector2* vector, float x, float y);
Vector2 add(Vector2 a, Vector2 b);
Vector2 multiple(Vector2 vector, float number);
void swap_Vector2(Vector2* a, Vector2* b);
Vector2 MoveTowards(Vector2 start, Vector2 target, float MaxDeltaLength);
float length(Vector2 a);
float lengthSquare(Vector2 a);

typedef struct Transfrom
{
	Vector2 position;
	float rotation;
	Vector2 scale;
}Transfrom;

typedef struct Buffer
{
	int width;
	int height;
	int* buffer;
}Buffer;




void swap_float(float* a, float* b);
void swap_int(int* a, int* b);
void swap_double(double* a, double* b);

#endif
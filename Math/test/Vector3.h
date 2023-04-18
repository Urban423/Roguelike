#pragma once

typedef struct Vector3
{
	float x;
	float y;
	float z;
}Vector3;

Vector3 newVector3(float x, float y, float z);
Vector3 cross(Vector3 a, Vector3 b);

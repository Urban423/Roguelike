#include "Vector3.h"

Vector3 newVector3(float x, float y, float z)
{
	Vector3 ret = {x, y, z};
	return ret;
}

Vector3 cross(Vector3 a, Vector3 b)
{
	Vector3 ret = {
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	};
	return ret;
}
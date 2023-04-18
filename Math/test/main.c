#include <stdio.h>
#include "Color.h"
#include "Matrix3x3.h"
#include "Vector2.h"
#include "Vector3.h"
#include "VertexMesh.h"
#include <assert.h>

char MultipleColorTest()
{
	Color a = MultipleColor((Color){1, 1, 1, 0}, 2);
	Color b = (Color){2, 2, 2, 0};
	if(!(a.r == b.r && a.g == b.g && a.b == b.b && a.a == b.a))
	{
		return 1;
	}
	return 0;
}

int main()
{
	if(!MultipleColorTest())
	{
		printf("MultipleColor Test: OK\n");
	}
	return 0;
}
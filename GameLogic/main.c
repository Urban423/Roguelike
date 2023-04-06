#include <stdio.h>
#include <unistd.h>
#include "Object.h"
#include "ObjectHelper.h"
#include "Vector2.h"
#include "ExampleClass.h"

int main()
{
	Object obj;
	Object obj2;
	Vector2 vect;
	ExampleClass* res;
	
	CreateVector2(&vect, 1, 1);
	ObjectConstructor(&obj, vect, vect);
	ObjectConstructor(&obj2, vect, vect);
	TEMPLATE(AddComponent, ExampleClass)(&obj, &res);
	TEMPLATE(AddComponent, ExampleClass)(&obj2, &res);
	res->ex = 2;
	
	UpdateAll(&obj);
	TEMPLATE(GetComponent, ExampleClass)(&obj, &res);
	lol(res, &obj2);
	UpdateAll(&obj2);
	
	system("Pause");
	return 0;
}
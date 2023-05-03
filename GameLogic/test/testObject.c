#include "testObject.h"
#include <Object.h>
#include <Vector2.h>

char test_ObjectConstructor()
{
	Vector2 vect = {0, 0};
	Vector2 sca = {1, 1};
	Object test;
	ObjectConstructor(&test, vect, sca);
	
	char res = test.enabled == 1
	&& test.componentManager.next == 0
	&& test.transform.position.x == vect.x
	&& test.transform.position.y == vect.y
	&& test.transform.rotation == 0
	&& test.number_of_components == 0
	&& test.transform.scale.x == sca.x
	&& test.transform.scale.y == sca.y
	&& test.parent == 0;
	
	return !res;
}

char test_UpdateObject()
{
	Vector2 vect = {0, 0};
	Vector2 sca = {1, 1};
	Object test;
	Object test2;
	ObjectConstructor(&test, vect, sca);
	ObjectConstructor(&test2, vect, sca);
	UpdateObject(&test);
	
	if(test.enabled != test2.enabled || test.number_of_components != test2.number_of_components)
	{
		return 1;
	}
	return 0;
}
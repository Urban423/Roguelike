#include "Physics.h"
#include <ObjectHelper.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char testCalculatePhysic()
{
	Vector2 vect;
	Vector2 sca;
	ObjectManager manager;
	Object A;
	Object B;
	memset(&manager, 0, sizeof(ObjectManager));
	
	
	BoxCollider* box;
	Rigidbody* rigidbody;
	
	
	CreateVector2(&sca, 1, 1);
	CreateVector2(&vect, 0, 0);
	ObjectConstructor(&A, vect, sca);
	TEMPLATE(AddComponent, BoxCollider)(&A, &box);
	TEMPLATE(AddComponent, Rigidbody)(&A, &rigidbody);
	AddObject(&manager, &A);
	
	CreateVector2(&sca, 1, 1);
	CreateVector2(&vect, 0, 0.3f);
	ObjectConstructor(&B, vect, sca);
	TEMPLATE(AddComponent, BoxCollider)(&B, &box);
	AddObject(&manager, &B);
	
	CalculatePhysic(&manager);
	
	char res = A.transform.position.x == 0 && A.transform.position.y == -0.7f && B.transform.position.x == 0 && B.transform.position.y == 0.3f;
	if(!res)
	{
		return 1;
	}
	
	return 0;
}
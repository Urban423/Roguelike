#include <stdio.h>
#include "testObject.h"
#include "testPhysics.h"
#include "testLevelGenerator.h"
#include "testTimeSystem.h"
#include "testInput.h"

int main()
{
	if(test_ObjectConstructor())
	{
		printf("testing ObjectConstructor: ERROR\n");
	}
	else{	
		printf("testing ObjectConstructor: SUCCSESSFULL\n");
	}
	
	if(test_UpdateObject())
	{
		printf("testing UpdateObject: ERROR\n");
	}
	else{	
		printf("testing UpdateObject: SUCCSESSFULL\n");
	}
	
	if(testCalculatePhysic())
	{
		printf("testing UpdatePhysic: ERROR\n");
	}
	else{	
		printf("testing UpdatePhysic: SUCCSESSFULL\n");
	}
	
	if(testGenerateLevel())
	{
		printf("testing GenerateLevel: ERROR\n");
	}
	else{	
		printf("testing GenerateLevel: SUCCSESSFULL\n");
	}
	
	if(testCreateTime())
	{
		printf("testing CreateTime: ERROR\n");
	}
	else{	
		printf("testing CreateTime: SUCCSESSFULL\n");
	}
	
	if(testUpdateTime())
	{
		printf("testing UpdateTime: ERROR\n");
	}
	else{	
		printf("testing UpdateTime: SUCCSESSFULL\n");
	}
	
	if(testSetKeyBoard())
	{
		printf("testing SetInput: ERROR\n");
	}
	else{	
		printf("testing SetInput: SUCCSESSFULL\n");
	}
	return 0;
}
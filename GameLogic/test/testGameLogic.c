#include "testGameLogic.h"

int testGameLogic()
{
	if(test_ObjectConstructor())
	{
		printf("testing ObjectConstructor: ERROR\n");
		return 1;
	}
	else{	
		printf("testing ObjectConstructor: SUCCSESSFULL\n");
	}
	
	if(test_UpdateObject())
	{
		printf("testing UpdateObject: ERROR\n");
		return 1;
	}
	else{	
		printf("testing UpdateObject: SUCCSESSFULL\n");
	}
	
	if(testCalculatePhysic())
	{
		printf("testing UpdatePhysic: ERROR\n");
		return 1;
	}
	else{	
		printf("testing UpdatePhysic: SUCCSESSFULL\n");
	}
	
	if(testGenerateLevel())
	{
		printf("testing GenerateLevel: ERROR\n");
		return 1;
	}
	else{	
		printf("testing GenerateLevel: SUCCSESSFULL\n");
	}
	
	if(testCreateTime())
	{
		printf("testing CreateTime: ERROR\n");
		return 1;
	}
	else{	
		printf("testing CreateTime: SUCCSESSFULL\n");
	}
	
	if(testUpdateTime())
	{
		printf("testing UpdateTime: ERROR\n");
		return 1;
	}
	else{	
		printf("testing UpdateTime: SUCCSESSFULL\n");
	}
	
	if(testSetKeyBoard())
	{
		printf("testing SetInput: ERROR\n");
		return 1;
	}
	else{	
		printf("testing SetInput: SUCCSESSFULL\n");
	}
	return 0;
}
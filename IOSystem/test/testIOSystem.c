#include "testIOSystem.h"
#include "testIOLoader.h"
#include <stdio.h>

int testIOSystem()
{
	if(test_createWindow())
	{
		printf("testing createOut: ERROR\n");
		return 1;
	}
	printf("testing createOut: SUCCESSFULL\n");
	
	if(test_updateWindow())
	{
		printf("testing updateOut: ERROR\n");
		return 1;
	}
	printf("testing updateOut: SUCCESSFULL\n");
	
	
	if(test_createKeyBoard())
	{
		printf("testing createInput: ERROR\n");
		return 1;
	}	
	printf("testing createInput: SUCCSESSFULL\n");
	
	if(test_updateKeyBoard())
	{
		printf("testing updateInput: ERROR\n");
		return 1;
	}	
	printf("testing updateInput: SUCCESSFULL\n");
	
	
	if(testShowError())
	{
		printf("testing ShowError: ERROR\n");
		return 1;
	}
	printf("testing ShowError: SUCCESSFULL\n");
	
	
	if(testShowMenu())
	{
		printf("testing ShowMenu: ERROR\n");
		return 1;
	}	
	printf("testing ShowMenu: SUCCESSFULL\n");
	
	return 0;	
}
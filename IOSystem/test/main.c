#include <stdio.h>
#include "testIOLoader.h"

int main()
{
	if(test_createWindow())
	{
		printf("testing createOut: ERROR\n");
	}
	else{	
		printf("testing createOut: SUCCSESSFULL\n");
	}
	
	if(test_updateWindow())
	{
		printf("testing updateOut: ERROR\n");
	}
	else{	
		printf("testing updateOut: SUCCSESSFULL\n");
	}
	
	
	if(test_createKeyBoard())
	{
		printf("testing createInput: ERROR\n");
	}
	else{	
		printf("testing createInput: SUCCSESSFULL\n");
	}
	
	if(test_updateKeyBoard())
	{
		printf("testing updateInput: ERROR\n");
	}
	else{	
		printf("testing updateInput: SUCCSESSFULL\n");
	}
	
	
	if(testShowError())
	{
		printf("testing ShowError: ERROR\n");
	}
	else{	
		printf("testing ShowError: SUCCSESSFULL\n");
	}
	
	
	if(testShowMenu())
	{
		printf("testing ShowMenu: ERROR\n");
	}
	else{	
		printf("testing ShowMenu: SUCCSESSFULL\n");
	}
	
	return 0;
}
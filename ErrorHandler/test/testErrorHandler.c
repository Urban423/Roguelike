#include "ErrorHandler.h"
#include "testErrorHandler.h"
#include <stdio.h>

const char* errorList[2] = {
	"Error",
	"FileReadERROR"
};

char* thandleError(char error)
{
	if(error == 1)
	{
		return (char*)errorList[1];
	}
	return (char*)errorList[0];
}

char testErrorHandler()
{
	char* check = thandleError(12);
	const char* error = "Error";
	int index = 0;
	while(1)
	{
		if(check[index] == 0)
		{
			break;
		}
		if(check[index] != error[index])
		{
			return 1;
		}
		index++;
	}
	return 0;
}

int testErrorHandlerLib()
{
	if(testErrorHandler())
	{
		printf("testing ErrorHandler: ERROR\n");
		return 1;
	}	
	printf("testing ErrorHandler: SUCCESSFULL\n");
	
	return 0;
}
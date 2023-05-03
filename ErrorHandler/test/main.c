#include <stdio.h>
#include "testErrorHandler.h"

int main()
{
	if(testErrorHandler())
	{
		printf("testing ErrorHandler: ERROR\n");
	}
	else{	
		printf("testing ErrorHandler: SUCCSESSFULL\n");
	}
	
	
	return 0;
}
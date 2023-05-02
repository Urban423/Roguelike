#include <stdio.h>
#include "testGraphicsEngine.h"

int main()
{
	if(testBufferConstructor())
	{
		printf("testing BufferConstructor: ERROR\n");
	}
	else{	
		printf("testing BufferConstructor: SUCCSESSFULL\n");
	}
	if(testBufferClear())
	{
		printf("testing BufferClear: ERROR\n");
	}
	else{	
		printf("testing BufferClear: SUCCSESSFULL\n");
	}
	if(testBufferDrawObject())
	{
		printf("testing BufferDrawObject: ERROR\n");
	}
	else{	
		printf("testing BufferDrawObject: SUCCSESSFULL\n");
	}
	return 0;
}
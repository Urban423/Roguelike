#include "../GraphicsEngine.h"
#include <stdio.h>

char test_BufferClear()
{
	int buffer_result = 0;
	
	Buffer buffer;
	BufferConstructor(&buffer, 12, 12);
	if(1)
	{
		printf("BufferClear: ERROR\n");
		return 1;
	}
	printf("BufferClear: OK\n");
	return 0;
}

int main()
{
	if(test_BufferClear)
	{
		return 1;
	}
	
	return 0;
}
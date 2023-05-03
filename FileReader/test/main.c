#include <stdio.h>
#include "teststatistic.h"
int main()
{
	if(testSaveStatistic())
	{
		printf("testing SaveStatistic: ERROR\n");
	}
	else{
		printf("testing SaveStatistic: SUCCSESSFULL\n");
	}
	if(testGetStatistic())
	{
		printf("testing testGetStatistic: ERROR\n");
	}
	else{
		printf("testing testGetStatistic: SUCCSESSFULL\n");
	}
	return 0;
}
#include "testSaveLoadSystem.h"
#include "teststatistic.h"

int testSaveLoadSystem()
{
	if(testSaveStatistic())
	{
		printf("testing SaveStatistic: ERROR\n");
		return 1;
	}
	printf("testing SaveStatistic: SUCCSESSFULL\n");
	if(testGetStatistic())
	{
		printf("testing GetStatistic: ERROR\n");
		return 1;
	}
	printf("testing GetStatistic: SUCCSESSFULL\n");
	return 0;
}

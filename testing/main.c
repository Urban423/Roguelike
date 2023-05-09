#include "testGameLogic.h"
#include "testErrorHandler.h"
#include "testSaveLoadSystem.h"
#include "testGraphicsEngine.h"
#include "testIOSystem.h"

int main()
{
	if(testGameLogic())
	{
		return 1;
	}
	if(testErrorHandlerLib())
	{
		return 1;
	}
	if(testSaveLoadSystem())
	{
		return 1;
	}
	if(testGraphicsEngine())
	{
		return 1;
	}
	if(testIOSystem())
	{
		return 1;
	}
	return 0;
}
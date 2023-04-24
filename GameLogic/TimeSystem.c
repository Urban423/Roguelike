#include "TimeSystem.h"
#include <time.h>

TimeSystem Time;

void CreateTime(TimeSystem* timeSys)
{
	timeSys->new_delta = clock();
	timeSys->old_delta = clock();
	
	timeSys->timescale = 1;
	timeSys->deltaTime = 0;
}


void UpdateTime(TimeSystem* timeSys)
{
	timeSys->old_delta = timeSys->new_delta;
	timeSys->new_delta = clock();
	
	timeSys->deltaTime = (timeSys->old_delta) ? (timeSys->new_delta - timeSys->old_delta) * timeSys->timescale / 1000 : 0;
}
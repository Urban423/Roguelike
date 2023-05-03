#include "TimeSystem.h"
#include "testTimeSystem.h"
#include <time.h>
#include <unistd.h>

char testCreateTime()
{
	TimeSystem Time;
	CreateTime(&Time);
	
	char res = Time.timescale == 1 && Time.deltaTime == 0 && Time.new_delta == Time.old_delta;
	
	return !res;
}

char testUpdateTime()
{
	TimeSystem Time;
	CreateTime(&Time);
	sleep(1);
	UpdateTime(&Time);
	
	char res = Time.timescale == 1 && Time.deltaTime != 0 && Time.new_delta != Time.old_delta;
	
	return !res;
}
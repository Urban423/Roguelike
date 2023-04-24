#pragma once

typedef struct TimeSystem
{
	long new_delta;
	long old_delta;
	
	float timescale;
	float deltaTime;
}TimeSystem;

void CreateTime(TimeSystem* timeSys);
void UpdateTime(TimeSystem* timeSys);
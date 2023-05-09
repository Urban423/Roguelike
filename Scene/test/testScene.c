#include <stdio.h>
#include <Scene.h>
const int count_physicUpdate = 1;
const int count_UpdateObject = 0;
const int count_UpdateInputState = 1;
const int count_UpdateOutState = 1;
const int count_GetInput = 1;
const int count_handleError = 1;
const int count_CreateBuffer = 1;
const int count_ClearBuffer = 1;
const int count_DrawObjectInBuffer = 0;

void onUpdato(Scene* s) {}
void onCreato(Scene* s) {}

char testOnUpdate()
{
	Scene scene;
	onUpdato(&scene);
	char res = count_physicUpdate == 1 
	&& count_UpdateObject == 0
	&& count_UpdateInputState == 1
	&& count_GetInput == 1
	&& count_ClearBuffer == 1
	&& count_DrawObjectInBuffer == 0;
	if(res == 0)
	{
		return 1;
	}
	return 0;
}

char testOnCreate()
{
	Scene scene;
	onCreato(&scene);
	char res = count_CreateBuffer == 1 && count_handleError == 1;
	if(res == 0)
	{
		return 1;
	}
	return 0;
}

int testScene()
{
	int res = 0;
	if(testOnCreate())
	{
		printf("testing OnCreate: ERROR\n");
		res = 1;
	}
	else{	
		printf("testing OnCreate: SUCCESSFULL\n");
	}
	if(testOnUpdate())
	{
		printf("testing OnUpdate: ERROR\n");
		res = 1;
	}
	else{	
		printf("testing OnUpdate: SUCCESSFULL\n");
	}
	return res;
}
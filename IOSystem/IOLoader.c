#include "IOLoader.h"
#include <unistd.h>
#include <stdio.h>
#include <time.h>

float old_time;

char createWindow(Renderer* renderer)
{
	struct timeval currentTime;
	mingw_gettimeofday(&currentTime, NULL);
	
	old_time = currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
	#ifdef WIN32
		return createWindowsWindow(renderer);
	#elif defined __linux__
		return createLinuxWindow(renderer);
	#endif

}


char updateWindow(Renderer* renderer, unsigned long time_of_begin)
{
	struct timeval currentTime;
	mingw_gettimeofday(&currentTime, NULL);
	
	float new_time = currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
	float delta = new_time - old_time;
	old_time = new_time;
	//printf("%f\n", delta / 1000);
	#ifdef WIN32
		return updateWindowsWindow(renderer);
	#elif defined __linux__
		return updateLinuxWindow(renderer);
	#endif
}


char createKeyBoard(KeyBoardState* keyBoard)
{
	#ifdef WIN32
		createWindowsKeyBoard(keyBoard);
	#elif defined __linux__
		createLinuxKeyBoardState(keyBoard);
	#endif
	return 0;
}


char updateKeyBoard(KeyBoardState* keyBoard)
{
	#ifdef WIN32
		updateWindowsKeyBoard(keyBoard);
	#elif defined __linux__
		updateLinuxKeyBoardState(keyBoard);
	#endif
	return 0;
}
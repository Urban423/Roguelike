#include "testIOLoader.h"
#include <stdio.h>
#define updateKeyBoard() 0

int showMenu()
{
	printf("Roguelike\n");
	printf("New Game\n");
	printf("Statistic\n");
	printf("Exit\n");
}

int showError(char* error)
{
	printf("%s\n", error);
}

char test_createWindow()
{
	return 0;
}

char test_updateWindow()
{
	//char updateKeyBoard(KeyBoardState* keyBoard);
	if(updateKeyBoard())
	{
		return 1;
	}
	return 0;
}

char test_createKeyBoard()
{
	return 0;
}

char test_updateKeyBoard()
{
	return 0;
}





char testShowError(){
	freopen("out.txt", "w", stdout);
	showError((char*)"u stupid");
	fclose(stdout);
	freopen("CON", "w", stdout);
	
	const char* massive = "u stupid\n";
	
	FILE* f = fopen("out.txt", "r");
	char c;
	int index = 0;
	while(1)
	{
		c = getc(f);
		if(c == -1)
		{
			break;
		}
		
		if(c != massive[index])
		{
			fclose(f);
			return 1;
		}
		index++;
	}
	fclose(f);
	
	return 0;
}

char testShowMenu()
{
	freopen("out.txt", "w", stdout);
	showMenu();
	fclose(stdout);
	freopen("CON", "w", stdout);
	
	const char* massive = "Roguelike\nNew Game\nStatistic\nExit\n";
	
	
	FILE* f = fopen("out.txt", "r");
	char c;
	int index = 0;
	while(1)
	{
		c = getc(f);
		if(c == -1)
		{
			break;
		}
		
		if(c != massive[index])
		{
			fclose(f);
			return 1;
		}
		index++;
	}
	fclose(f);
	
	return 0;
}
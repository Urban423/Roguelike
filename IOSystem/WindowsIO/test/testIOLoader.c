#include "testIOLoader.h"
#include <stdio.h>
#include "WindowsInputSystem.h"

int showMenu()
{
	printf("Roguelike\n");
	printf("New Game\n");
	printf("Statistic\n");
	printf("Exit\n");
}

void CreateInput(KeyBoardState* keys)
{
	for(int i = 0;i < 256; i++)
	{
		keys->key_board_state[i] = fgetc(stdin);
	}
}
void UpdateInput(KeyBoardState* keys)
{
	for(int i = 0;i < 256; i++)
	{
		keys->key_board_state[i] = fgetc(stdin);
	}
}

int showError(char* error)
{
	printf("%s\n", error);
}

int UpdateOut(char* error)
{
	printf("%s\n", error);
}

int CreateOut(char* error)
{
	printf("%s\n", error);
}

char test_createWindow()
{
	freopen("out.txt", "w", stdout);
	CreateOut((char*)"u stupid");
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

char test_updateWindow()
{
	freopen("out.txt", "w", stdout);
	UpdateOut((char*)"u stupid");
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

char test_createKeyBoard()
{
	KeyBoardState keys;
	freopen("input.txt", "r", stdin);
	CreateInput(&keys);
	fclose(stdout);
	freopen("CON", "w", stdout);
	
	for(int i = 0;i < 256; i++)
	{
		if(keys.key_board_state[i] != 0)
		{
			return 1;
		}			
	}
	
	return 0;
}
char test_updateKeyBoard()
{
	KeyBoardState keys;
	freopen("input.txt", "r", stdin);
	UpdateInput(&keys);
	fclose(stdout);
	freopen("CON", "w", stdout);
	
	for(int i = 0;i < 256; i++)
	{
		if(keys.key_board_state[i] != 0)
		{
			return 1;
		}			
	}
	
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
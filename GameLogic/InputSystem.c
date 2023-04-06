#include "InputSystem.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void Keys(char** key_board_state, char** old_key_board_state, char flag)
{
	static char* new_keys;
	static char* old_keys;
	
	if(flag == 1)
	{
		new_keys = malloc(256);
		old_keys = malloc(256);
		system("pause");
		printf("%d\n", **key_board_state);
		system("pause");
		for(int i = 0; i < 256; i++)
		{
			new_keys[i] = *key_board_state[i];
			system("pause");
			old_keys[i] = *old_key_board_state[i];
		}
		system("pause");
		return;
	}
	if(flag == 2)
	{
		for(int i = 0; i < 256; i++)
		{
			new_keys[i] = *key_board_state[i];
			old_keys[i] = *old_key_board_state[i];
		}
		return;
	}
	*key_board_state = new_keys;
	*old_key_board_state = old_keys;
}

char GetKey(char key_code)
{
	char* key_board_state;
	char* old_key_board_state;
	Keys(&key_board_state, &old_key_board_state, 0);
	
	char l = *key_board_state;
	printf("got %c\n", l);
	
	return 0;
}


char GetKeyDown(char key_code)
{
	char* key_board_state;
	char* old_key_board_state;
	Keys(&key_board_state, &old_key_board_state, 0);
	if(key_board_state[key_code] != old_key_board_state[key_code] && key_board_state[key_code] == 2)
	{
		return 1;
	}
	return 0;
}


char GetKeyUp(char key_code)
{
	char* key_board_state;
	char* old_key_board_state;
	Keys(&key_board_state, &old_key_board_state, 0);
	if(key_board_state[key_code] != old_key_board_state[key_code] && old_key_board_state[key_code] == 2)
	{
		return 1;
	}
	return 0;
}
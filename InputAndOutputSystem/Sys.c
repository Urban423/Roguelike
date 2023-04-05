#include <conio.h>
#include <stdio.h>
#include "Sys.h"
#include <windows.h>

void systemPause()
{
	printf("press any key to continue...\n");
	char cd= getch();
}

void UpdateKeyBoard(KeyBoardState* this)
{
	GetKeyboardState(this->old_key_board_state);
	for(int i = 0; i < 256; i++)
	{
		printf("%d", this->old_key_board_state[i]);
	}
}
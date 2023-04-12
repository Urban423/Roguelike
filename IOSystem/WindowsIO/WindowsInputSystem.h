#pragma once

typedef struct KeyBoardState
{
	char key_board_state[256];
	char old_key_board_state[256];
}KeyBoardState;

void createWindowsKeyBoard(KeyBoardState* this);
void updateWindowsKeyBoard(KeyBoardState* this);
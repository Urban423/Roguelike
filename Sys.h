#pragma once

void systemPause();

typedef struct KeyBoardState
{
	char old_key_board_state[256];
}KeyBoardState;

void UpdateKeyBoard(KeyBoardState* this);
char GetKey(char key_code);
char GetKeyDown(char key_code);
char GetKeyUp(char key_code);
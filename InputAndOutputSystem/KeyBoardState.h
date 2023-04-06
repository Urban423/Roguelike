#pragma once

typedef struct KeyBoardState
{
	char key_board_state[256];
	char old_key_board_state[256];
}KeyBoardState;

void CreateKeyBoard(KeyBoardState* this);
void UpdateKeyBoard(KeyBoardState* this);

char GetKey(char key_code);
char GetKeyDown(char key_code);
char GetKeyUp(char key_code);
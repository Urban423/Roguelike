#pragma once
#include "GameMessages.h"

typedef struct KeyCodes
{
	
	char LeftArrow;
	char UpArrrow;
	char RightArrow;
	char DownArrow;
	
	char Alpha0;
	char Alpha1;
	char Alpha2;
	char Alpha3;
	char Alpha4;
	char Alpha5;
	char Alpha6;
	char Alpha7;
	char Alpha8;
	char Alpha9;
	
	char A;
	char B;
	char C;
	char D;
	char E;
	char F;
	char G;
	char H;
	char I;
	char J;
	char K;
	char L;
	char M;
	char N;
	char O;
	char P;
	char Q;
	char R;
	char S;
	char T;
	char U;
	char V;
	char W;
	char X;
	char Y;
	char Z;
	char Enter;
	char Escape;
	char Space;
	char LeftShift;
}KeyCodes;

char setKeyBoard(char* keyBoardStatePointer, char* oldKeyBoardStatePointer);


char GetKeyMoveUp();
char GetKeyMoveDown();
char GetKeyMoveRight();
char GetKeyMoveLeft();

char GetKeyDownMoveUp();
char GetKeyDownMoveDown();
char GetKeyDownMoveRight();
char GetKeyDownMoveLeft();

char GetKey(char key_code);
char GetKeyDown(char key_code);
char GetKeyUp(char key_code);
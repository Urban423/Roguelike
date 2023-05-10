#include "Input.h"


KeyCodes KeyCode;

void CreateKeyCode()
{
	KeyCode.Enter = 13;
	KeyCode.Escape = 27;
	KeyCode.Space = 32;
	KeyCode.Alpha0 = 48;
	KeyCode.Alpha1 = 49;
	KeyCode.Alpha2 = 50;
	KeyCode.Alpha3 = 51;
	KeyCode.Alpha4 = 52;
	KeyCode.Alpha5 = 53;
	KeyCode.Alpha6 = 54;
	KeyCode.Alpha7 = 55;
	KeyCode.Alpha8 = 56;
	KeyCode.Alpha9 = 57;
	KeyCode.A = 65;
	KeyCode.B = 66;
	KeyCode.C = 67;
	KeyCode.D = 68;
	KeyCode.E = 69;
	KeyCode.F = 70;
	KeyCode.G = 71;
	KeyCode.H = 72;
	KeyCode.I = 73;
	KeyCode.J = 74;
	KeyCode.K = 75;
	KeyCode.L = 76;
	KeyCode.M = 77;
	KeyCode.N = 78;
	KeyCode.O = 79;
	KeyCode.P = 80;
	KeyCode.Q = 81;
	KeyCode.R = 82;
	KeyCode.S = 83;
	KeyCode.T = 84;
	KeyCode.U = 85;
	KeyCode.V = 86;
	KeyCode.W = 87;
	KeyCode.X = 88;
	KeyCode.Y = 89;
	KeyCode.Z = 90;
}

char* keyBoardState;
char* oldKeyBoardState;

char setKeyBoard(char* keyBoardStatePointer, char* oldKeyBoardStatePointer)
{
	keyBoardState = keyBoardStatePointer;
	oldKeyBoardState = oldKeyBoardStatePointer;
	CreateKeyCode();
}

char GetKey(char key_code)
{
	if(keyBoardState[key_code] == oldKeyBoardState[key_code] && keyBoardState[key_code] == 2)
	{
		return 1;
	}
	return 0;
}

char GetKeyDown(char key_code)
{
	if(keyBoardState[key_code] != oldKeyBoardState[key_code] && keyBoardState[key_code] == 2)
	{
		return 1;
	}
	return 0;
}

char GetKeyUp(char key_code)
{
	if(keyBoardState[key_code] != oldKeyBoardState[key_code] && oldKeyBoardState[key_code] == 2)
	{
		return 1;
	}
	return 0;
}
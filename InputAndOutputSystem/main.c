#include "InputSystem.h"

int main()
{
	KeyBoardState keys;
	CreateKeyBoard(&keys);
	while(1)
	{
		UpdateKeyBoard(&keys);
	}
	return 1;
}
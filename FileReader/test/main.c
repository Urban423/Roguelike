#include <stdio.h>
#include "testBMPImage.h"

int main()
{
	Texture texture;
	if(test_ReadBMPFile(&texture, "./Assets/ex.bmp"))
	{
		printf("testing ReadBMPImage: ERROR\n");
		return 1;
	}
	printf("testing ReadBMPImage: SUCCSESSFULL\n");
	return 0;
}
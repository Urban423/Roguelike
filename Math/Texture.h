#pragma once
#include <stdlib.h>
#include <stdint.h>

typedef struct Texture
{
	int* pixels;
	unsigned char* alpha;
	unsigned int width;
	unsigned int height;
}Texture;

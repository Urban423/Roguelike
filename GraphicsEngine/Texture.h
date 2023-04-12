#pragma once
#include <stdlib.h>
#include <stdint.h>

typedef struct Texture
{
	char* pixels;
	unsigned int width;
	unsigned int height;
}Texture;

void CreateTextureFromFile(Texture* this, const char* filename);
#pragma once

typedef struct Buffer
{
	unsigned int width;
	unsigned int height;
	char* buffer;
}Buffer;

void BufferConstructor(Buffer* buffer, unsigned int width, unsigned int height, char sprite);
void BufferClear(Buffer* buffer, char sprite);
void BufferDrawObject(Buffer* buffer, unsigned int pos_x, unsigned int pos_y, char sprite);
void BufferDraw(Buffer* buffer);


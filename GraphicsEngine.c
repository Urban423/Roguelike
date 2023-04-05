#include "GraphicsEngine.h"
#include <stdio.h>
#include <stdlib.h>

void BufferConstructor(Buffer* buffer, unsigned int width, unsigned int height, char sprite) {
    buffer->width = width;
    buffer->height = height;
    buffer->buffer = (char*) malloc((width * height + height + 1) * sizeof(char));

    unsigned int index = 0;
    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            buffer->buffer[index++] = sprite;
        }
        buffer->buffer[index++] = '\n';
    }
    buffer->buffer[index] = '\0';
}

void BufferClear(Buffer* buffer, char sprite) {
    unsigned int index = 0;
    for (unsigned int y = 0; y < buffer->height; y++) {
        for (unsigned int x = 0; x < buffer->width; x++) {
            buffer->buffer[index++] = sprite;
        }
        index++; // Skip newline character
    }
}

void BufferDrawObject(Buffer* buffer, unsigned int pos_x, unsigned int pos_y, char sprite) {
    if (pos_x < buffer->width && pos_y < buffer->height && pos_x>=0 && pos_y>=0) {
        buffer->buffer[pos_y * (buffer->width + 1) + pos_x] = sprite;
    }
}

void BufferDraw(Buffer* buffer) {
	system("cls");
    printf("%s", buffer->buffer);
}
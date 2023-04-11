#pragma once
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    unsigned short type;                 // Тип файла (должен быть 0x4D42)
    unsigned int size;                   // Размер файла в байтах
    unsigned short reserved1, reserved2; // Зарезервированные поля (должны быть 0)
    unsigned int offset;                 // Смещение до начала данных изображения
    unsigned int header_size;            // Размер заголовка (должен быть 40)
    int width, height;                   // Ширина и высота изображения в пикселях
    unsigned short planes;               // Количество цветовых плоскостей (должно быть 1)
    unsigned short bits_per_pixel;       // Битность цвета (должна быть 24)
    unsigned int compression;            // Тип сжатия (должен быть 0 для несжатых изображений)
    unsigned int image_size;             // Размер данных изображения в байтах
    int x_resolution, y_resolution;      // Горизонтальное и вертикальное разрешение (пикселей на метр)
    unsigned int colors_used;            // Количество используемых цветов (0)
    unsigned int colors_important;       // Количество "важных" цветов (0)
} BMPHeader;

typedef struct Texture
{
	char* pixels;
	unsigned int width;
	unsigned int height;
}Texture;

void CreateTextureFromFile(Texture* this, const char* filename);
#include "Texture.h"
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <unistd.h>

typedef struct
{
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t off_bits;
}__attribute__ ((packed)) bmp_file_header_t;

typedef struct
{
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bit_count;
    uint32_t compression;
    uint32_t size_image;
    uint32_t x_pels_permeter;
    uint32_t y_pels_permeter;
    uint32_t clr_used;
    uint32_t clr_important;
} bmp_info_header_t;

static bmp_file_header_t s_bmp_file_header = { 0x4d42, 0, 0, 0, 0 };
static bmp_info_header_t s_bmp_info_header = { 0, 0, 0, 1, 8, 0, 0, 0, 0, 0, 0 };

static uint8_t s_bmpdata[200 * 200] = { 0 };
static uint32_t s_bmp_col = 0;
static uint32_t s_bmp_row = 0;
char in_file_path[256] = "in.bmp";
char out_file_path[256] = "out.bmp";

void CreateTextureFromFile(Texture* this, const char* filename)
{
    FILE *file = NULL;
    uint32_t line_width = 0;
    uint32_t width = 0;
    uint32_t height = 0;
    int32_t err = 0;
    uint8_t buf[200 * 200] = { 0 };
    char temp[2048] = { 0 };
    int i = 0;

    do {
        file = fopen(filename, "rb");
        if (NULL == file)
        {
			err = -1;
            break;
        }
        fread(&s_bmp_file_header, sizeof(s_bmp_file_header), 1, file);

        fread(&s_bmp_info_header, sizeof(s_bmp_info_header), 1, file);
        fread(temp, 4*256, 1, file);
        width = s_bmp_info_header.width;
        height = s_bmp_info_header.height;
        this->width = width;
        this->height = height;
        line_width = (width + 3) / 4 * 4;
        printf("[%s] line_width = %d, width = %d, height = %d\n", __func__, line_width, width, height);

        for (i = height - 1; i >= 0; i--)
        {
			if (line_width == width)
			{
				fread(buf + i * width, width, 1, file);
		    }
		    else if (line_width > width)
			{
				fread(buf + i * width, width, 1, file);
				fread(temp, line_width-width, 1, file);
			}
        }
		this->pixels = (char*)malloc(width * height);
        memcpy(this->pixels , buf, width * height);

    } while (0);

    if (file != NULL)
    {
        fclose(file);
    }
}
#include "BMPImage.h"
#include <malloc.h>
#include <stdio.h>

char ReadBMPFile(Texture* texture, const char* filename)
{
    FILE *f = fopen(filename, "rb");
    if( !f ) return 1;

	short  bfType;
	int    bfSize;
	short  bfReserved1;
	short  bfReserved2;
	int    bfOffBits;
    fread(&bfType, sizeof(short), 1, f);
    fread(&bfSize, sizeof(int), 1, f);
    fread(&bfReserved1, sizeof(short), 1, f);
    fread(&bfReserved2, sizeof(short), 1, f);
    fread(&bfOffBits, sizeof(int), 1, f);
	
	
	//printf("%d %d %d %d %d\n", bfType, bfSize, bfReserved1, bfReserved2, bfOffBits);
	
	int    biSize;
	int    biWidth;
	int    biHeight;
	short   biPlanes;
	short   biBitCount;
	int    biCompression;
	int    biSizeImage; 
	int    biXPelsPerMeter;
	int    biYPelsPerMeter;
	int    biClrUsed;     
	int    biClrImportant;
	
	fread(&biSize, sizeof(int), 1, f);
    fread(&biWidth, sizeof(int), 1, f);
    fread(&biHeight, sizeof(int), 1, f);
    fread(&biPlanes, sizeof(short), 1, f);
    fread(&biBitCount, sizeof(short), 1, f);
    fread(&biCompression, sizeof(int), 1, f);
    fread(&biSizeImage, sizeof(int), 1, f);
    fread(&biXPelsPerMeter, sizeof(int), 1, f);
    fread(&biYPelsPerMeter, sizeof(int), 1, f);
    fread(&biClrUsed, sizeof(int), 1, f);
    fread(&biClrImportant, sizeof(int), 1, f);
	
	
	//printf("%d %d %d %d %d %d %d %d\n", biSize, biWidth, biHeight, biPlanes, biBitCount, biCompression, biSizeImage, biXPelsPerMeter, biYPelsPerMeter, biClrUsed, biClrImportant);

	texture->width = biWidth;
	texture->height = biHeight;
    texture->pixels = (char*)malloc(biWidth * biHeight * 4);

	fseek(f, bfOffBits, SEEK_SET);

	char temp;
	int index = 0;
    for(int y = 0; y < biHeight; y++) 
	{
		index = (biHeight - y - 1) * biWidth * 4;
        for(int x = 0; x < biWidth; x++) 
		{
			fread(&texture->pixels[index], biBitCount / 8, 1, f);
			temp = texture->pixels[index];
			texture->pixels[index] = texture->pixels[index + 2];
			texture->pixels[index + 2] = temp;
			if(biBitCount < 32)
			{
				texture->pixels[index + 3] = 255;
			}
			//printf("%d\n", texture->pixels[index + 3]); 
			index+=4;
        }
		fseek(f,  (biWidth* (biBitCount / 8)) % 4, SEEK_CUR);
    }
    return 0;
}
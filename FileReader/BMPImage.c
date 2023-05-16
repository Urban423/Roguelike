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
	
	//move to main data
	fseek(f, bfOffBits, SEEK_SET);
	
	//set texture's data
	texture->width = biWidth;
	texture->height = biHeight;
    texture->pixels = (int*)malloc(biWidth * biHeight * sizeof(int));
    texture->alpha = (unsigned char*)malloc(biWidth * biHeight);
	
	//helping values
	unsigned char* alpha_ptr = texture->alpha;
	char temp = 0;
	unsigned int index = 0;
	
    for(int y = 0; y < biHeight; y++) 
	{
		// left_bottom_corner index -> left_to_corner index
		index = (biHeight - y - 1) * biWidth;
		alpha_ptr = &texture->alpha[index];
		
        for(int x = 0; x < biWidth; x++) 
		{
			if(biBitCount == 32)
			{
				fread(&texture->pixels[index], 3, 1, f);
				fread(alpha_ptr, 1, 1, f);
			}
			else
			{
				fread(&texture->pixels[index], biBitCount / 8, 1, f);
				*alpha_ptr = 255;
			}
			
			//change indexes
			index++;
			alpha_ptr++;
        }
		
		//skip offset
		fseek(f,  (biWidth* (biBitCount / 8)) % 4, SEEK_CUR);
    }
    return 0;
}
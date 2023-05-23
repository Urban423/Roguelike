#include "GraphicsEngine.h"
#include "Vector2.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "Color.h"
#include "Triangle.h"

int min_int(int a, int b) { if(a < b) { return a; } return b; }
int max_int(int a, int b) { if(a > b) { return a; } return b; }


void BufferConstructor(Buffer* buffer, unsigned int width, unsigned int height) {
	buffer->width = width;
    buffer->height = height;
    buffer->buffer = (int*)malloc(width * height * sizeof(int));
}

void BufferClear(Buffer* buffer, char r, char g, char b)
{
	int* pointer = buffer->buffer;
	unsigned int size = buffer->width * buffer->height;
	int aim = (int)b + ((int)g << 8) + ((int)r << 16) + (255 << 24);
    for (unsigned int index = 0; index < size; index++)
	{
        *pointer = aim;
		pointer++;
    }
}

void BufferDrawObject(Buffer* buffer, 
Matrix3x3* world_pos, 
Matrix3x3* cam_view,
Matrix3x3* cam_proj, 
VertexMesh* mesh, Texture* texture)
{
	Matrix3x3 temp = MultipleMatrixMatrix(*world_pos, *cam_view);
	temp = MultipleMatrixMatrix(temp, *cam_proj);
	Vector2* copy_of_verticles = (Vector2*)malloc(sizeof(Vector2) * mesh->verticles_size);
	
	for(unsigned int i = 0; i < mesh->verticles_size; i++)
	{
		copy_of_verticles[i] = MultipleMatrixVector2(temp, mesh->verticles[i]);
	}
	
	for(unsigned int i = 0; i < mesh->faces_size; i += 3)	
	{
		int p1 = mesh->faces[i];
		int p2 = mesh->faces[i + 1];
		int p3 = mesh->faces[i + 2];
		DrawTriangleByTexture(
			buffer, 
			copy_of_verticles[p1], copy_of_verticles[p2], copy_of_verticles[p3],
			texture, 
			mesh->UV_map[p1], mesh->UV_map[p2], mesh->UV_map[p3]);
	}
		
	
	free(copy_of_verticles);
}

int CharToTextureIndex(char letter)
{
	if(letter > 96 && letter < 122)
	{
		return letter - 97;
	}
	if(letter > 64 && letter < 91)
	{
		return letter - 65;
	}
	if(letter > 47 && letter < 58)
	{
		return letter - 48 + 26;
	}
	return -1;
}

void BufferDrawText(Buffer* buffer, 
Matrix3x3* world_pos,
Matrix3x3* cam_view,
Matrix3x3* cam_proj,
VertexMesh* mesh, Texture* texture, char* text, unsigned int text_size)
{
	Matrix3x3 temp = MultipleMatrixMatrix(*world_pos, *cam_view);
	temp = MultipleMatrixMatrix(temp, *cam_proj);

	float x_offset_add = cam_proj->m_mat[0][0] * 1.1f;
	float y_offset_add = cam_proj->m_mat[1][1]* 1.45f;
	
	float x_offset = 0;
	float y_offset = 0;
	Vector2* copy_of_verticles = (Vector2*)malloc(sizeof(Vector2) * mesh->verticles_size);
	
	for(unsigned int i = 0; i < mesh->verticles_size; i++)
	{
		copy_of_verticles[i] = MultipleMatrixVector2(temp, mesh->verticles[i]);
	}
	

	for(int text_letter = 0; text_letter < text_size; text_letter++)
	{
		
		int index = CharToTextureIndex(text[text_letter]);
		if(text[text_letter] == '\n')
		{
			x_offset = 0;
			y_offset += y_offset_add;
			continue;
		}
		if(index == -1)
		{
			x_offset += x_offset_add;
			continue;
		}
		for(unsigned int i = 0; i < mesh->faces_size; i += 3)	
		{
			
			int p1 = mesh->faces[i];
			int p2 = mesh->faces[i + 1];
			int p3 = mesh->faces[i + 2];
			
			Vector2 Point1 = {copy_of_verticles[p1].x + x_offset, copy_of_verticles[p1].y + y_offset};
			Vector2 Point2 = {copy_of_verticles[p2].x + x_offset, copy_of_verticles[p2].y + y_offset};
			Vector2 Point3 = {copy_of_verticles[p3].x + x_offset, copy_of_verticles[p3].y + y_offset};
			
			DrawTriangleByTexture(
				buffer, 
				Point1,Point2, Point3,
				texture, 
				mesh->UV_map[p1], mesh->UV_map[p2], mesh->UV_map[p3]);
		}
		x_offset += x_offset_add;
	}
		
	
	free(copy_of_verticles);
}

void SetImage(Buffer* buffer, Texture* texture)
{
	unsigned int max_y = buffer->height - 1;
	unsigned int max_x = buffer->width - 1;
	int* pointer = 0;
	int* texture_pixel_pointer = texture->pixels;
	for(int y = 0; y < texture->height; y++)
	{
		if(y > max_y)
		{
			break;
		}
		pointer = &buffer->buffer[y * buffer->width];
		for(int x = 0; x < texture->width; x++)
		{
			if(x > max_x)
			{
				texture_pixel_pointer += texture->width - buffer->width;
				break;
			}
			*pointer = *texture_pixel_pointer;
			texture_pixel_pointer++;
			pointer++;
		}
	}
}
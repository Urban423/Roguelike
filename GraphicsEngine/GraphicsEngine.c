#include "GraphicsEngine.h"
#include "Vector2.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "Color.h"

int min_int(int a, int b) { if(a < b) { return a; } return b; }
int max_int(int a, int b) { if(a > b) { return a; } return b; }

void swap_float(float* a, float* b)
{
	float temp = *a;
	*a = *b;
	*b = temp;
}

void swap_Color(Color* a, Color* b)
{
	Color temp = *a;
	*a = *b;
	*b = temp;
}

void swap_int(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


void getBarycentricCoordinates(float* resx, float* resy, float* resz, Vector2 p, Vector2 v0, Vector2 v1, Vector2 v2) {
    Vector2 a = {v1.x - v0.x, v2.x - v0.x};
    Vector2 b = {v1.y - v0.y, v2.y - v0.y};
    Vector2 c = {p.x - v0.x,  p.y - v0.y};

    float det = a.x * b.y - a.y * b.x;
    *resy = (c.x * b.y - c.y * a.y) / det;
    *resz = (a.x * c.y - b.x * c.x) / det;
    *resx = 1.0f - *resy - *resz;
}


char lerp(char a, char b, float percent)
{
	return (1 - percent) * b + percent * a;
}

int Orientation(Vector2* a, Vector2* b, Vector2* c)
{
	return (b->x - a->x)*(c->y - a->y) - (c->x - a->x)*(b->y - a->y);
}

void DrawLine(Buffer* buffer,
int x1, int y1, 
int x2, int y2,
char r, char g, char b)
{
	char changed = 0;
	unsigned int deltax = abs(x2 - x1);
	unsigned int deltay = abs(y2 - y1);
	if(deltay > deltax)
	{
		changed = 1;
		deltax = deltay;
		deltay = abs(x2 - x1);
		
		int temp = x1;
		x1 = y1;
		y1 = temp;
		
		temp = x2;
		x2 = y2;
		y2 = temp;
	}
	if(x2 < x1)
	{
		int temp = x1;
		x1 = x2;
		x2 = temp;
		
		temp = y1;
		y1 = y2;
		y2 = temp;
	}
	
	int dx = x2 - x1;
	int dy = abs(y2 - y1);
	int error = dx / 2;
	int y = y1;
	int diry = 0;
	if(y2 > y1)
	{
		diry = 1;
	}
	else{
		diry = -1;
	}
	for(int x = x1; x < x2 + 1; x++)
	{
		unsigned int index = 0;
		if(changed == 1)
		{
			index = buffer->width * x + y;
		}else{
			index = buffer->width * y + x;
		}
		index *= 4;
		buffer->buffer[index] = r;
		buffer->buffer[index + 1] = g;
		buffer->buffer[index + 2] = b;
		error -= dy;
		if(error < 0)
		{
			y += diry;
			error += dx;
		}
	}
}

void DrawTriangleByTexture(Buffer* buffer, 
int x1, int y1, 
int x2, int y2, 
int x3, int y3,
Texture* texture, 
Vector2 uv1,
Vector2 uv2,
Vector2 uv3)
{
	float perc = (float)1 / 255;
	
	float x_size = 1;
	float xOffset = 0;
	float y_size = 1;
	float yOffset = 0.0f;
	
	uv1.x = uv1.x * x_size + xOffset;
	uv2.x = uv2.x * x_size + xOffset;
	uv3.x = uv3.x * x_size + xOffset;
	uv1.y = uv1.y * y_size + yOffset;
	uv2.y = uv2.y * y_size + yOffset;
	uv3.y = uv3.y * y_size + yOffset;
	
	int min_y = max_int(0, min_int(y1, min_int(y2, y3)));
	int max_y = min_int(buffer->height - 1, max_int(y1, max_int(y2, y3)));
	int min_x = max_int(0, min_int(x1, min_int(x2, x3)));
	int max_x = min_int(buffer->width - 1,  max_int(x1, max_int(x2, x3)));
	
	Vector2 a = {x1, y1};
	Vector2 b = {x2, y2};
	Vector2 c = {x3, y3};
	
	int index;
	for (int i = min_y; i <= max_y; i++)
	{
		index = i * buffer->width + min_x;
		index *= 4;
		for (int j = min_x; j <= max_x; j++)
		{
			float w1, w2, w3;
			Vector2 p = {j, i};
			getBarycentricCoordinates(&w1, &w2, &w3, p, a, b, c);
            if (w1 >= 0 && w2 >= 0 && w3 >= 0) 
			{
                float u = w1 * uv1.x + w2 * uv2.x + w3 * uv3.x;
                float v = w1 * uv1.y + w2 * uv2.y + w3 * uv3.y;
				
				if(u > 1)
				{
					u = u - (int)u;
				}
				if(v > 1)
				{
					v = v - (int)v;
				}
					
				int tex_x = min_int((int)(u * texture->width), texture->width - 1);
				int tex_y = min_int((int)(v * texture->height), texture->height - 1);
					
				int tex_index = (tex_y * texture->width + tex_x) * 4;
				
				if(texture->pixels[tex_index + 3] != 0)
				{
					
					float percent = (float)((unsigned char)texture->pixels[tex_index + 3]) * perc;
					buffer->buffer[index] = lerp(buffer->buffer[index], texture->pixels[tex_index], 0);
					buffer->buffer[index + 1] = lerp(buffer->buffer[index + 1], texture->pixels[tex_index + 1], 0);
					buffer->buffer[index + 2] = lerp(buffer->buffer[index + 2], texture->pixels[tex_index + 2], 0);
				}
            }
			index += 4;
		}
    }
}

void DrawTriangle(Buffer* buffer, 
int x1, int y1, 
int x2, int y2, 
int x3, int y3,
Texture* texture, 
Vector2 uv1,
Vector2 uv2,
Vector2 uv3)
{
	if(y1 > y2)
	{
		swap_int(&x1, &x2);
		swap_int(&y1, &y2);
		swap_Vector2(&uv1, &uv2);
	}
	if(y1 > y3)
	{
		swap_int(&x1, &x3);
		swap_int(&y1, &y3);
		swap_Vector2(&uv1, &uv3);
	}
	if(y2 > y3)
	{
		swap_int(&x2, &x3);
		swap_int(&y2, &y3);
		swap_Vector2(&uv2, &uv3);
	}
	if(y3 < 0)
	{
		return;
	}
	if(y1 > (int)buffer->height - 1)
	{
		return;
	}
	
	int min_y = max_int(0, y1);
	int min_x = max_int(0, min_int(x1, min_int(x2, x3)));
	
	char changed = 0;
	float dx13 = 0;
	float dx12 = 0;
	float dx23 = 0;
	if (y3 != y1) 
	{
		dx13 = (float)(x3 - x1);
		dx13 /= y3 - y1;
    }
	if (y2 != y1)
	{
		dx12 = (float)(x2 - x1);
		dx12 /= (y2 - y1);
	}
	if (y3 != y2)
	{
		dx23 = (float)(x3 - x2);
		dx23 /= (y3 - y2);
    }
	if(x2 > x3)
	{
		changed = 1;
	}
	
	float wx1 = (float)x1;
    float wx2 = wx1;
	float _dx13 = dx13;
	
	if (dx13 > dx12)
    {
		swap_float(&dx13, &dx12);
    }
	
	int tex_x = 0;
	int tex_y = 0;
	int index_of_texture = 0;
	int max_texture_x = texture->width - 1;
	int max_texture_y = texture->height - 1;
	
	Vector2 v0 = {x1, y1};
	Vector2 v1 = {x2, y2};
	Vector2 v2 = {x3, y3};
	
	int det = Orientation(&v0, &v1, &v2);
	float A01 = (float)(v0.y - v1.y) / det;
    float A12 = (float)(v1.y - v2.y) / det;
    float A20 = (float)(v2.y - v0.y) / det;
	
	float B01 = (float)(v1.x - v0.x) / det;
	float B12 = (float)(v2.x - v1.x) / det;
	float B20 = (float)(v0.x - v2.x) / det;
	
	
	unsigned int index = 0;
	float w0_row, w1_row, w2_row;
	float stw0_row, stw1_row, stw2_row;
	Vector2 p = {min_x, min_y};
	getBarycentricCoordinates(&w0_row, &w1_row, &w2_row, p, v0, v1, v2);
	stw0_row = w0_row;
	stw1_row = w1_row;
	stw2_row = w2_row;
	
	int st_y = y1;
	if(st_y < 0)
	{
		w0_row += -st_y * B12;
        w1_row += -st_y * B20;
        w2_row += -st_y * B01;
		wx1 += -st_y * dx13;
		wx2 += -st_y * dx12;
		st_y = 0;
	}
	
	for(int y = st_y; y < y2; y++)
	{
		if(y > buffer->height - 1)
		{
			break;
		}
		float w0 = w0_row;
        float w1 = w1_row;
        float w2 = w2_row;
		int st = (int)wx1;
		if(st < 0)
		{
			st = 0;
		}
		w0 += abs(min_x - st) * A12;
		w1 += abs(min_x - st) * A20;
		w2 += abs(min_x - st) * A01;
		
		//calculate new row's of buffer index
		index = (buffer->width * y + st) * 4;
		
		for(int x = st; x < (int)wx2; x++)
		{
			if(x > buffer->width - 1)
			{
				break;
			}
			float u = w0 * uv1.x + w1 * uv2.x + w2 * uv3.x;
			float v = w0 * uv1.y + w1 * uv2.y + w2 * uv3.y;
			
			tex_x = (int)(u * texture->width);
			if(tex_x > max_texture_x)
			{
				tex_x = max_texture_x;
			}
			if(tex_x < 0)
			{
				tex_x = 0;
			}
			tex_y = (int)(v * texture->height);
			if(tex_y > max_texture_y)
			{
				tex_y = max_texture_y;
			}
			if(tex_y < 0)
			{
				tex_y = 0;
			}
			
			//calculate index of texture by tex_x and tex_y
			index_of_texture = (tex_y * texture->width + tex_x) * 4;
			
			if(texture->pixels[index_of_texture + 3] != 0)
			{
				//Draw Pixel in Buffer
				buffer->buffer[index]     = texture->pixels[index_of_texture];
				buffer->buffer[index + 1] = texture->pixels[index_of_texture + 1];
				buffer->buffer[index + 2] = texture->pixels[index_of_texture + 2];
			}
			
			//calculate new column's barecentric coordinates
			w0 += A12;
            w1 += A20;
            w2 += A01;
			
			//step for the next pixel in buffer
			index += 4;
		}
		
		//calculate new row's barecentric coordinates
		w0_row += B12;
        w1_row += B20;
        w2_row += B01;
		
		//calculate new row's x coordinates
		wx1 += dx13;
		wx2 += dx12;
    }
	
	if (y1 == y2)
	{
		wx1 = (float)x1;
		wx2 = (float)x2;
    }
	if (_dx13 < dx23)
	{
		swap_float(&_dx13, &dx23);
	}
	if(wx1 > wx2)
	{
		swap_float(&wx1, &wx2);
	}
	w0_row = stw0_row;
	w1_row = stw1_row;
	w2_row = stw2_row;
	
	
	//printf("y: %d %d\n", (int)y2, (int)y3);
	//printf("x: %d %d\n", (int)wx1, (int)wx2);
	for(int y = y2; y < y3; y++)
	{
		if(y < 0)
		{
			w0_row += B12;
			w1_row += B20;
			w2_row += B01;
			wx1 += _dx13;
			wx2 += dx23;
			continue;
		}
		if(y > buffer->height - 1)
		{
			break;
		}
		float w0 = w0_row;
        float w1 = w1_row;
        float w2 = w2_row;
		int st = (int)wx1;
		if(wx1 < 0)
		{
			st = 0;
		}
		w0 += abs(min_x - st) * A12;
		w1 += abs(min_x - st) * A20;
		w2 += abs(min_x - st) * A01;
		
		//calculate new row's of buffer index
		index = (buffer->width * y + st) * 4;
		
		for(int x = st; x < (int)wx2; x++)
		{
			if(x > buffer->width - 1)
			{
				break;
			}
			float u = w0 * uv1.x + w1 * uv2.x + w2 * uv3.x;
			float v = w0 * uv1.y + w1 * uv2.y + w2 * uv3.y;
			
			tex_x = (int)(u * texture->width);
			if(tex_x > max_texture_x)
			{
				tex_x = max_texture_x;
			}
			if(tex_x < 0)
			{
				tex_x = 0;
			}
			tex_y = (int)(v * texture->height);
			if(tex_y > max_texture_y)
			{
				tex_y = max_texture_y;
			}
			if(tex_y < 0)
			{
				tex_y = 0;
			}
			
			//calculate index of texture by tex_x and tex_y
			index_of_texture = (tex_y * texture->width + tex_x) * 4;
			
			if(texture->pixels[index_of_texture + 3] != 0)
			{
				//Draw Pixel in Buffer
				buffer->buffer[index]     = texture->pixels[index_of_texture];
				buffer->buffer[index + 1] = texture->pixels[index_of_texture + 1];
				buffer->buffer[index + 2] = texture->pixels[index_of_texture + 2];
			}
			
			//calculate new column's barecentric coordinates
			w0 += A12;
            w1 += A20;
            w2 += A01;
			
			//step for the next pixel in buffer
			index += 4;
		}
		
		//calculate new row's barecentric coordinates
		w0_row += B12;
        w1_row += B20;
        w2_row += B01;
		
		//calculate new row's x coordinates
		wx1 += _dx13;
		wx2 += dx23;
    }
}

void BufferConstructor(Buffer* buffer, unsigned int width, unsigned int height) {
	buffer->width = width;
    buffer->height = height;
    buffer->buffer = (char*) malloc((width * height * 4) * sizeof(char));
}

void BufferClear(Buffer* buffer, char r, char g, char b)
{
	unsigned int size = buffer->width * buffer->height * 4;
    for (unsigned int index = 0; index < size; index += 4)
	{
        buffer->buffer[index + 0] = r;
        buffer->buffer[index + 1] = g;
        buffer->buffer[index + 2] = b;
        buffer->buffer[index + 3] = 255;
    }
}

void BufferDrawObject(Buffer* buffer, Matrix3x3 world_pos, VertexMesh* mesh, Texture* texture)
{
	Vector2* copy_of_verticles = (Vector2*)malloc(sizeof(Vector2) * mesh->verticles_size);
	
	for(unsigned int i = 0; i < mesh->verticles_size; i++)
	{
		copy_of_verticles[i] = MultipleMatrixVector2(world_pos, mesh->verticles[i]);
	}
	
	for(unsigned int i = 0; i < mesh->faces_size; i += 3)	
	{
		DrawTriangleByTexture(buffer, 
				copy_of_verticles[mesh->faces[i]].x - 15,  copy_of_verticles[mesh->faces[i]].y - 15,
				copy_of_verticles[mesh->faces[i + 1]].x - 15, copy_of_verticles[mesh->faces[i + 1]].y - 15,
				copy_of_verticles[mesh->faces[i + 2]].x - 15, copy_of_verticles[mesh->faces[i + 2]].y- 15,
				texture, 
				mesh->UV_map[mesh->faces[i]],
				mesh->UV_map[mesh->faces[i + 1]],
				mesh->UV_map[mesh->faces[i + 2]]);
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

void BufferDrawText(Buffer* buffer, Matrix3x3 world_pos, VertexMesh* mesh, Texture* texture, char* text, unsigned int text_size)
{
	float x_offset = 0;
	float y_offset = 0;
	Vector2* copy_of_verticles = (Vector2*)malloc(sizeof(Vector2) * mesh->verticles_size);
	
	for(unsigned int i = 0; i < mesh->verticles_size; i++)
	{
		copy_of_verticles[i] = MultipleMatrixVector2(world_pos, mesh->verticles[i]);
	}
	

	for(int text_letter = 0; text_letter < text_size; text_letter++)
	{
		int index = CharToTextureIndex(text[text_letter]);
		if(text[text_letter] == '\n')
		{
			x_offset = 0;
			y_offset += 35;
			continue;
		}
		if(index == -1)
		{
			x_offset += 30;
			continue;
		}
		for(unsigned int i = 0; i < mesh->faces_size; i += 3)	
		{
			DrawTriangle(buffer, 
					copy_of_verticles[mesh->faces[i]].x - 15 + x_offset ,  copy_of_verticles[mesh->faces[i]].y - 15 + y_offset,
					copy_of_verticles[mesh->faces[i + 1]].x - 15 + x_offset, copy_of_verticles[mesh->faces[i + 1]].y - 15 + y_offset,
					copy_of_verticles[mesh->faces[i + 2]].x- 15 + x_offset, copy_of_verticles[mesh->faces[i + 2]].y- 15 + y_offset,
					&texture[index], 
					mesh->UV_map[mesh->faces[i]],
					mesh->UV_map[mesh->faces[i + 1]],
					mesh->UV_map[mesh->faces[i + 2]]);
		}
		x_offset += 30;
	}
		
	
	free(copy_of_verticles);
}

void SetImage(Buffer* buffer, Texture* texture)
{
	int pixel_index = 0;
	for(int y = 0; y < texture->height; y++)
	{
		int index = y * buffer->width * 4;
		for(int x = 0; x < texture->width; x++)
		{
			buffer->buffer[index] = texture->pixels[pixel_index];
			buffer->buffer[index + 1] = texture->pixels[pixel_index + 1];
			buffer->buffer[index + 2] = texture->pixels[pixel_index + 2];
			pixel_index += 4;
			index += 4;
		}
	}
}
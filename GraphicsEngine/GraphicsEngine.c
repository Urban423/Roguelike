#include "GraphicsEngine.h"
#include "Vector2.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "Color.h"

void swap_Vector2(Vector2* a, Vector2* b)
{
	Vector2 temp = *a;
	*a = *b;
	*b = temp;
}

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

void DrawTriangle(Buffer* buffer, 
int x1, int y1, 
int x2, int y2, 
int x3, int y3,
Color color1,
Color color2,
Color color3)
{
	if(y1 > y2)
	{
		swap_int(&x1, &x2);
		swap_int(&y1, &y2);
		swap_Color(&color1, &color2);
	}
	if(y1 > y3)
	{
		swap_int(&x1, &x3);
		swap_int(&y1, &y3);
		swap_Color(&color1, &color3);
	}
	if(y2 > y3)
	{
		swap_int(&x2, &x3);
		swap_int(&y2, &y3);
		swap_Color(&color2, &color3);
	}
	if(y3 < 0)
	{
		return;
	}
	if(y1 > (int)buffer->height - 1)
	{
		return;
	}
	
	int delta_color12 = abs(y1 - y2);
	int delta_color13 = abs(y3 - y1);
	int delta_color23 = abs(y3 - y2);
	
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
	
	for (int i = y1; i < y2; i++)
	{
		if(i < 0)
		{
			wx1 += dx13;
			wx2 += dx12;
			continue;
		}
		if(i > (int)buffer->height - 1)
		{
			break;
		}
		int st = (int)wx1;
		if(st < 0)
		{
			st = 0;
		}
		
		unsigned int index = buffer->width * i + st;
		index *= 4;
		float interPolation1 = (float)(i - y1) / delta_color12;
		float interPolation2 = (float)(i - y1) / delta_color13;
		float interPolation3 = 0;
		int delta_x = abs((int)wx2 - (int)wx1) + 1;
		Color c1 = addColor(MultipleColor(color3, interPolation2), MultipleColor(color1, 1 - interPolation2));
		Color c2 = addColor(MultipleColor(color2, interPolation1), MultipleColor(color1, 1 - interPolation1));
		if(changed == 1)
		{
			Color temp = c1;
			c1 = c2;
			c2 = temp;
		}
		for (int j = st; j <= (int)wx2; j++)
		{
			if(j > (int)buffer->width - 1)
			{
				break;
			}
			interPolation3 = (float)(j - (int)wx1) / delta_x;
			Color c3 = addColor(MultipleColor(c1, interPolation3), MultipleColor(c2, 1 - interPolation3));
			buffer->buffer[index] = c3.r * 255;
			buffer->buffer[index + 1] = c3.g * 255;
			buffer->buffer[index + 2] = c3.b * 255;
			index += 4;
		}
		wx1 += dx13;
		wx2 += dx12;
    }
	
	if (y1 == y2)
	{
		if(x2 > x1 && changed == 0)
		{
			swap_Color(&color2, &color1);
		}
		wx1 = (float)x1;
		wx2 = (float)x2;
    }
	if (_dx13 < dx23)
	{
		swap_float(&_dx13, &dx23);
	}
	if (wx1 > wx2)
	{
		swap_float(&wx1, &wx2);
	}
	for (int i = y2; i < y3; i++)
	{
		if(i < 0)
		{
			wx1 += _dx13;
			wx2 += dx23;
			continue;
		}
		if(i > (int)buffer->height - 1)
		{
			break;
		}
		int st = (int)wx1;
		if(st < 0)
		{
			st = 0;
		}
		unsigned int index = buffer->width * i + st;
		index *= 4;
		float interPolation1 = (float)(i - y1) / delta_color13;
		float interPolation2 = (float)(i - y2) / delta_color23;
		float interPolation3 = 0;
		int delta_x = abs((int)wx2 - (int)wx1);
		Color c1 = addColor(MultipleColor(color3, interPolation1), MultipleColor(color1, 1 - interPolation1));
		Color c2 = addColor(MultipleColor(color3, interPolation2), MultipleColor(color2, 1 - interPolation2));
		if(changed == 1)
		{
			Color temp = c1;
			c1 = c2;
			c2 = temp;
		}
		for (int j = st; j <= (int)wx2; j++)
		{
			if(j > (int)buffer->width - 1)
			{
				break;
			}
			interPolation3 = (float)(j - (int)wx1) / delta_x;
			Color c3 = addColor(MultipleColor(c1, interPolation3), MultipleColor(c2, 1 - interPolation3));
			buffer->buffer[index] = c3.r * 255;
			buffer->buffer[index + 1] = c3.g * 255;
			buffer->buffer[index + 2] = c3.b * 255;
			index += 4;
		}
		wx1 += _dx13;
		wx2 += dx23;
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
	
	int delta_color12 = abs(y1 - y2);
	int delta_color13 = abs(y3 - y1);
	int delta_color23 = abs(y3 - y2);
	
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
	int tindex = 0;
	for (int i = y1; i < y2; i++)
	{
		if(i < 0)
		{
			wx1 += dx13;
			wx2 += dx12;
			continue;
		}
		if(i > (int)buffer->height - 1)
		{
			break;
		}
		int st = (int)wx1;
		if(st < 0)
		{
			st = 0;
		}
		
		unsigned int index = buffer->width * i + st;
		index *= 4;
		float interPolation1 = (float)(i - y1) / delta_color12;
		float interPolation2 = (float)(i - y1) / delta_color13;
		float interPolation3 = 0;
		int delta_x = abs((int)wx2 - (int)wx1) + 1;
		Vector2 c1 = add(multiple(uv3, interPolation2), multiple(uv1, 1 - interPolation2));
		Vector2 c2 = add(multiple(uv2, interPolation1), multiple(uv1, 1 - interPolation1));
		if(changed == 1)
		{
			Vector2 temp = c1;
			c1 = c2;
			c2 = temp;
		}
		for (int j = st; j <= (int)wx2; j++)
		{
			if(j > (int)buffer->width - 1)
			{
				break;
			}
			interPolation3 = (float)(j - (int)wx1) / delta_x;
			Vector2 c3 = add(multiple(c1, interPolation3), multiple(c2, 1 - interPolation3));
			
			buffer->buffer[index] = 0;
			buffer->buffer[index + 1] = 0;
			buffer->buffer[index + 2] = 0;
			index += 4;
			tindex += 1;
		}
		wx1 += dx13;
		wx2 += dx12;
    }
	
	if (y1 == y2)
	{
		if(x2 > x1 && changed == 0)
		{
			swap_Vector2(&uv1, &uv2);
		}
		wx1 = (float)x1;
		wx2 = (float)x2;
    }
	if (_dx13 < dx23)
	{
		swap_float(&_dx13, &dx23);
	}
	if (wx1 > wx2)
	{
		swap_float(&wx1, &wx2);
	}
	
	for (int i = y2; i < y3; i++)
	{
		if(i < 0)
		{
			wx1 += _dx13;
			wx2 += dx23;
			continue;
		}
		if(i > (int)buffer->height - 1)
		{
			break;
		}
		int st = (int)wx1;
		if(st < 0)
		{
			st = 0;
		}
		unsigned int index = buffer->width * i + st;
		index *= 4;
		for (int j = st; j <= (int)wx2; j++)
		{
			if(j > (int)buffer->width - 1)
			{
				break;
			}
			buffer->buffer[index] = 0;
			buffer->buffer[index + 1] = 0;
			buffer->buffer[index + 2] = 0;
			index += 4;
		}
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
        buffer->buffer[index + 0] = b;
        buffer->buffer[index + 1] = g;
        buffer->buffer[index + 2] = r;
        buffer->buffer[index + 3] = 255;
    }
}

void BufferDrawObject1(Buffer* buffer, Transfrom transform, VertexMesh* mesh, char r, char g, char b, Matrix3x3 camera) 
{	
	Color colors[4];
	colors[0] = newColor(0, 1, 0, 1);
	colors[1] = newColor(1, 0, 0, 1);
	colors[2] = newColor(0, 0, 1, 1);
	colors[3] = newColor(1, 1, 1, 1);
	
	Vector2* copy_of_verticles = (Vector2*)malloc(sizeof(Vector2) * mesh->verticles_size);
	
	Matrix3x3 mat;
	Matrix3x3 temp;
	setIdentity(&mat);
	
	setIdentity(&temp);
	SetScale(&temp, transform.scale);
	mat = MultipleMatrixMatrix(mat, temp);
	
	setIdentity(&temp);
	SetRotation(&temp, transform.rotation);
	mat = MultipleMatrixMatrix(mat, temp);
	
	setIdentity(&temp);
	transform.position.y *= -1;
	setTranslation(&temp, transform.position);
	mat = MultipleMatrixMatrix(mat, temp);
	
	for(unsigned int i = 0; i < mesh->verticles_size; i++)
	{
		copy_of_verticles[i] = MultipleMatrixVector2(mat, mesh->verticles[i]);
	}
	
	for(unsigned int i = 0; i < mesh->faces_size; i += 3)	
	{
		DrawTriangle(buffer, 
				copy_of_verticles[mesh->faces[i]].x,  copy_of_verticles[mesh->faces[i]].y,
				copy_of_verticles[mesh->faces[i + 1]].x, copy_of_verticles[mesh->faces[i + 1]].y,
				copy_of_verticles[mesh->faces[i + 2]].x, copy_of_verticles[mesh->faces[i + 2]].y,
				colors[mesh->faces[i]],
				colors[mesh->faces[i + 1]],
				colors[mesh->faces[i + 2]]);
	}
		
	
	free(copy_of_verticles);
}

void BufferDrawObject(Buffer* buffer, Transfrom transform, VertexMesh* mesh, Texture* texture)
{
	Vector2 UV_map[4] = {
		{-1,  1},
		{ 1,  1},
		{ 1, -1},
		{-1, -1}
	};
	
	Vector2* copy_of_verticles = (Vector2*)malloc(sizeof(Vector2) * mesh->verticles_size);
	
	Matrix3x3 mat;
	Matrix3x3 temp;
	setIdentity(&mat);
	
	setIdentity(&temp);
	SetScale(&temp, transform.scale);
	mat = MultipleMatrixMatrix(mat, temp);
	
	setIdentity(&temp);
	SetRotation(&temp, transform.rotation);
	mat = MultipleMatrixMatrix(mat, temp);
	
	setIdentity(&temp);
	transform.position.y *= -1;
	setTranslation(&temp, transform.position);
	mat = MultipleMatrixMatrix(mat, temp);
	
	for(unsigned int i = 0; i < mesh->verticles_size; i++)
	{
		copy_of_verticles[i] = MultipleMatrixVector2(mat, mesh->verticles[i]);
	}
	
	for(unsigned int i = 0; i < mesh->faces_size; i += 3)	
	{
		DrawTriangleByTexture(buffer, 
				copy_of_verticles[mesh->faces[i]].x,  copy_of_verticles[mesh->faces[i]].y,
				copy_of_verticles[mesh->faces[i + 1]].x, copy_of_verticles[mesh->faces[i + 1]].y,
				copy_of_verticles[mesh->faces[i + 2]].x, copy_of_verticles[mesh->faces[i + 2]].y,
				texture, 
				UV_map[mesh->faces[i]],
				UV_map[mesh->faces[i + 1]],
				UV_map[mesh->faces[i + 2]]);
	}
		
	
	free(copy_of_verticles);
}

void SetImage(Buffer* buffer, Texture* texture)
{
	int pixel_index = 0;
	for(int y = 0; y < texture->height; y++)
	{
		int index = y * buffer->width * 3;
		for(int x = 0; x < texture->width; x++)
		{
			buffer->buffer[index] = texture->pixels[pixel_index];
			buffer->buffer[index + 1] = texture->pixels[pixel_index + 1];
			buffer->buffer[index + 2] = texture->pixels[pixel_index + 2];
			pixel_index+=3;
			index += 3;
		}
	}
}
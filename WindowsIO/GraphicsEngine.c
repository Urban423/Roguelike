#include "GraphicsEngine.h"
#include "Vector2.h"
#include <stdlib.h>

void swap_float(float* a, float* b)
{
	float temp = *a;
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
char r, char g, char b)
{
	if (y2 < y1) 
	{
		swap_int(&y1, &y2);
		swap_int(&x1, &x2);
    }
    if (y3 < y1)
	{
		swap_int(&y1, &y3);
		swap_int(&x1, &x3);
    }
	if (y2 > y3)
	{
		swap_int(&y2, &y3);
		swap_int(&x2, &x3); 
    }
	float dx13 = 0;
	float dx12 = 0;
	float dx23 = 0;
	if (y3 != y1) 
	{
		dx13 = (float)(x3 - x1);
		dx13 /= y3 - y1;
    }
	else
	{
		dx13 = 0;
	}
	if (y2 != y1)
	{
		dx12 = (float)(x2 - x1);
		dx12 /= (y2 - y1);
	}
	else
	{
		dx12 = 0;
	}
	if (y3 != y2)
	{
		dx23 = (float)(x3 - x2);
		dx23 /= (y3 - y2);
    }
	else
	{
		dx23 = 0;
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
		for (int j = (int)wx1; j <= (int)wx2; j++)
		{
			unsigned int index = buffer->width * i + j;
			index *= 4;
			buffer->buffer[index] = r;
			buffer->buffer[index + 1] = g;
			buffer->buffer[index + 2] = b;
		}
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
	for (int i = y2; i <= y3; i++)
	{
		for (int j = (int)wx1; j <= (int)wx2; j++)
		{
			unsigned int index = buffer->width * i + j;
			index *= 4;
			buffer->buffer[index] = r;
			buffer->buffer[index + 1] = g;
			buffer->buffer[index + 2] = b;
		}
		wx1 += _dx13;
		wx2 += dx23;
    }
}

void BufferConstructor(Buffer* buffer, unsigned int width, unsigned int height, char sprite) {
	buffer->width = width;
    buffer->height = height;
    buffer->buffer = (char*) malloc((width * height * 4) * sizeof(char));
	
	createWindow(buffer);
	//updateWindow(buffer);
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

void BufferDrawObject(Buffer* buffer, Transfrom transform, char r, char g, char b, Matrix3x3 camera) 
{
	Vector2 points[4];
	CreateVector2(&points[0], -0.5f,  0.5f);
	CreateVector2(&points[1],  0.5f,  0.5f);
	CreateVector2(&points[2],  0.5f, -0.5f);
	CreateVector2(&points[3], -0.5f, -0.5f);
	
	
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
	setTranslation(&temp, transform.position);
	mat = MultipleMatrixMatrix(mat, temp);
	mat = MultipleMatrixMatrix(mat, camera);
	
	for(int i = 0; i < 4; i++)
	{
		points[i] = MultipleMatrixVector2(mat, points[i]);
	}

	DrawTriangle(buffer, 
	points[0].x,  points[0].y,
	points[1].x,  points[1].y,
	points[2].x,  points[2].y,
	r, g, b);
	
	DrawTriangle(buffer, 
	points[0].x,  points[0].y,
	points[3].x,  points[3].y,
	points[2].x,  points[2].y,
	r, g, b);
}

char BufferDraw(Buffer* buffer) {
	if(updateWindow(buffer))
	{
		return 1;
	}
	return 0;
}
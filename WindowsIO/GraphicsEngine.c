#include "GraphicsEngine.h"
#include "Vector2.h"
#include "Matrix3x3.h"
#include <stdlib.h>

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

void BufferDrawObject(Buffer* buffer, Transfrom transform, char r, char g, char b) 
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
	
	for(int i = 0; i < 3; i++)
	{
		Vector2 a = MultipleMatrixVector2(mat, points[i]);
		Vector2 a2 = MultipleMatrixVector2(mat, points[i + 1]);
		DrawLine(buffer, (int)a.x, (int)a.y,(int)a2.x, (int)a2.y, r, g, b);
	}
	Vector2 a = MultipleMatrixVector2(mat, points[0]);
	Vector2 a2 = MultipleMatrixVector2(mat, points[3]);
	DrawLine(buffer, (int)a.x, (int)a.y, (int)a2.x, (int)a2.y, r, g, b);
}

char BufferDraw(Buffer* buffer) {
	if(updateWindow(buffer))
	{
		return 1;
	}
	return 0;
}
#include "Line.h"
#include "math.h"

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
#include "Triangle.h"
#include <stdio.h>

void sortThreeTrinanglePointsByY(
Vector2* a, Vector2* b, Vector2* c, 
Vector2* uv1, Vector2* uv2, Vector2* uv3)
{
	if(a->y > b->y)
	{
		swap_Vector2(a, b);
		swap_Vector2(uv1, uv2);
	}
	if(a->y > c->y)
	{
		swap_Vector2(a, c);
		swap_Vector2(uv1, uv3);
	}
	if(b->y > c->y)
	{
		swap_Vector2(b, c);
		swap_Vector2(uv2, uv3);
	}
}

void DrawTrianlgePart(Buffer* buffer,
 int start_y,          int end_y,
 double wx1,           double wx2,
 double u_left,        double v_left,
 double u_right,       double v_right,
 double delta_wx1,     double delta_wx2,
 double delta_u_left,  double delta_v_left,
 double delta_u_right, double delta_v_right,
 Texture* texture)
{
	if(end_y < 0) { return; } 
	if(start_y > buffer->height - 1) { return; }
	
	
	if(start_y < 0)
	{
		start_y = -start_y;
		u_left  += start_y * delta_u_left;
		v_left  += start_y * delta_v_left;
		u_right += start_y * delta_u_right;
		v_right += start_y * delta_v_right;
		
		wx1 += start_y * delta_wx1;
		wx2 += start_y * delta_wx2;
		start_y = 0;
	}
	
	if(end_y > buffer->height - 1)
	{
		end_y = buffer->height;
	}
	
	
	int* pointer_buffer;
	int tex_x = 0;
	int tex_y = 0;
	unsigned int index_of_texture = 0;
	int max_texture_x = texture->width - 1;
	int max_texture_y = texture->height - 1;
	
	double u, v, delta_u, delta_v;
	int start_x, end_x;
	
	for(int y = start_y; y < end_y; y++)
	{
		u = u_left;
		v = v_left;
		delta_u = (u_right - u_left) / (wx2 - wx1);
		delta_v = (v_right - v_left) / (wx2 - wx1);
		
		
		//calculate start row's x and end row's x
		start_x = (int)wx1;
		if(start_x < 0)
		{
			u += -start_x * delta_u;
			v += -start_x * delta_v;
			start_x = 0;
		}
		end_x = (int)wx2;
		if(end_x > (int)buffer->width - 1)
		{
			end_x = (int)buffer->width;
		}
		
		//calculate new row's of buffer index
		pointer_buffer = buffer->buffer + buffer->width * y + start_x;
		
		for(int x = start_x; x < end_x; x++)
		{
			tex_x = (int)(u * max_texture_x);
			tex_y = (int)(v * max_texture_y);
			
			index_of_texture = tex_y * texture->width + tex_x;
			
			if(texture->alpha[index_of_texture] != 0)
			{
				*pointer_buffer = texture->pixels[index_of_texture];
				//*pointer_buffer = 666;
			}
			
			u += delta_u;
			v += delta_v;
			
			//step for the next pixel in buffer
			pointer_buffer++;
		}
		
		u_left += delta_u_left;
		v_left += delta_v_left;
		
		u_right += delta_u_right;
		v_right += delta_v_right;
		
		//calculate new row's x coordinates
		wx1 += delta_wx1;
		wx2 += delta_wx2;
    }
}

void DrawTriangleByTexture(
Buffer* buffer, 
Vector2 p1, Vector2 p2, Vector2 p3,
Texture* texture, 
Vector2 uv1, Vector2 uv2, Vector2 uv3)
{
	sortThreeTrinanglePointsByY(&p1, &p2, &p3, &uv1, &uv2, &uv3); //sort
	//printf("%f %f, %f %f,%f %f\n", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
	
	
	//skip if there is no reason to draw
	if(p3.y < 0) { return; } 
	if(p1.y > (int)buffer->height - 1) { return; }
	
	
	//calculate delta x1-3, x1-2, x2-3
	float dx13 = 0;
	float dx12 = 0;
	float dx23 = 0;
	if (p3.y != p1.y) 
	{
		dx13 = (float)(p3.x - p1.x);
		dx13 /= p3.y - p1.y;
    }
	if (p2.y != p1.y)
	{
		dx12 = (float)(p2.x - p1.x);
		dx12 /= (p2.y - p1.y);
	}
	if (p3.y != p2.y)
	{
		dx23 = (float)(p3.x - p2.x);
		dx23 /= (p3.y - p2.y);
	}
	
	
	//calculate data for top traingle:
	char changed = 0;
	float wx1 = (float)p1.x;
    float wx2 = wx1;
	float _dx13 = dx13;
	
	if (dx13 > dx12)
    {
		swap_float(&dx13, &dx12);
    }
	
	int y_from_left = p2.y;
	int y_from_right = p3.y;
	Vector2 uv_left = uv2;
	Vector2 uv_right = uv3;
	if(p2.x > p3.x)
	{
		changed = 1;
		swap_int(&y_from_left, &y_from_right);
		swap_Vector2(&uv_left, &uv_right);
	}
	
	double u_left = uv1.x;
	double v_left = uv1.y;
	double u_right = u_left;
	double v_right = v_left;
	double delta_u_left  = (uv_left.x - u_left) / (y_from_left - p1.y);
	double delta_v_left  = (uv_left.y - v_left) / (y_from_left - p1.y);
	
	double delta_u_right = (uv_right.x - u_left) / (y_from_right - p1.y);
	double delta_v_right = (uv_right.y - v_left) / (y_from_right - p1.y);
	
	
	
	//calculate data for bottom traingle:
	float Bottom_wx1 = p2.x;
	float Bottom_wx2 = p1.x + dx12 * (p2.y - p1.y);
	if (_dx13 < dx23)
	{
		swap_float(&_dx13, &dx23);
	}
	
	uv_right.x = uv1.x + delta_u_right * (p2.y - p1.y);
	uv_right.y = uv1.y + delta_v_right * (p2.y - p1.y);
	if(p2.x > p3.x)
	{
		uv_right.x = uv1.x + delta_u_left * (p2.y - p1.y);
		uv_right.y = uv1.y + delta_v_left * (p2.y - p1.y);
	}
	
	double Bottom_u_left  = uv2.x;
	double Bottom_v_left  = uv2.y;
	double Bottom_u_right = uv_right.x;
	double Bottom_v_right = uv_right.y;
	
	if(Bottom_wx1 > Bottom_wx2)
	{
		swap_float(&Bottom_wx1, &Bottom_wx2);
		swap_double(&Bottom_u_left, &Bottom_u_right);
		swap_double(&Bottom_v_left, &Bottom_v_right);
	}
	
	double Bottom_delta_u_left  = uv3.x - Bottom_u_left;
	double Bottom_delta_v_left  = uv3.y - Bottom_v_left;
	
	double Bottom_delta_u_right = uv3.x - Bottom_u_right;
	double Bottom_delta_v_right = uv3.y - Bottom_v_right;
	if(p3.y != p2.y)
	{
		Bottom_delta_u_left  /= (p3.y - p2.y);
		Bottom_delta_v_left  /= (p3.y - p2.y);
		
		Bottom_delta_u_right /= (p3.y - p2.y);
		Bottom_delta_v_right /= (p3.y - p2.y);
	}
	
	
	
	//draw Top part
	DrawTrianlgePart(buffer, 
	p1.y, p2.y, 
	p1.x, p1.x, 
	u_left, v_left,
	u_right, v_right, 
	dx13, dx12, 
	delta_u_left, delta_v_left, 
	delta_u_right, delta_v_right, 
	texture);
	
	//draw Bottom part
	DrawTrianlgePart(buffer, 
	p2.y, p3.y, 
	Bottom_wx1, Bottom_wx2, 
	Bottom_u_left, Bottom_v_left,
	Bottom_u_right, Bottom_v_right, 
	_dx13, dx23, 
	0, 0, 
	0, 0, 
	texture);
	
	//_beginthread(DrawTopPart, 0,  (void *)&x1);
}
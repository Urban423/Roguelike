#include "Color.h"

int toInt(Color color)
{
	int res = (int)color.b + ((int)color.g << 8) + ((int)color.r << 16) + ((int)color.a << 24);
	return res;
}

Color newColor(float r, float g, float b, float a)
{
	Color ret;
	ret.r = r;
	ret.g = g;
	ret.b = b;
	ret.a = a;
	return ret;
}

Color MultipleColor(Color a, float b)
{
	a.r *= b;
	a.g *= b;
	a.b *= b;
	a.a *= b;
	return a;
}

Color addColor(Color a, Color b)
{
	a.r += b.r;
	a.g += b.g;
	a.b += b.b;
	a.a += b.a;
	return a;
}

void swap_Color(Color* a, Color* b)
{
	Color temp = *a;
	*a = *b;
	*b = temp;
}
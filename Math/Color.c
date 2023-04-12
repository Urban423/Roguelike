#include "Color.h"

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
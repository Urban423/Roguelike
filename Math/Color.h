#pragma once

typedef struct Color
{
	float r;
	float g;
	float b;
	float a;
}Color;

Color newColor(float r, float g, float b, float a);
Color MultipleColor(Color a, float b);
Color addColor(Color a, Color b);
int toInt(Color color);
#pragma once
#include "Vector2.h"

typedef struct Matrix3x3
{
	float m_mat[3][3];
}Matrix3x3;

void setIdentity(Matrix3x3* this);
void SetScale(Matrix3x3* this, Vector2 scale);
void setTranslation(Matrix3x3* this, Vector2 translation);
void SetRotation(Matrix3x3* this, float x);
void setOrthoLH(Matrix3x3* this, float width, float height, float near_plane, float far_plane);
Matrix3x3 MultipleMatrixMatrix(Matrix3x3 a, Matrix3x3 b);
Vector2 MultipleMatrixVector2(Matrix3x3 a, Vector2 b);
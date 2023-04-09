#include "Matrix3x3.h"
#include <unistd.h>
#include <math.h>

#define M_PI 3.14159265358979323846

void setIdentity(Matrix3x3* this)
{
	memset(this->m_mat, 0, sizeof(float) * 9);
	this->m_mat[0][0] = 1;
	this->m_mat[1][1] = 1;
	this->m_mat[2][2] = 1;
}

void SetScale(Matrix3x3* this, Vector2 scale)
{
	this->m_mat[0][0] = scale.x;
	this->m_mat[1][1] = scale.y;
}

void setTranslation(Matrix3x3* this, Vector2 translation)
{
	this->m_mat[2][0] = translation.x;
	this->m_mat[2][1] = translation.y;
}

void SetRotation(Matrix3x3* this, float x)
{
	x *= M_PI / 180;
	this->m_mat[0][0] = cos(x);
	this->m_mat[0][1] = -sin(x);
	this->m_mat[1][0] = -this->m_mat[0][1];
	this->m_mat[1][1] = this->m_mat[0][0];
}


Matrix3x3 MultipleMatrixMatrix(Matrix3x3 a, Matrix3x3 b)
{
	Matrix3x3 ret;
	for (int i = 0; i < 3; i++)
	{
		for (int i1 = 0; i1 < 3; i1++)
		{
			ret.m_mat[i][i1] =
			a.m_mat[i][0] * b.m_mat[0][i1]
			+ a.m_mat[i][1] * b.m_mat[1][i1]
			+ a.m_mat[i][2] * b.m_mat[2][i1];
		}
	}
	return ret;
}

Vector2 MultipleMatrixVector2(Matrix3x3 a, Vector2 b)
{
	Vector2 ret;
	ret.x = a.m_mat[0][0] * b.x + a.m_mat[0][1] * b.y + a.m_mat[2][0];
	ret.y = a.m_mat[1][0] * b.x + a.m_mat[1][1] * b.y + a.m_mat[2][1];
	return ret;
}
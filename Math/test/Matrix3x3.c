#include "Matrix3x3.h"
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include "Vector3.h"

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
	this->m_mat[2][1] = -translation.y;
}

void SetRotation(Matrix3x3* this, float x)
{
	x *= M_PI / 180;
	this->m_mat[0][0] =  cos(x);
	this->m_mat[0][1] = -sin(x);
	this->m_mat[1][0] =  sin(x);
	this->m_mat[1][1] =  cos(x);
}

void setOrthoLH(Matrix3x3* this, float width, float height, float near_plane, float far_plane)
{
	setIdentity(this);
	this->m_mat[0][0] = (float)width / (far_plane - near_plane);
	this->m_mat[1][1] = (float)width / (far_plane - near_plane);
	this->m_mat[2][0] = (float)width / 2 - 1;
	this->m_mat[2][1] = (float)height / 2 - 1;
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

float getDeterminant(Matrix3x3* matrix)
{
	float det;

	float m1 = matrix->m_mat[1][1] * matrix->m_mat[2][2] - matrix->m_mat[1][2] * matrix->m_mat[2][1];
	float m2 = matrix->m_mat[1][0] * matrix->m_mat[2][2] - matrix->m_mat[1][2] * matrix->m_mat[2][0];
	float m3 = matrix->m_mat[1][0] * matrix->m_mat[2][1] - matrix->m_mat[1][1] * matrix->m_mat[2][0];

	det = matrix->m_mat[0][0] * m1 - matrix->m_mat[0][1] * m2 + matrix->m_mat[0][2] * m3;
	return det;
}

Matrix3x3 inverse(Matrix3x3 matrix)
{
	Matrix3x3 res;
	int a, i, j;
	Vector3 v, vec[2];
	float det = 0.0f;
	float x, y, z;

	det = getDeterminant(&matrix);
	if (!det) return res;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j != i)
			{
				a = j;
				if (j > i) a = a - 1;
				vec[a].x = (matrix.m_mat[j][0]);
				vec[a].y = (matrix.m_mat[j][1]);
				vec[a].z = (matrix.m_mat[j][2]);
			}
		}
		v = cross(vec[0], vec[1]);

		res.m_mat[0][i] = (float)(pow(-1.0f, i)) * v.x / det;
		res.m_mat[1][i] = (float)(pow(-1.0f, i)) * v.y / det;
		res.m_mat[2][i] = (float)(pow(-1.0f, i)) * v.z / det;
	}
	
	/*
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("%f ", matrix.m_mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("%f ", res.m_mat[i][j]);
		}
		printf("\n");
	}
		printf("\n");
		printf("\n");
	*/
	return res;
}
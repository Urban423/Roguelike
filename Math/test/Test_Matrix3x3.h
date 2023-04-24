#pragma once
#include "Vector2.h"



void test_setIdentity(Matrix3x3* this);
void test_SetScale(Matrix3x3* this, Vector2 scale);
void test_setTranslation(Matrix3x3* this, Vector2 translation);
void test_SetRotation(Matrix3x3* this, float x);
void test_setOrthoLH(Matrix3x3* this, float width, float height, float near_plane, float far_plane);
Matrix3x3 test_MultipleMatrixMatrix(Matrix3x3 a, Matrix3x3 b);
Vector2 test_MultipleMatrixVector2(Matrix3x3 a, Vector2 b);

float test_getDeterminant(Matrix3x3* matrix);
Matrix3x3 test_inverse(Matrix3x3 matrix);
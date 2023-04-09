#pragma once
#include "Vector2.h"
#include "Object.h"
#include "BoxCollider.h"

Vector2 BoxVsBox(
Vector2 center1, Vector2 center2,
BoxCollider* box1, BoxCollider* box2);
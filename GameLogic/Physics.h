#pragma once
#include "Vector2.h"
#include "Object.h"
#include "BoxCollider.h"

void CalculatePhysic(ObjectManager* manager);

Vector2 BoxVsBox(
Transfrom transform1, Transfrom transform2,
BoxCollider* box1, BoxCollider* box2);
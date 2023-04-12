#pragma once
#include "Object.h"
#include "VertexMesh.h"


typedef struct GraphElement
{
	int* connected_points;
	int connected_points_size;
	int* radiuses_index;
	int radiuses_index_size;
}GraphElement;

typedef struct NavMesh
{
	GraphElement* grathElements;
	unsigned int grathElementsSize;
	Vector2* points;
	unsigned int points_size;
	float* radiuses;
	unsigned int radiuses_size;
	float width;
	float height;
}NavMesh;

void BuildNavMesh(NavMesh* navmesh, int count_object, Object *objects,int count_figures, VertexMesh* figures, float offset);
void FindPath(NavMesh* navmesh, Vector2* start, Vector2* end);
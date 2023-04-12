#include "NavMeshAgent.h"
#include <malloc.h>

void BuildNavMesh(NavMesh* navmesh, int count_object, Object *objects,int count_figures, VertexMesh* figures, float offset)
{
	float width = 0;
	float height = 0;
	navmesh->points_size = 0;
	for (int i=0;i < count_object;i++){
		navmesh->points_size+=figures[objects[i].index_of_figure].verticles_size;
	}
	navmesh->points = (Vector2*)malloc(sizeof(Vector2) * navmesh->points_size);
	
	
}
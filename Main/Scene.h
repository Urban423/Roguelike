#include "GraphicsEngine.h"
#include "KeyBoardState.h"
#include "ObjectHelper.h"
#include "Matrix3x3.h"
#include "VertexMesh.h"
#include "Texture.h"

#define size 5

typedef struct Scene
{
	Object player;
	Object wall1;
	Object wall2;
	KeyBoardState keyBoard;
	Buffer renderer;
	char is_running;
	float time;
	
	Transfrom camera;
	Matrix3x3 mat_cam;
	
	VertexMesh meshes[size];
	unsigned int meshes_size;
	
	Texture textures[size];
	unsigned int textures_size;
}Scene;

void onCreate(Scene* scene);
void onUpdate(Scene* scene);
char render(Scene* scene);
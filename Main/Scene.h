#include "KeyBoardState.h"
#include "ObjectHelper.h"
#include "Matrix3x3.h"
#include "VertexMesh.h"
#include "Texture.h"
#include "Window.h"

typedef struct Scene
{
	Object player;
	Object wall1;
	Object wall2;
	KeyBoardState keyBoard;
	Buffer renderer;
	char is_running;
	float time;
	HWND hwnd;
	
	Transfrom camera;
	Matrix3x3 mat_cam;
	
	VertexMesh meshes[5];
	unsigned int meshes_size;
	
	Texture textures[5];
	unsigned int textures_size;
}Scene;

void onCreate(Scene* scene);
void onUpdate(Scene* scene);
char render(Scene* scene);
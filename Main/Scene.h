#include "GraphicsEngine.h"
#include "KeyBoardState.h"
#include "ObjectHelper.h"
#include "Matrix3x3.h"

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
	
}Scene;

void onCreate(Scene* scene);
void onUpdate(Scene* scene);
char render(Scene* scene);
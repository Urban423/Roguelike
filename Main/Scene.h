#include "GraphicsEngine.h"
#include "KeyBoardState.h"
#include "ObjectHelper.h"

typedef struct Scene
{
	Object player;
	Object wall1;
	Object wall2;
	KeyBoardState keyBoard;
	Buffer renderer;
	char is_running;
	float time;
	
}Scene;

void onCreate(Scene* scene);
void onUpdate(Scene* scene);
char render(Scene* scene);
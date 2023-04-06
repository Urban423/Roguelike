#include "GraphicsEngine.h"
#include "KeyBoardState.h"
#include "ObjectHelper.h"

typedef struct Scene
{
	Object obj;
	KeyBoardState keyBoard;
	Buffer renderer;
	char is_running;
	
}Scene;

void onCreate(Scene* scene);
void onUpdate(Scene* scene);
void render(Scene* scene);
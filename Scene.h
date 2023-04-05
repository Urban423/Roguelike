#include "GraphicsEngine.h"
#include "Sys.h"

typedef struct Scene
{
	KeyBoardState keyBoard;
	Buffer renderer;
	char is_running;
	
}Scene;

void onCreate(Scene* scene);
void onUpdate(Scene* scene);
void render(Scene* scene);
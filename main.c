#include "Scene.h"

int main()
{
	Scene scene;
	onCreate(&scene);
	while(scene.is_running)
	{
		onUpdate(&scene);
	}
	return 0;
}
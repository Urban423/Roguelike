#include "Scene.h"

int main()
{
	Scene scene;
	onCreate(&scene);
	while(scene.is_running == 1)
	{
		onUpdate(&scene);
	}
	return 0;
}
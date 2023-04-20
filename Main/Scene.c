#include "Scene.h"
#include "ObjectHelper.h"
#include "Vector2.h"
#include <math.h>
#include "Physics.h"
#include "BMPImage.h"
#include "GraphicsEngine.h"
#include "Input.h"
#include "SceneLoader.h"

void onCreate(Scene* scene)
{
	BufferConstructor(&scene->renderer.buffer, 640, 480);
	createWindow(&scene->renderer);
	createKeyBoard(&(scene->keyBoard));
	setKeyBoard(scene->keyBoard.key_board_state, scene->keyBoard.old_key_board_state);
	scene->is_running = 1;
	scene->time = 0;
	CreateVertexBox(&scene->meshes[0]);
	scene->meshes_size = 5;
	scene->textures_size = 5;
	ReadBMPFile(&scene->textures[0], "./Assets/LoadGame.bmp");
	ReadBMPFile(&scene->textures[1], "./Assets/LoadGame.bmp");
	ReadBMPFile(&scene->textures[2], "./Assets/Statistic.bmp");
	ReadBMPFile(&scene->textures[3], "./Assets/Exit.bmp");
	
	CreateSceneMenu(scene);
	
	setOrthoLH(&scene->view_proj, scene->renderer.buffer.width, scene->renderer.buffer.height, 10, 30);
}

void UpdateCamera(Scene* scene, Object* object)
{
	Matrix3x3 m_view, temp;
	setIdentity(&m_view);
	SetRotation(&m_view, object->transform.rotation);


	setIdentity(&temp);
	setTranslation(&temp, object->transform.position);
	m_view = MultipleMatrixMatrix(m_view, temp);
	
	scene->world_cam  = inverse(m_view);
}

void onUpdate(Scene* scene)
{
	
	scene->time += 1.1f;
	updateKeyBoard(&scene->keyBoard);
	
	Object* obj;
	ObjectList* list = scene->objectManager.list;
	
	obj = list->object;
	UpdateObject(obj);
	UpdateCamera(scene, obj);
	ProcessWorldPos(obj, scene->view_proj, scene->world_cam);
	list = list->next;
	
	for(int i = 1; i < scene->objectManager.size; i++)
	{
		obj = list->object;
		list = list->next;
		UpdateObject(obj);
		ProcessWorldPos(obj, scene->view_proj, scene->world_cam);
	}
	
	if(render(scene))
	{
		scene->is_running = 0;
	}
};


char render(Scene* scene)
{
	BufferClear(&scene->renderer.buffer, 0, 255, 0);
	
	Object* obj;
	ObjectList* list = scene->objectManager.list;
	for(int i = 0; i < scene->objectManager.size; i++)
	{
		obj = list->object;
		list = list->next;
		BufferDrawObject(&scene->renderer.buffer, obj->world_pos, &scene->meshes[0], &scene->textures[0]);
	}
	
	//SetImage(&scene->renderer.buffer, &scene->textures[0]);
	
	if(updateWindow(&scene->renderer))
	{
		return 1;
	}
	return 0;
}

#include "graphics_scene.h"

graphics_scene::graphics_scene()
{
	_type = GRAPHICS_SCENE;
}

graphics_scene::~graphics_scene()
{

}

void graphics_scene::init(uobject* root, state_manager* st_mng)
{
	_root = root->getGameObject(GRAPHICS_OBJECT, st_mng);
}

void graphics_scene::run(double* delta, int thread)
{
	_root->run(delta, thread);
}
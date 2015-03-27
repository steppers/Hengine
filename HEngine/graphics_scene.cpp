#include "graphics_scene.h"

graphics_scene::graphics_scene()
{
	_type = GRAPHICS_SCENE;
}

graphics_scene::~graphics_scene()
{

}

void graphics_scene::init(uobject* root)
{
	_root = root->getGameObject(GRAPHICS_OBJECT);
}
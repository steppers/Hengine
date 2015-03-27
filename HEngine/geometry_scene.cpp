#include "geometry_scene.h"

geometry_scene::geometry_scene()
	: scene()
{
	_type = GEOMETRY_SCENE;
}

geometry_scene::~geometry_scene()
{

}

void geometry_scene::init(uobject* root)
{
	_root = root->getGameObject(GEOMETRY_OBJECT);
}
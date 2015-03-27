#include "geometry_scene.h"

geometry_scene::geometry_scene()
	: scene()
{
	_type = GEOMETRY_SCENE;
}

geometry_scene::~geometry_scene()
{

}

void geometry_scene::init(uobject* root, state_manager* st_mng)
{
	_root = root->getGameObject(GEOMETRY_OBJECT, st_mng);
}

void geometry_scene::run(double* delta, int thread)
{
	_root->run(delta, thread);
}
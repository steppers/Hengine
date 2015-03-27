#include "scene_loader.h"

scene_loader::scene_loader()
{
	_u_scene = new uscene();
	_geometry_scene = new geometry_scene();
	_graphics_scene = new graphics_scene();
}

void scene_loader::load(scene_template* scene)
{
	scene->load();
	_u_scene->init(scene->getRoot());
	_geometry_scene->init(_u_scene->getRoot());
	_graphics_scene->init(_u_scene->getRoot());
}

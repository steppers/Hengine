#include "scene_loader.h"

scene_loader::scene_loader(state_manager* st_mng)
{
	_u_scene = new uscene();
	_geometry_scene = new geometry_scene();
	_graphics_scene = new graphics_scene();
	_st_mng = st_mng;
}

void scene_loader::load(scene_template* scene)
{
	scene->load();
	_u_scene->init(scene->getRoot(), _st_mng);
	_geometry_scene->init(_u_scene->getRoot(), _st_mng);
	_graphics_scene->init(_u_scene->getRoot(), _st_mng);
}

#include "scene_loader.h"

void scene_loader::load(scene_template* scene)
{
	scene->load();
	_rootObject = scene->getRoot();
}

void scene_loader::genScenes()
{
	//Generate the different scene types from the root object and it's children's components.
}

game_object* scene_loader::getRootObject()
{
	return _rootObject;
}

vector<scene*>* scene_loader::getScenes()
{
	return &_scenes;
}
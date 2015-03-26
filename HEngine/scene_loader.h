#pragma once

#include <vector>

#include "scene_template.h"
#include "scene.h"

class scene_loader
{
public:
	scene_loader(){};
	~scene_loader(){};

	void load(scene_template* scene);

	game_object* getRootObject();
	vector<scene*>* getScenes();

private:
	vector<scene*> _scenes;
	game_object* _rootObject;

	void genScenes();
};


#pragma once

#include <vector>

#include "scene_template.h"

#include "uscene.h"
#include "geometry_scene.h"
#include "graphics_scene.h"

class scene_loader
{
public:
	scene_loader();
	~scene_loader(){};

	void load(scene_template* scene);
	
	//Scene getters
	uscene* getUScene(){ return _u_scene; }
	geometry_scene* getGeometryScene(){ return _geometry_scene; }
	graphics_scene* getGraphicsScene(){ return _graphics_scene; }

private:
	//UScene
	uscene* _u_scene = NULL;

	//System scenes
	geometry_scene* _geometry_scene = NULL;
	graphics_scene* _graphics_scene = NULL;

	void genScenes();
	void createNewScenes();
};


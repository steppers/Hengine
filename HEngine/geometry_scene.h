#pragma once

#include "scene.h"
#include "uobject.h"

class geometry_scene : public scene
{
public:
	geometry_scene();
	~geometry_scene();

	void init(uobject* root) override;

private:
	game_object* _root;
};


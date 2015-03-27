#pragma once

#include "scene.h"
#include "uobject.h"

class geometry_scene : public scene
{
public:
	geometry_scene();
	~geometry_scene();

	void init(uobject* root, state_manager* st_mng) override;
	void run(double* delta, int thread) override;

private:
	game_object* _root;
};
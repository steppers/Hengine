#pragma once

#include "scene.h"
#include "uobject.h"

class graphics_scene : public scene
{
public:
	graphics_scene();
	~graphics_scene();

	void init(uobject* root) override;

private:
	game_object* _root;
};
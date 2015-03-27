#pragma once

#include <vector>
#include "game_object.h"

#define U_SCENE 0
#define GEOMETRY_SCENE 1
#define GRAPHICS_SCENE 2
#define PHYSICS_SCENE 3

class scene
{
public:
	scene();
	~scene();

	virtual void init(uobject* root){};

protected:
	short _type;
};


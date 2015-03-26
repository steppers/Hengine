#pragma once

#include <vector>
#include "game_object.h"

class scene
{
public:
	scene();
	~scene();

private:
	vector<game_object*> objects;
	string type;
};


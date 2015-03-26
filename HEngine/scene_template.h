#pragma once

#include "game_object.h"

class scene_template
{
public:
	virtual void load() = 0;
	game_object* getRoot(){ return &root; };
	
protected:
	game_object root;
};
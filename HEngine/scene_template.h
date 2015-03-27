#pragma once

#include "uobject.h"

//Component includes
#include "geometry_component.h"
#include "graphics_component.h"

class scene_template
{
public:
	scene_template():root("root"){}

	virtual void load() = 0;
	uobject* getRoot(){ return &root; };
	
protected:
	uobject root;
};
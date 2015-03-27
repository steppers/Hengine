#pragma once

#include "scene.h"

enum system_type
{
	GEOMETRY_SYSTEM,
	GRAPHICS_SYSTEM,
	INPUT_SYSTEM,
	PHYSICS_SYSTEM
};

class System
{
public:
	//Task used by the task manager
	virtual void system_task(int thread){};
	virtual void init(double* deltaLocation){};

	system_type getType(){ return _type; }

protected:
	system_type _type;
	double* p_delta;
};

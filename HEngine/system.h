#pragma once

#include "scene.h"

class System
{
public:
	//Task used by the task manager
	virtual void system_task(){};

	//Called by the scene loader
	virtual void createSystemScene(){};
};
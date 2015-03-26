#pragma once

#include "game_object.h"
#include "scene.h"

class System
{
public:
	//Task used by the task manager
	virtual void system_task(){};

	//Called by the scene loader
	virtual void createSystemScene(){};

protected:
	scene _scene;
};
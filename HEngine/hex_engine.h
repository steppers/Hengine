#pragma once

//managers
#include "state_manager.h"
#include "environment_manager.h"
#include "platform_manager.h"
#include "service_manager.h"
#include "task_manager.h"

//framework
#include "u_scene.h"

//Systems
#include "graphics_system.h"
#include "input_system.h"
#include "geometry_system.h"

//Scheduler
#include "scheduler.h"

//Misc.
#include <thread>

class hex_engine
{
public:
	hex_engine();
	~hex_engine();

	void setScene(u_scene scene);
	void start();

private:
	//Scene
	u_scene scene;

	//Managers
	state_manager _state_manager;
	environment_manager _environment_manager;
	platform_manager _platform_manager;
	service_manager _service_manager;
	task_manager _task_manager;

	//systems
	graphics_system* _graphics;
	input_system* _input;
	geometry_system* _geometry;

	//scheduler
	scheduler _scheduler;

	bool _running = false;

	void run();
};


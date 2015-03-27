#pragma once

//GLFW
#include <GLFW\glfw3.h>

//managers
#include "state_manager.h"
#include "environment_manager.h"
#include "platform_manager.h"
#include "service_manager.h"
#include "task_manager.h"

//Game World
#include "scene_loader.h"

//Systems
#include "system_builder.h"
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
	hex_engine(scene_template* first_scene);
	~hex_engine();

	void start();

private:
	//Scene
	scene_loader _scene_loader;

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
	double delta = 0;

	void run();
	void stop();
};


#include "hex_engine.h"

hex_engine::hex_engine(scene_template* first_scene)
{
	_graphics = new graphics_system(&_state_manager,
		&_environment_manager,
		&_platform_manager,
		&_service_manager,
		&_task_manager);

	_input = new input_system(&_state_manager,
		&_environment_manager,
		&_platform_manager,
		&_service_manager,
		&_task_manager);

	_geometry = new geometry_system(&_state_manager,
		&_environment_manager,
		&_platform_manager,
		&_service_manager,
		&_task_manager);

	_scene_loader.load(first_scene);

	_graphics->init();
	_input->init();
	_geometry->init();

	
}


hex_engine::~hex_engine()
{
	delete _graphics;
}

void hex_engine::start()
{
	_running = true;
	run();
}

void hex_engine::run()
{
	double delta = 0;
	glfwSetTime(0);

	while (_running)
	{
		delta = glfwGetTime();
		glfwSetTime(0);
		if (delta < 0.016)
			this_thread::sleep_for(chrono::microseconds((int)((0.016-delta)*1000000)));

		_platform_manager.pollWindowEvents();

		//Add the tasks to the scheduler
		_scheduler.addTask(_graphics);
		_scheduler.addTask(_input);
		_scheduler.addTask(_geometry);

		//Submit the tasks and execute them
		_task_manager.submitTasks(_scheduler.getTaskQueue());
		_task_manager.executeTasks();

		//Update changes across systems
		_state_manager.distributeChanges();

		if (_platform_manager.getWindow()->isCloseRequested())
			_running = false;
	}
}

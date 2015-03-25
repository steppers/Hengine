#include "hex_engine.h"

hex_engine::hex_engine()
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
	while (_running)
	{
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

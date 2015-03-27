#include "hex_engine.h"

hex_engine::hex_engine(scene_template* first_scene)
	: _scene_loader(&_state_manager)
{
	system_builder sys(&_state_manager, &_environment_manager, &_platform_manager, &_service_manager, &_task_manager);
	_geometry = (geometry_system*)sys.createSystem(GEOMETRY_SYSTEM);
	_graphics = (graphics_system*)sys.createSystem(GRAPHICS_SYSTEM);
	_input = (input_system*)sys.createSystem(INPUT_SYSTEM);

	//Load the first scene
	_scene_loader.load(first_scene);

	//Set the system scenes
	_graphics->setScene(_scene_loader.getGraphicsScene());
	_geometry->setScene(_scene_loader.getGeometryScene());

	//Initialise the systems
	_geometry->init(&delta);
	_graphics->init(&delta);
	_input->init(&delta);
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
			stop();
	}
}

void hex_engine::stop()
{
	_running = false;

	//Make sure all our objects and threads are deleted
	_task_manager.destroy();
}

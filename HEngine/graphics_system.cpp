#include "graphics_system.h"

graphics_system::graphics_system(state_manager* st_mng,
	environment_manager* env_mng,
	platform_manager* plt_mng,
	service_manager* svc_mng,
	task_manager* tsk_mng)
{
	//set manager pointers
	_state_manager = st_mng;
	_environment_manager = env_mng;
	_platform_manager = plt_mng;
	_service_manager = svc_mng;
	_task_manager = tsk_mng;

	win = new window(800, 600, "Untitled");
	plt_mng->setWindow(win);
}

graphics_system::~graphics_system()
{
	_platform_manager->setWindow(NULL);
	delete win;
}

void graphics_system::init(double* deltaLocation)
{
	p_delta = deltaLocation;
}

void graphics_system::system_task(int thread)
{
	glfwMakeContextCurrent(win->getWindow());
	_scene->run(p_delta, thread);
	win->update();
}

#include "input_system.h"

input_system::input_system(state_manager* st_mng,
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
}

input_system::~input_system()
{

}

void input_system::init(double* deltaLocation)
{
	p_delta = deltaLocation;
}

void input_system::system_task(int thread)
{
	if (_platform_manager->getInput()->isKeyDown(GLFW_KEY_SPACE))
		cout << num++ << endl;
}
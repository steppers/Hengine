#include "geometry_system.h"

geometry_system::geometry_system(state_manager* st_mng,
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

geometry_system::~geometry_system()
{

}

void geometry_system::init()
{

}

void geometry_system::system_task()
{
	
}
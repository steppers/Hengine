#pragma once

#include "system.h"
#include "geometry_system.h"
#include "graphics_system.h"
#include "input_system.h"

class state_manager;
class environment_manager;
class platform_manager;
class service_manager;
class task_manager;

class system_builder
{
public:
	system_builder(state_manager* st_mng,
		environment_manager* env_mng,
		platform_manager* plt_mng,
		service_manager* svc_mng,
		task_manager* tsk_mng)
	{
		_state_manager = st_mng;
		_environment_manager = env_mng;
		_platform_manager = plt_mng;
		_service_manager = svc_mng;
		_task_manager = tsk_mng;
	}

	System* createSystem(system_type type)
	{
		switch (type)
		{
		case GEOMETRY_SYSTEM:
			return new geometry_system(_state_manager,
				_environment_manager,
				_platform_manager,
				_service_manager,
				_task_manager);
		case GRAPHICS_SYSTEM:
			return new graphics_system(_state_manager,
				_environment_manager,
				_platform_manager,
				_service_manager,
				_task_manager);
		case INPUT_SYSTEM:
			return new input_system(_state_manager,
				_environment_manager,
				_platform_manager,
				_service_manager,
				_task_manager);
		case PHYSICS_SYSTEM:
			return NULL;
		default:
			return NULL;
		}
	}

private:
	state_manager* _state_manager;
	environment_manager* _environment_manager;
	platform_manager* _platform_manager;
	service_manager* _service_manager;
	task_manager* _task_manager;
};
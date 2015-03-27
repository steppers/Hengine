#pragma once

#include "state_manager.h"
#include "environment_manager.h"
#include "platform_manager.h"
#include "service_manager.h"
#include "task_manager.h"

#include "system.h"

#include "geometry_scene.h"

class geometry_system : public System
{
public:
	geometry_system(state_manager* st_mng,
		environment_manager* env_mng,
		platform_manager* plt_mng,
		service_manager* svc_mng,
		task_manager* tsk_mng);
	~geometry_system();

	void setScene(geometry_scene* scene){ _scene = scene; }
	void init(double* deltaLocation) override;

	void system_task(int thread) override;

private:
	//Manager interfaces
	state_manager* _state_manager;
	environment_manager* _environment_manager;
	platform_manager* _platform_manager;
	service_manager* _service_manager;
	task_manager* _task_manager;

	geometry_scene* _scene;
};
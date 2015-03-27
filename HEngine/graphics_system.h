#pragma once

#include "state_manager.h"
#include "environment_manager.h"
#include "platform_manager.h"
#include "service_manager.h"
#include "task_manager.h"

#include "window.h"
#include "system.h"

#include "graphics_scene.h"

class graphics_system : public System
{
public:
	graphics_system(state_manager* st_mng,
		environment_manager* env_mng,
		platform_manager* plt_mng,
		service_manager* svc_mng,
		task_manager* tsk_mng);
	~graphics_system();

	void setScene(graphics_scene* scene){ _scene = scene; }
	void init();

	void system_task() override;

private:
	//Manager interfaces
	state_manager* _state_manager;
	environment_manager* _environment_manager;
	platform_manager* _platform_manager;
	service_manager* _service_manager;
	task_manager* _task_manager;

	window* win;

	graphics_scene* _scene;
};


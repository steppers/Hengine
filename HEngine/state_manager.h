#pragma once

#include "system.h"
#include "object_change_listener.h"
#include "scene_change_listener.h"

using namespace std;

class state_manager
{
public:
	state_manager();
	~state_manager();

	void submitObjectChange(game_object* obj, System* sys, int thread);
	void submitSceneChange(u_scene* scn, System* sys, int thread);

	void registerObjectListener(game_object* obj, System* observer, System* subject){
		_object_listener.registerListener(obj,  observer, subject);
	}
	void registerSceneListener(System* observer, System* subject){
		_scene_listener.registerListener(observer, subject);
	}

	void distributeChanges()
	{
		_object_listener.distributeChanges();
		_scene_listener.distributeChanges();
	}

private:
	//Change listeners
	object_change_listener _object_listener;
	scene_change_listener _scene_listener;
};


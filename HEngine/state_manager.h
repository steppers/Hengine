#pragma once

#include "system.h"
#include "component_change_listener.h"
#include "scene_change_listener.h"

using namespace std;

class state_manager
{
public:
	state_manager() : _component_listener(thread::hardware_concurrency()){};
	~state_manager(){};

	component_change_listener* getComponentListener(){ return &_component_listener; }
	scene_change_listener* getSceneListener(){ return &_scene_listener; }

	void distributeChanges()
	{
		_component_listener.distributeChanges();
		//_scene_listener.distributeChanges();
	}

private:
	//Change listeners
	component_change_listener _component_listener;
	scene_change_listener _scene_listener;
};


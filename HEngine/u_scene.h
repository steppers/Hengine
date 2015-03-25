#pragma once

#include <vector>
#include "scene_change_listener.h"
#include "u_object.h"

using namespace std;

class u_scene
{
public:
	u_scene();
	~u_scene();

	void setListener(scene_change_listener* listener);
	void registerChange(System* system)
	{
		if (listener != NULL)
			listener->addChange(this, system);
	}

private:
	scene_change_listener* listener;
	vector<u_object> objects;
};
#pragma once

#include <vector>
#include <thread>

#include "system.h"

using namespace std;

class u_scene;

typedef struct _scene_change
{
	_scene_change(u_scene* scn, System* sys)
	{
		scene = scn;
		system = sys;
	}
	u_scene* scene = NULL;
	System* system = NULL;
} scene_change;

class scene_change_listener
{
public:
	scene_change_listener();
	~scene_change_listener();

	void registerListener(System* observer, System* subject);
	void addChange(u_scene* scn, System* subject);

	void distributeChanges();

private:
	vector<scene_change*>* changes;
};


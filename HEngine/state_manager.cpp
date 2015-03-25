#include "state_manager.h"

state_manager::state_manager()
{
	
}


state_manager::~state_manager()
{
}

void state_manager::submitObjectChange(u_object* obj, System* sys, int thread)
{
	/*object_change* change = new object_change(obj, sys);
	changes[thread].push_back(change);*/
}

void state_manager::submitSceneChange(u_scene* scn, System* sys, int thread)
{
	/*scene_change* change = new scene_change(scn, sys);
	changes[thread].push_back(change);*/
}
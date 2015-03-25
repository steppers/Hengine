#include "scene_change_listener.h"

scene_change_listener::scene_change_listener()
{
	changes = new vector<scene_change*>[thread::hardware_concurrency()];
}


scene_change_listener::~scene_change_listener()
{
	delete[] changes;
}

void scene_change_listener::distributeChanges()
{

}

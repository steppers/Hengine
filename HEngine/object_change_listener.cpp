#include "object_change_listener.h"

object_change_listener::object_change_listener()
{
	changes = new vector<object_change*>[thread::hardware_concurrency()];
}


object_change_listener::~object_change_listener()
{
	delete[] changes;
}

void object_change_listener::registerListener(game_object* obj, System* observer, System* subject)
{

}

void object_change_listener::addChange(game_object* obj, System* subject, int thread)
{

}

void object_change_listener::distributeChanges()
{

}
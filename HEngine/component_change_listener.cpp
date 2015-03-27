#include "component_change_listener.h"
#include "uobject.h"

component_change_listener::component_change_listener(int numThreads)
{
	for (int i = 0; i < numThreads; i++)
	{
		_changes.push_back(new vector<component_change*>);
	}
}


component_change_listener::~component_change_listener()
{
	
}

void component_change_listener::addChange(component* comp, uobject* uObj, int thread)
{
	_changes[thread]->push_back(new component_change(comp, uObj));
}

void component_change_listener::distributeChanges()
{
	for (int i = 0; i < thread::hardware_concurrency(); i++)
	{
		for (component_change* c : *_changes[i])
		{
			c->_uobject->synchronizeWith(c->component);
			delete c;
		}
		_changes[i]->clear();
	}
}
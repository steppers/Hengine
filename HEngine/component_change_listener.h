#pragma once

#include <vector>
#include <thread>

using namespace std;

class uobject;
class System;
class component;

typedef struct _component_change
{
	_component_change(component* comp, uobject* uObj)
	{
		component = comp;
		_uobject = uObj;
	}
	component* component = NULL;
	uobject* _uobject = NULL;
} component_change;

class component_change_listener
{
public:
	component_change_listener(int numThreads);
	~component_change_listener();

	void addChange(component* obj, uobject* uObj, int thread);

	void distributeChanges();

private:
	vector<vector<component_change*>*> _changes;
};

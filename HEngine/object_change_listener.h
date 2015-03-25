#pragma once

#include <vector>
#include <thread>

#include "system.h"

using namespace std;

class u_object;

typedef struct _object_change
{
	_object_change(u_object* obj, System* sys)
	{
		object = obj;
		system = sys;
	}
	u_object* object = NULL;
	System* system = NULL;
} object_change;

class object_change_listener
{
public:
	object_change_listener();
	~object_change_listener();

	void registerListener(u_object* obj, System* observer, System* subject);
	void addChange(u_object* obj, System* subject);

	void distributeChanges();

private:
	vector<object_change*>* changes;
};

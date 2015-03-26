#pragma once

#include <vector>
#include <thread>

using namespace std;

class System;
class game_object;

typedef struct _object_change
{
	_object_change(game_object* obj, System* sys)
	{
		object = obj;
		system = sys;
	}
	game_object* object = NULL;
	System* system = NULL;
} object_change;

class object_change_listener
{
public:
	object_change_listener();
	~object_change_listener();

	void registerListener(game_object* obj, System* observer, System* subject);
	void addChange(game_object* obj, System* subject, int thread);

	void distributeChanges();

private:
	vector<object_change*>* changes;
};

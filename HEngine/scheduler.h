#pragma once

#include <queue>
#include "system.h"

using namespace std;

class scheduler
{
public:
	scheduler(){};
	~scheduler(){};

	void addTask(System* system)
	{
		tasks.push(system);
	};

	queue<System*>* getTaskQueue() { return &tasks; };

private:
	queue<System*> tasks;
};


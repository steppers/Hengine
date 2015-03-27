#pragma once

#include "thread_pool.h"
#include "system.h"
#include <queue>

using namespace std;

class task_manager
{
public:
	task_manager();
	~task_manager();
	
	void submitTasks(queue<System*>* queue){ taskQueue = queue; }
	void executeTasks();

	void destroy();

private:
	thread_pool* pool;
	queue<System*>* taskQueue;
};


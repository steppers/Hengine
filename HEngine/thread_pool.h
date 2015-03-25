#pragma once

#include "task_thread.h"
#include "system.h"

using namespace std;

class thread_pool
{
public:
	thread_pool(int numThreads);
	~thread_pool();

	void startTask(System* t);
	bool isEmpty(){
		for (int i = 0; i < _numThreads; i++)
		{
			if (!_threads[i].isAvailable())
				return false;
		}
		return true;
	};

private:
	task_thread* _threads = NULL;
	int _numThreads = 0;
};


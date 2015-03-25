#include "thread_pool.h"

thread_pool::thread_pool(int numThreads)
{
	_numThreads = numThreads;
	_threads = new task_thread[numThreads];
}

thread_pool::~thread_pool()
{
	delete[] _threads;
}

void thread_pool::startTask(System* t)
{
	while (true)
	{
		for (int i = 0; i < _numThreads; i++)
		{
			if (_threads[i].isAvailable())
			{
				_threads[i].setTask(t);
				_threads[i].notify();
				return;
			}
		}
	}
}

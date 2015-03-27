#include "thread_pool.h"

thread_pool::thread_pool(int numThreads)
{
	_numThreads = numThreads;
	_threads = new task_thread[numThreads];

	for (int i = 0; i < numThreads; i++)
	{
		_threads[i].setId(i);
	}
}

thread_pool::~thread_pool()
{
	
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

void thread_pool::destroy()
{
	for (int i = 0; i < _numThreads; i++)
	{
		_threads[i].stop();
	}
	delete[] _threads;
}

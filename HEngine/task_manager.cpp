#include "task_manager.h"

task_manager::task_manager()
{
	//Create a pool with the same number of threads as cores.
	pool = new thread_pool(thread::hardware_concurrency());
}

task_manager::~task_manager()
{
	delete pool;
}

void task_manager::executeTasks()
{
	while (!taskQueue->empty())
	{
		//start the task at the front of the queue
		pool->startTask(taskQueue->front());
		taskQueue->pop();
	}

	//Wait for all tasks to complete
	while (!pool->isEmpty()){}
}

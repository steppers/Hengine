#include "task_thread.h"

void wait(mutex mtx, condition_variable cv);

task_thread::task_thread()
{
	thr = new thread(&task_thread::loop, this);
}

task_thread::~task_thread()
{
	
}

void task_thread::loop()
{
	unique_lock<mutex> lk(mtx);
	while (executing)
	{
		//Wait
		cv.wait(lk);

		if (_task != NULL)
		{
			//Execute task here
			_task->system_task();
			_task = NULL;
		}
	}
}

void task_thread::notify()
{
	lock_guard<mutex> lk(mtx);
	cv.notify_all();
}

void task_thread::wait()
{
	unique_lock<mutex> lk(mtx);
	cv.wait(lk);
}

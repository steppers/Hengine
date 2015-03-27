#pragma once

#include <thread>
#include <mutex>
#include <condition_variable>
#include "system.h"

using namespace std;

class task_thread
{

public:
	task_thread();
	~task_thread();

	void notify();
	bool isAvailable(){ return _task == NULL; }
	void setTask(System* t){ _task = t; }

	void stop(){ 
		_task = NULL;
		executing = false;
		notify();
		thr->join();
	}

private:
	thread* thr;
	System* _task = NULL;

	mutex mtx;
	condition_variable cv;

	bool executing = true;
	bool taskAvailable = false;

	void loop();
	void wait();
};


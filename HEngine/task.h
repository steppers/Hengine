#pragma once
#include "scheduler.h"

class task
{
public:
	task(queuedTask function);
	~task();

	void run();

private:
	queuedTask f;
};


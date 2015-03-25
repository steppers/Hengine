#include "task.h"

task::task(queuedTask function)
{
	f = function;
}


task::~task()
{
}

void task::run()
{
	(*_function)();
}

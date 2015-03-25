#pragma once

#include "object_change_listener.h"
#include "system.h"

class u_object
{
public:
	u_object();
	~u_object();

	void setListener(object_change_listener* listener);
	void registerChange(System* system)
	{
		if (listener != NULL)
			listener->addChange(this, system);
	}

private:
	object_change_listener* listener;
};
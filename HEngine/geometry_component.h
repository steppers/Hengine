#pragma once

#include "component.h"

class geometry_component : public component
{
public:
	geometry_component();
	~geometry_component();

	void run() override;
	void updateWith(component* comp) override;
	component* copy() override;
};

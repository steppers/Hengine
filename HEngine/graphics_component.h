#pragma once

#include "component.h"

class graphics_component : public component
{
public:
	graphics_component();
	~graphics_component();

	void run() override;
	void updateWith(component* comp) override;
	component* copy() override;
};

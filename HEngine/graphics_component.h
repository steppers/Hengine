#pragma once

#include <GLFW\glfw3.h>
#include "component.h"
#include "game_object.h"
#include "geometry_component.h"

class graphics_component : public component
{
public:
	graphics_component();
	~graphics_component();

	void run(int thread) override;
	void updateWith(component* comp) override;
	component* copy() override;

	void submitChange(int thread) override;
};

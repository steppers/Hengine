#pragma once

#include "component.h"
#include "vector3d.h"
#include "game_object.h"

class geometry_component : public component
{
public:
	geometry_component();
	geometry_component(double posX, double posY, double posZ);
	~geometry_component();

	void run(int thread) override;
	void updateWith(component* comp) override;
	component* copy() override;

	vector3d* getPos(){ return &_pos; };

	void submitChange(int thread) override;

private:
	vector3d _pos;
};

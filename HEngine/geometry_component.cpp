#include "geometry_component.h"

#include <random>

using namespace std;

default_random_engine generator;
uniform_real_distribution<float> distribution(0, 1);

geometry_component::geometry_component()
{
	_type = GEOMETRY_COMPONENT;
}

geometry_component::geometry_component(double posX, double posY, double posZ)
	: _pos(posX, posY, posZ)
{
}

geometry_component::~geometry_component()
{

}

void geometry_component::run(int thread)
{
	_pos.set(distribution(generator), distribution(generator), distribution(generator));
	_changed = true;

	if (_changed)
		submitChange(thread);
}

void geometry_component::updateWith(component* comp)
{
	((geometry_component*)comp)->getPos()->copyTo(&_pos);
}

component* geometry_component::copy()
{
	return new geometry_component();
}

void geometry_component::submitChange(int thread)
{
	if (_component_listener != NULL)
	{
		_component_listener->addChange(this, _owner->getUObject(), thread);
	}
}
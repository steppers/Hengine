#include "geometry_component.h"

geometry_component::geometry_component()
{
	_type = GEOMETRY_COMPONENT;
}

geometry_component::~geometry_component()
{

}

void geometry_component::run()
{

}

void geometry_component::updateWith(component* comp)
{

}

component* geometry_component::copy()
{
	return new geometry_component();
}
#include "graphics_component.h"

graphics_component::graphics_component()
{
	_type = GRAPHICS_COMPONENT;
}

graphics_component::~graphics_component()
{

}

void graphics_component::run()
{

}

void graphics_component::updateWith(component* comp)
{

}

component* graphics_component::copy()
{
	return new graphics_component();
}
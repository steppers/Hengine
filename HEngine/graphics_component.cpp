#include "graphics_component.h"

graphics_component::graphics_component()
{
	_type = GRAPHICS_COMPONENT;
}

graphics_component::~graphics_component()
{

}

void graphics_component::run(int thread)
{
	vector3d* v = ((geometry_component*)(_owner->getComponent(GEOMETRY_COMPONENT)))->getPos();
	glClearColor(v->getX(), v->getY(), v->getZ(), 1);
	glClear(GL_COLOR_BUFFER_BIT);
}

void graphics_component::updateWith(component* comp)
{

}

component* graphics_component::copy()
{
	return new graphics_component();
}

void graphics_component::submitChange(int thread)
{
	if (_component_listener != NULL)
	{
		_component_listener->addChange(this, _owner->getUObject(), thread);
	}
}
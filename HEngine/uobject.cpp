#include "uobject.h"

uobject::uobject(string name)
{
	uobject(name, 0, 0, 0);
}

uobject::uobject(string name, int x, int y, int z)
{
	_name = name;
	addComponent(new geometry_component());
}

void uobject::addChild(uobject* child)
{
	child->setParent(this);
	_children.push_back(child);
}

void uobject::setParent(uobject* parent)
{
	_parent = parent;
}

game_object* uobject::getGameObject(game_object_type type){
	switch (type)
	{
		case GEOMETRY_OBJECT:
			return getGeometryObject();
		case GRAPHICS_OBJECT:
			return getGraphicsObject();
	}
	return NULL;
}

game_object* uobject::getGeometryObject()
{
	game_object* me = new game_object();
	me->setUObject(this);

	component* ge = getComponent(GEOMETRY_COMPONENT);
	if (ge != NULL)
		me->addComponent(ge->copy());

	if (!_children.empty()){
		for (uobject* obj : _children){
			game_object* gObj = obj->getGameObject(GEOMETRY_OBJECT);
			gObj->setParent(me);
			me->addChild(gObj);
		}
	}
	return me;
}

game_object* uobject::getGraphicsObject()
{
	game_object* me = new game_object();
	me->setUObject(this);

	component* gr = getComponent(GRAPHICS_COMPONENT);
	if (gr != NULL)
		me->addComponent(gr->copy());

	component* ge = getComponent(GEOMETRY_COMPONENT);
	if (ge != NULL)
		me->addComponent(ge->copy());

	if (!_children.empty()){
		for (uobject* obj : _children){
			game_object* gObj = obj->getGameObject(GRAPHICS_OBJECT);
			gObj->setParent(me);
			me->addChild(gObj);
		}
	}
	return me;
}

void uobject::addComponent(component* comp)
{
	_components[comp->getType()] = comp;
}

component* uobject::getComponent(component_type type)
{
	if (_components.count(type) > 0)
		return _components.find(type)->second;
	return NULL;
}
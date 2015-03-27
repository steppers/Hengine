#include "uobject.h"

uobject::uobject(string name)
{
	uobject(name, 0, 0, 0);
}

uobject::uobject(string name, double x, double y, double z)
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

game_object* uobject::getGameObject(game_object_type type, state_manager* st_mng){
	switch (type)
	{
		case GEOMETRY_OBJECT:
			return getGeometryObject(st_mng);
		case GRAPHICS_OBJECT:
			return getGraphicsObject(st_mng);
	}
	return NULL;
}

game_object* uobject::getGeometryObject(state_manager* st_mng)
{
	game_object* me = new game_object();
	me->setUObject(this);
	_extensions.push_back(me);

	component* co = getComponent(GEOMETRY_COMPONENT);
	if (co != NULL)
	{
		co = co->copy();
		co->setListener(st_mng->getComponentListener());
		me->addComponent(co);
	}
		

	if (!_children.empty()){
		for (uobject* obj : _children){
			game_object* gObj = obj->getGameObject(GEOMETRY_OBJECT, st_mng);
			gObj->setParent(me);
			me->addChild(gObj);
		}
	}
	return me;
}

game_object* uobject::getGraphicsObject(state_manager* st_mng)
{
	game_object* me = new game_object();
	me->setUObject(this);
	_extensions.push_back(me);

	component* co = getComponent(GRAPHICS_COMPONENT);
	if (co != NULL)
	{
		co = co->copy();
		co->setListener(st_mng->getComponentListener());
		me->addComponent(co);

		co = getComponent(GEOMETRY_COMPONENT);
		if (co != NULL)
		{
			co = co->copy();
			co->setListener(st_mng->getComponentListener());
			me->addComponent(co);
		}
	}

	if (!_children.empty()){
		for (uobject* obj : _children){
			game_object* gObj = obj->getGameObject(GRAPHICS_OBJECT, st_mng);
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

void uobject::addExtension(game_object* obj)
{
	_extensions.push_back(obj);
}

void uobject::synchronizeWith(component* comp)
{
	for (game_object* go : _extensions)
	{
		go->synchronizeComponent(comp);
	}
}
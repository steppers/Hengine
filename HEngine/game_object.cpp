#include "game_object.h"

void game_object::addChild(game_object* child)
{
	child->setParent(this);
	_children.push_back(child);
}

void game_object::setParent(game_object* parent)
{
	_parent = parent;
}

void game_object::addComponent(component* comp)
{
	comp->setOwner(this);
	_components[comp->getType()] = comp;
}

component* game_object::getComponent(component_type type)
{
	if (_components.count(type) > 0)
		return _components.find(type)->second;
	return NULL;
}

void game_object::synchronizeComponent(component* comp)
{
	unordered_map<component_type, component*>::const_iterator c = _components.find(comp->getType());
	if (c != _components.end())
		c->second->updateWith(comp);
}
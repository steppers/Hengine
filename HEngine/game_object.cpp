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

game_object* game_object::getParent()
{
	return _parent;
}
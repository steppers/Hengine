#pragma once

#include <unordered_map>
#include <vector>
#include "component.h"

enum game_object_type
{
	GEOMETRY_OBJECT,
	GRAPHICS_OBJECT
};

using namespace std;

class uobject;

class game_object
{
public:
	game_object(){};
	~game_object();

	void addChild(game_object* child);
	void setParent(game_object* parent);
	void setUObject(uobject* uobject){ _uobject = uobject; }

	void addComponent(component* comp);
	component* getComponent(component_type type);

	game_object* getParent(){ return _parent; }
	vector<game_object*>* getChildren(){ return &_children; }

private:
	uobject* _uobject;

	game_object* _parent;
	vector<game_object*> _children;

	unordered_map<component_type, component*> _components;
};
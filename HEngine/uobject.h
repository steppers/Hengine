#pragma once

#include <unordered_map>
#include <vector>
#include <string>

#include "game_object.h"

#include "component.h"
#include "geometry_component.h"
#include "graphics_component.h"
#include "state_manager.h"

using namespace std;

class uobject
{
public:
	uobject(string name);
	uobject(string name, double x, double y, double z);
	~uobject(){};

	void addChild(uobject* child);
	void setParent(uobject* parent);

	void addComponent(component* comp);
	component* getComponent(component_type type);

	uobject* getParent(){ return _parent; }
	vector<uobject*>* getChildren(){ return &_children; }

	game_object* getGameObject(game_object_type type, state_manager* st_mng);

	void addExtension(game_object* obj);
	void synchronizeWith(component* comp);

private:
	uobject* _parent;
	vector<uobject*> _children;
	string _name;
	unordered_map<component_type, component*> _components;

	vector<game_object*> _extensions;

	game_object* getGeometryObject(state_manager* st_mng);
	game_object* getGraphicsObject(state_manager* st_mng);
};


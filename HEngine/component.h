#pragma once

#include "component_change_listener.h"

class game_object;

enum component_type
{
	GEOMETRY_COMPONENT,
	GRAPHICS_COMPONENT,
	SCRIPT_COMPONENT
};

class component
{
public:
	component(){};
	~component(){};

	virtual void run(int thread){};
	virtual void updateWith(component* comp){};
	virtual component* copy(){ return 0; };

	void setOwner(game_object* owner){ _owner = owner; };
	component_type getType(){ return _type; }

	void setListener(component_change_listener* listener){ _component_listener = listener; }
	virtual void submitChange(int thread) = 0;

protected:
	game_object* _owner;
	component_type _type;

	component_change_listener* _component_listener = NULL;
	bool _changed = false;
};
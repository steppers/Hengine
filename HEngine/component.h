#pragma once

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

	virtual void run(){};
	virtual void updateWith(component* comp){};
	virtual component* copy(){ return 0; };

	void setOwner(game_object* owner){ _owner = owner; };
	component_type getType(){ return _type; }

protected:
	game_object* _owner;
	component_type _type;
};
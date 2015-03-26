#pragma once

#include <vector>

using namespace std;

class game_object
{
public:
	game_object(){};
	~game_object();

	void addChild(game_object* child);
	void setParent(game_object* parent);
	game_object* getParent();

private:
	game_object* _parent;
	vector<game_object*> _children;
};
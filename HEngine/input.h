#pragma once

#include <unordered_map>
#include <GLFW\glfw3.h>

using namespace std;

class input
{
public:
	input(){};
	~input(){};

	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

	bool isKeyDown(int key)
	{
		if (states.count(key) > 0)
			return states.find(key)->second;
   		return false;
	}

	bool isKeyUp(int key)
	{
		if (states.count(key) > 0)
			return !states.find(key)->second;
		return true;
	}

private:
	unordered_map<int, bool> states;
};


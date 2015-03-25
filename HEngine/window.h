#pragma once

#include <GLFW/glfw3.h>
#include <string>

#include "input.h"

using namespace std;

class window
{
public:

	window(int width, int height, string title);
	~window();
	
	bool isCreated(){ return _success; }

	void update();
	bool isCloseRequested();
	void setVSync(bool val);
	void setFullscreen(bool val);

	void setInput(input* in)
	{
		glfwSetWindowUserPointer(_window, in);
	}

	GLFWwindow* getWindow(){ return _window; }

private:
	GLFWwindow* _window;
	bool _success = true;

	int _width, _height;
	string _title;
	bool _fullscreen = false;
	bool _vsync = false;
};


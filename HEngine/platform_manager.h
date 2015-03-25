#pragma once

#include "window.h"
#include "input.h"

class platform_manager
{
public:
	platform_manager();
	~platform_manager();

	void setWindow(window* window){
		_window = window;
		if (_window != NULL)
			_window->setInput(&_input);
	}
	window* getWindow(){ return _window; }
	void pollWindowEvents(){ glfwPollEvents(); }

	input* getInput(){ return &_input; }

private:
	input _input;
	window* _window;
};


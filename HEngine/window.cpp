#include "window.h"

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

window::window(int width, int height, string title)
{
	_width = width;
	_height = height;
	_title = title;

	if (!glfwInit())
	{
		_success = false;
		return;
	}

	_window = glfwCreateWindow(width, height, ("HEngine - " + title).c_str(), NULL, NULL);
	if (!_window)
	{
		_success = false;
		glfwTerminate();
		return;
	}

	setVSync(_vsync);
	setFullscreen(_fullscreen);

	glfwSetKeyCallback(_window, keyCallback);
	glfwSetWindowUserPointer(_window, NULL);
}

window::~window()
{
	if (_success)
	{
		glfwDestroyWindow(_window);
		glfwTerminate();
	}
}

void window::update()
{
	glfwSwapBuffers(_window);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	input* in = (input*)glfwGetWindowUserPointer(window);
	if (in != NULL)
		in->keyCallback(window, key, scancode, action, mods);
}

bool window::isCloseRequested()
{
	return glfwWindowShouldClose(_window) == GL_TRUE;
}

void window::setVSync(bool val)
{
	glfwSwapInterval(val ? 1 : 0);
}

void window::setFullscreen(bool val)
{
	
}

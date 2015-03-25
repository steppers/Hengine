#include "input.h"

void input::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	states[key] = action == GLFW_PRESS ? true : false;

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
#include "input.h"

void input::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	switch (action){
	case GLFW_PRESS:
		states[key] = true;
		break;
	case GLFW_REPEAT:
		states[key] = true;
		break;
	case GLFW_RELEASE:
		states[key] = false;
		break;
	}

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
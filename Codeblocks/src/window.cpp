#include "window.h"

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

Window::Window(int width, int height, string title)
{
    if(!glfwInit())
    {
        cerr << "ERROR: GLFW could not be initialised." << endl;
        _success = false;
        return;
    }

    _window = glfwCreateWindow(width, height, "Hengine", NULL, NULL);
    if(_window == NULL)
    {
        cerr << "ERROR: GLFW could not create the window." << endl;
        _success = false;
        return;
    }

    //glfwMakeContextCurrent(_window);

    //glfwSetKeyCallback(_window, key_callback);
    glfwSwapInterval(1);
}

Window::~Window()
{
    if(_success)
    {
        if(_window != NULL)
            glfwDestroyWindow(_window);
        glfwTerminate();
    }
}

void Window::update()
{
    glfwPollEvents();
    glfwSwapBuffers(_window);
}

bool Window::isCloseRequested()
{
    return glfwWindowShouldClose(_window) == GL_TRUE;
}

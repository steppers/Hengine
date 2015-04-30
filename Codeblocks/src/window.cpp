#include "window.h"

window::window(int width, int height, string title)
{
    if(!glfwInit())
    {
        cerr << "ERROR: GLFW could not be initialised." << endl;
        _success = false;
        return;
    }

    _window = glfwCreateWindow(width, height, title, NULL, NULL);
    if(_window == null)
    {
        cerr << "ERROR: GLFW could not create the window." << endl;
        _success = false;
    }
}

window::~window()
{
    if(_success)
    {
        if(_window != null)
            glfwDestroyWindow(_window);
        glfwTerminate();
    }
}

#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;

class Window
{
    public:
        Window(int width, int height, string title);
        ~Window();

        void update();
        void getInput();

        bool isCloseRequested();

    private:
        GLFWwindow* _window;

        bool _success = true;
};

#endif // WINDOW_H

#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <iostream>

class window
{
    public:
        window(int width, int height, string title);
        ~window();
    private:
        GLFWwindow* _window;

        bool _success = true;
};

#endif // WINDOW_H

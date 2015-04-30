#include "window.h"

int main(void)
{
    Window window(400, 400, "Hengine");

    while(!window.isCloseRequested())
    {
        window.update();
    }
}

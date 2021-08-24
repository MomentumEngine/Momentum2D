#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "window.h"

int main()
{
    GLFW::Window window(1280, 720, "Momentum 2D");

    while (!window.ShouldClose())
        window.Update();

	return 0;
}

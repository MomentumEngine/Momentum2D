#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "window.h"

int main()
{
    GLFW::Window window(800, 600, "Momentum 2D");

    while (!glfwWindowShouldClose(window.m_Window))
        window.update();

	return 0;
}

#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>

namespace GLFW
{
    class Window {
    public:
        Window(int width, int height, const char* title);
        ~Window();
        void Update();
        int ShouldClose();
        GLFWwindow* m_Window;

    private:
        const char* m_Title;
        int m_Width;
        int m_Height;

        void InitWindow();
    };

}

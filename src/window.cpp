#include "window.h"

GLFW::Window::Window(int width, int height, const char* title):m_Width(width), m_Height(height), m_Title(title){
    InitWindow();
    }

GLFW::Window::~Window(){
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}


void GLFW::Window::InitWindow()
{
    if (!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
    if (m_Window == NULL)
    {
        throw std::runtime_error("Failed to initialize window");
        glfwTerminate();
    }

    glfwMakeContextCurrent(m_Window);
    glfwSetWindowUserPointer(m_Window, this);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw std::runtime_error("Failed to initialize glad");

    glViewport(0, 0, m_Width, m_Height);
}

void GLFW::Window::Update()
{
    glClearColor(0.5f, 0.8f, 0.9f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(m_Window);
    glfwPollEvents();
}

bool GLFW::Window::ShouldClose()
{
    return glfwWindowShouldClose(m_Window);
}
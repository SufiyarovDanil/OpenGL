#include "Window.h"
#include <iostream>
#include <string>
#include <GLFW/glfw3.h>


Window::Window(std::string name, const int width, const int height)
{
    init(name, width, height);
}


Window::~Window()
{
    glfwWindowShouldClose(window);
    glfwTerminate();
}


Window& Window::get_instance()
{
    static Window instance("OpenGL", 1024, 720);

    return instance;
}


int Window::get_width() const
{
    int width = 0;

    glfwGetWindowSize(window, &width, nullptr);
    
    return width;
}


int Window::get_height() const
{
    int height = 0;

    glfwGetWindowSize(window, nullptr, &height);

    return height;
}


void FrameSizeBufferCallBack(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}


void Window::init(const std::string& name, const int width, const int height)
{
    this->name = name;
    this->width = width;
    this->height = height;

    if (!glfwInit())
    {
        throw std::runtime_error("Can't init GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);

    if (!window)
    {
        glfwTerminate();

        throw std::runtime_error("Can't create a window");
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, FrameSizeBufferCallBack);
}

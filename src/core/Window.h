#pragma once

#include <string>


struct GLFWwindow;


class Window final
{

private:

	GLFWwindow* window = nullptr;

	std::string name;

	int width;

	int height;

public:

	Window(const Window&) = delete;

	Window& operator=(const Window&) = delete;

private:

	Window(std::string name, const int width, const int height);

	~Window();

public:

	void init(const std::string& name, const int width, const int height);

	static Window& get_instance();

	inline GLFWwindow* get_glfw_window() const { return window; }

	int get_width() const;

	int get_height() const;

};


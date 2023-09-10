#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "core/Window.h"
#include "core/Texture2D.h"
#include "core/ShaderProgram.h"
#include "core/VertexBuffer.h"
#include "core/VertexBufferLayout.h"
#include "core/IndexBuffer.h"
#include "core/VertexArray.h"
#include "core/Renderer.h"


int main(void)
{
	Window &window = Window::get_instance();

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Error!" << std::endl;

		return -1;
	}

	// canvas
	std::vector<GLfloat> verts = {
		// positions      // colors       // texture coords
		-1.f, 1.f,  0.f,  0.f, 0.f, 0.f,  0.f, 1.f,
		1.f,  1.f,  0.f,  0.f, 0.f, 0.f,  1.f, 1.f,
		1.f,  -1.f, 0.f,  0.f, 0.f, 0.f,  1.f, 0.f,
		-1.f, -1.f, 0.f,  0.f, 0.f, 0.f,  0.f, 0.f
	};

	std::vector<GLuint> inds = {
		0, 1, 2,
		2, 3, 0
	};

	core::VertexBuffer vb(verts);
	core::VertexBufferLayout layout;

	layout.push<GLfloat>(3); // position:		x, y, z
	layout.push<GLfloat>(3); // color:			x, y, z
	layout.push<GLfloat>(2); // texture coord:	x, y

	core::VertexArray va;

	va.add_buffer(vb, layout);

	core::IndexBuffer ib(inds);

	std::string vertex_shader = core::ShaderProgram::get_shader_source("res/shaders/texture.vert");
	std::string fragment_shader = core::ShaderProgram::get_shader_source("res/shaders/texture.frag");

	core::ShaderProgram shader_program(vertex_shader, fragment_shader);

	core::Texture2D texture("res/textures/fucking_deer.jpg", 0);

	va.unbind();
	vb.unbind();
	ib.unbind();
	texture.unbind();

	while (!glfwWindowShouldClose(window.get_glfw_window()))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		shader_program.bind();

		if (shader_program.has_uniform("ourTexture"))
		{
			shader_program.set_uniform1i("ourTexture", 0);
		}

		if (shader_program.has_uniform("resolution"))
		{
			shader_program.set_uniform2f("resolution", window.get_width(), window.get_height());
		}

		if (shader_program.has_uniform("time"))
		{
			shader_program.set_uniform1f("time", glfwGetTime());
		}

		core::Renderer::draw(va, ib, shader_program, texture);

		glfwSwapBuffers(window.get_glfw_window());
		glfwPollEvents();
	}

	shader_program.destroy();
	texture.destroy();

	glfwTerminate();

	return 0;
}

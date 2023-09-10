#include "ShaderProgram.h"
#include <GL/glew.h>
#include <iostream>
#include <fstream>


namespace core
{
	ShaderProgram::ShaderProgram(const std::string& vertex_source, const std::string& fragment_source)
	{
		const GLuint vert_shader = make_shader(GL_VERTEX_SHADER, vertex_source.c_str());
		const GLuint frag_shader = make_shader(GL_FRAGMENT_SHADER, fragment_source.c_str());

		this->object_id = make_program(vert_shader, frag_shader);

		glDeleteShader(vert_shader);
		glDeleteShader(frag_shader);
	}


	GLuint ShaderProgram::make_shader(const GLenum type, const char* src)
	{
		const GLuint shader = glCreateShader(type);

		glShaderSource(shader, 1, &src, nullptr);
		glCompileShader(shader);

		if (!check_shader(shader))
		{
			glDeleteShader(shader);

			return 0;
		}

		return shader;
	}


	GLuint ShaderProgram::make_program(const GLuint vertex_shader, const GLuint fragment_shader)
	{
		GLuint program = glCreateProgram();

		glAttachShader(program, vertex_shader);
		glAttachShader(program, fragment_shader);
		glLinkProgram(program);
		glValidateProgram(program);

		check_program(program);

		return program;
	}


	bool ShaderProgram::check_shader(const GLuint shader)
	{
		GLint result;

		glGetShaderiv(shader, GL_COMPILE_STATUS, &result);

		if (result == GL_FALSE)
		{
			GLint length;

			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);

			GLchar* message = new char[length];

			glGetShaderInfoLog(shader, length, &length, message);

			std::cout << "Failed to compile shader!" << std::endl;
			std::cout << message << std::endl;

			delete[] message;

			return false;
		}

		return true;
	}


	bool ShaderProgram::check_program(const GLuint program)
	{
		GLint result;

		glGetProgramiv(program, GL_LINK_STATUS, &result);

		if (result == GL_FALSE)
		{
			GLint length;

			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);

			GLchar* message = new char[length];

			glGetProgramInfoLog(program, length, &length, message);

			std::cout << "Failed to compile shader program!" << std::endl;
			std::cout << message << std::endl;

			delete[] message;

			return false;
		}

		return true;
	}


	void ShaderProgram::bind() const
	{
		if (is_destroyed())
		{
			return;
		}

		glUseProgram(object_id);
	}


	void ShaderProgram::unbind() const
	{
		glUseProgram(0);
	}


	void ShaderProgram::destroy()
	{
		if (is_destroyed())
		{
			return;
		}

		GLObject::destroy();

		glDeleteProgram(object_id);

		object_id = 0;
	}


	bool ShaderProgram::is_valid() const
	{
		return !is_destroyed() && object_id != 0;
	}


	GLint ShaderProgram::get_uniform_location(const std::string& name)
	{
		const GLint location = glGetUniformLocation(object_id, name.c_str());

		if (location == -1)
		{
			throw std::runtime_error("Failed to get uniform location: " + name);
		}

		return location;
	}


	bool ShaderProgram::has_uniform(const std::string& name)
	{
		const GLint location = glGetUniformLocation(object_id, name.c_str());

		return location != -1;
	}


	std::string ShaderProgram::get_shader_source(const std::string& file_path)
	{
		std::ifstream file(file_path, std::ios::binary);
		std::string result;

		if (!file.is_open())
		{
			throw std::runtime_error("can't find a shader file");

			return result;
		}

		file.seekg(0, std::ios::end);
		result.resize(file.tellg());
		file.seekg(0, std::ios::beg);
		file.read(&result[0], result.size());
		file.close();

		return result;
	}


	void ShaderProgram::set_uniform1i(const std::string& name, const int v0)
	{
		const GLint location = get_uniform_location(name);

		glUniform1i(location, v0);
	}


	void ShaderProgram::set_uniform1f(const std::string& name, const float v0)
	{
		const GLint location = get_uniform_location(name);

		glUniform1f(location, v0);
	}


	void ShaderProgram::set_uniform2f(const std::string& name, const float v0, const float v1)
	{
		const GLint location = get_uniform_location(name);

		glUniform2f(location, v0, v1);
	}


	void ShaderProgram::set_uniform3f(const std::string& name, const float v0, const float v1, const float v2)
	{
		const GLint location = get_uniform_location(name);

		glUniform3f(location, v0, v1, v2);
	}


	void ShaderProgram::set_uniform4f(const std::string& name, const float v0, const float v1, const float v2, const float v3)
	{
		const GLint location = get_uniform_location(name);

		glUniform4f(location, v0, v1, v2, v3);
	}
}

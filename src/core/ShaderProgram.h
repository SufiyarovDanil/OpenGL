#pragma once

#include "GLObject.h"
#include <string>


namespace core
{
	class ShaderProgram final : public GLObject
	{

	private:

		GLuint make_shader(const GLenum type, const char* src);

		GLuint make_program(const GLuint vertex_shader, const GLuint fragment_shader);

		bool check_shader(const GLuint shader);

		bool check_program(const GLuint program);

	public:

		ShaderProgram(const std::string& vertex_source, const std::string& fragment_source);

		virtual void bind() const final;

		virtual void unbind() const final;

		virtual void destroy() final;

		bool is_valid() const;

		GLint get_uniform_location(const std::string& name);

		bool has_uniform(const std::string& name);

		static std::string get_shader_source(const std::string& file_path);

		void set_uniform1i(const std::string& name, const int v0);

		void set_uniform1f(const std::string& name, const float v0);

		void set_uniform2f(const std::string& name, const float v0, const float v1);

		void set_uniform3f(const std::string& name, const float v0, const float v1, const float v2);

		void set_uniform4f(const std::string& name, const float v0, const float v1, const float v2, const float v3);

	};
}

#pragma once

#include "GLObject.h"
#include <string>


namespace core
{
	class Texture2D final : public GLObject
	{

	private:

		int width;

		int height;

		GLuint texture_block;

	public:

		Texture2D(const std::string& file_path, const GLuint texture_block);

		~Texture2D();

		virtual void bind() const final;

		virtual void unbind() const final;

		virtual void destroy() final;

		inline GLuint get_slot() const { return texture_block; }

	};
}

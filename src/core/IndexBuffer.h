#pragma once

#include "GLObject.h"
#include <vector>
#include <GL/glew.h>


namespace core
{
	class IndexBuffer final : public GLObject
	{

	private:

		GLuint count;

	public:

		IndexBuffer(const std::vector<GLuint> data);

		~IndexBuffer();

		virtual void bind() const final;

		virtual void unbind() const final;

		virtual void destroy() final;

		inline GLuint get_counts() const { return count; }

	};
}

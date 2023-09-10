#pragma once

#include "GLObject.h"
#include <vector>
#include "GL/glew.h"


namespace core
{
	class VertexBuffer final : public GLObject
	{

	public:

		VertexBuffer(const std::vector<GLfloat>& data);

		~VertexBuffer();

		virtual void bind() const final;

		virtual void unbind() const final;

		virtual void destroy() final;

	};
}

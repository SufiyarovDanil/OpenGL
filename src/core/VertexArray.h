#pragma once

#include "GLObject.h"


namespace core
{
	class VertexBuffer;
	class VertexBufferLayout;


	class VertexArray final : public GLObject
	{

	public:

		VertexArray();

		~VertexArray();

		virtual void bind() const final;

		virtual void unbind() const final;

		virtual void destroy() final;

		void add_buffer(const VertexBuffer& buffer, const VertexBufferLayout& layout);

	};
}

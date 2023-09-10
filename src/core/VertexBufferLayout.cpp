#include "VertexBufferLayout.h"
#include <iostream>
#include <GL/glew.h>


namespace core
{
	unsigned int VertexBufferElement::get_size_of_type(const unsigned int type)
	{
		switch (type)
		{
		case GL_FLOAT:			return sizeof(GLfloat);
		case GL_UNSIGNED_INT:	return sizeof(GLuint);
		case GL_UNSIGNED_BYTE:	return sizeof(GLubyte);
		}

		throw std::runtime_error("in param is not a type");

		return 0u;
	}


	VertexBufferLayout::VertexBufferLayout()
	{
		stride = 0;
	}


	template<>
	void VertexBufferLayout::push<GLfloat>(const unsigned int count)
	{
		VertexBufferElement element = {
			GL_FLOAT,
			count,
			GL_FALSE
		};

		elements.push_back(element);
		stride += count * VertexBufferElement::get_size_of_type(GL_FLOAT);
	}


	template<>
	void VertexBufferLayout::push<GLuint>(const unsigned int count)
	{
		VertexBufferElement element = {
			GL_UNSIGNED_INT,
			count,
			GL_FALSE
		};

		elements.push_back(element);
		stride += count * VertexBufferElement::get_size_of_type(GL_UNSIGNED_INT);
	}


	template<>
	void VertexBufferLayout::push<GLubyte>(const unsigned int count)
	{
		VertexBufferElement element = {
			GL_UNSIGNED_BYTE,
			count,
			GL_TRUE
		};

		elements.push_back(element);
		stride += count * VertexBufferElement::get_size_of_type(GL_UNSIGNED_BYTE);
	}
}

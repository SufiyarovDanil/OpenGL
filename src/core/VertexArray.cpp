#include "VertexArray.h"
#include <GL/glew.h>
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"


namespace core
{
	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &object_id);
		glBindVertexArray(object_id);
	}


	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &object_id);
	}


	void VertexArray::bind() const
	{
		glBindVertexArray(object_id);
	}

	void VertexArray::unbind() const
	{
		glBindVertexArray(0);
	}


	void VertexArray::destroy()
	{
		glDeleteVertexArrays(1, &object_id);
	}


	void VertexArray::add_buffer(const VertexBuffer& buffer, const VertexBufferLayout& layout)
	{
		buffer.bind();

		const auto& elements = layout.get_elements();
		GLuint offset = 0;

		for (unsigned int i = 0; i < elements.size(); i++)
		{
			const VertexBufferElement& element = elements[i];

			glEnableVertexAttribArray(i);
			glVertexAttribPointer(
				i,
				element.count,
				element.type,
				element.normalized,
				layout.get_stride(),
				(void*)offset);

			offset += element.count * VertexBufferElement::get_size_of_type(element.type);
		}
	}
}

#pragma once

#include <vector>


namespace core
{
	struct VertexBufferElement
	{
		unsigned int type;
		unsigned int count;
		unsigned char normalized;

		static unsigned int get_size_of_type(const unsigned int type);
	};


	class VertexBufferLayout
	{

	private:

		std::vector<VertexBufferElement> elements;

		unsigned int stride;

	public:

		VertexBufferLayout();

		template<typename T>
		void push(const unsigned int count);

		inline const std::vector<VertexBufferElement> get_elements() const& { return elements; }

		inline unsigned int get_stride() const { return stride; }

	};
}

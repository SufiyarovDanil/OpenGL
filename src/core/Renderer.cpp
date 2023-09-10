#include "Renderer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "ShaderProgram.h"
#include "Texture2D.h"


namespace core
{
	void Renderer::draw(const VertexArray& va, const IndexBuffer& ib, const ShaderProgram& shader)
	{
		shader.bind();
		va.bind();
		ib.bind();

		glDrawElements(GL_TRIANGLES, ib.get_counts(), GL_UNSIGNED_INT, nullptr);

		shader.unbind();
		va.unbind();
		ib.unbind();
	}


	void Renderer::draw(const VertexArray& va, const IndexBuffer& ib, const ShaderProgram& shader, const Texture2D& texture)
	{
		texture.bind();

		draw(va, ib, shader);

		texture.unbind();
	}
}

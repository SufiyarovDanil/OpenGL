#pragma once


namespace core
{
	class VertexArray;
	class IndexBuffer;
	class ShaderProgram;
	class Texture2D;


	class Renderer final
	{

	public:

		static void draw(const VertexArray& va, const IndexBuffer& ib, const ShaderProgram& shader);

		static void draw(const VertexArray& va, const IndexBuffer& ib, const ShaderProgram& shader, const Texture2D& texture);

	};
}

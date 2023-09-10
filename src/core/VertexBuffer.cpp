#include "VertexBuffer.h"
#include "Renderer.h"


namespace core
{
    VertexBuffer::VertexBuffer(const std::vector<GLfloat>& data)
    {
        const GLuint size = static_cast<GLuint>(data.size() * sizeof(GLfloat));

        glGenBuffers(1, &object_id);
        glBindBuffer(GL_ARRAY_BUFFER, object_id);
        glBufferData(GL_ARRAY_BUFFER, size, data.data(), GL_STATIC_DRAW);
    }


    VertexBuffer::~VertexBuffer()
    {
        destroy();
    }


    void VertexBuffer::bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, object_id);
    }


    void VertexBuffer::unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }


    void VertexBuffer::destroy()
    {
        glDeleteBuffers(1, &object_id);
    }
}

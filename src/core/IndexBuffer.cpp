#include "IndexBuffer.h"


namespace core
{
    IndexBuffer::IndexBuffer(const std::vector<GLuint> data)
    {
        this->count = static_cast<GLuint>(data.size());

        glGenBuffers(1, &object_id);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, object_id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data.data(), GL_STATIC_DRAW);
    }


    IndexBuffer::~IndexBuffer()
    {
        this->destroy();
    }


    void IndexBuffer::bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, object_id);
    }


    void IndexBuffer::unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }


    void IndexBuffer::destroy()
    {
        glDeleteBuffers(1, &object_id);
    }
}

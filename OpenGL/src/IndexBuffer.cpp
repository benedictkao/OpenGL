#include "IndexBuffer.h"
#include "Renderer.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
    : m_Count(count)
{
    ASSERT(sizeof(unsigned int) == sizeof(GLuint));                                               // just in case different systems have different sizes for the types

    GLCall(glGenBuffers(1, &m_RendererID));                                                       // assign id to buffer
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));                                          // bind the buffer (changes OpenGL state)
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));    // creates a data store for the buffer - size is in bytes
}

IndexBuffer::~IndexBuffer()
{
    GLCall(glDeleteBuffers(1, &m_RendererID));
}

void IndexBuffer::Bind() const
{
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));                                          // bind the buffer (changes OpenGL state)
}

void IndexBuffer::Unbind() const
{
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

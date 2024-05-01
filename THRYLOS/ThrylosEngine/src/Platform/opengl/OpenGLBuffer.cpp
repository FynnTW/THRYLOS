#include "tpch.h"
#include "OpenGLBuffer.h"

#include <glad/glad.h>

namespace Thrylos
{
    OpenGLVertexBuffer::OpenGLVertexBuffer(const float* vertices, const uint32_t size)
    {
        glGenBuffers(1, &m_RendererId);
        glBindBuffer(GL_ARRAY_BUFFER, m_RendererId);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
        LOG_CORE_INFO("Vertex Buffer created with id: {0}", m_RendererId);
    }

    OpenGLVertexBuffer::~OpenGLVertexBuffer()
    {
        glDeleteBuffers(1, &m_RendererId);
    }

    void OpenGLVertexBuffer::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_RendererId);
    }

    void OpenGLVertexBuffer::Unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    OpenGLIndexBuffer::OpenGLIndexBuffer(const uint32_t* indices, const uint32_t count)
    {
        glGenBuffers(1, &m_RendererId);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
        m_Count = count;
        LOG_CORE_INFO("Index Buffer created with id: {0}", m_RendererId);
    }

    OpenGLIndexBuffer::~OpenGLIndexBuffer()
    {
        glDeleteBuffers(1, &m_RendererId);
    }

    void OpenGLIndexBuffer::Bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererId);
    }

    void OpenGLIndexBuffer::Unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}

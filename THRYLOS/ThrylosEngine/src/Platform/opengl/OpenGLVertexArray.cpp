#include "tpch.h"
#include "OpenGLVertexArray.h"

#include "glad/glad.h"

namespace Thrylos
{
    OpenGLVertexArray::OpenGLVertexArray()
    {
        glGenVertexArrays(1, &m_RendererId);
    }

    OpenGLVertexArray::~OpenGLVertexArray()
    {
        glDeleteVertexArrays(1, &m_RendererId);
    }

    void OpenGLVertexArray::Bind() const
    {
        glBindVertexArray(m_RendererId);
    }

    void OpenGLVertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }

    void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
    {
        THRYLOS_ASSERT(!vertexBuffer->GetLayout().GetElements().empty(), "Vertex Buffer has no layout!")
        
        glBindVertexArray(m_RendererId);
        vertexBuffer->Bind();
        vertexBuffer->GetLayout().EnableVertexAttribArray();
        m_VertexBuffers.push_back(vertexBuffer);
    }

    void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
    {
        glBindVertexArray(m_RendererId);
        indexBuffer->Bind();

        m_IndexBuffer = indexBuffer;
    }
}

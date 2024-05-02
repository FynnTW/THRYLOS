#pragma once
#include "Renderer/Buffer.h"
#include "Renderer/VertexArray.h"

namespace Thrylos
{
    /**
     * @brief The OpenGL implementation of the VertexArray class.
     */
    class OpenGLVertexArray : public VertexArray
    {
    public:
        OpenGLVertexArray();
        ~OpenGLVertexArray();
        
        void Bind() const override;
        void Unbind() const override;
        
        void AddVertexBuffer(const VertexBufferRef& vertexBuffer) override;
        void SetIndexBuffer(const IndexBufferRef& indexBuffer) override;

        [[nodiscard]] const std::vector<VertexBufferRef>& GetVertexBuffers() const override { return m_VertexBuffers; }
        [[nodiscard]] const IndexBufferRef& GetIndexBuffer() const override { return m_IndexBuffer; }

    private:
        std::vector<VertexBufferRef> m_VertexBuffers;
        IndexBufferRef m_IndexBuffer;
        uint32_t m_RendererId;
    
    };
    
}

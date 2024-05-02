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
        
        void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) override;
        void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) override;

        [[nodiscard]] const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const override { return m_VertexBuffers; }
        [[nodiscard]] const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const override { return m_IndexBuffer; }

    private:
        std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
        std::shared_ptr<IndexBuffer> m_IndexBuffer;
        uint32_t m_RendererId;
    
    };
    
}

#include "tpch.h"
#include "Buffer.h"

#include "Renderer.h"
#include "Platform/opengl/OpenGLBuffer.h"

namespace Thrylos
{
    VertexBuffer* VertexBuffer::Create(const float* vertices, const uint32_t size)
    {
        switch (Renderer::GetRendererApi())
        {
            case RendererApi::None:
                THRYLOS_CORE_ASSERT(false, "RendererApi::None is currently not supported!")
                return nullptr;
            case RendererApi::OpenGl:
                return new OpenGLVertexBuffer(vertices, size);
        }
        
        return nullptr;
    }

    IndexBuffer* IndexBuffer::Create(const uint32_t* indices, const uint32_t count)
    {
        
        switch (Renderer::GetRendererApi())
        {
            case RendererApi::None:
                THRYLOS_CORE_ASSERT(false, "RendererApi::None is currently not supported!")
                return nullptr;
            case RendererApi::OpenGl:
                return new OpenGLIndexBuffer(indices, count);
        }
        
        return nullptr;
    }
}

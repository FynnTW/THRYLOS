#include "tpch.h"
#include "Buffer.h"

#include "Renderer/RendererApi.h"
#include "glad/glad.h"
#include "Platform/opengl/OpenGLBuffer.h"

namespace Thrylos
{
        
    [[nodiscard]] uint32_t BufferElement::TypeToOpenGl() const
    {
        switch (type)
        {
        case ShaderDataType::None:     break;
        case ShaderDataType::Float:    return GL_FLOAT;
        case ShaderDataType::Float2:   return GL_FLOAT;
        case ShaderDataType::Float3:   return GL_FLOAT;
        case ShaderDataType::Float4:   return GL_FLOAT;
        case ShaderDataType::Mat3:     return GL_FLOAT;
        case ShaderDataType::Mat4:     return GL_FLOAT;
        case ShaderDataType::Int:      return GL_INT;
        case ShaderDataType::Int2:     return GL_INT;
        case ShaderDataType::Int3:     return GL_INT;
        case ShaderDataType::Int4:     return GL_INT;
        case ShaderDataType::Bool:     return GL_BOOL;
        }

        THRYLOS_CORE_ASSERT(false, "Unknown ShaderDataType!")
        return 0;
    }
    
    void BufferLayout::EnableVertexAttribArray() const
    {
        uint32_t index = 0;
        for (auto& element : m_Elements)
        {
            glEnableVertexAttribArray(index);
            glVertexAttribPointer(
                index,
                element.GetElementCount(),
                element.TypeToOpenGl(),
                element.normalized ? GL_TRUE : GL_FALSE,
                m_Stride,
                reinterpret_cast<const void*>(element.offset) // NOLINT(performance-no-int-to-ptr)
            );
            index++;
        }
    }
    
    VertexBuffer* VertexBuffer::Create(const float* vertices, const uint32_t size)
    {
        switch (RendererApi::GetRendererApi())
        {
        case RendererApi::API::None:
                THRYLOS_CORE_ASSERT(false, "RendererApi::None is currently not supported!")
                return nullptr;
        case RendererApi::API::OpenGl:
                return new OpenGLVertexBuffer(vertices, size);
        }
        
        return nullptr;
    }

    IndexBuffer* IndexBuffer::Create(const uint32_t* indices, const uint32_t count)
    {
        
        switch (RendererApi::GetRendererApi())
        {
            case RendererApi::API::None:
                THRYLOS_CORE_ASSERT(false, "RendererApi::None is currently not supported!")
                return nullptr;
            case RendererApi::API::OpenGl:
                return new OpenGLIndexBuffer(indices, count);
        }
        
        return nullptr;
    }
}

#pragma once
#include "Renderer/Buffer.h"

namespace Thrylos
{
    /**
     * \brief Open Graphics Library (OpenGL) implementation of the VertexBuffer class.
     */
    class OpenGLVertexBuffer : public VertexBuffer
    {
    public:
       
        /**
         * \brief Constructor for OpenGLVertexBuffer
         * \param vertices The array of vertices
         * \param size The size of the array
         */
        OpenGLVertexBuffer(const float* vertices, uint32_t size);
        ~OpenGLVertexBuffer();
        /**
         * \brief Binds the OpenGL vertex buffer.
         *
         * This method is used to bind the OpenGL vertex buffer object (VBO) to the current OpenGL context's GL_ARRAY_BUFFER target.
         * When a VBO is bound, subsequent operations that modify the buffer's data or attributes will affect this bound buffer.
         *
         * Example usage:
         * \code
         * OpenGLVertexBuffer vbo(vertices, size);
         * vbo.Bind();
         * \endcode
         *
         * \note This method must be called before modifying or rendering the vertex buffer.
         * \note Only one VBO can be bound to GL_ARRAY_BUFFER target at a time.
         */
        void Bind() const override;
        /**
         * \brief Unbinds the OpenGL vertex buffer object (VBO).
         *
         * This method is used to unbind the currently bound OpenGL vertex buffer object (VBO)
         * from the current OpenGL context's GL_ARRAY_BUFFER target. Once unbound, subsequent
         * operations that modify the buffer's data or attributes will not affect this unbound buffer.
         *
         * Example usage:
         * \code
         * OpenGLVertexBuffer vbo(vertices, size);
         * vbo.Bind();
         * // Perform operations on the bound VBO
         * vbo.Unbind();
         * \endcode
         *
         * \note This method must be called when you're finished modifying or rendering the vertex buffer.
         * \note Only one VBO can be bound to GL_ARRAY_BUFFER target at a time.
         */
        void Unbind() const override;

        /**
         * \brief Sets the layout of the buffer for the vertex buffer object (VBO).
         *
         * This method is used to set the layout of the buffer for the vertex buffer object. The layout specifies the attributes of the vertices stored in the buffer, such as position, normal
         *, texture coordinates, etc.
         * The layout is defined using a BufferLayout object, which contains a list of BufferElement objects. Each BufferElement represents an attribute of the vertices, including its name,
         * data type, size, offset, and whether it should be normalized.
         *
         * Example usage:
         * \code
         * OpenGLVertexBuffer vbo(vertices, size);
         * BufferLayout layout = { { "position", ShaderDataType::Float3 }, { "normal", ShaderDataType::Float3 }, { "texcoord", ShaderDataType::Float2 } };
         * vbo.SetLayout(layout);
         * \endcode
         *
         * \param layout The layout of the buffer for the vertex buffer object.
         * \note This method must be called before binding or rendering the vertex buffer object.
         */
        void SetLayout(const BufferLayout& layout) override { m_Layout = layout; }
        /**
         * \brief Returns the layout of the vertex buffer object (VBO).
         *
         * This method returns the layout of the buffer for the vertex buffer object. The layout specifies the attributes of the vertices stored in the buffer, such as position, normal, texture
         * coordinates, etc.
         * The layout is defined using a BufferLayout object, which contains a list of BufferElement objects. Each BufferElement represents an attribute of the vertices, including its name,
         * data type, size, offset, and whether it should be normalized.
         *
         * Example usage:
         * \code
         * OpenGLVertexBuffer vbo(vertices, size);
         * const BufferLayout& layout = vbo.GetLayout();
         * // Use the layout to access and manipulate the attributes of the vertices
         * \endcode
         *
         * \return The layout of the buffer for the vertex buffer object.
         */
        [[nodiscard]] const BufferLayout& GetLayout() const override { return m_Layout; }
    private:
        uint32_t m_RendererId;
        BufferLayout m_Layout = {};
    
    };

    /**
     * \class OpenGLIndexBuffer
     *
     * \brief Represents an OpenGL implementation of the IndexBuffer class.
     *
     * This class inherits from the IndexBuffer class and provides an implementation for OpenGL-specific index buffer functionality.
     */
    class OpenGLIndexBuffer : public IndexBuffer
    {
    public:
        OpenGLIndexBuffer(const uint32_t* indices, uint32_t count);
        ~OpenGLIndexBuffer();
        void Bind() const override;
        void Unbind() const override;

        /**
         * \brief Returns the count of elements in the buffer.
         *
         * \return The count of elements in the buffer.
         */
        [[nodiscard]] uint32_t GetCount() const override { return m_Count; }

    private:
        uint32_t m_RendererId;
        uint32_t m_Count;
    };
}

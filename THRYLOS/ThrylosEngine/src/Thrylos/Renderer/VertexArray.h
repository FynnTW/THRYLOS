#pragma once
#include "Thrylos/Renderer/Buffer.h"

namespace Thrylos
{
    /**
     * @brief The VertexArray class is an abstract class that represents a VertexArray.
     */
    class VertexArray
    {
    public:
        VertexArray() = default;
        ~VertexArray() = default;

        /**
         * @brief Binds the VertexArray.
         *
         * This method is used to bind the VertexArray. It is a pure virtual method
         * and must be implemented by the derived classes.
         */
        virtual void Bind() const = 0;

        /**
         * @brief Unbinds the VertexArray.
         *
         * @details This method is used to unbind the VertexArray, releasing it from the current context.
         * This is typically done after the VertexArray has been used for rendering.
         * It is a pure virtual method and must be implemented by the derived classes.
         *
         * @see VertexArray, VertexArray::Bind()
         */
        virtual void Unbind() const = 0;

        /**
         * @brief Adds a vertex buffer to the vertex array.
         *
         * @details This method is used to add a vertex buffer to the vertex array.
         * It takes a shared pointer to a VertexBuffer object as a parameter.
         * The vertex buffer contains the actual vertex data that will be used for rendering.
         *
         * @param vertexBuffer A shared pointer to a VertexBuffer object representing the vertex buffer to be added.
         *
         * @see VertexBuffer, VertexBuffer::Create(), VertexBuffer::Bind(), VertexBuffer::SetLayout()
         */
        virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) = 0;

        /**
         * @brief Sets the index buffer for the vertex array.
         *
         * @details This method is used to set the index buffer for the vertex array.
         * The index buffer contains the indices that define the order in which vertices
         * are rendered. Only one index buffer can be set per vertex array.
         *
         * @param indexBuffer A shared pointer to an IndexBuffer object representing the index buffer to be set.
         *
         * @see VertexArray, IndexBuffer
         */
        virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) = 0;

        /**
         * @brief Gets the vertex buffers associated with the vertex array.
         *
         * @details This method returns the vertex buffers that have been added to the vertex array.
         * The return value is a constant reference to a vector of shared pointers to VertexBuffer objects.
         * These vertex buffers contain the actual vertex data used for rendering.
         *
         * @return A constant reference to a vector of shared pointers to VertexBuffer objects representing the vertex buffers.
         *
         * @see VertexArray, VertexBuffer, VertexArray::AddVertexBuffer()
         */
        [[nodiscard]] virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const = 0;

        /**
         * @brief Gets the index buffer associated with the vertex array.
         *
         * @details This method returns the index buffer that has been set for the vertex array.
         * The index buffer contains the indices that define the order in which vertices are rendered.
         * Only one index buffer can be set per vertex array.
         *
         * @return A constant reference to a shared pointer to an IndexBuffer object representing the index buffer.
         *
         * @see VertexArray, IndexBuffer, VertexArray::SetIndexBuffer()
         */
        [[nodiscard]] virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const = 0;


        /**
         * @brief Creates a new VertexArray object based on the current renderer API.
         *
         * @details This method is used to create a new VertexArray object based on the current renderer API.
         * It checks the current renderer API and returns a new VertexArray object specific to that API.
         * If the current renderer API is not supported, an assertion error is thrown.
         *
         * @return A pointer to a VertexArray object specific to the current renderer API, or nullptr if the renderer API is not supported.
         *
         * @see Renderer::GetRendererApi(), OpenGLVertexArray
         */
        static VertexArray* Create();
        
    
    };
    
}

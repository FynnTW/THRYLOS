#pragma once
#include "Thrylos/Renderer/RendererApi.h"

namespace Thrylos
{
    class RenderCommand
    {
    public:
        /**
         * @brief Draw indexed vertices of a vertex array using the current rendering API.
         *
         * This method is used to draw indexed vertices of a given vertex array using the current rendering API. The vertex array must have an associated index buffer.
         *
         * @param vertexArray A shared pointer to a VertexArray object representing the vertex array to be drawn.
         *
         * @pre
         * - The rendering API must be initialized before calling this method.
         * - The vertex array must have an associated index buffer.
         *
         * @post The indexed vertices of the vertex array will be drawn using the current rendering API.
         *
         * @remark
         * - If the vertex array is not bound, this method will not have any effect.
         *
         * @see
         * - VertexArray
         * - IndexBuffer
         */
        static void DrawIndexed(const VertexArrayRef& vertexArray)
        {
            m_SRendererApi->DrawIndexed(vertexArray);
        }

        /**
         * @brief Set the clear color for the current rendering API.
         *
         * This method is used to set the clear color for the current rendering API. The clear color is the color that is used to clear the screen before rendering the next frame.
         *
         * @param color A glm::vec4 object representing the clear color to be set.
         *
         * @pre The rendering API must be initialized before calling this method.
         *
         * @post The clear color for the current rendering API will be set to the specified color.
         *
         * @see RendererApi::SetClearColor()
         */
        static void SetClearColor(const glm::vec4& color)
        {
            m_SRendererApi->SetClearColor(color);
        }

        /**
         * @brief Clear the screen using the current rendering API.
         *
         * This method is used to clear the screen using the current rendering API. The screen is cleared using the clear color that was previously set.
         *
         * @pre The rendering API must be initialized before calling this method.
         *
         * @post The screen will be cleared using the current rendering API.
         *
         * @see RendererApi::Clear()
         */
        static void Clear()
        {
            m_SRendererApi->Clear();
        }

        static void Init()
        {
            m_SRendererApi->Init();
        }

    private:
        static RendererApi* m_SRendererApi;
    
    };
    
}

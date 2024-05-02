#pragma once

#include "Thrylos/Renderer/VertexArray.h"
#include "glm/glm.hpp"

namespace Thrylos
{
    class RendererApi
    {
    public:
        ~RendererApi() = default;
        
        /**
         * @enum API
         *
         * This enumeration represents the available renderer APIs.
         */
        // ReSharper disable once CppInconsistentNaming
        enum class API
        {
            None = 0, OpenGl = 1
        };

        virtual void SetClearColor(const glm::vec4& color) = 0;
        virtual void Clear() = 0;

        virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) = 0;

        /**
         * @brief Get the renderer API.
         *
         * This method returns the current renderer API that is being used.
         *
         * @return The renderer API being used.
         */
        static API GetRendererApi() { return m_SRendererApi; }

        /**
         * @brief Set the renderer API.
         *
         * This method sets the current renderer API to the specified value.
         *
         * @param api The renderer API to be set.
         */
        static void SetRendererApi(const API api) { m_SRendererApi = api; }

    private:
        static API m_SRendererApi;
        
    };
    
}

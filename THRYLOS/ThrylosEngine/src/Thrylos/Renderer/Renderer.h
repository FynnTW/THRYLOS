#pragma once
#include "Thrylos/Renderer/OrtographicCamera.h"
#include "Thrylos/Renderer/Shader.h"
#include "Thrylos/Renderer/VertexArray.h"

namespace Thrylos
{

    
    /**
     * \brief The Renderer class
     */
    class Renderer
    {
    public:
        static void BeginScene(const OrtographicCamera& camera);
        static void EndScene();
        static void Submit(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& shader, const glm::mat4& transform = glm::mat4(1.0f));
    private:
        struct SceneData
        {
            glm::mat4 viewProjectionMatrix;
        };
        static SceneData* m_SceneData;
    };
}


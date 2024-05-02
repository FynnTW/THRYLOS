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
        static void Submit(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& shader);
    private:
        struct SceneData
        {
            glm::mat4 viewProjectionMatrix;
        };
        static SceneData* m_SceneData;
    };
}


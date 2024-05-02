#include "tpch.h"
#include "Renderer.h"

#include "RenderCommand.h"

namespace Thrylos
{
    Renderer::SceneData* Renderer::m_SceneData = new SceneData();
    void Renderer::BeginScene(const OrtographicCamera& camera)
    {
        m_SceneData->viewProjectionMatrix = camera.GetViewProjectionMatrix();
    }

    void Renderer::EndScene()
    {
    }

    void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& shader, const glm::mat4& transform)
    {
        shader->Bind();
        shader->UploadUniformMat4("u_ViewProjection", m_SceneData->viewProjectionMatrix);
        shader->UploadUniformMat4("u_Transform", transform);
        vertexArray->Bind();
        RenderCommand::DrawIndexed(vertexArray);
    }
}

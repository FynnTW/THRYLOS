#include "tpch.h"
#include "Renderer.h"

#include "RenderCommand.h"

namespace Thrylos
{
    Renderer::SceneData* Renderer::m_SceneData = new SceneData();

    void Renderer::Init()
    {
        RenderCommand::Init();
    }

    void Renderer::BeginScene(const OrtographicCamera& camera)
    {
        m_SceneData->viewProjectionMatrix = camera.GetViewProjectionMatrix();
    }

    void Renderer::EndScene()
    {
    }

    void Renderer::Submit(const VertexArrayRef& vertexArray)
    {
        vertexArray->Bind();
        RenderCommand::DrawIndexed(vertexArray);
    }
}

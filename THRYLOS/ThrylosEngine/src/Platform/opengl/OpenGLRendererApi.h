#pragma once
#include "Renderer/RendererApi.h"

namespace Thrylos
{
    class OpenGLRendererApi : public RendererApi
    {
    public:
        virtual void DrawIndexed(const VertexArrayRef& vertexArray) override;
        //void Init() override;
        void SetClearColor(const glm::vec4& color) override;
        void Clear() override;
    };
    
}

#pragma once

namespace Thrylos
{
    enum class RendererApi
    {
        None = 0, OpenGl = 1
    };
    
    class Renderer
    {
    public:
        static RendererApi GetRendererApi() { return m_SRendererApi; }
        static void SetRendererApi(const RendererApi api) { m_SRendererApi = api; }
    private:
        static RendererApi m_SRendererApi;
    };
}


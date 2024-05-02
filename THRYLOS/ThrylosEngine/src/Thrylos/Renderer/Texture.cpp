#include "tpch.h"
#include "Texture.h"

#include "RendererApi.h"
#include "Platform/opengl/OpenGLTexture.h"

namespace Thrylos
{
    Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height)
    {
        switch (RendererApi::GetRendererApi())
        {
        case RendererApi::API::None:
            THRYLOS_CORE_ASSERT(false, "RendererApi::None is currently not supported!")
            return nullptr;
        case RendererApi::API::OpenGl:
            return createRef<OpenGLTexture2D>(width, height);
        }
        
        return nullptr;
    }

    Ref<Texture2D> Texture2D::Create(const std::string& path)
    {
        switch (RendererApi::GetRendererApi())
        {
        case RendererApi::API::None:
            THRYLOS_CORE_ASSERT(false, "RendererApi::None is currently not supported!")
            return nullptr;
        case RendererApi::API::OpenGl:
            return createRef<OpenGLTexture2D>(path);
        }
        
        return nullptr;
    }
}

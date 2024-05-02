#include "tpch.h"
#include "Shader.h"

#include <glm/gtc/type_ptr.hpp>

#include "RendererApi.h"
#include "Platform/opengl/OpenGLShader.h"


namespace Thrylos
{

    Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
    {
        
        switch (RendererApi::GetRendererApi())
        {
        case RendererApi::API::None:
            THRYLOS_CORE_ASSERT(false, "RendererApi::None is currently not supported!")
            return nullptr;
        case RendererApi::API::OpenGl:
            return new OpenGLShader(vertexSrc, fragmentSrc);
        }
        
        return nullptr;
    }
}

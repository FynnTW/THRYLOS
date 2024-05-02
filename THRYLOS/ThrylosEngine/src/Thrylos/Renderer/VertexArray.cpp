#include "tpch.h"
#include "VertexArray.h"

#include "RendererApi.h"
#include "Platform/opengl/OpenGLVertexArray.h"

namespace Thrylos
{
    VertexArray* VertexArray::Create()
    {
        switch (RendererApi::GetRendererApi())
        {
        case RendererApi::API::None:   THRYLOS_ASSERT(false, "RendererApi::None is currently not supported!"); return nullptr;
        case RendererApi::API::OpenGl:  return new OpenGLVertexArray();
        }

        THRYLOS_ASSERT(false, "Unknown RendererApi!");
        return nullptr;
    }
}

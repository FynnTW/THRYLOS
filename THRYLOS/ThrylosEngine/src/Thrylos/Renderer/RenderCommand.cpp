#include "tpch.h"
#include "RenderCommand.h"

#include "Platform/opengl/OpenGLRendererApi.h"

namespace Thrylos
{
    RendererApi* RenderCommand::m_SRendererApi = new OpenGLRendererApi();
}

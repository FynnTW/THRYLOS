#pragma once
#include "Window.h"
#include "Renderer/GraphicsContext.h"

namespace Thrylos
{
    class OpenGLContext : public GraphicsContext
    {
    public:
        OpenGLContext(GLFWwindow* windowHandle);
        
        void Init() override;
        void SwapBuffers() override;
    private:
        GLFWwindow* m_WindowHandle;
    };
    
}

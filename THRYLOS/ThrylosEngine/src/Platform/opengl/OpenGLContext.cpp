#include "tpch.h"
#include "OpenGLContext.h"

#include "glad/glad.h"

namespace Thrylos
{
    OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
        : m_WindowHandle(windowHandle)
    {
        THRYLOS_ASSERT(windowHandle, "Window handle is null!")
    }

    void OpenGLContext::Init()
    {
        glfwMakeContextCurrent(m_WindowHandle);
        const int status = gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));  // NOLINT(clang-diagnostic-cast-function-type-strict)
        THRYLOS_ASSERT(status, "Failed to initialize Glad!")
        

        LOG_CORE_INFO("OpenGL Info:");
        LOG_CORE_INFO("  Vendor: {0}", reinterpret_cast<const char*>(glGetString(GL_VENDOR)));
        LOG_CORE_INFO("  Renderer: {0}", reinterpret_cast<const char*>(glGetString(GL_RENDERER)));
        LOG_CORE_INFO("  Version: {0}", reinterpret_cast<const char*>(glGetString(GL_VERSION)));
        
    }

    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_WindowHandle);
    }
}

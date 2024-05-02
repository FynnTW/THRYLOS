#pragma once
#include "Window.h"
#include "Renderer/GraphicsContext.h"

namespace Thrylos
{
    /**
     * @class OpenGLContext
     * @brief A class representing an OpenGL context.
     *
     * This class inherits from GraphicsContext and provides functionality to initialize and swap buffers for an OpenGL context.
     */
    class OpenGLContext : public GraphicsContext
    {
    public:
        /**
         * \brief Construct a new OpenGLContext object
         * \param windowHandle The handle to the window
         */
        OpenGLContext(GLFWwindow* windowHandle);

        /**
         * \brief Initialize the OpenGL context.
         */
        void Init() override;

        /**
         * \brief Swaps the front and back buffers for the OpenGL context.
         *
         * This method is responsible for swapping the front and back buffers to update the rendering displayed on the window. It calls the `glfwSwapBuffers` function with the appropriate `
         *window` parameter.
         *
         * \note This method must be called after finishing rendering a frame to display the updated rendering on the screen.
         */
        void SwapBuffers() override;
    private:
        GLFWwindow* m_WindowHandle;
    };
    
}

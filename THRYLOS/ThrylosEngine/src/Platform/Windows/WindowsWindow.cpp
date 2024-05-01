#include "tpch.h"
#include "WindowsWindow.h"

#include "Log.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

#include "Platform/opengl/OpenGLContext.h"

namespace Thrylos
{
    //Static variable to keep track of whether GLFW has been initialized+
    static bool S_GLFW_INITIALIZED = false;
    
    /**
     * @brief Window constructor
     * @param props Window Properties
     */
    Window* Window::Create(const WindowProps& props)
    {
        return new WindowsWindow(props);
    }

    /**
     * @brief WindowsWindow constructor
     */
    WindowsWindow::WindowsWindow(const WindowProps& props)
    {
        WindowsWindow::Init(props);
    }

    /**
     * @brief WindowsWindow destructor
     */
    WindowsWindow::~WindowsWindow()
    {
        WindowsWindow::Shutdown();
    }

     /**
     * @brief Initializes the WindowsWindow object.
     * 
     * This function initializes the WindowsWindow object with the provided properties.
     * It sets the title, width, and height of the window, and logs this information.
     * If GLFW has not been initialized, it initializes it.
     * It then creates the window with the specified properties and makes it the current context.
     * It also sets the user pointer of the window to the data of this object.
     * Finally, it enables VSync.
     * 
     * @param props The properties to initialize the WindowsWindow object with.
     */
    void WindowsWindow::Init(const WindowProps& props)
    {
        m_Data.title = props.title;
        m_Data.width = props.width;
        m_Data.height = props.height;

        LOG_CORE_INFO("Creating window {0} ({1}, {2})", props.title, props.width, props.height);


        //Only initialize GLFW if it has not been initialized
        if (!S_GLFW_INITIALIZED)
        {
            const int success = glfwInit();
            THRYLOS_ASSERT(success, "Could not initialize GLFW!")
            S_GLFW_INITIALIZED = true;
        }

        m_Window = glfwCreateWindow(static_cast<int>(props.width), static_cast<int>(props.height), props.title.c_str(), nullptr, nullptr);
        m_Context = new OpenGLContext(m_Window);
        m_Context->Init();
        
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, const int width, const int height)
        {
            auto& [
                Title,
                Width,
                Height,
                VSync,
                EventCallback]
            = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
            
            Width = width;
            Height = height;
            WindowResizeEvent event(width, height);
            EventCallback(event);
        });

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
        {
            auto& [Title, Width, Height, VSync, EventCallback] = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
            WindowCloseEvent event;
            EventCallback(event);
        });

        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, const int key, [[maybe_unused]] const int scanCode, const int action, const int mods)
        {
            auto& [
                Title,
                Width,
                Height,
                VSync,
                EventCallback]
            = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

            switch (action)
            {
                case GLFW_PRESS:
                    {
                        KeyPressedEvent event(key, 0);
                        EventCallback(event);
                        break;
                    }
                case GLFW_RELEASE:
                    {
                        KeyReleasedEvent event(key);
                        EventCallback(event);
                        break;
                    }
                case GLFW_REPEAT:
                    {
                        KeyPressedEvent event(key, 1);
                        EventCallback(event);
                        break;
                    }
                default: ;
            }
        });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, const int button, const int action, [[maybe_unused]] const int mods)
        {
            auto& [
                Title,
                Width,
                Height,
                VSync,
                EventCallback]
            = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
            
            switch (action)
            {
                case GLFW_PRESS:
                    {
                        MouseButtonPressedEvent event(button);
                        EventCallback(event);
                        break;
                    }
                    case GLFW_RELEASE:
                    {
                        MouseButtonReleasedEvent event(button);
                        EventCallback(event);
                        break;
                    }
                    default: ;
                }
            });

        glfwSetScrollCallback(m_Window, [](GLFWwindow* window, const double xOffset, const double yOffset)
        {
            auto& [
                Title,
                Width,
                Height,
                VSync,
                EventCallback]
            = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
            
            MouseScrolledEvent event(static_cast<float>(xOffset), static_cast<float>(yOffset));
            EventCallback(event);
        });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, const double xPos, const double yPos)
        {
            auto& [
                Title,
                Width,
                Height,
                VSync,
                EventCallback]
            = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
            
            MouseMovedEvent event(static_cast<float>(xPos), static_cast<float>(yPos));
            EventCallback(event);
        });
    }
    
    /**
    * @brief Shuts down the WindowsWindow object.
    *
    * This function destroys the window associated with the WindowsWindow object.
    * It uses the GLFW function glfwDestroyWindow to do this.
    */
    void WindowsWindow::Shutdown()
    {
        glfwDestroyWindow(m_Window);
    }

    /**
    * @brief Updates the WindowsWindow object.
    *
    * This function is responsible for updating the state of the WindowsWindow object.
    * It polls for any pending events using the GLFW function glfwPollEvents.
    * Then, it swaps the front and back buffers of the window using the GLFW function glfwSwapBuffers.
    */
    void WindowsWindow::OnUpdate()
    {
        glfwPollEvents();
        m_Context->SwapBuffers();
    }

    /**
    * @brief Set the vertical sync (VSync) for the window.
    * When VSync is enabled, the window's buffer swap will be synchronized with the vertical refresh rate of the monitor.
    * @param enabled Whether VSync should be enabled or disabled
    */
    void WindowsWindow::SetVSync(bool enabled)
    {
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_Data.vSync = enabled;
    }

    /**
     * @brief Check if vertical sync (VSync) is enabled.
     * @return True if VSync is enabled, false otherwise.
     */
    bool WindowsWindow::IsVSync() const
    {
        return m_Data.vSync;
    }
    
}

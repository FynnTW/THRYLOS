#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"

class Window;

namespace Thrylos
{
    /**
     * @brief The main application class
     */
    class THRYLOS_API Application
    {
    public:
        Application();
        virtual ~Application();
        /**
         * @brief Run the application
         */
        void Run();

        //onEvent
        void OnEvent(Event& e);
    private:
        bool OnWindowClose(WindowCloseEvent& e);
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    /**
     * @brief Create an application
     * @return The application
     */
    Application* CreateApplication();
}


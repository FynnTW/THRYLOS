#pragma once

#include "Core.h"
#include "Layer.h"
#include "LayerStack.h"
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
        static Application& Get() { return *m_SInstance; }

        //onEvent
        void OnEvent(Event& e);
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
        
        [[nodiscard]] Window& GetWindow() const { return *m_Window; }
    private:
        bool OnWindowClose(WindowCloseEvent& e);
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
        static Application* m_SInstance;
    };

    /**
     * @brief Create an application
     * @return The application
     */
    Application* CreateApplication();
}


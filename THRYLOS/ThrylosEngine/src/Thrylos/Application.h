#pragma once

#include "Core.h"
#include "Layer.h"
#include "LayerStack.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"
#include "imgui/ImGuiLayer.h"
#include "Renderer/Buffer.h"
#include "Renderer/Shader.h"

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

        ImGuiLayer* GetImGuiLayer() const { return m_ImGuiLayer; }
        
        [[nodiscard]] Window& GetWindow() const { return *m_Window; }
    private:

        unsigned int m_VertexArray;
        std::unique_ptr<Shader> m_Shader;
        std::unique_ptr<VertexBuffer> m_VertexBuffer;
        std::unique_ptr<IndexBuffer> m_IndexBuffer;
        bool OnWindowClose(WindowCloseEvent& e);
        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
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


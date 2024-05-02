#pragma once

#include "Core.h"
#include "Layer.h"
#include "LayerStack.h"
#include "Window.h"
#include "Core/TimeStep.h"
#include "Events/ApplicationEvent.h"
#include "imgui/ImGuiLayer.h"
#include "Renderer/OrtographicCamera.h"
#include "Renderer/Shader.h"
#include "Renderer/VertexArray.h"

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

        /**
         * @brief Get the instance of the Application class.
         *
         * @return Application& The reference to the Application instance.
         */
        static Application& Get() { return *m_SInstance; }

        /**
         * @brief Handles the event passed to the application.
         *
         * @param e The event to be handled.
         */
        void OnEvent(Event& e);

        /**
         * @brief Pushes a layer onto the layer stack.
         *
         * This method is used to add a layer to the application's layer stack. The layer will be
         * rendered and updated in the order it was pushed onto the stack.
         *
         * @param layer A pointer to the layer to be pushed onto the stack.
         */
        void PushLayer(Layer* layer);

        /**
         * @brief Pushes a layer onto the layer stack.
         *
         * This method is used to add an overlay layer to the application's layer stack. The overlay layer will be
         * rendered and updated on top of the regular layers in the order it was pushed onto the stack.
         *
         * @param overlay A pointer to the overlay layer to be pushed onto the stack.
         */
        void PushOverlay(Layer* overlay);


        /**
         * @brief Get the ImGuiLayer attached to the Application.
         *
         * This method returns a pointer to the ImGuiLayer that is attached to the Application.
         * The ImGuiLayer is responsible for drawing the ImGui user interface on top of the main application window.
         *
         * @return ImGuiLayer* A pointer to the ImGuiLayer.
         */
        ImGuiLayer* GetImGuiLayer() const { return m_ImGuiLayer; }

        /**
         * @brief Get the window associated with the application.
         *
         * This method returns a reference to the window associated with the application.
         * The window is responsible for displaying the graphical user interface of the application.
         *
         * @return Window& A reference to the application window.
         */
        [[nodiscard]] Window& GetWindow() const { return *m_Window; }
    private:
        bool OnWindowClose(WindowCloseEvent& e);
        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;
        LayerStack m_LayerStack;
        float m_LastFrameTime = 0.0f;
        static Application* m_SInstance;
    };

    /**
     * @brief Create an application
     * @return The application
     */
    Application* CreateApplication();
}


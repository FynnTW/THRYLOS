#include "tpch.h"
#include "Application.h"

#include "imgui.h"
#include "Renderer/RenderCommand.h"

namespace Thrylos
{

    // ReSharper disable once CppInconsistentNaming
    Application* Application::m_SInstance = nullptr;
    
    /**
     * @brief Default constructor for the Application class.
     *
     * This constructor creates a new Application object and initializes the member variables.
     * It creates a unique pointer to a Window object by calling the static Create() method of the Window class.
     * It then sets the event callback function of the window to the OnEvent() method of the Application class.
     *
     * @return None.
     */
    Application::Application()
    {
        THRYLOS_ASSERT(!m_SInstance, "Application already exists!")
        m_SInstance = this;
        
        m_Window = Scope<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
        m_ImGuiLayer = new ImGuiLayer();
        PushOverlay(m_ImGuiLayer);
    }

    /**
     * @brief Destructor for the Application class.
     *
     * This destructor is called when the Application object is being destroyed.
     *
     * @return None.
     */
    Application::~Application()
    {
    }

    /**
     * @brief Pushes a layer onto the layer stack.
     *
     * This method adds a layer to the layer stack of the application.
     *
     * @param layer A pointer to the layer to be pushed onto the layer stack.
     *
     * @return None.
     */
    void Application::PushLayer(Layer* layer)
    {
        m_LayerStack.PushLayer(layer);
    }

    /**
     * @brief Pushes a layer to the overlay stack.
     *
     * This method adds the specified layer to the overlay stack of the application's layer stack. The layer is pushed onto the top of the overlay stack.
     *
     * @param overlay A pointer to the Layer object that is being added to the overlay stack.
     *
     * @return None.
     */
    void Application::PushOverlay(Layer* overlay)
    {
        m_LayerStack.PushOverlay(overlay);
    }

    /**
     
     * @brief Handles an event by dispatching it to the appropriate event handler and notifying the layers.
     
     *
     
     * This method is responsible for dispatching the given event to the appropriate event handler using the EventDispatcher class.
     
     * It first creates an EventDispatcher object with the given event. Then, it dispatches the event to the event handler for the WindowCloseEvent type by calling the OnWindowClose() method
     * of
     
     * the Application class and binding it to the Dispatcher. After that, it logs the event using the LOG_CORE_TRACE macro.
     
     * Finally, it iterates through all the layers in the LayerStack and calls their OnEvent() method, passing the event as a parameter.
     
     *
     
     * @param e The event to be handled.
     
     * @return None.
     
     */
    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
        
        LOG_CORE_TRACE("{0}", e);

        for (Layer* layer : m_LayerStack)
        {
            layer->OnEvent(e);
            if (e.handled)
                break;
        }
    }

    /**
     * @brief Run the application.
     *
     * This method is responsible for running the application. It enters a loop that continues
     * until the m_Running flag is set to false. On each iteration of the loop, it calls the OnUpdate()
     * method of each layer in the layer stack, and then calls the OnUpdate() method of the window.
     * This allows for updating the state of the application and handling events.
     *
     * @return None.
     */
    void Application::Run()
    {
        while (m_Running)
        {
            const float time = static_cast<float>(glfwGetTime());
            TimeStep timeStep = time - m_LastFrameTime;
            m_LastFrameTime = time;
            
            for (Layer* layer : m_LayerStack)
                layer->OnUpdate(timeStep);
            
            m_ImGuiLayer->Begin();
            
            for (Layer* layer : m_LayerStack)
                layer->OnImGuiRender();
            
            m_ImGuiLayer->End();
            
            m_Window->OnUpdate();
        }
    }

    /**
     * @brief Callback function for handling the WindowCloseEvent.
     *
     * This function is called when a WindowCloseEvent is dispatched. It sets the 'm_Running' member variable
     * of the Application class to false, indicating that the application should stop running, and returns true.
     *
     * @param e The WindowCloseEvent object.
     * @return true.
     */
    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_Running = false;
        return true;
    }
}

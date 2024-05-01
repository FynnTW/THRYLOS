#pragma once
#include "Window.h"
#include "GLFW/glfw3.h"

namespace Thrylos
{
    /**
     * @brief Windows implementation of the Window Interface
     */
    class WindowsWindow : public Window
    {
    public:
        /**
         * @brief Constructor
         * @param props Window properties
         */
        explicit WindowsWindow(const WindowProps& props);

        ~WindowsWindow() override;

        void OnUpdate() override;

        /**
         * @brief Get the width of the window
         * @return The width of the window
         */
        unsigned int GetWidth() const override {return m_Data.width;}
        /**
         * @brief Get the height of the window
         * @return The height of the window
         */
        unsigned int GetHeight() const override {return m_Data.height;}

        void SetEventCallback(const EventCallbackFn& callback) override {m_Data.eventCallback = callback;}
        void SetVSync(bool enabled) override;
        bool IsVSync() const override;
        
        [[nodiscard]] void* GetNativeWindow() const override { return m_Window; }
    private:
        virtual void Init(const WindowProps& props);
        virtual void Shutdown();
    private:
        GLFWwindow* m_Window;
        struct WindowData
        {
            std::string title;
            unsigned int width, height;
            bool vSync;

            EventCallbackFn eventCallback;
        } m_Data;
        
    
    };
    
}

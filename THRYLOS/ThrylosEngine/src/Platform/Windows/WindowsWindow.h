#pragma once
#include "Window.h"
#include "GLFW/glfw3.h"
#include "Renderer/GraphicsContext.h"

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
        [[nodiscard]] unsigned int GetWidth() const override {return m_Data.width;}
        /**
         * @brief Get the height of the window
         * @return The height of the window
         */
        [[nodiscard]] unsigned int GetHeight() const override {return m_Data.height;}

        /**
         * @brief Set the callback function to handle window events.
         *
         * This method sets the callback function that will be called whenever a window event occurs.
         * The provided callback function should have the following signature:
         *
         * @code{.cpp}
         * void CallbackFunction(Event& event);
         * @endcode
         *
         * The `Event` object passed to the callback function contains information about the event.
         *
         * @param callback The callback function to handle window events.
         *                   The function should have the following signature: void CallbackFunction(Event& event).
         */
        void SetEventCallback(const EventCallbackFn& callback) override {m_Data.eventCallback = callback;}

        /**
         * @brief Set the vertical synchronization (VSync) for the window.
         *
         * This method enables or disables VSync for the window. When VSync is enabled,
         * the window's buffer swap will be synchronized to the refresh rate of the monitor,
         * which helps to eliminate tearing artifacts. When VSync is disabled, the buffer swap
         * will happen as soon as possible, allowing for potentially higher frame rates, but
         * with the risk of tearing.
         *
         * @param enabled Whether VSync should be enabled or disabled.
         *                Set to true to enable VSync, false to disable.
         */
        void SetVSync(bool enabled) override;

        /**
         * @brief Check whether vertical synchronization (VSync) is enabled or disabled.
         *
         * This method returns a boolean indicating whether VSync is currently enabled or disabled for the window.
         * When VSync is enabled, the window's buffer swap will be synchronized to the refresh rate of the monitor,
         * which helps to eliminate tearing artifacts. When VSync is disabled, the buffer swap will happen as soon
         * as possible, allowing for potentially higher frame rates, but with the risk of tearing.
         *
         * @return True if VSync is enabled, false if VSync is disabled.
         */
        [[nodiscard]] bool IsVSync() const override;

        /**
         * @brief Get the native window pointer.
         *
         * This method returns a pointer to the native window object that is used by the WindowsWindow instance.
         * The returned pointer can be used to perform platform-specific operations on the window.
         *
         * @return A void pointer to the native window.
         *
         * @note The returned pointer should not be de-referenced unless the caller knows the specific type of the window object.
         *       This method is mainly intended for interoperability with external libraries or for performing platform-specific operations.
         */
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
        GraphicsContext *m_Context;
        
    
    };
    
}

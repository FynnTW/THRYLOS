#pragma once

#include "tpch.h"

#include "Events/Event.h"
#include "GLFW/glfw3.h"

namespace Thrylos
{
    /**
     * @brief Window properties
     */
    struct WindowProps
    {
        std::string title;
        unsigned int width;
        unsigned int height;

        /**
         * @brief Constructor
         * @param title Window title
         * @param width Window width
         * @param height Window height
         */
        explicit WindowProps(std::string title = "Thrylos Engine",
                             const unsigned int width = 1280,
                             const unsigned int height = 720)
            : title(std::move(title)), width(width), height(height)
        {
        }
    };

    /**
     * @brief Desktop Window Interface
     */
    class THRYLOS_API Window
    {
    public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() = default;

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;
        virtual void* GetNativeWindow() const = 0;
        
        static Window* Create(const WindowProps& props = WindowProps());
    };
}
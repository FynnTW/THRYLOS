#pragma once

namespace Thrylos
{
    class THRYLOS_API Input
    {
    public:
        /**
         * @brief Check if a specific key is currently pressed.
         *
         * @param keycode The key code of the key to check.
         *
         * @return true if the key is currently pressed, false otherwise.
         */
        static bool IsKeyPressed(const int keycode) { return m_SInstance->IsKeyPressedImpl(keycode); }
        /**
         * @brief Check if a specific mouse button is currently pressed.
         *
         * @param button The button ID of the mouse button to check.
         *
         * @return true if the mouse button is currently pressed, false otherwise.
         */
        static bool IsMouseButtonPressed(const int button) { return m_SInstance->IsMouseButtonPressedImpl(button); }
        /**
         * @brief Get the x-coordinate of the mouse position.
         *
         * @return The x-coordinate of the mouse position.
         */
        static float GetMouseX() { return m_SInstance->GetMouseXImpl(); }
        /**
         * @brief Get the y-coordinate of the mouse position.
         *
         * This method retrieves the y-coordinate of the current mouse position.
         *
         * @return The y-coordinate of the mouse position.
         */
        static float GetMouseY() { return m_SInstance->GetMouseYImpl(); }
        /**
         * @brief Get the x-coordinate of the mouse position relative to the window.
         *
         * This method retrieves the x-coordinate of the current mouse position relative to the window.
         *
         * @return The x-coordinate of the mouse position relative to the window.
         */
        static float GetWindowMouseX() { return m_SInstance->GetWindowMouseXImpl(); }
        /**
         * @brief Get the y-coordinate of the mouse position relative to the window.
         *
         * This method retrieves the y-coordinate of the current mouse position relative to the window.
         *
         * @return The y-coordinate of the mouse position relative to the window.
         */
        static float GetWindowMouseY() { return m_SInstance->GetWindowMouseYImpl(); }
        /**
         * @brief Get the current x and y coordinates of the mouse position.
         *
         * This method retrieves the current x and y coordinates of the mouse position.
         *
         * @return A std::pair object containing the x and y coordinates of the mouse position.
         */
        static std::pair<float, float> GetMousePosition() { return m_SInstance->GetMousePositionImpl(); }
        /**
         * @brief Get the current x and y coordinates of the mouse position relative to the window.
         *
         * This method retrieves the current x and y coordinates of the mouse position relative to the window.
         *
         * @return A std::pair object containing the x and y coordinates of the mouse position relative to the window.
         */
        static std::pair<float, float> GetWindowMousePosition() { return m_SInstance->GetWindowMousePositionImpl(); }
    protected:
        virtual bool IsKeyPressedImpl(int keycode) = 0;
        virtual bool IsMouseButtonPressedImpl(int button) = 0;
        virtual float GetMouseXImpl() = 0;
        virtual float GetMouseYImpl() = 0;
        virtual float GetWindowMouseXImpl() = 0;
        virtual float GetWindowMouseYImpl() = 0;
        virtual std::pair<float, float> GetMousePositionImpl() = 0;
        virtual std::pair<float, float> GetWindowMousePositionImpl() = 0;
    private:
        static Input* m_SInstance;
    };
}

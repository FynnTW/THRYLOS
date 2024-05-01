#include "tpch.h"
#include "WindowsInput.h"

#include "Application.h"

namespace Thrylos
{
    Input* Input::m_SInstance = new WindowsInput();

    /**
     * @brief Check if a key is currently pressed.
     *
     * @param keycode the key code to check
     * @return true if the key is currently pressed, false otherwise
     */
    bool WindowsInput::IsKeyPressedImpl(const int keycode)
    {
        const auto state = GetAsyncKeyState(keycode);
        return state & 0x8000;
    }

    /**
     * @brief Check if a mouse button is currently pressed.
     *
     * @param button the button code to check
     * @return true if the button is currently pressed, false otherwise
     */
    bool WindowsInput::IsMouseButtonPressedImpl(const int button)
    {
        const auto state = GetAsyncKeyState(button);
        return state & 0x8000;
    }

    /**
     * @brief Get the x-coordinate of the mouse cursor on the screen.
     *
     * @return The x-coordinate of the mouse cursor on the screen.
     */
    float WindowsInput::GetMouseXImpl()
    {
        POINT point;
        GetCursorPos(&point);
        return point.x;
    }

    /**
     * @brief Get the y-coordinate of the mouse cursor.
     *
     * This method retrieves the current y-coordinate of the mouse cursor.
     *
     * @return The y-coordinate of the mouse cursor
     */
    float WindowsInput::GetMouseYImpl()
    {
        POINT point;
        GetCursorPos(&point);
        return point.y;
    }

    /**
     * @brief Get the x-coordinate of the mouse cursor relative to the application window.
     *
     * @return the x-coordinate of the mouse cursor
     */
    float WindowsInput::GetWindowMouseXImpl()
    {
        const auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double x, y;
        glfwGetCursorPos(window, &x, &y);
        return x;  // NOLINT(clang-diagnostic-implicit-float-conversion)
    }

    /**
     * @brief Get the Y coordinate of the mouse cursor relative to the application window.
     *
     * @return the Y coordinate of the mouse cursor
     */
    float WindowsInput::GetWindowMouseYImpl()
    {
        const auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double x, y;
        glfwGetCursorPos(window, &x, &y);
        return y;  // NOLINT(clang-diagnostic-implicit-float-conversion)
    }

    /**
     * @brief Get the current position of the mouse cursor on the screen.
     *
     * This method retrieves the current position of the mouse cursor on the screen
     * using the Windows API function GetCursorPos.
     *
     * @return A pair of floats representing the x and y coordinates of the mouse cursor.
     */
    std::pair<float, float> WindowsInput::GetMousePositionImpl()
    {
        POINT point;
        GetCursorPos(&point);
        return {point.x, point.y};
    }

    /**
     * @brief Get the current mouse position in window coordinates.
     *
     * This method retrieves the current position of the mouse cursor relative to the top-left corner of the window. The coordinates are returned as a pair of floats representing the x and
     * y positions.
     *
     * @return a pair of floats representing the x and y coordinates of the mouse position in window coordinates
     */
    std::pair<float, float> WindowsInput::GetWindowMousePositionImpl()
    {
        const auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double x, y;
        glfwGetCursorPos(window, &x, &y);
        return {x, y};
    }
}

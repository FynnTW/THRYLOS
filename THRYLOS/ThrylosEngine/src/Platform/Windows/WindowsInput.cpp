#include "tpch.h"
#include "WindowsInput.h"

#include "Application.h"

namespace Thrylos
{
    Input* Input::m_SInstance = new WindowsInput();
    
    bool WindowsInput::IsKeyPressedImpl(const int keycode)
    {
        const auto state = GetAsyncKeyState(keycode);
        return state & 0x8000;
    }

    bool WindowsInput::IsMouseButtonPressedImpl(const int button)
    {
        const auto state = GetAsyncKeyState(button);
        return state & 0x8000;
    }

    float WindowsInput::GetMouseXImpl()
    {
        POINT point;
        GetCursorPos(&point);
        return point.x;
    }

    float WindowsInput::GetMouseYImpl()
    {
        POINT point;
        GetCursorPos(&point);
        return point.y;
    }

    float WindowsInput::GetWindowMouseXImpl()
    {
        const auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double x, y;
        glfwGetCursorPos(window, &x, &y);
        return x;  // NOLINT(clang-diagnostic-implicit-float-conversion)
    }

    float WindowsInput::GetWindowMouseYImpl()
    {
        const auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double x, y;
        glfwGetCursorPos(window, &x, &y);
        return y;  // NOLINT(clang-diagnostic-implicit-float-conversion)
    }

    std::pair<float, float> WindowsInput::GetMousePositionImpl()
    {
        POINT point;
        GetCursorPos(&point);
        return {point.x, point.y};
    }

    std::pair<float, float> WindowsInput::GetWindowMousePositionImpl()
    {
        const auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double x, y;
        glfwGetCursorPos(window, &x, &y);
        return {x, y};
    }
}

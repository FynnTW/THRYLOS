#pragma once

namespace Thrylos
{
    class THRYLOS_API Input
    {
    public:
        static bool IsKeyPressed(const int keycode) { return m_SInstance->IsKeyPressedImpl(keycode); }
        static bool IsMouseButtonPressed(const int button) { return m_SInstance->IsMouseButtonPressedImpl(button); }
        static float GetMouseX() { return m_SInstance->GetMouseXImpl(); }
        static float GetMouseY() { return m_SInstance->GetMouseYImpl(); }
        static float GetWindowMouseX() { return m_SInstance->GetWindowMouseXImpl(); }
        static float GetWindowMouseY() { return m_SInstance->GetWindowMouseYImpl(); }
        static std::pair<float, float> GetMousePosition() { return m_SInstance->GetMousePositionImpl(); }
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

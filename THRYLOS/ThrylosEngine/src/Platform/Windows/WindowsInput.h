#pragma once
#include "Input.h"

namespace Thrylos
{
    class WindowsInput : public Input
    {
    protected:
        bool IsKeyPressedImpl(int keycode) override;
        bool IsMouseButtonPressedImpl(int button) override;
        float GetMouseXImpl() override;
        float GetMouseYImpl() override;
        float GetWindowMouseXImpl() override;
        float GetWindowMouseYImpl() override;
        std::pair<float, float> GetMousePositionImpl() override;
        std::pair<float, float>  GetWindowMousePositionImpl() override;
    };
}


#pragma once

#include "Core.h"

namespace Thrylos
{
    class THRYLOS_API Application
    {
    public:
        void Run();
    };

    Application* CreateApplication();
}


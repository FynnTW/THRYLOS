#pragma once

#include "Core.h"

namespace Thrylos
{
    /**
     * @brief The main application class
     */
    class THRYLOS_API Application
    {
    public:
        /**
         * @brief Run the application
         */
        static void Run();
    };

    /**
     * @brief Create an application
     * @return The application
     */
    Application* CreateApplication();
}


#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Thrylos
{
    /**
     * @brief Logging class
     */
    class THRYLOS_API Log
    {
    public:
        /**
         * @brief Initialize the logging system
         */
        static void Init();
        /**
         * @brief Get the core logger
         * @return The core logger
         */
        static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return m_CoreLogger; }
        /**
         * @brief Get the client logger
         * @return The client logger
         */
        static std::shared_ptr<spdlog::logger>& GetClientLogger() { return m_ClientLogger; }

        /**
         * @brief Set the core logging level
         * @param level The level from spdlog level enum
         */
        static void SetCoreLogLevel(spdlog::level::level_enum level);

        /**
         * @brief Set the client logging level
         * @param level The level from spdlog level enum
         */
        static void SetClientLogLevel(spdlog::level::level_enum level);

    private:
        static std::shared_ptr<spdlog::logger> m_CoreLogger;
        static std::shared_ptr<spdlog::logger> m_ClientLogger;
    
    };
}

//------------------Logging macros---------------------
//-------Engine Logging----------
#define LOG_CORE_ERROR(...) ::Thrylos::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LOG_CORE_WARN(...)  ::Thrylos::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_CORE_INFO(...)  ::Thrylos::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_CORE_TRACE(...) ::Thrylos::Log::GetCoreLogger()->trace(__VA_ARGS__)
//------Client Logging-----------
#define LOG_CLIENT_ERROR(...) ::Thrylos::Log::GetClientLogger()->error(__VA_ARGS__)
#define LOG_CLIENT_WARN(...)  ::Thrylos::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LOG_CLIENT_INFO(...)  ::Thrylos::Log::GetClientLogger()->info(__VA_ARGS__)
#define LOG_CLIENT_TRACE(...) ::Thrylos::Log::GetClientLogger()->trace(__VA_ARGS__)

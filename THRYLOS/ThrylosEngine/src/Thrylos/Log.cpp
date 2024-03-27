#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Thrylos
{
    std::shared_ptr<spdlog::logger> Log::m_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::m_ClientLogger;
    
    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        m_CoreLogger = spdlog::stdout_color_mt("THRYLOS");
        m_CoreLogger->set_level(spdlog::level::trace);
        m_ClientLogger = spdlog::stdout_color_mt("APP");
        m_ClientLogger->set_level(spdlog::level::trace);
    }
    
    void Log::SetClientLogLevel(const spdlog::level::level_enum level){ m_ClientLogger->set_level(level); }

    void Log::SetCoreLogLevel(const spdlog::level::level_enum level) { m_CoreLogger->set_level(level); }
}

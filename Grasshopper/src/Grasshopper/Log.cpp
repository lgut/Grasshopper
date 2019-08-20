#include "Grasshopper/Log.hpp"

namespace gh
{
    std::shared_ptr<spdlog::logger> Log::s_client_logger;
    std::shared_ptr<spdlog::logger> Log::s_core_logger;

    void Log::init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        s_core_logger   = spdlog::stdout_logger_mt("GRASSHOPPER");
        s_client_logger = spdlog::stdout_logger_mt("APP");

        //TODO: expose these
        s_core_logger->set_level(spdlog::level::trace);
        s_client_logger->set_level(spdlog::level::trace);
    }

}  // namespace gh
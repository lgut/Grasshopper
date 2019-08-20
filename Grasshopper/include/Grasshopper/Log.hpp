#pragma once

#include <memory>
#include "Core.hpp"
#include "spdlog/spdlog.h"  //FIXME: fixed cmake issue with c_cpp_properties
#include "spdlog/sinks/stdout_sinks.h"

namespace gh
{
    class GRASSHOPPER_API Log
    {
      public:
        static void init();
        inline static std::shared_ptr<spdlog::logger> &get_core_logger() { return s_core_logger; }
        inline static std::shared_ptr<spdlog::logger> &get_client_logger() { return s_client_logger; }

      private:
        static std::shared_ptr<spdlog::logger> s_core_logger;
        static std::shared_ptr<spdlog::logger> s_client_logger;
    };
}  // namespace gh
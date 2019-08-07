#pragma once
#include "Core.hpp"

namespace gh
{
    class GRASSHOPPER_API Application
    {
      public:
        Application();
        virtual ~Application();

        void run();
    };

    // Defined in client applications
    Application *create_application();

}  // namespace gh

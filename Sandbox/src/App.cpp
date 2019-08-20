#include <iostream>
#include "Grasshopper/Grasshopper.hpp"

class Sandbox : public gh::Application
{
  public:
    Sandbox(){};
    ~Sandbox(){};
};

gh::Application *gh::create_application()
{
    gh::Log::get_client_logger()->info("Hello from client!");
    return new Sandbox();
};
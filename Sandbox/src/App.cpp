#include <iostream>
#include <Grasshopper.hpp>

class Sandbox : public gh::Application
{
  public:
    Sandbox(){};
    ~Sandbox(){};
};

gh::Application *gh::create_application()
{
    return new Sandbox();
};
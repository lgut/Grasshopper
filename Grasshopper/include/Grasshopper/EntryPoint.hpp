#pragma once
#include "Application.hpp"
#include <iostream>

extern gh::Application *gh::create_application();

int main(int argc, char const *argv[])
{
    gh::Log::init();
    gh::Log::get_core_logger()->info("Application Started");

    gh::Application *app = gh::create_application();
    app->run();
    delete app;
}

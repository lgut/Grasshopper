#pragma once
#include "Application.hpp"

extern gh::Application *gh::create_application();

int main(int argc, char const *argv[])
{
    gh::Application *app = gh::create_application();
    app->run();
    delete app;
}

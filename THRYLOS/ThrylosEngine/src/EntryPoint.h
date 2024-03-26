#pragma once

#include "Thrylos/Application.h"

#ifdef THRYLOS_PLATFORM_WINDOWS

extern Thrylos::Application* Thrylos::CreateApplication();

int main(int argc, int argv[])
{
    auto const app = Thrylos::CreateApplication();
    app->Run();
    delete app;
}

#endif


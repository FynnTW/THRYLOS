﻿#pragma once

#include "Thrylos/Application.h"
#include "Thrylos/Log.h"

#ifdef THRYLOS_PLATFORM_WINDOWS

extern Thrylos::Application* Thrylos::CreateApplication();  // NOLINT(readability-redundant-declaration)

// ReSharper disable once CppNonInlineFunctionDefinitionInHeaderFile
int main(int argc, int argv[])
{
    Thrylos::Log::Init();
    LOG_CORE_INFO("Initialized log");
    LOG_CLIENT_INFO("Initialized Log!");
    auto const app = Thrylos::CreateApplication();
    app->Run();
    delete app;
}

#endif


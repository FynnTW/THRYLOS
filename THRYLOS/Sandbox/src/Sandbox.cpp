#include "imgui.h"
#include "Thrylos.h"

class ExampleLayer : public Thrylos::Layer
{
public:
    ExampleLayer()
    {
    }
    
    void OnImGuiRender() override
    {
        static bool show = true;
        ImGui::Begin("Window", &show);
        ImGui::Text("Hello World");
        ImGui::End();
    }
};

class Sandbox : public Thrylos::Application
{
public:
    ExampleLayer* layer = nullptr;
    Sandbox()
    {
        Thrylos::Log::SetCoreLogLevel(spdlog::level::level_enum::info);
        Thrylos::Log::SetClientLogLevel(spdlog::level::level_enum::trace);
        layer = new ExampleLayer();
        PushLayer(layer);
    }
    ~Sandbox()
    {
    }
};

Thrylos::Application* Thrylos::CreateApplication()
{
    return new Sandbox();
}

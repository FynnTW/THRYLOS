#include "imgui.h"
#include "Thrylos.h"

class ExampleLayer : public Thrylos::ImGuiLayer
{
public:
    ExampleLayer()
    {
    }
    
    void OnEvent(Thrylos::Event& event) override
    {
        ImGuiLayer::OnEvent(event);
        LOG_CLIENT_TRACE("{0}", event);
    }

    void OnContextCreated(ImGuiContext* context) override
    {
        ImGui::SetCurrentContext(context);
    }
    
    void OnDrawFrame() override
    {
        static bool show = true;
        ImGui::ShowDemoWindow(&show);
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

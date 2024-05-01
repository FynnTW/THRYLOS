#include "Thrylos.h"

class ExampleLayer : public Thrylos::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    {
    }
    void OnUpdate() override
    {
        //LOG_CLIENT_INFO("ExampleLayer::Update");
    }
    void OnEvent(Thrylos::Event& event) override
    {
        LOG_CLIENT_TRACE("{0}", event);
    }
};

class Sandbox : public Thrylos::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }
    ~Sandbox()
    = default;
};

Thrylos::Application* Thrylos::CreateApplication()
{
    return new Sandbox();
}

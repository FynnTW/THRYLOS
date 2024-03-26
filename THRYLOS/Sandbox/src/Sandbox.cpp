#include "Thrylos.h"

class Sandbox : public Thrylos::Application
{
public:
    Sandbox()
    = default;

    ~Sandbox()
    = default;
};

Thrylos::Application* Thrylos::CreateApplication()
{
    return new Sandbox();
}

#include "imgui.h"
#include "Thrylos.h"
#include "Thrylos/Events/KeyEvent.h"

using namespace Thrylos;

class ExampleLayer : public Layer
{
public:
    ExampleLayer()
        : m_Camera(-1.6f, 1.6f, -0.9f, 0.9f)
    {
        
        constexpr float vertices[3 * 3] = {
            -0.5f, -0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.0f,  0.5f, 0.0f
        };
        constexpr uint32_t indices[3] = { 0, 1, 2 };

        std::shared_ptr<VertexBuffer> vertexBuffer;
        m_VertexArray.reset(VertexArray::Create());
        vertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));
        vertexBuffer->SetLayout({
            {
                ShaderDataType::Float3, "a_Position"
            }});
        m_VertexArray->AddVertexBuffer(vertexBuffer);
        std::shared_ptr<IndexBuffer> indexBuffer; 
        indexBuffer.reset(IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
        m_VertexArray->SetIndexBuffer(indexBuffer);

        const std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
            
            uniform mat4 u_ViewProjection;

			out vec3 v_Position;
			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);	
			}
		)";
        const std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			in vec3 v_Position;
			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
			}
		)";

        m_Shader.reset(new Shader(vertexSrc, fragmentSrc));
    }

    void OnUpdate() override
    {
        RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
        RenderCommand::Clear();

        Renderer::BeginScene(m_Camera);
            
        Renderer::Submit(m_VertexArray, m_Shader);

        Renderer::EndScene();
    }
    
    void OnImGuiRender() override
    {
        static bool show = true;
        ImGui::Begin("Window", &show);
        ImGui::Text("Hello World");
        ImGui::End();
    }

    bool OnKeyPressed(const KeyPressedEvent& e)
    {
        switch (auto keyCode = static_cast<Th_Key>(e.GetKeyCode()))
        {
            case Th_Key::Left:
                LOG_CLIENT_INFO("Left arrow key pressed");
                m_Camera.SetPosition(m_Camera.GetPosition() + glm::vec3(-0.1f, 0.0f, 0.0f));
                break;
            case Th_Key::Right:
                LOG_CLIENT_INFO("Right arrow key pressed");
                m_Camera.SetPosition(m_Camera.GetPosition() + glm::vec3(0.1f, 0.0f, 0.0f));
                break;
            case Th_Key::Up:
                LOG_CLIENT_INFO("Up arrow key pressed");
                m_Camera.SetPosition(m_Camera.GetPosition() + glm::vec3(0.0f, 0.1f, 0.0f));
                break;
            case Th_Key::Down:
                LOG_CLIENT_INFO("Down arrow key pressed");
                m_Camera.SetPosition(m_Camera.GetPosition() + glm::vec3(0.0f, -0.1f, 0.0f));
                break;
            case Th_Key::E:
                m_Camera.SetRotation(m_Camera.GetRotation() + 10.0f);
                break;
            case Th_Key::Q:
                m_Camera.SetRotation(m_Camera.GetRotation() - 10.0f);
                break;
            default:
                break;
        }
        return false;
    }

    void OnEvent(Event& event) override
    {
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(ExampleLayer::OnKeyPressed));
    }
private:
    OrtographicCamera m_Camera;
    std::shared_ptr<Shader> m_Shader;
    std::shared_ptr<VertexArray> m_VertexArray;
};

class Sandbox : public Application
{
public:
    ExampleLayer* layer = nullptr;
    Sandbox()
    {
        Log::SetCoreLogLevel(spdlog::level::level_enum::info);
        Log::SetClientLogLevel(spdlog::level::level_enum::trace);
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

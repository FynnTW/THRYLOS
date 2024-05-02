#include <glm/ext/matrix_transform.hpp>

#include "imgui.h"
#include "Thrylos.h"
#include "Platform/opengl/OpenGLShader.h"
#include "Thrylos/Events/KeyEvent.h"

using namespace Thrylos;

class ExampleLayer : public Layer
{
public:
    ExampleLayer()
        : m_Camera(-1.6f, 1.6f, -0.9f, 0.9f)
    {
        
        constexpr float vertices[5 * 4] = {
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
             0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
             0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
            -0.5f,  0.5f, 0.0f, 0.0f, 1.0f
        };
        VertexBufferRef vertexBuffer;
        m_VertexArray.reset(VertexArray::Create());
        vertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));
        vertexBuffer->SetLayout({
            {ShaderDataType::Float3, "a_Position"},
            {ShaderDataType::Float2, "a_TexCoord"}
        });
        m_VertexArray->AddVertexBuffer(vertexBuffer);
        
        constexpr uint32_t indices[6] = { 0, 1, 2, 2, 3, 0};
        IndexBufferRef indexBuffer; 
        indexBuffer.reset(IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
        m_VertexArray->SetIndexBuffer(indexBuffer);

        const std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
            
            uniform mat4 u_ViewProjection;
            uniform mat4 u_Transform;

			out vec3 v_Position;
			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
			}
		)";
        const std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			in vec3 v_Position;
            uniform vec3 u_Color;
			void main()
			{
				color = vec4(u_Color, 1.0);
			}
		)";

        m_Shader.reset(Shader::Create(vertexSrc, fragmentSrc));

        const std::string vertexSrcTex = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
            layout(location = 1) in vec2 a_TexCoord;
            
            uniform mat4 u_ViewProjection;
            uniform mat4 u_Transform;

            out vec2 v_TexCoord;

			void main()
			{
                v_TexCoord = a_TexCoord;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
			}
		)";
        const std::string fragmentSrcTex = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
            in vec2 v_TexCoord;
            
            uniform vec3 u_Color;
			void main()
			{
				color = vec4(v_TexCoord, 0.0, 1.0);
			}
		)";

        m_TextureShader.reset(Shader::Create(vertexSrcTex, fragmentSrcTex));
    }

    void OnUpdate(TimeStep ts) override
    {
        //LOG_CLIENT_INFO("Delta time: {0}s ({1}ms)", ts.GetSeconds(), ts.GetMilliseconds());
        RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
        RenderCommand::Clear();

        Renderer::BeginScene(m_Camera);

        const glm::mat4 transform = translate(glm::mat4(1.0f), m_SquarePosition);

        std::dynamic_pointer_cast<OpenGLShader>(m_TextureShader)->Bind(transform);
        Renderer::Submit(m_VertexArray);

        Renderer::EndScene();
    }
    
    void OnImGuiRender() override
    {
        static bool show = true;
        if (show)
        {
            ImGui::Begin("Window", &show);
            ImGui::Text("Hello World");
            ImGui::End();
        }
    }

    bool OnKeyPressed(const KeyPressedEvent& e)
    {
        switch (static_cast<Th_Key>(e.GetKeyCode()))
        {
            case Th_Key::Left:
                m_Camera.SetPosition(m_Camera.GetPosition() + glm::vec3(-0.1f, 0.0f, 0.0f));
                break;
            case Th_Key::Right:
                m_Camera.SetPosition(m_Camera.GetPosition() + glm::vec3(0.1f, 0.0f, 0.0f));
                break;
            case Th_Key::Up:
                m_Camera.SetPosition(m_Camera.GetPosition() + glm::vec3(0.0f, 0.1f, 0.0f));
                break;
            case Th_Key::Down:
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
    Ref<Shader> m_Shader, m_TextureShader;
    VertexArrayRef m_VertexArray;
    glm::vec3 m_SquarePosition = { 0.0f, 0.0f, 0.0f };
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

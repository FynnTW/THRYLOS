#include "tpch.h"
#include "ImGuiLayer.h"

#include "Application.h"
#include "imgui.h"
#include "glad/glad.h"
#include "Platform/opengl/imgui_impl_glfw.h"
#include "Platform/opengl/imgui_impl_opengl3.h"

namespace Thrylos
{
    ImGuiLayer::ImGuiLayer()
    {
    }

    ImGuiLayer::~ImGuiLayer()
    {
    }

    void ImGuiLayer::OnAttach()
    {
        m_Context = ImGui::CreateContext();
        LOG_CORE_TRACE("ImGui Context Created");

        ImGui::StyleColorsDark();

        ImGuiIO& io = ImGui::GetIO();
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;

        const Application& app = Application::Get();

        int success = ImGui_ImplOpenGL3_Init("#version 410");
        THRYLOS_CORE_ASSERT(success, "Failed to initialize ImGui OpenGL3")
        LOG_CORE_TRACE("ImGui_ImplOpenGL3 initialized");
        
        success = ImGui_ImplGlfw_InitForOpenGL(static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow()), true);
        THRYLOS_CORE_ASSERT(success, "Failed to initialize ImGui GLFW")
        LOG_CORE_TRACE("ImGui_ImplGlfw initialized");
        
        OnContextCreated(m_Context);
    }

    void ImGuiLayer::OnDetach()
    {
        Layer::OnDetach();
    }

    void ImGuiLayer::OnUpdate()
    {
		glClear(GL_COLOR_BUFFER_BIT);
        
        OnBeforeDrawFrame();
        
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        
        OnDrawFrame();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        
        OnAfterDrawFrame();
    }

    void ImGuiLayer::OnEvent(Event& event)
    {
        Layer::OnEvent(event);
    }
}

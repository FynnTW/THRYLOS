#include "tpch.h"
#include "ImGuiLayer.h"

#include "Application.h"
#include "imgui.h"
#include "Platform/opengl/imgui_impl_glfw.h"
#include "Platform/opengl/imgui_impl_opengl3.h"

namespace Thrylos
{
    ImGuiLayer::ImGuiLayer()
    = default;

    ImGuiLayer::~ImGuiLayer()
    = default;

    void ImGuiLayer::OnAttach()
    {
        const Application& app = Application::Get();
        ImGui::CreateContext();
        LOG_CORE_TRACE("ImGui Context Created");

        ImGui::StyleColorsDark();

        ImGuiIO& io = ImGui::GetIO();
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
        io.BackendFlags |= ImGuiBackendFlags_PlatformHasViewports;
        io.BackendFlags |= ImGuiBackendFlags_RendererHasViewports;
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;


        int success = ImGui_ImplOpenGL3_Init("#version 410");
        THRYLOS_CORE_ASSERT(success, "Failed to initialize ImGui OpenGL3")
        LOG_CORE_TRACE("ImGui_ImplOpenGL3 initialized");
        
        success = ImGui_ImplGlfw_InitForOpenGL(static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow()), true);
        THRYLOS_CORE_ASSERT(success, "Failed to initialize ImGui GLFW")
        LOG_CORE_TRACE("ImGui_ImplGlfw initialized");
    }

    void ImGuiLayer::OnDetach()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    void ImGuiLayer::Begin()
    {
        OnBeforeDrawFrame();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void ImGuiLayer::End()
    {
        ImGuiIO& io = ImGui::GetIO();
        const Application& app = Application::Get();
        io.DisplaySize = ImVec2(static_cast<float>(app.GetWindow().GetWidth()), static_cast<float>(app.GetWindow().GetHeight()));
        
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* backupCurrentContext = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backupCurrentContext);
        }
        OnAfterDrawFrame();
    }
}

#pragma once
#include "imgui_internal.h"
#include "Thrylos/Layer.h"

namespace Thrylos
{
    class THRYLOS_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate() override;
        void OnEvent(Event& event) override;

        /**
         * @brief This method returns the ImGuiContext associated with the current instance of the ImGuiLayer.
         *
         * @return A pointer to the ImGuiContext object.
         */
        ImGuiContext *GetContext() const { return m_Context; }

        /**
         * @brief This method is called before the main ImGui frame is drawn.
         *
         * This method is meant to be overridden by derived classes to perform any necessary setup or preprocessing before the ImGui frame is drawn.
         * The derived class should implement any logic or operations that need to be performed before the ImGui rendering takes place, such as setting up rendering state or updating internal
         * data.
         *
         * @note The base implementation of this method does nothing.
         */
        virtual void OnBeforeDrawFrame() {}

        /**
         * @brief This method is called during the rendering loop to handle the drawing of the ImGui frame.
         *
         * This method is meant to be overridden by derived classes to perform any custom ImGui rendering operations.
         * The derived class should implement the necessary ImGui drawing code within this method.
         *
         * @note The base implementation of this method does nothing.
         */
        virtual void OnDrawFrame() {}

        /**
         * @brief This method is called after the main ImGui frame is drawn.
         *
         * This method is meant to be overridden by derived classes to perform any necessary cleanup or post-processing after the ImGui frame is drawn.
         * The derived class should implement any logic or operations that need to be performed after the ImGui rendering is complete, such as restoring rendering state or updating any additional
         * data.
         *
         * @note The base implementation of this method does nothing.
         */
        virtual void OnAfterDrawFrame() {}

        /**
         * @brief This method is called when an ImGuiContext object is created.
         *
         * This method is meant to be overridden by derived classes to handle any custom behavior when an ImGuiContext object is created.
         * The derived class should implement any logic or operations that need to be performed when an ImGuiContext is created, such as setting up additional context-specific data or initializing
         * ImGui widgets or settings.
         *
         * @param context A pointer to the ImGuiContext object that was created.
         *
         * @note The base implementation of this method does nothing.
         */
        virtual void OnContextCreated(ImGuiContext *context) {}

    private:
        ImGuiContext *m_Context = nullptr;
        
    };
}

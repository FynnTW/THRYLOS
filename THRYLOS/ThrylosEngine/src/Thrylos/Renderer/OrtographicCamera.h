#pragma once
#include <glm/glm.hpp>

namespace Thrylos
{
    class OrtographicCamera
    {
    public:
        OrtographicCamera(float left, float right, float bottom, float top);
        ~OrtographicCamera() = default;

        void SetPosition(const glm::vec3& position) { m_Position = position; RecalculateViewMatrix(); }
        [[nodiscard]] const glm::vec3& GetPosition() const { return m_Position; }

        void SetRotation(const float rotation) { m_Rotation = rotation; RecalculateViewMatrix(); }
        [[nodiscard]] float GetRotation() const { return m_Rotation; }

        [[nodiscard]] const glm::mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
        [[nodiscard]] const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; }
        [[nodiscard]] const glm::mat4& GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }
    private:
        void RecalculateViewMatrix();

    private:
        glm::mat4 m_ProjectionMatrix{};
        glm::mat4 m_ViewMatrix{};
        glm::mat4 m_ViewProjectionMatrix{};

        glm::vec3 m_Position{0.0f, 0.0f, 0.0f};
        float m_Rotation = 0.0f;
    };
    
}

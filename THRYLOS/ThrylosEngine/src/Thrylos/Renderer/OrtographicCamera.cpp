﻿#include "tpch.h"
#include "OrtographicCamera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Thrylos
{
    OrtographicCamera::OrtographicCamera(float left, float right, float bottom, float top)
        : m_ProjectionMatrix(glm::ortho(left, right, bottom, top, -1.0f, 1.0f)),
          m_ViewMatrix(1.0f),
          m_ViewProjectionMatrix(m_ProjectionMatrix * m_ViewMatrix)
    {
            
    }

    void OrtographicCamera::RecalculateViewMatrix()
    {
        const glm::mat4 transform = translate(glm::mat4(1.0f), m_Position) *
                              rotate(glm::mat4(1.0f), glm::radians(m_Rotation), glm::vec3(0, 0, 1));

        m_ViewMatrix = inverse(transform);
        m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
    }
}

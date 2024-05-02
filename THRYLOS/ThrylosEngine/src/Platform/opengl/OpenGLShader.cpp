#include "tpch.h"
#include "OpenGLShader.h"

#include <glm/gtc/type_ptr.hpp>

#include "glad/glad.h"
#include "Renderer/Renderer.h"

namespace Thrylos
{
    OpenGLShader::OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc)
    {
        const GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        const GLchar* source = vertexSrc.c_str();
        glShaderSource(vertexShader, 1, &source, nullptr);

        glCompileShader(vertexShader);

        GLint isCompiled = 0;
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
        if (isCompiled == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

            std::vector<GLchar> infoLog(maxLength);
            glGetShaderInfoLog(vertexShader, maxLength, &maxLength, infoLog.data());

            glDeleteShader(vertexShader);

            LOG_CORE_ERROR("{0}", infoLog.data());
            THRYLOS_CORE_ASSERT(false, "Vertex shader compilation failure!")
            return;
        }

        const GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        source = fragmentSrc.c_str();
        glShaderSource(fragmentShader, 1, &source, nullptr);
        glCompileShader(fragmentShader);

        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
        if (isCompiled == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

            std::vector<GLchar> infoLog(maxLength);
            glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, infoLog.data());

            glDeleteShader(fragmentShader);
            glDeleteShader(vertexShader);

            LOG_CORE_ERROR("{0}", infoLog.data());
            THRYLOS_CORE_ASSERT(false, "Fragment shader compilation failure!")
            return;
        }

        m_RendererId = glCreateProgram();
        glAttachShader(m_RendererId, vertexShader);
        glAttachShader(m_RendererId, fragmentShader);
        glLinkProgram(m_RendererId);

        GLint isLinked = 0;
        glGetProgramiv(m_RendererId, GL_LINK_STATUS, &isLinked);
        if (isLinked == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetProgramiv(m_RendererId, GL_INFO_LOG_LENGTH, &maxLength);

            std::vector<GLchar> infoLog(maxLength);
            glGetProgramInfoLog(m_RendererId, maxLength, &maxLength, infoLog.data());

            glDeleteProgram(m_RendererId);
            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);

            LOG_CORE_ERROR("{0}", infoLog.data());
            THRYLOS_CORE_ASSERT(false, "Shader link failure!")
            return;
        }

        glDetachShader(m_RendererId, vertexShader);
        glDetachShader(m_RendererId, fragmentShader);
        
    }

    OpenGLShader::~OpenGLShader()
    {
        glDeleteProgram(m_RendererId);
    }

    void OpenGLShader::Bind() const
    {
        glUseProgram(m_RendererId);
    }

    void OpenGLShader::Bind(const glm::mat4& transform) const
    {
        glUseProgram(m_RendererId);
        UploadUniformMat4("u_ViewProjection", Renderer::GetViewProjectionMatrix());
        UploadUniformMat4("u_Transform", transform);
        UploadUniformFloat3("u_Color", { 0.2f, 0.3f, 0.8f });
    }

    void OpenGLShader::Unbind() const
    {
        glUseProgram(0);
    }

    void OpenGLShader::UploadUniformMat3(const std::string& name, const glm::mat3& matrix) const
    {
        const GLint location = glGetUniformLocation(m_RendererId, name.c_str());
        glUniformMatrix3fv(location, 1, GL_FALSE, value_ptr(matrix));
    }

    void OpenGLShader::UploadUniformMat4(const std::string& name, const glm::mat4& matrix) const
    {
        const GLint location = glGetUniformLocation(m_RendererId, name.c_str());
        glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(matrix));
    }

    void OpenGLShader::UploadUniformFloat(const std::string& name, const float value) const
    {
        const GLint location = glGetUniformLocation(m_RendererId, name.c_str());
        glUniform1f(location, value);
    }

    void OpenGLShader::UploadUniformFloat2(const std::string& name, const glm::vec2& values) const
    {
        const GLint location = glGetUniformLocation(m_RendererId, name.c_str());
        glUniform2f(location, values.x, values.y);
    }

    void OpenGLShader::UploadUniformFloat3(const std::string& name, const glm::vec3& values) const
    {
        const GLint location = glGetUniformLocation(m_RendererId, name.c_str());
        glUniform3f(location, values.x, values.y, values.z);
    }

    void OpenGLShader::UploadUniformFloat4(const std::string& name, const glm::vec4& values) const
    {
        const GLint location = glGetUniformLocation(m_RendererId, name.c_str());
        glUniform4f(location, values.x, values.y, values.z, values.w);
    }

    void OpenGLShader::UploadUniformInt(const std::string& name, const int value) const
    {
        const GLint location = glGetUniformLocation(m_RendererId, name.c_str());
        glUniform1i(location, value);
    }

    void OpenGLShader::UploadUniformInt2(const std::string& name, const glm::ivec2& values) const
    {
        const GLint location = glGetUniformLocation(m_RendererId, name.c_str());
        glUniform2i(location, values.x, values.y);
    }

    void OpenGLShader::UploadUniformInt3(const std::string& name, const glm::ivec3& values) const
    {
        const GLint location = glGetUniformLocation(m_RendererId, name.c_str());
        glUniform3i(location, values.x, values.y, values.z);
    }

    void OpenGLShader::UploadUniformInt4(const std::string& name, const glm::ivec4& values) const
    {
        const GLint location = glGetUniformLocation(m_RendererId, name.c_str());
        glUniform4i(location, values.x, values.y, values.z, values.w);
    }
}

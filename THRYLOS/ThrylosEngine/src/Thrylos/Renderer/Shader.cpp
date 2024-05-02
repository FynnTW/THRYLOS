#include "tpch.h"
#include "Shader.h"

#include "glad/glad.h"
#include <glm/gtc/type_ptr.hpp>


namespace Thrylos
{
    Shader::Shader(const std::string& vertexSrc, const std::string& fragmentSrc)
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

    Shader::~Shader()
    {
        glDeleteProgram(m_RendererId);
    }

    void Shader::Bind() const
    {
        glUseProgram(m_RendererId);
    }

    void Shader::Unbind() const
    {
        glUseProgram(0);
    }

    void Shader::UploadUniformMat4(const std::string& name, const glm::mat4& matrix)
    {
        const GLint location = glGetUniformLocation(m_RendererId, name.c_str());
        glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(matrix));
    }
}

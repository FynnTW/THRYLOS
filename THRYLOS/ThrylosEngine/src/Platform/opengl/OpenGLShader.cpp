#include "tpch.h"
#include "OpenGLShader.h"

#include <glm/gtc/type_ptr.hpp>

#include "glad/glad.h"
#include "Renderer/Renderer.h"

namespace Thrylos
{
    OpenGLShader::OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc)
    {
        std::unordered_map<GLenum, std::string> shaderSources =
        {
            { GL_VERTEX_SHADER,   vertexSrc },
            { GL_FRAGMENT_SHADER, fragmentSrc }
        };
        CompileShader(shaderSources);
    }

    OpenGLShader::OpenGLShader(const std::string& filePath)
    {
        auto shaderSources = PreProcess(ReadFile(filePath));
        CompileShader(shaderSources);
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

    std::string OpenGLShader::ReadFile(const std::string& filePath)
    {
        std::string result;
        if (std::ifstream file(filePath, std::ios::in, std::ios::binary); file)
        {
            file.seekg(0, std::ios::end);
            result.resize(file.tellg());
            file.seekg(0, std::ios::beg);
            file.read(result.data(), result.size());
            file.close();
        }
        else
        {
            LOG_CORE_ERROR("Failed to open file!");
        }
        return result;
    }

    GLenum shaderTypeFromString(const std::string& type)
    {
        if (type == "vertex")
            return GL_VERTEX_SHADER;
        if (type == "fragment" || type == "pixel")
            return GL_FRAGMENT_SHADER;

        THRYLOS_CORE_ASSERT(false, "Invalid shader type specified!")
        return 0;
    }

    std::unordered_map<GLenum, std::string> OpenGLShader::PreProcess(const std::string& source)
    {
        std::unordered_map<GLenum, std::string> shaderSources;

        const auto typeToken = "#type";
        const size_t typeTokenLength = strlen(typeToken);
        size_t pos = source.find(typeToken, 0);
        while (pos != std::string::npos)
        {
            const size_t eol = source.find_first_of("\r\n", pos);
            THRYLOS_CORE_ASSERT(eol != std::string::npos, "Syntax error!")
            const size_t begin = pos + typeTokenLength + 1;
            std::string type = source.substr(begin, eol - begin);
            THRYLOS_CORE_ASSERT(shaderTypeFromString(type), "Invalid shader type specified!")

            const size_t nextLinePos = source.find_first_not_of("\r\n", eol);
            pos = source.find(typeToken, nextLinePos);
            shaderSources[shaderTypeFromString(type)] =
                source.substr(nextLinePos, pos - (nextLinePos == std::string::npos ?
                    source.size() - 1 : nextLinePos));
        }
        return shaderSources;
    }

    void OpenGLShader::CompileShader(std::unordered_map<GLenum, std::string>& shaderSources)
    {
        const GLuint program = glCreateProgram();
        std::vector<GLenum> glShaderIDs(shaderSources.size());
        for (auto& [type, source] : shaderSources)
        {
            const GLuint shader = glCreateShader(type);
            const GLchar* sourceCStr = source.c_str();
            glShaderSource(shader, 1, &sourceCStr, nullptr);
            
            glCompileShader(shader);
            GLint isCompiled = 0;
            glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
            if (isCompiled == GL_FALSE)
            {
                GLint maxLength = 0;
                glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

                std::vector<GLchar> infoLog(maxLength);
                glGetShaderInfoLog(shader, maxLength, &maxLength, infoLog.data());

                glDeleteShader(shader);

                LOG_CORE_ERROR("{0}", infoLog.data());
                THRYLOS_CORE_ASSERT(false, "Shader compilation failure!")
                break;
            }
            glAttachShader(program, shader);
            glShaderIDs.push_back(shader);
        }
        glLinkProgram(program);

        GLint isLinked = 0;
        glGetProgramiv(program, GL_LINK_STATUS, &isLinked);
        if (isLinked == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

            std::vector<GLchar> infoLog(maxLength);
            glGetProgramInfoLog(program, maxLength, &maxLength, infoLog.data());

            glDeleteProgram(program);
            for (const auto id : glShaderIDs)
                glDeleteShader(id);

            LOG_CORE_ERROR("{0}", infoLog.data());
            THRYLOS_CORE_ASSERT(false, "Shader link failure!")
            return;
        }

        for (const auto id : glShaderIDs)
        {
            glDetachShader(program, id);
            glDeleteShader(id);
        }

        m_RendererId = program;
    }
}

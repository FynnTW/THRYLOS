#pragma once
#include <glm/fwd.hpp>
#include <unordered_map>

#include "Thrylos/Renderer/Shader.h"

namespace Thrylos
{
    class OpenGLShader : public Shader
    {
    public:
        /**
         * @brief Constructs a Shader object.
         *
         * This constructor creates a Shader object and compiles the vertex and fragment shaders.
         *
         * @param vertexSrc The source code of the vertex shader.
         * @param fragmentSrc The source code of the fragment shader.
         */
        OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
        OpenGLShader(const std::string&  filePath);
        virtual ~OpenGLShader();

        void Bind() const override;
        void Bind(const glm::mat4& transform) const;
        void Unbind() const override;
        
        void UploadUniformMat3(const std::string& name, const glm::mat3& matrix) const;
        void UploadUniformMat4(const std::string& name, const glm::mat4& matrix) const;
        void UploadUniformFloat(const std::string& name, const float value) const;
        void UploadUniformFloat2(const std::string& name, const glm::vec2& values) const;
        void UploadUniformFloat3(const std::string& name, const glm::vec3& values) const;
        void UploadUniformFloat4(const std::string& name, const glm::vec4& values) const;
        void UploadUniformInt(const std::string& name, const int value) const;
        void UploadUniformInt2(const std::string& name, const glm::ivec2& values) const;
        void UploadUniformInt3(const std::string& name, const glm::ivec3& values) const;
        void UploadUniformInt4(const std::string& name, const glm::ivec4& values) const;
    protected:
        static std::string ReadFile(const std::string& filePath);
        static std::unordered_map<uint32_t, std::string>  PreProcess(const std::string& source);
        void CompileShader(std::unordered_map<uint32_t, std::string>& shaderSources);
        uint32_t m_RendererId;
    };
}

#pragma once
#include <glm/fwd.hpp>

namespace Thrylos
{
    /**
     * @class Shader
     *
     * @brief Represents a shader program in OpenGL.
     *
     * A Shader object encapsulates the creation, compilation, and linking of vertex and fragment shaders.
     * It provides methods to bind and unbind the shader program for use in rendering.
     */
    class Shader
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
        Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
        ~Shader();

        /**
         * @brief Binds the shader program for use in rendering.
         *
         * This method sets the currently active shader program to the one represented by the Shader object.
         * It allows the shader program to be used in rendering operations.
         */
        void Bind() const;

        /**
         * @brief Unbinds the shader program.
         *
         * This method unbinds the currently active shader program, allowing other shader programs to be used in rendering operations.
         */
        void Unbind() const;


        void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);
        
    private:
        uint32_t m_RendererId;
    };
}

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
        ~Shader() = default;

        /**
         * @brief Binds the shader program for use in rendering.
         *
         * This method sets the currently active shader program to the one represented by the Shader object.
         * It allows the shader program to be used in rendering operations.
         */
        virtual void Bind() const = 0;

        /**
         * @brief Unbinds the shader program.
         *
         * This method unbinds the currently active shader program, allowing other shader programs to be used in rendering operations.
         */
        virtual void Unbind() const = 0;

        static Shader* Create(const std::string& vertexSrc, const std::string& fragmentSrc);

    };
}

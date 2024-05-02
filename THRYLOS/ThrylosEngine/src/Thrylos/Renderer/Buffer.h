#pragma once

namespace Thrylos
{
    /**
     * @enum ShaderDataType
     * @brief Enum class that represents the shader data types.
     * @details It defines the available shader data types, including None, Float, Float2, Float3, Float4, Mat3, Mat4, Int, Int2, Int3, Int4, and Bool.
     * @see Buffer.h
     */
    enum class ShaderDataType : uint8_t
    {
        None = 0,
        Float,
        Float2,
        Float3,
        Float4,
        Mat3,
        Mat4,
        Int,
        Int2,
        Int3,
        Int4,
        Bool
    };

    /**
     * @brief Calculates the size in bytes for a given shader data type.
     * @param type The shader data type.
     * @return The size in bytes for the given shader data type.
     */
    static uint32_t shaderDataTypeSize(const ShaderDataType type)
    {
        switch (type)
        {
            case ShaderDataType::None:     break;
            case ShaderDataType::Float:    return 4;
            case ShaderDataType::Float2:   return 4 * 2;
            case ShaderDataType::Float3:   return 4 * 3;
            case ShaderDataType::Float4:   return 4 * 4;
            case ShaderDataType::Mat3:     return 4 * 3 * 3;
            case ShaderDataType::Mat4:     return 4 * 4 * 4;
            case ShaderDataType::Int:      return 4;
            case ShaderDataType::Int2:     return 4 * 2;
            case ShaderDataType::Int3:     return 4 * 3;
            case ShaderDataType::Int4:     return 4 * 4;
            case ShaderDataType::Bool:     return 1;
        }

        THRYLOS_CORE_ASSERT(false, "Unknown ShaderDataType!")
        return 0;
    }

    /**
     * @struct BufferElement
     * @brief A struct representing a buffer element.
     * @details The BufferElement struct contains information about a buffer element, such as its name, type, size, offset, and whether it is a normalized value.
     * The BufferElement struct is used in the Buffer class to define the layout of the buffer.
     * This struct provides methods to convert the shader data type to OpenGL data type and to get the element count.
     * @see Buffer, ShaderDataType
     */
    struct BufferElement
    {
        /**
         * @brief The name of the buffer element.
         * @details The name is a string that represents the name of the buffer element.
         * @see BufferElement
         */
        std::string name;
        /**
         * @brief Declaration of the variable 'type'.
         * @details The variable 'type' is of type 'ShaderDataType' and is used to represent the shader data types.
         * It is defined in the file 'Buffer.h' and has the following possible values:
         * - None: Represents no shader data type.
         * - Float: Represents a single-precision floating-point value.
         * - Float2: Represents a 2-dimensional vector of single-precision floating-point values.
         * - Float3: Represents a 3-dimensional vector of single-precision floating-point values.
         * - Float4: Represents a 4-dimensional vector of single-precision floating-point values.
         * - Mat3: Represents a 3x3 matrix of single-precision floating-point values.
         * - Mat4: Represents a 4x4 matrix of single-precision floating-point values.
         * - Int: Represents a signed integer value.
         * - Int2: Represents a 2-dimensional vector of signed integer values.
         * - Int3: Represents a 3-dimensional vector of signed integer values.
         * - Int4: Represents a 4-dimensional vector of signed integer values.
         * - Bool: Represents a boolean value.
         * The 'type' variable can be used to define the data type of a buffer element.
         * @see Buffer.h
         */
        ShaderDataType type;
        /**
         * @brief The size of the variable in bytes.
         * @details The variable 'size' is of type 'uint32_t' and represents the size of the variable in bytes.
         * It is used in the 'BufferElement' struct in the file 'Buffer.h'.
         * @see Buffer.h
         */
        uint32_t size;
        /**
         * @brief The offset variable represents an unsigned 32-bit integer.
         * @details It is used in the BufferElement struct in the file Buffer.h.
         * The offset variable indicates the byte offset of the buffer element in memory when it is stored in a buffer.
         * @see Buffer.h
         */
        uint32_t offset;
        /**
         * @brief Indicates whether the variable 'normalized' is a normalized value.
         * @details The variable 'normalized' is of type 'bool' and is used to specify whether the data stored in a buffer element needs to be normalized before it is passed to a shader.
         * A normalized value is a value that is scaled to a specific range, typically between 0 and 1 or -1 and 1.
         * If 'normalized' is set to 'true', the data in the buffer element will be divided by the maximum value of the data type to normalize it.
         * If 'normalized' is set to 'false', the data will not be modified.
         * The 'normalized' variable is used in the 'BufferElement' struct in the file 'Buffer.h', which is included in the current context.
         * @see BufferElement, Buffer.h
         */
        bool normalized;

        BufferElement() = default;

        /**
         * \brief Constructor for the BufferElement struct.
         * \param type 
         * \param name 
         * \param normalized 
         */
        BufferElement(const ShaderDataType type, std::string name, const bool normalized = false)
            : name(std::move(name)), type(type), size(shaderDataTypeSize(type)), offset(0), normalized(normalized)
        {
        }

        /**
         * @brief Converts the shader data type to its corresponding OpenGL data type.
         * @details This method takes the shader data type and returns the corresponding OpenGL data type.
         * The mapping of shader data types to OpenGL data types is as follows:
         * - ShaderDataType::None: No OpenGL data type.
         * - ShaderDataType::Float: GL_FLOAT.
         * - ShaderDataType::Float2: GL_FLOAT.
         * - ShaderDataType::Float3: GL_FLOAT.
         * - ShaderDataType::Float4: GL_FLOAT.
         * - ShaderDataType::Mat3: GL_FLOAT.
         * - ShaderDataType::Mat4: GL_FLOAT.
         * - ShaderDataType::Int: GL_INT.
         * - ShaderDataType::Int2: GL_INT.
         * - ShaderDataType::Int3: GL_INT.
         * - ShaderDataType::Int4: GL_INT.
         * - ShaderDataType::Bool: GL_BOOL.
         *
         * @return The corresponding OpenGL data type for the shader data type.
         *
         * @see BufferElement::Type
         * @see Buffer.cpp
         */
        [[nodiscard]] uint32_t TypeToOpenGl() const;

        /**
         * @brief Get the element count for the shader data type.
         * @details This method returns the number of elements in the shader data type represented by the "type" member variable.
         * The element count is determined by the switch statement that matches the "type" value with the corresponding ShaderDataType enum case.
         * For example, if the "type" value is ShaderDataType::Float2, the method will return 2.
         *
         * @return The number of elements in the shader data type, or 0 if the "type" value is unknown.
         *
         * @see ShaderDataType
         * @see THRYLOS_CORE_ASSERT
         */
        [[nodiscard]] uint32_t GetElementCount() const
        {
            switch (type)
            {
                case ShaderDataType::None:     break;
                case ShaderDataType::Float:    return 1;
                case ShaderDataType::Float2:   return 2;
                case ShaderDataType::Float3:   return 3;
                case ShaderDataType::Float4:   return 4;
                case ShaderDataType::Mat3:     return 3 * 3;
                case ShaderDataType::Mat4:     return 4 * 4;
                case ShaderDataType::Int:      return 1;
                case ShaderDataType::Int2:     return 2;
                case ShaderDataType::Int3:     return 3;
                case ShaderDataType::Int4:     return 4;
                case ShaderDataType::Bool:     return 1;
            }

            THRYLOS_CORE_ASSERT(false, "Unknown ShaderDataType!")
            return 0;
        }
    };

    /**
     * @class BufferLayout
     * @brief Represents the layout of a buffer.
     * @details The BufferLayout class is used to define the layout of a buffer, including the elements, stride, and offsets.
     *          It provides methods to calculate the offsets and stride based on the buffer elements, and to access the elements and stride.
     *          It also provides iterator methods to iterate over the elements of the layout.
     *          The layout can be assigned to a buffer to define the data structure.
     * @see BufferElement
     */
    class BufferLayout
    {
    public:
        BufferLayout() = default;

        /**
         * \brief Constructor for the BufferLayout class.
         * \param elements  
         */
        BufferLayout(const std::initializer_list<BufferElement>& elements)
            : m_Elements(elements)
        {
            CalculateOffsetsAndStride();
        }

        /**
         * @brief Gets the stride of the buffer layout.
         * @details The stride is the byte size of each vertex in the buffer layout.
         * @return The stride of the buffer layout as a 32-bit unsigned integer.
         *
         * @see BufferLayout
         */
        [[nodiscard]] uint32_t GetStride() const { return m_Stride; }

        /**
         * @brief Gets the elements of the buffer layout.
         * @details This method returns a const reference to the vector of BufferElement objects that represent the elements of the buffer layout.
         * @return A const reference to the vector of BufferElement objects.
         *
         * @see BufferLayout
         */
        [[nodiscard]] const std::vector<BufferElement>& GetElements() const { return m_Elements; }

        std::vector<BufferElement>::iterator begin() { return m_Elements.begin(); }
        std::vector<BufferElement>::iterator end() { return m_Elements.end(); }
        std::vector<BufferElement>::const_iterator begin() const { return m_Elements.begin(); }
        std::vector<BufferElement>::const_iterator end() const { return m_Elements.end(); }

        /**
         * @brief Enables the vertex attribute arrays for the buffer layout.
         *
         * @details This method enables the vertex attribute arrays for each element in the buffer layout.
         * It calls the glEnableVertexAttribArray and glVertexAttribPointer functions for each element in the buffer layout.
         * The index of the vertex attribute arrays is determined by the position of the element in the buffer layout.
         *
         * @see BufferLayout, glEnableVertexAttribArray, glVertexAttribPointer
         */
        void EnableVertexAttribArray() const;
        
    private:
        /**
         * @brief Calculates the offsets and stride for each element in the buffer layout.
         * @details This method is responsible for calculating the offsets and stride for each element in the buffer layout.
         * It iterates through the elements in the buffer layout and assigns the offset of each element based on the previous element's offset
         * and the size of the element. It also calculates the stride of the buffer layout by summing up the sizes of all the elements.
         * The offsets and stride are stored in the corresponding members of the BufferLayout object.
         *
         * @see BufferLayout, BufferElement
         */
        void CalculateOffsetsAndStride()
        {
            uint32_t offset = 0;
            m_Stride = 0;
            for (auto& element : m_Elements)
            {
                element.offset = offset;
                offset += element.size;
                m_Stride += element.size;
            }
        }
        
        std::vector<BufferElement> m_Elements;
        uint32_t m_Stride = 0;
        
    };

    /**
     * \brief Represents a vertex buffer object (VBO).
     */
    class VertexBuffer
    {
    public:
        virtual ~VertexBuffer() = default;

        /**
         * @brief Binds the vertex array.
         *
         * @details This method binds the vertex array by calling the glBindVertexArray function with the renderer ID member variable.
         * After binding the vertex array, it also calls the Bind method of the vertex buffer associated with the vertex array.
         *
         * @see OpenGLVertexArray, VertexBuffer, glBindVertexArray
         */
        virtual void Bind() const = 0;

        /**
         * @brief Unbinds the vertex buffer.
         *
         * @details This method unbinds the vertex buffer by unbinding the vertex array associated with it.
         * It should be called after the vertex buffer has been used to draw.
         *
         * @see VertexBuffer, VertexBuffer::Bind, VertexBuffer::SetLayout
         */
        virtual void Unbind() const = 0;

        /**
         * @brief Sets the layout for the buffer.
         *
         * @details This method sets the layout for the buffer by taking a const reference to a BufferLayout object.
         * The buffer layout contains information about the elements in the buffer, such as their data type and size.
         * This method is pure virtual and needs to be implemented in a derived class.
         *
         * @param layout A const reference to a BufferLayout object representing the layout of the buffer.
         *
         * @see BufferLayout, BufferLayout::BufferLayout
         */
        virtual void SetLayout(const BufferLayout& layout) = 0;

        /**
         * @brief Gets the layout for the buffer.
         *
         * @details This method returns a const reference to a BufferLayout object that represents the layout of the buffer.
         * The buffer layout contains information about the elements in the buffer, such as their data type and size.
         *
         * @return A const reference to a BufferLayout object representing the layout of the buffer.
         *
         * @see BufferLayout, BufferLayout::BufferLayout
         */
        [[nodiscard]] virtual const BufferLayout& GetLayout() const = 0;

        /**
         * @brief Creates a vertex buffer.
         *
         * @details This method creates a vertex buffer by taking in a pointer to an array of vertices and the size of the vertices.
         * It dynamically allocates memory for the buffer based on the renderer API and returns a pointer to the created buffer.
         *
         * @param vertices A pointer to an array of vertices.
         * @param size The size of the vertices in bytes.
         * @return A pointer to the created vertex buffer.
         *
         * @see Renderer::GetRendererApi(), RendererApi, OpenGLVertexBuffer
         */
        static VertexBuffer* Create(const float* vertices, uint32_t size);
    };

    /**
     * \brief Represents an index buffer object (IBO).
     */
    class IndexBuffer
    {
    public:
        virtual ~IndexBuffer() = default;
     
        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        /**
         * @brief Gets the count of the elements.
         *
         * @return The count of the elements.
         */
        [[nodiscard]] virtual uint32_t GetCount() const = 0;


        /**
         * @brief Creates an IndexBuffer object.
         *
         * @param indices An array of unsigned integers representing the indices.
         * @param count The number of elements in the indices array.
         * @return A pointer to the created IndexBuffer object.
         *
         * @note The caller is responsible for managing the lifetime of the returned object.
         * @see Renderer.h, IndexBuffer, OpenGLIndexBuffer
         */
        static IndexBuffer* Create(const uint32_t* indices, uint32_t count);
    };
 
    typedef std::shared_ptr<IndexBuffer> IndexBufferRef;
    typedef std::shared_ptr<VertexBuffer> VertexBufferRef;
    
}

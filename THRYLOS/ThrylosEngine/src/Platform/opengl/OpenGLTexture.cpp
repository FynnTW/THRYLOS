﻿#include "tpch.h"
#include "OpenGLTexture.h"

#include <glad/glad.h>

#include "stb_image.h"

namespace Thrylos
{
    OpenGLTexture2D::OpenGLTexture2D(const uint32_t width, const uint32_t height)
        : m_Width(width), m_Height(height)
    {
    }

    OpenGLTexture2D::OpenGLTexture2D(std::string path)
        : m_Path(std::move(path))
    {
        int width, height, channels;
        stbi_set_flip_vertically_on_load(1);
        stbi_uc* data = stbi_load(m_Path.c_str(), &width, &height, &channels, 0);
        THRYLOS_CORE_ASSERT(data, "Failed to load image!")
        m_Width = width;
        m_Height = height;
        m_Channels = channels;

        GLenum internalFormat = 0, dataFormat = 0;
        if (m_Channels == 4)
        {
            internalFormat = GL_RGBA8;
            dataFormat = GL_RGBA;
        }
        else if (m_Channels == 3)
        {
            internalFormat = GL_RGB8;
            dataFormat = GL_RGB;
        }
        THRYLOS_ASSERT(internalFormat & dataFormat, "Format not supported!")

        glCreateTextures(GL_TEXTURE_2D, 1, &m_RendererId);
        glTextureStorage2D(m_RendererId, 1, internalFormat, m_Width, m_Height);

        glTextureParameteri(m_RendererId, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTextureParameteri(m_RendererId, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glTextureSubImage2D(m_RendererId, 0, 0, 0, m_Width, m_Height, dataFormat, GL_UNSIGNED_BYTE, data);

        stbi_image_free(data);
    }

    OpenGLTexture2D::~OpenGLTexture2D()
    {
        glDeleteTextures(1, &m_RendererId);
    }

    void OpenGLTexture2D::Bind(const uint32_t slot) const 
    {
        glBindTextureUnit(slot, m_RendererId);
    }
    
}

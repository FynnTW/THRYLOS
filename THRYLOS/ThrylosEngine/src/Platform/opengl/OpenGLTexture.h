#pragma once
#include "Renderer/Texture.h"

namespace Thrylos
{

    class OpenGLTexture2D : public Texture2D
    {
    public:
        OpenGLTexture2D(uint32_t width, uint32_t height);
        OpenGLTexture2D(std::string path);
        ~OpenGLTexture2D() override;

        [[nodiscard]] uint32_t GetWidth() const override { return m_Width; }
        [[nodiscard]] uint32_t GetHeight() const override { return m_Height; }
        [[nodiscard]] int GetChannels() const { return m_Channels; }
        [[nodiscard]] std::string GetPath() const { return m_Path; }
        void Bind(uint32_t slot = 0) const override;

    private:
        std::string m_Path;
        uint32_t m_Width, m_Height;
        int m_Channels;
        uint32_t m_RendererId;
    };
    
}

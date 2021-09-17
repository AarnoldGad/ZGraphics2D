#include "zgraphics2D/Renderer/Resources/Texture.hpp"

#include "zgraphics2D/Engine/GraphicsEngine.hpp"

#include <zengine/Memory/New.hpp>

namespace zg
{
   Texture const Texture::Null;

   Texture::Texture()
      : m_texture(0), m_size{} {}

   void Texture::loadFile(std::filesystem::path const& file)
   {
      int width, height, channelCount;
      uint8_t* data = stbi_load(file.string().c_str(), &width, &height, &channelCount, 0);
      if (!data)
      {
         GFX_LOG_ERROR("Fail to load texture at %s : %s", file.string(), stbi_failure_reason());
         return;
      }

      loadData(data, { width, height }, static_cast<Image::Format>(channelCount));
      stbi_image_free(data);
   }

   void Texture::loadImage(Image const& image)
   {
      if (!image) return;

      loadData(image.getData(), image.getSize(), image.getFormat());
   }

   void Texture::loadData(uint8_t const* data, glm::ivec2 size, Image::Format format)
   {
      if (!m_texture) glGenTextures(1, &m_texture);

      bind();
      int glFormat = (format == Image::Format::Grey      ? GL_RED :
                           (format == Image::Format::GreyAlpha ? GL_RG  :
                           (format == Image::Format::RGB       ? GL_RGB : GL_RGBA)));
      glTexImage2D(GL_TEXTURE_2D, 0, glFormat, size.x, size.y, 0, glFormat, GL_UNSIGNED_BYTE, data);

      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

      glGenerateMipmap(GL_TEXTURE_2D);

      m_size = size;
      Bind(Texture::Null);
   }

   void Texture::Bind(Texture const& texture) noexcept
   {
      texture.bind();
   }

   void Texture::bind() const noexcept
   {
      glBindTexture(GL_TEXTURE_2D, m_texture);
   }

   Texture::~Texture()
   {
      if (m_texture) glDeleteTextures(1, &m_texture);
   }
}

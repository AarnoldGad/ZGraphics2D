#include "zgraphics2D/Common/Image.hpp"

#include <zengine/Memory/New.hpp>

namespace zg
{
   Image::Image()
      : m_data(nullptr), m_format(Format::Unknown), m_size(0, 0) {}

   Image::Image(std::filesystem::path const& file, Format desiredFormat)
      : m_data(nullptr), m_format(Format::Unknown), m_size(0, 0)
   {
      load(file, desiredFormat);
   }

   Image::Image(Image const& other)
      : m_data(nullptr), m_format(Format::Unknown), m_size(0, 0)
   {
      if (other)
      {
         m_size = other.m_size;
         m_format = other.m_format;
         size_t dataSize = m_size.x * m_size.y * static_cast<unsigned>(m_format);
         m_data = new uint8_t[dataSize];
         std::copy(other.m_data, other.m_data + dataSize, m_data);
      }
   }

   Image::Image(Image&& other)
      : m_data(std::exchange(other.m_data, nullptr)),
        m_format(std::exchange(other.m_format, Format::Unknown)),
        m_size(std::move(other.m_size)) {}

   Image& Image::operator=(Image const& other)
   {
      if (m_data)
         unload();

      m_size = other.m_size;
      m_format = other.m_format;
      size_t dataSize = m_size.x * m_size.y * static_cast<unsigned>(m_format);
      m_data = new uint8_t[dataSize];
      std::copy(other.m_data, other.m_data + dataSize, m_data);

      return *this;
   }

   Image& Image::operator=(Image&& other)
   {
      if (m_data)
         unload();

      m_data = std::exchange(other.m_data, nullptr);
      m_format = std::exchange(other.m_format, Format::Unknown);
      m_size = std::move(other.m_size);

      return *this;
   }

   bool Image::load(std::filesystem::path const& file, Format desiredFormat)
   {
      if (m_data)
         unload();

      stbi_set_flip_vertically_on_load(true);

      int width, height, numberOfChannels;
      uint8_t* data = stbi_load(file.c_str(), &width, &height, &numberOfChannels, static_cast<int>(desiredFormat));
      if (!data)
         return LOG_TRACE("Fail to load image at ", file.string(), " : ", stbi_failure_reason()), false;

      m_size = { width, height };
      m_format = desiredFormat == Format::Unknown ? static_cast<Format>(numberOfChannels) : desiredFormat;
      size_t dataSize = m_size.x * m_size.y * static_cast<unsigned>(m_format);
      m_data = new uint8_t[dataSize];
      std::copy(data, data + dataSize, m_data);

      stbi_image_free(data);

      return true;
   }

   void Image::unload() noexcept
   {
      if (!isLoaded()) return;

      delete[] m_data;
      m_data = nullptr;
      m_format = Format::Unknown;
      m_size = {0, 0};
   }

   Image::~Image()
   {
      unload();
   }
}

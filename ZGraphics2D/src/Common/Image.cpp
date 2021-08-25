#include "zgraphics2D/Common/Image.hpp"

#include <zengine/Memory/New.hpp>

namespace zg
{
   Image::Image()
      : m_data(nullptr), m_format(Format::Unknown), m_size(0, 0) {}

   Image::Image(std::filesystem::path const& file)
      : m_data(nullptr), m_format(Format::Unknown), m_size(0, 0)
   {
      load(file);
   }

   Image::Image(Image const& other)
      : m_data(nullptr), m_format(Format::Unknown), m_size(0, 0)
   {
      if (other)
      {
         m_size = other.m_size;
         m_format = other.m_format;
         std::memcpy(m_data, other.m_data, m_size.x * m_size.y);
      }
   }

   Image::Image(Image&& other)
      : m_data(std::exchange(other.m_data, nullptr)),
        m_format(std::exchange(other.m_format, Format::Unknown)),
        m_size(std::move(other.m_size)) {}

   Image& Image::operator=(Image const& other)
   {
      m_size = other.m_size;
      m_format = other.m_format;
      std::memcpy(m_data, other.m_data, m_size.x * m_size.y);

      return *this;
   }

   Image& Image::operator=(Image&& other)
   {
      m_data = std::exchange(other.m_data, nullptr);
      m_format = std::exchange(other.m_format, Format::Unknown);
      m_size = std::move(other.m_size);

      return *this;
   }

   bool Image::load(std::filesystem::path const& file)
   {
      // TODO
   }

   void Image::unload() noexcept
   {
      if (!isLoaded()) return;

      delete m_data;
      m_data = nullptr;
      m_format = Format::Unknown;
      m_size = {0, 0};
   }

   Image::~Image()
   {
      unload();
   }
}

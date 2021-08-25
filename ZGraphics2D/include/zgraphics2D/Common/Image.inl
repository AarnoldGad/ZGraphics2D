#include <zengine/Memory/New.hpp>

inline uint8_t const* zg::Image::getData() const noexcept
{
   return m_data;
}

inline uint8_t zg::Image::getData(glm::uvec2 coord) const noexcept
{
   if (!m_data || coord.x > m_size.x || coord.y > m_size.y)
      return LOG_TRACE("Out of range exception"), 0;
   
   return m_data[coord.x + coord.y * m_size.x];
}

inline zg::Image::Format zg::Image::getFormat() const noexcept
{
   return m_format;
}

inline glm::uvec2 zg::Image::getSize() const noexcept
{
   return m_size;
}

inline zg::Image::operator bool() const noexcept
{
   return isLoaded();
}

inline bool zg::Image::isLoaded() const noexcept
{
   return m_data;
}

#include <zengine/Memory/NewOff.hpp>

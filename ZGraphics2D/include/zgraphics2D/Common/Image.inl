inline uint8_t const* zg::Image::getData() const noexcept
{
   return m_data;
}

inline zg::Image::Format zg::Image::getFormat() const noexcept
{
   return m_format;
}

inline glm::ivec2 zg::Image::getSize() const noexcept
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

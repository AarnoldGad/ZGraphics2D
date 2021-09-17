#include <zengine/Memory/New.hpp>

inline unsigned int zg::Texture::getHandle() const noexcept
{
   return m_texture;
}

inline glm::ivec2 zg::Texture::getSize() const noexcept
{
   return m_size;
}

#include <zengine/Memory/NewOff.hpp>

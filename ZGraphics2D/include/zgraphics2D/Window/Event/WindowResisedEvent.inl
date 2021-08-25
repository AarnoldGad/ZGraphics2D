#include <zengine/Memory/New.hpp>

inline glm::ivec2 zg::WindowResisedEvent::getSize() const noexcept
{
   return m_size;
}

inline glm::ivec2 zg::WindowResisedEvent::getOffset() const noexcept
{
   return m_offset;
}

#include <zengine/Memory/NewOff.hpp>

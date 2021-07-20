#include <zengine/Memory/New.hpp>

inline glm::ivec2 zg::WindowMovedEvent::getPosition() const noexcept
{
   return m_pos;
}

inline glm::ivec2 zg::WindowMovedEvent::getOffset() const noexcept
{
   return m_offset;
}

#include <zengine/Memory/NewOff.hpp>
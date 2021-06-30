#include <zengine/Memory/New.hpp>

inline zg::Window* zg::MouseEvent::getWindow() noexcept
{
   return m_window;
}

inline glm::ivec2 zg::MouseEvent::getPosition() const noexcept
{
   return m_pos;
}

#include <zengine/Memory/NewOff.hpp>
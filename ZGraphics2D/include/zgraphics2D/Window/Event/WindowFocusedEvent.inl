#include <zengine/Memory/New.hpp>

inline bool zg::WindowFocusedEvent::isFocused() const noexcept
{
   return m_focused;
}

#include <zengine/Memory/NewOff.hpp>
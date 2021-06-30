#include <zengine/Memory/New.hpp>

inline double zg::MouseScrolledEvent::getHorizontalOffset() const noexcept
{
   return m_xoffset;
}

inline double zg::MouseScrolledEvent::getVerticalOffset() const noexcept
{
   return m_yoffset;
}


#include <zengine/Memory/NewOff.hpp>
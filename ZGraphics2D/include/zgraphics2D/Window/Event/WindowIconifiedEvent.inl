#include <zengine/Memory/New.hpp>

inline bool zg::WindowIconifiedEvent::isIconified() const noexcept
{
   return m_iconified;
}

#include <zengine/Memory/NewOff.hpp>

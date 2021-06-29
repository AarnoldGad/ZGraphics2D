#include <zengine/Memory/New.hpp>

inline zg::Window& zg::WindowEvent::getWindow() noexcept
{
   return m_window;
}

#include <zengine/Memory/NewOff.hpp>
#include "zgraphics2D/Window/WindowEvent.hpp"

#include <zengine/Memory/New.hpp>

namespace zg
{
   WindowEvent::WindowEvent(Window& window)
      : m_window(window) {}
}
#include "zgpch.hpp"

#include "zgraphics2D/Window/Event/WindowFocusedEvent.hpp"

namespace zg
{
   WindowFocusedEvent::WindowFocusedEvent(Window* window, bool focused)
      : WindowEvent(window), m_focused(focused) {}

   std::string WindowFocusedEvent::toString() const
   {
      std::stringstream debugStr;
      debugStr << "Window " << std::hex << m_window << std::dec << (isFocused() ? " focused" : " unfocused");
      return debugStr.str();
   }
}

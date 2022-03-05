#include "zgpch.hpp"

#include "zgraphics2D/Window/Event/WindowClosedEvent.hpp"

namespace zg
{
   WindowClosedEvent::WindowClosedEvent(Window* window)
      : WindowEvent(window) {}

   std::string WindowClosedEvent::toString() const
   {
      std::stringstream debugStr;
      debugStr << "Window " << std::hex << m_window << std::dec << " closed";
      return debugStr.str();
   }
}

#include "zgpch.hpp"

#include "zgraphics2D/Window/Event/WindowIconifiedEvent.hpp"

namespace zg
{
   WindowIconifiedEvent::WindowIconifiedEvent(Window* window, int iconified)
      : WindowEvent(window), m_iconified(static_cast<bool>(iconified)) {}

   std::string WindowIconifiedEvent::toString() const
   {
      std::stringstream debugStr;

      debugStr << "Window " << std::hex << m_window << std::dec
      << (isIconified() ? " iconified" : " restored");

      return debugStr.str();
   }
}

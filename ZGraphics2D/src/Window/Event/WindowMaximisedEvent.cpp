#include "zgpch.hpp"

#include "zgraphics2D/Window/Event/WindowMaximisedEvent.hpp"

namespace zg
{
   WindowMaximisedEvent::WindowMaximisedEvent(Window* window, int maximised)
      : WindowEvent(window), m_maximised(static_cast<bool>(maximised)) {}

   std::string WindowMaximisedEvent::toString() const
   {
      std::stringstream debugStr;

      debugStr << "Window " << std::hex << m_window << std::dec
      << (isMaximised() ? " maximised" : " minimised");

      return debugStr.str();
   }
}

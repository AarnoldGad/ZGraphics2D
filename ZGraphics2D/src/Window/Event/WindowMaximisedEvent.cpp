#include "zgraphics2D/Window/Event/WindowMaximisedEvent.hpp"

#include <zengine/Memory/New.hpp>

namespace zg
{
   WindowMaximisedEvent::WindowMaximisedEvent(Window* window, int maximised)
      : WindowEvent(window), m_maximised(static_cast<bool>(maximised)) {}

   std::string WindowMaximisedEvent::toString() const
   {
      std::stringstream debugStr;

      debugStr << "Window 0x" << std::hex << m_window << std::dec
      << (isMaximised() ? "Maximised" : "Minimised") << std::endl;

      return debugStr.str();
   }
}

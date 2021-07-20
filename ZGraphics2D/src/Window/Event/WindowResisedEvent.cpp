#include "zgraphics2D/Window/Event/WindowResisedEvent.hpp"

namespace zg
{
   WindowResisedEvent::WindowResisedEvent(Window* window, glm::ivec2 size)
      : WindowEvent(window), m_size(size) {}

   std::string WindowResisedEvent::toString() const
   {
      std::stringstream debugStr;
      debugStr << "Window 0x" << std::hex << m_window << std::dec
               << " resised to ( " << m_size.x << "," << m_size.y << " )" << std::endl;
      return debugStr.str();
   }
}
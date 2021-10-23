#include "zgpch.hpp"

#include "zgraphics2D/Window/Event/WindowResisedEvent.hpp"

namespace zg
{
   WindowResisedEvent::WindowResisedEvent(Window* window, glm::ivec2 newSize, glm::ivec2 oldSize)
      : WindowEvent(window), m_size(newSize), m_offset(newSize - oldSize) {}

   std::string WindowResisedEvent::toString() const
   {
      std::stringstream debugStr;
      debugStr << "Window 0x" << std::hex << m_window << std::dec
               << " resised from (" << m_size.x - m_offset.x << ", " << m_size.y - m_offset.y
               << ") to (" << m_size.x << ", " << m_size.y << ")" << std::endl;
      return debugStr.str();
   }
}

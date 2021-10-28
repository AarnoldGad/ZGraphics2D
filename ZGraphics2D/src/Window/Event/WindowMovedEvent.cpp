#include "zgpch.hpp"

#include "zgraphics2D/Window/Event/WindowMovedEvent.hpp"

namespace zg
{
   WindowMovedEvent::WindowMovedEvent(Window* window, glm::ivec2 newPos, glm::ivec2 oldPos)
      : WindowEvent(window), m_pos(newPos), m_offset(newPos - oldPos) {}

   std::string WindowMovedEvent::toString() const
   {
      std::stringstream debugStr;
      debugStr << "Window 0x" << std::hex << m_window << std::dec
               << " moved from (" << (m_pos.x - m_offset.x) << "," << (m_pos.y - m_offset.y)
               << ") to (" << m_pos.x << "," << m_pos.y << ")";
      return debugStr.str();
   }
}

#include "zgpch.hpp"

#include "zgraphics2D/Input/Event/MouseMovedEvent.hpp"

namespace zg
{
   MouseMovedEvent::MouseMovedEvent(Window* window, glm::ivec2 pos)
      : MouseEvent(window, pos) {}

   std::string MouseMovedEvent::toString() const
   {
      std::stringstream debugStr;

      debugStr << "Mouse moved to (" << m_pos.x << ", " << m_pos.y << ")";

      return debugStr.str();
   }
}

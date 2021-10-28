#include "zgpch.hpp"

#include "zgraphics2D/Input/Event/MouseScrolledEvent.hpp"

namespace zg
{
   MouseScrolledEvent::MouseScrolledEvent(Window* window, glm::ivec2 pos, double xoffset, double yoffset)
      : MouseEvent(window, pos), m_xoffset(xoffset), m_yoffset(yoffset) {}

   std::string MouseScrolledEvent::toString() const
   {
      std::stringstream debugStr;

      debugStr << "Mouse scrolled by (" << m_xoffset << ", " << m_yoffset << ")";

      return debugStr.str();
   }
}

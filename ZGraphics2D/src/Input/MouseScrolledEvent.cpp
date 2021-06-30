#include "zgraphics2D/Input/MouseScrolledEvent.hpp"

#include <zengine/Memory/New.hpp>

namespace zg
{
   MouseScrolledEvent::MouseScrolledEvent(Window* window, glm::ivec2 pos, double xoffset, double yoffset)
      : MouseEvent(window, pos), m_xoffset(xoffset), m_yoffset(yoffset) {}

   std::string MouseScrolledEvent::toString() const
   {
      return "MouseScrolledEvent";
   }
}
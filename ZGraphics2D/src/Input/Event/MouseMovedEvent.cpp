#include "zgraphics2D/Input/Event/MouseMovedEvent.hpp"

#include <zengine/Memory/New.hpp>

namespace zg
{
   MouseMovedEvent::MouseMovedEvent(Window* window, glm::ivec2 pos)
      : MouseEvent(window, pos) {}

   std::string MouseMovedEvent::toString() const
   {
      return "MouseMovedEvent";
   }
}

#include "zgraphics2D/Input/MouseButtonReleasedEvent.hpp"

#include <zengine/Memory/New.hpp>

namespace zg
{
   MouseButtonReleasedEvent::MouseButtonReleasedEvent(Window* window, glm::ivec2 pos, Mouse::Button button, uint32_t modifiers)
      : MouseButtonEvent(window, pos, button, Action::Released, modifiers) {}

   std::string MouseButtonReleasedEvent::toString() const
   {
      return "MouseButtonReleasedEvent";
   }
}
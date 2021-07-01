#include "zgraphics2D/Input/Event/MouseButtonPressedEvent.hpp"

#include <zengine/Memory/New.hpp>

namespace zg
{
   MouseButtonPressedEvent::MouseButtonPressedEvent(Window* window, glm::ivec2 pos, Mouse::Button button, uint32_t modifiers)
      : MouseButtonEvent(window, pos, button, Action::Pressed, modifiers){}

   std::string MouseButtonPressedEvent::toString() const
   {
      return "MouseButtonPressedEvent";
   }
}

#include "zgraphics2D/Input/Event/MouseButtonEvent.hpp"

#include <zengine/Memory/New.hpp>

namespace zg
{
   MouseButtonEvent::MouseButtonEvent(Window* window, glm::ivec2 pos, Mouse::Button button, Action action, uint32_t modifiers)
      : MouseEvent(window, pos), m_button(button), m_action(action), m_modifiers(modifiers) {}

   std::string MouseButtonEvent::toString() const
   {
      return m_action == Action::Pressed ? "MouseButtonPressedEvent" : "MouseButtonReleasedEvent";
   }
}
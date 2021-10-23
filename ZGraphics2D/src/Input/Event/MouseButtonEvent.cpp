#include "zgpch.hpp"

#include "zgraphics2D/Input/Event/MouseButtonEvent.hpp"

namespace zg
{
   MouseButtonEvent::MouseButtonEvent(Window* window, glm::ivec2 pos, Mouse::Button button, Action action, uint32_t modifiers)
      : MouseEvent(window, pos), m_button(button), m_action(action), m_modifiers(modifiers) {}
}

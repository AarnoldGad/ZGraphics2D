#include "zgraphics2D/Input/Event/MouseButtonReleasedEvent.hpp"

#include <zengine/Memory/New.hpp>

namespace zg
{
   MouseButtonReleasedEvent::MouseButtonReleasedEvent(Window* window, glm::ivec2 pos, Mouse::Button button, uint32_t modifiers)
      : MouseButtonEvent(window, pos, button, Action::Released, modifiers) {}

   std::string MouseButtonReleasedEvent::toString() const
   {
      std::stringstream debugStr;

      debugStr << "Mouse button " << static_cast<int>(m_button)
               << " released at (" << m_pos.x << ", " << m_pos.y << ")" << std::endl;

      return debugStr.str();
   }
}

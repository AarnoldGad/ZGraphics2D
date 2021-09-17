#include "zgraphics2D/Input/Event/KeyRepeatedEvent.hpp"

#include <zengine/Memory/New.hpp>

namespace zg
{
   KeyRepeatedEvent::KeyRepeatedEvent(Window* window, Keyboard::Key key, int scancode, uint32_t modifiers)
      : KeyEvent(window, key, scancode, Action::Repeated, modifiers) {}

   std::string KeyRepeatedEvent::toString() const
   {
      std::stringstream debugStr;

      debugStr << "Key " << static_cast<int>(m_key) << " repeated" << std::endl;

      return debugStr.str();
   }
}

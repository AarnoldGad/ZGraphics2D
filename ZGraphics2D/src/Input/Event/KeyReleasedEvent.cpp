#include "zgraphics2D/Input/Event/KeyReleasedEvent.hpp"

#include <zengine/Memory/New.hpp>

namespace zg
{
   KeyReleasedEvent::KeyReleasedEvent(Window* window, Keyboard::Key key, int scancode, uint32_t modifiers)
      : KeyEvent(window, key, scancode, Action::Released, modifiers) {}

   std::string KeyReleasedEvent::toString() const
   {
      std::stringstream debugStr;

      debugStr << "Key " << static_cast<int>(m_key) << " released" << std::endl;

      return debugStr.str();
   }
}

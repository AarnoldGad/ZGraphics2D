#include "zgraphics2D/Input/KeyPressedEvent.hpp"

#include <zengine/Memory/New.hpp>

namespace zg
{
   KeyPressedEvent::KeyPressedEvent(Window* window, Keyboard::Key key, int scancode, uint32_t modifiers)
      : KeyEvent(window, key, scancode, Action::Pressed, modifiers) {}

   std::string KeyPressedEvent::toString() const
   {
      return "KeyPressedEvent";
   }
}
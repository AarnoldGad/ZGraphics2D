#include "zgraphics2D/Input/KeyRepeatedEvent.hpp"

#include <zengine/Memory/New.hpp>

namespace zg
{
   KeyRepeatedEvent::KeyRepeatedEvent(Window& window, Keyboard::Key key, int scancode, uint32_t modifiers)
      : KeyEvent(window, key, scancode, Action::Repeated, modifiers) {}

   std::string KeyRepeatedEvent::toString() const
   {
      return "KeyRepeatedEvent";
   }
}
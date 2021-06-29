#include "zgraphics2D/Input/KeyEvent.hpp"

#include <zengine/Memory/New.hpp>

namespace zg
{
   KeyEvent::KeyEvent(Window& window, Keyboard::Key key, int scancode, Action action, uint32_t modifiers)
      : m_window(window), m_key(key), m_scancode(scancode), m_action(action), m_modifiers(modifiers) {}
}

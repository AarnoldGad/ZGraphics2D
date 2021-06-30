#include "zgraphics2D/Input/Event/MouseEvent.hpp"

#include <zengine/Memory/New.hpp>

namespace zg
{
   MouseEvent::MouseEvent(Window* window, glm::ivec2 pos)
      : m_window(window), m_pos(pos) {}
}

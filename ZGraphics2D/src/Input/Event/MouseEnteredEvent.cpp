#include "zgraphics2D/Input/Event/MouseEnteredEvent.hpp"

#include <zengine/Memory/New.hpp>

namespace zg
{
   MouseEnteredEvent::MouseEnteredEvent(Window* window, glm::ivec2 pos, bool entered)
      : MouseEvent(window, pos), m_entered(entered) {}

   std::string MouseEnteredEvent::toString() const
   {
      return hasEntered() ? "Mouse entered" : "Mouse leaved";
   }
}

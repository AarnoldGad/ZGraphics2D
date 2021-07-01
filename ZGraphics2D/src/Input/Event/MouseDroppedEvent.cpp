#include "zgraphics2D/Input/Event/MouseDroppedEvent.hpp"

#include <zengine/Memory/New.hpp>

namespace zg
{
   MouseDroppedEvent::MouseDroppedEvent(Window* window, glm::ivec2 pos, size_t count, char const* paths[])
      : MouseEvent(window, pos), m_paths{}
   {
      for (size_t i = 0; i < count; i++)
         m_paths.push_back(paths[i]);
   }

   std::string MouseDroppedEvent::toString() const
   {
      return "MouseDroppedEvent";
   }
}

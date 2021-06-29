#include "zgraphics2D/Window/WindowClosedEvent.hpp"

#include <zengine/Memory/New.hpp>

namespace zg
{
   WindowClosedEvent::WindowClosedEvent(Window& window)
      : WindowEvent(window) {}

   std::string WindowClosedEvent::toString() const
   {
      return "WindowClosedEvent";
   }
}
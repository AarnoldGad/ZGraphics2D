#include "zgpch.hpp"

#include "zgraphics2D/Window/Event/FrameBufferResisedEvent.hpp"

namespace zg
{
   FrameBufferResisedEvent::FrameBufferResisedEvent(Window* window, int width, int height)
      : WindowEvent(window), m_size(width, height) {}

   std::string FrameBufferResisedEvent::toString() const
   {
      std::stringstream debugStr;

      debugStr << "Window 0x" << std::hex << m_window << std::dec
      << " framebuffer resised to (" << getSize().x << ", " << getSize().y << ")" << std::endl;

      return debugStr.str();
   }
}

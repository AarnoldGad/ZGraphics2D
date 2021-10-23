#include "zgpch.hpp"

#include "zgraphics2D/Window/Event/WindowRefreshedEvent.hpp"

namespace zg
{
   WindowRefreshedEvent::WindowRefreshedEvent(Window* window)
      : WindowEvent(window) {}

   std::string WindowRefreshedEvent::toString() const
   {
      std::stringstream debugStr;
      debugStr << "Window 0x" << std::hex << m_window << std::dec << " refreshed";
      return debugStr.str();
   }
}
#include "zgpch.hpp"

#include "zgraphics2D/Window/Event/WindowScaledEvent.hpp"

namespace zg
{
   WindowScaledEvent::WindowScaledEvent(Window* window, float xscale, float yscale)
      : WindowEvent(window), m_scale{xscale, yscale} {}

   std::string WindowScaledEvent::toString() const
   {
      std::stringstream debugStr;

      debugStr << "Window 0x" << std::hex << m_window << std::dec
      << " scaled by (" << getScale().x << ", " << getScale().y << ")" << std::endl;

      return debugStr.str();
   }
}

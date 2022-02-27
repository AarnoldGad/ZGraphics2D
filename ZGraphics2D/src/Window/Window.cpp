#include "zgpch.hpp"

#include "zgraphics2D/Window/Window.hpp"

#include "zgraphics2D/Engine/GraphicsEngine.hpp"

#include "detail/Window/WindowImpl.hpp"

namespace zg
{
   void Window::Configure(WindowSettings window, ContextSettings context, FrameBufferSettings framebuffer)
   {
      details::WindowImpl::ConfigureWindow(window, context, framebuffer);
   }

   std::shared_ptr<Window> Window::Make(std::string const& title, glm::ivec2 size, glm::ivec2 pos)
   {
      std::shared_ptr<Window> window = std::make_shared<details::WindowImpl>();
      window->open(title, size, pos);
      return window;
   }
}

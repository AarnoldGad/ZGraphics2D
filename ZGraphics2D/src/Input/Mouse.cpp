#include "zgraphics2D/Input/Mouse.hpp"

#include "zgraphics2D/Input/MouseMovedEvent.hpp"
#include "zgraphics2D/Input/MouseEnteredEvent.hpp"
#include "zgraphics2D/Input/MouseButtonPressedEvent.hpp"
#include "zgraphics2D/Input/MouseButtonReleasedEvent.hpp"
#include "zgraphics2D/Input/MouseScrolledEvent.hpp"

#include <zengine/Memory/New.hpp>

namespace zg
{
   Mouse::Mouse()
      : m_window(nullptr) {}

   Mouse::Mouse(Window& window)
      : m_window(&window)
   {
      glfwSetCursorPosCallback(m_window->getHandle(), &Mouse::CursorPositionInput);
      glfwSetCursorEnterCallback(m_window->getHandle(), &Mouse::CursorEnterInput);

      glfwSetMouseButtonCallback(m_window->getHandle(), &Mouse::MouseButtonInput);
      glfwSetScrollCallback(m_window->getHandle(), &Mouse::MouseWheelInput);

      glfwSetDropCallback(m_window->getHandle(), &Mouse::DropInput);
   }

   void Mouse::setPosition(glm::ivec2 pos)
   {
      if (!m_window) return;

      glfwSetCursorPos(m_window->getHandle(), static_cast<double>(pos.x), static_cast<double>(pos.y));
   }

   void Mouse::setWindow(Window* window)
   {
      if (m_window) // Reset last window if one
      {
         glfwSetCursorPosCallback(m_window->getHandle(), nullptr);
         glfwSetCursorEnterCallback(m_window->getHandle(), nullptr);

         glfwSetMouseButtonCallback(m_window->getHandle(), nullptr);
         glfwSetScrollCallback(m_window->getHandle(), nullptr);

         glfwSetDropCallback(m_window->getHandle(), nullptr);
      }

      if (m_window = window, m_window) // Set new window
      {
         glfwSetCursorPosCallback(m_window->getHandle(), &Mouse::CursorPositionInput);
         glfwSetCursorEnterCallback(m_window->getHandle(), &Mouse::CursorEnterInput);

         glfwSetMouseButtonCallback(m_window->getHandle(), &Mouse::MouseButtonInput);
         glfwSetScrollCallback(m_window->getHandle(), &Mouse::MouseWheelInput);

         glfwSetDropCallback(m_window->getHandle(), &Mouse::DropInput);
      }
   }

   void Mouse::CursorPositionInput(GLFWwindow* window, double x, double y) noexcept
   {
      Window* windowPtr = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
      ze::Core::GetApplication().useEventBusTo().pushEvent<MouseMovedEvent>(windowPtr, glm::ivec2(glm::floor(x), glm::floor(y)));
   }

   void Mouse::CursorEnterInput(GLFWwindow* window, int entered) noexcept
   {
      PushMouseEvent<MouseEnteredEvent>(window, static_cast<bool>(entered));
   }

   void Mouse::MouseButtonInput(GLFWwindow* window, int button, int type, int mods) noexcept
   {
      switch (type)
      {
         case GLFW_RELEASE:
            PushMouseEvent<MouseButtonReleasedEvent>(window, static_cast<Button>(button), static_cast<uint32_t>(mods));
            break;
         case GLFW_PRESS:
            PushMouseEvent<MouseButtonPressedEvent>(window, static_cast<Button>(button), static_cast<uint32_t>(mods));
            break;
      }
   }

   void Mouse::MouseWheelInput(GLFWwindow* window, double dx, double dy) noexcept
   {
      PushMouseEvent<MouseScrolledEvent>(window, dx, dy);
   }

   void Mouse::DropInput(GLFWwindow* window, int count, char const* paths[]) noexcept
   {
      // TODO
   }
}

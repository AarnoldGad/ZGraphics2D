#include "zgpch.hpp"

#include "zgraphics2D/Input/Mouse.hpp"

#include "zgraphics2D/Input/Event/MouseMovedEvent.hpp"
#include "zgraphics2D/Input/Event/MouseEnteredEvent.hpp"
#include "zgraphics2D/Input/Event/MouseButtonPressedEvent.hpp"
#include "zgraphics2D/Input/Event/MouseButtonReleasedEvent.hpp"
#include "zgraphics2D/Input/Event/MouseScrolledEvent.hpp"
#include "zgraphics2D/Input/Event/MouseDroppedEvent.hpp"

namespace zg
{
   Window* Mouse::s_window = nullptr;

   void Mouse::SetPosition(glm::ivec2 pos) noexcept
   {
      if (!s_window) return;

      glfwSetCursorPos(s_window->getHandle(), static_cast<double>(pos.x), static_cast<double>(pos.y));
   }

   void Mouse::SetCursorMode(CursorMode mode) noexcept
   {
      if (!s_window) return;

      glfwSetInputMode(s_window->getHandle(), GLFW_CURSOR, static_cast<int>(mode));
   }

   void Mouse::SetRawMouseMotion(bool raw) noexcept
   {
      if (!s_window) return;

      if (glfwRawMouseMotionSupported())
         glfwSetInputMode(s_window->getHandle(), GLFW_RAW_MOUSE_MOTION, raw ? GLFW_TRUE : GLFW_FALSE);
   }

   void Mouse::ConnectWindow(Window* window) noexcept
   {
      if (window)
      {
         glfwSetCursorPosCallback(window->getHandle(), &Mouse::CursorPositionInput);
         glfwSetCursorEnterCallback(window->getHandle(), &Mouse::CursorEnterInput);

         glfwSetMouseButtonCallback(window->getHandle(), &Mouse::MouseButtonInput);
         glfwSetScrollCallback(window->getHandle(), &Mouse::MouseWheelInput);

         glfwSetDropCallback(window->getHandle(), &Mouse::DropInput);
      }
   }

   void Mouse::DisconnectWindow(Window* window) noexcept
   {
      if (window)
      {
         glfwSetCursorPosCallback(window->getHandle(), nullptr);
         glfwSetCursorEnterCallback(window->getHandle(), nullptr);

         glfwSetMouseButtonCallback(window->getHandle(), nullptr);
         glfwSetScrollCallback(window->getHandle(), nullptr);

         glfwSetDropCallback(window->getHandle(), nullptr);
      }
   }

   void Mouse::CursorPositionInput(GLFWwindow* window, double x, double y)
   {
      Window* windowPtr = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
      ze::Core::UseEventBus().pushEvent<MouseMovedEvent>(windowPtr, glm::ivec2(glm::floor(x), glm::floor(y)));
   }

   void Mouse::CursorEnterInput(GLFWwindow* window, int entered)
   {
      PushMouseEvent<MouseEnteredEvent>(window, static_cast<bool>(entered));
   }

   void Mouse::MouseButtonInput(GLFWwindow* window, int button, int type, int mods)
   {
      switch (type)
      {
         case GLFW_RELEASE:
            PushMouseEvent<MouseButtonReleasedEvent>(window, static_cast<Button>(button), static_cast<uint32_t>(mods));
            break;
         case GLFW_PRESS:
            PushMouseEvent<MouseButtonPressedEvent>(window, static_cast<Button>(button), static_cast<uint32_t>(mods));
            break;
         default:
            break;
      }
   }

   void Mouse::MouseWheelInput(GLFWwindow* window, double dx, double dy)
   {
      PushMouseEvent<MouseScrolledEvent>(window, dx, dy);
   }

   void Mouse::DropInput(GLFWwindow* window, int count, char const* paths[])
   {
      PushMouseEvent<MouseDroppedEvent>(window, count, paths);
   }
}

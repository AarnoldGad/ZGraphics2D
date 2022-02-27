#include "zgpch.hpp"

#include "detail/Input/GLFWMouse.hpp"

#include "zgraphics2D/Input/Event/MouseMovedEvent.hpp"
#include "zgraphics2D/Input/Event/MouseEnteredEvent.hpp"
#include "zgraphics2D/Input/Event/MouseButtonPressedEvent.hpp"
#include "zgraphics2D/Input/Event/MouseButtonReleasedEvent.hpp"
#include "zgraphics2D/Input/Event/MouseScrolledEvent.hpp"
#include "zgraphics2D/Input/Event/MouseDroppedEvent.hpp"

namespace zg { namespace details
{
   std::shared_ptr<Window> MouseImpl::s_window = nullptr;

   void MouseImpl::ConnectWindow(std::shared_ptr<Window> window)
   {
      if (window)
      {
         GLFWwindow* windowPtr = static_cast<GLFWwindow*>(window->getHandle());
         glfwSetCursorPosCallback(windowPtr, &MouseImpl::CursorPositionInput);
         glfwSetCursorEnterCallback(windowPtr, &MouseImpl::CursorEnterInput);

         glfwSetMouseButtonCallback(windowPtr, &MouseImpl::MouseButtonInput);
         glfwSetScrollCallback(windowPtr, &MouseImpl::MouseWheelInput);

         glfwSetDropCallback(windowPtr, &MouseImpl::DropInput);
      }
   }

   void MouseImpl::DisconnectWindow(std::shared_ptr<Window> window)
   {
      if (window)
      {
         GLFWwindow* windowPtr = static_cast<GLFWwindow*>(window->getHandle());
         glfwSetCursorPosCallback(windowPtr, nullptr);
         glfwSetCursorEnterCallback(windowPtr, nullptr);

         glfwSetMouseButtonCallback(windowPtr, nullptr);
         glfwSetScrollCallback(windowPtr, nullptr);

         glfwSetDropCallback(windowPtr, nullptr);
      }
   }

   void MouseImpl::SetActiveWindow(std::shared_ptr<Window> window)
   {
      s_window = window;
   }

   std::string MouseImpl::GetButtonName(Mouse::Button button)
   {
      switch (button)
      {
         case Mouse::Button::Left:
            return "Left";
         case Mouse::Button::Right:
            return "Right";
         case Mouse::Button::Middle:
            return "Middle";
         case Mouse::Button::X1:
            return "X1";
         case Mouse::Button::X2:
            return "X2";
         case Mouse::Button::X3:
            return "X3";
         case Mouse::Button::X4:
            return "X4";
         case Mouse::Button::X5:
            return "X5";
         default:
            return "Unknown";
      }
   }

   bool MouseImpl::IsButtonPressed(Mouse::Button button)
   {
      if (!s_window) return false;

      return static_cast<bool>(glfwGetMouseButton(static_cast<GLFWwindow*>(s_window->getHandle()),
                               static_cast<int>(button)));
   }

   glm::ivec2 MouseImpl::GetPosition()
   {
      if (!s_window) return { 0,0 };

      double x, y;
      glfwGetCursorPos(static_cast<GLFWwindow*>(s_window->getHandle()), &x, &y);
      return { glm::floor(x), glm::floor(y) };
   }

   void MouseImpl::SetPosition(glm::ivec2 pos)
   {
      if (!s_window) return;

      glfwSetCursorPos(static_cast<GLFWwindow*>(s_window->getHandle()), static_cast<double>(pos.x), static_cast<double>(pos.y));
   }

   void MouseImpl::SetCursorMode(Mouse::CursorMode mode)
   {
      if (!s_window) return;

      glfwSetInputMode(static_cast<GLFWwindow*>(s_window->getHandle()), GLFW_CURSOR, static_cast<int>(mode));
   }

   void MouseImpl::SetRawMouseMotion(bool raw)
   {
      if (!s_window) return;

      if (glfwRawMouseMotionSupported())
         glfwSetInputMode(static_cast<GLFWwindow*>(s_window->getHandle()), GLFW_RAW_MOUSE_MOTION, raw ? GLFW_TRUE : GLFW_FALSE);
   }

   void MouseImpl::CursorPositionInput(GLFWwindow* window, double x, double y)
   {
      Window* windowPtr = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
      ze::Core::UseEventBus().pushEvent<MouseMovedEvent>(windowPtr, glm::ivec2(glm::floor(x), glm::floor(y)));
   }

   void MouseImpl::CursorEnterInput(GLFWwindow* window, int entered)
   {
      PushMouseEvent<MouseEnteredEvent>(window, static_cast<bool>(entered));
   }

   void MouseImpl::MouseButtonInput(GLFWwindow* window, int button, int type, int mods)
   {
      switch (type)
      {
         case GLFW_RELEASE:
            PushMouseEvent<MouseButtonReleasedEvent>(window, static_cast<Mouse::Button>(button),
                                                     static_cast<uint32_t>(mods));
            break;
         case GLFW_PRESS:
            PushMouseEvent<MouseButtonPressedEvent>(window, static_cast<Mouse::Button>(button),
                                                    static_cast<uint32_t>(mods));
            break;
         default:
            break;
      }
   }

   void MouseImpl::MouseWheelInput(GLFWwindow* window, double dx, double dy)
   {
      PushMouseEvent<MouseScrolledEvent>(window, dx, dy);
   }

   void MouseImpl::DropInput(GLFWwindow* window, int count, char const* paths[])
   {
      PushMouseEvent<MouseDroppedEvent>(window, count, paths);
   }
}}

#include "zgpch.hpp"

#include "detail/Input/GLFWKeyboard.hpp"

#include "zgraphics2D/Input/Event/KeyPressedEvent.hpp"
#include "zgraphics2D/Input/Event/KeyReleasedEvent.hpp"
#include "zgraphics2D/Input/Event/KeyRepeatedEvent.hpp"

namespace zg { namespace details
{
   std::shared_ptr<Window> KeyboardImpl::s_window = nullptr;

   void KeyboardImpl::ConnectWindow(std::shared_ptr<Window> window)
   {
      if (window)
      {
         GLFWwindow* windowPtr = static_cast<GLFWwindow*>(window->getHandle());
         glfwSetKeyCallback(windowPtr, &KeyboardImpl::KeyInput);
         glfwSetCharCallback(windowPtr, &KeyboardImpl::TextInput);
      }
   }

   void KeyboardImpl::DisconnectWindow(std::shared_ptr<Window> window)
   {
      if (window)
      {
         GLFWwindow* windowPtr = static_cast<GLFWwindow*>(window->getHandle());
         glfwSetKeyCallback(windowPtr, nullptr);
         glfwSetCharCallback(windowPtr, nullptr);
      }
   }

   void KeyboardImpl::SetActiveWindow(std::shared_ptr<Window> window)
   {
      s_window = window;
   }

   std::string KeyboardImpl::GetKeyName(Keyboard::Key key)
   {
      char const* name = glfwGetKeyName(static_cast<int>(key), GetKeyScancode(key));
      return name ? name : "";
   }

   int KeyboardImpl::GetKeyScancode(Keyboard::Key key)
   {
      return glfwGetKeyScancode(static_cast<int>(key));
   }

   bool KeyboardImpl::IsKeyPressed(Keyboard::Key key)
   {
      if (!s_window) return false;

      return static_cast<bool>(glfwGetKey(static_cast<GLFWwindow*>(s_window->getHandle()), static_cast<int>(key)));
   }

   uint32_t KeyboardImpl::GetModifiers()
   {
      uint32_t mods = 0;

      mods |= (IsKeyPressed(Keyboard::Key::LeftShift)   || IsKeyPressed(Keyboard::Key::RightShift))
                  ? static_cast<uint32_t>(Keyboard::Modifiers::Shift)    : 0;
      mods |= (IsKeyPressed(Keyboard::Key::LeftControl) || IsKeyPressed(Keyboard::Key::RightControl))
                  ? static_cast<uint32_t>(Keyboard::Modifiers::Ctrl)     : 0;
      mods |= (IsKeyPressed(Keyboard::Key::LeftAlt)     || IsKeyPressed(Keyboard::Key::RightAlt))
                  ? static_cast<uint32_t>(Keyboard::Modifiers::Alt)      : 0;
      mods |= (IsKeyPressed(Keyboard::Key::LeftSuper)   || IsKeyPressed(Keyboard::Key::RightSuper))
                  ? static_cast<uint32_t>(Keyboard::Modifiers::Super)    : 0;
      mods |= (IsKeyPressed(Keyboard::Key::CapsLock))
                  ? static_cast<uint32_t>(Keyboard::Modifiers::CapsLock) : 0;
      mods |= (IsKeyPressed(Keyboard::Key::NumLock))
                  ? static_cast<uint32_t>(Keyboard::Modifiers::NumLock)  : 0;

      return mods;
   }

   void KeyboardImpl::KeyInput(GLFWwindow* window, int key, int scancode, int type, int modifiers)
   {
      switch (type)
      {
         case GLFW_RELEASE:
            PushKeyEvent<KeyReleasedEvent>(window, key, scancode, modifiers);
            break;
         case GLFW_PRESS:
            PushKeyEvent<KeyPressedEvent>(window, key, scancode, modifiers);
            break;
         case GLFW_REPEAT:
            PushKeyEvent<KeyRepeatedEvent>(window, key, scancode, modifiers);
            break;
         default:
            break;
      }
   }

   void KeyboardImpl::TextInput(GLFWwindow* window, uint32_t codepoint)
   {
      // TODO
   }
}}


#include "zgpch.hpp"

#include "zgraphics2D/Input/Keyboard.hpp"

#include "zgraphics2D/Window/Window.hpp"
#include "zgraphics2D/Input/Event/KeyPressedEvent.hpp"
#include "zgraphics2D/Input/Event/KeyReleasedEvent.hpp"
#include "zgraphics2D/Input/Event/KeyRepeatedEvent.hpp"

namespace zg
{
   Window* Keyboard::s_window = nullptr;

   void Keyboard::ConnectWindow(Window* window) noexcept
   {
      if (window)
      {
         glfwSetKeyCallback(window->getHandle(), &Keyboard::KeyInput);
         glfwSetCharCallback(window->getHandle(), &Keyboard::TextInput);
      }
   }

   void Keyboard::DisconnectWindow(Window* window) noexcept
   {
      if (window)
      {
         glfwSetKeyCallback(window->getHandle(), nullptr);
         glfwSetCharCallback(window->getHandle(), nullptr);
      }
   }

   uint32_t Keyboard::GetModifiers() noexcept
   {
      uint32_t mods = 0;

      mods |= (IsKeyPressed(Key::LeftShift)   || IsKeyPressed(Key::RightShift))
                  ? static_cast<uint32_t>(Modifiers::Shift)    : 0;
      mods |= (IsKeyPressed(Key::LeftControl) || IsKeyPressed(Key::RightControl))
                  ? static_cast<uint32_t>(Modifiers::Ctrl)     : 0;
      mods |= (IsKeyPressed(Key::LeftAlt)     || IsKeyPressed(Key::RightAlt))
                  ? static_cast<uint32_t>(Modifiers::Alt)      : 0;
      mods |= (IsKeyPressed(Key::LeftSuper)   || IsKeyPressed(Key::RightSuper))
                  ? static_cast<uint32_t>(Modifiers::Super)    : 0;
      mods |= (IsKeyPressed(Key::CapsLock))
                  ? static_cast<uint32_t>(Modifiers::CapsLock) : 0;
      mods |= (IsKeyPressed(Key::NumLock))
                  ? static_cast<uint32_t>(Modifiers::NumLock)  : 0;

      return mods;
   }

   void Keyboard::KeyInput(GLFWwindow* window, int key, int scancode, int type, int modifiers)
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
      }
   }

   void Keyboard::TextInput(GLFWwindow* window, uint32_t codepoint)
   {
      // TODO
   }
}

#include "zgraphics2D/Input/Keyboard.hpp"

#include "zgraphics2D/Window/Window.hpp"
#include "zgraphics2D/Input/Event/KeyPressedEvent.hpp"
#include "zgraphics2D/Input/Event/KeyReleasedEvent.hpp"
#include "zgraphics2D/Input/Event/KeyRepeatedEvent.hpp"

#include <zengine/Memory/New.hpp>

namespace zg
{
   Keyboard::Keyboard(Window* window)
      : m_window(window)
   {
      if (m_window)
      {
         glfwSetKeyCallback(m_window->getHandle(), &Keyboard::KeyInput);
         glfwSetCharCallback(m_window->getHandle(), &Keyboard::TextInput);
      }
   }

   void Keyboard::setWindow(Window* window) noexcept
   {
      if (m_window) // Reset last window if one
      {
         glfwSetKeyCallback(m_window->getHandle(), nullptr);
         glfwSetCharCallback(m_window->getHandle(), nullptr);
      }

      if (m_window = window, m_window) // Set new window
      {
         glfwSetKeyCallback(m_window->getHandle(), &Keyboard::KeyInput);
         glfwSetCharCallback(m_window->getHandle(), &Keyboard::TextInput);
      }
   }

   uint32_t Keyboard::getModifiers() noexcept
   {
      uint32_t mods = 0;

      mods |= (isKeyPressed(Key::LeftShift)   || isKeyPressed(Key::RightShift))
                  ? static_cast<uint32_t>(Modifiers::Shift)    : 0;
      mods |= (isKeyPressed(Key::LeftControl) || isKeyPressed(Key::RightControl))
                  ? static_cast<uint32_t>(Modifiers::Ctrl)     : 0;
      mods |= (isKeyPressed(Key::LeftAlt)     || isKeyPressed(Key::RightAlt))
                  ? static_cast<uint32_t>(Modifiers::Alt)      : 0;
      mods |= (isKeyPressed(Key::LeftSuper)   || isKeyPressed(Key::RightSuper))
                  ? static_cast<uint32_t>(Modifiers::Super)    : 0;
      mods |= (isKeyPressed(Key::CapsLock))
                  ? static_cast<uint32_t>(Modifiers::CapsLock) : 0;
      mods |= (isKeyPressed(Key::NumLock))
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

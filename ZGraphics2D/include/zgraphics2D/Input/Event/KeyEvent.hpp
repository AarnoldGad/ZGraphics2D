/**
 * KeyEvent.hpp
 * 21 Jun 2021
 * Gaétan "The Aarnold" Jalin
 *
 * Copyright (C) 2020-2021 Gaétan Jalin
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 *    1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 *
 *    2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 *
 *    3. This notice may not be removed or altered from any source distribution.
 **/
#ifndef ZG_KEYEVENT_HPP
#define ZG_KEYEVENT_HPP

#include "zgraphics2D/defines.hpp"

#include "zgraphics2D/Window/Window.hpp"
#include "zgraphics2D/Input/Keyboard.hpp"

namespace zg
{
   class ZG_API KeyEvent : public ze::Event
   {
   public:
      enum class Action
      {
         Released = GLFW_RELEASE,
         Pressed = GLFW_PRESS,
         Repeated = GLFW_REPEAT
      };

      Window* getWindow() noexcept;
      Keyboard::Key getKey() const noexcept;
      int getScancode() const noexcept;
      Action getAction() const noexcept;
      uint32_t getModifiers() const noexcept;

      explicit KeyEvent(Window* window, Keyboard::Key key, int scancode, Action action, uint32_t modifiers);

   protected:
      Window* m_window;
      Keyboard::Key m_key;
      int m_scancode;
      Action m_action;
      uint32_t m_modifiers;
   };
}

#include "KeyEvent.inl"

#endif // ZG_KEYEVENT_HPP

/**
 * MouseButtonEvent.hpp
 * 30 Jun 2021
 * Ga�tan "The Aarnold" Jalin
 *
 * Copyright (C) 2020-2021 Ga�tan Jalin
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
#ifndef ZG_MOUSEBUTTONEVENT_HPP
#define ZG_MOUSEBUTTONEVENT_HPP

#include "zgraphics2D/zgmacros.hpp"

#include "zgraphics2D/Input/Event/MouseEvent.hpp"

namespace zg
{
   class ZE_API MouseButtonEvent : public MouseEvent
   {
   public:
      enum class Action
      {
         Pressed = GLFW_PRESS,
         Released = GLFW_RELEASE
      };

      Mouse::Button getButton() const noexcept;
      Action getAction() const noexcept;
      uint32_t getModifiers() const noexcept;

      std::string toString() const override;

      MouseButtonEvent(Window* window, glm::ivec2 pos, Mouse::Button button, Action action, uint32_t modifiers);

   protected:
      Mouse::Button m_button;
      Action m_action;
      uint32_t m_modifiers;
   };
}

#include "MouseButtonEvent.inl"

#endif // ZG_MOUSEBUTTONEVENT_HPP
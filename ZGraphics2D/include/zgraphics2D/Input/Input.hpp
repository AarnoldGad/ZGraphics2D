/**
 * Input.hpp
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
#ifndef ZG_INPUT_HPP
#define ZG_INPUT_HPP

#include "zgraphics2D/zgmacros.hpp"

namespace zg
{
   class ZE_API Input
   {
   public:
      static void Initialise(GLFWwindow* window);

   private:
      static void KeyInput(GLFWwindow* window, int key, int scancode, int type, int mods) noexcept;
      static void TextInput(GLFWwindow* window, uint32_t codepoint) noexcept;

      static void CursorPositionInput(GLFWwindow* window, double x, double y) noexcept;
      static void CursorEnterInput(GLFWwindow* window, int entered) noexcept;
      static void MouseButtonInput(GLFWwindow* window, int button, int type, int mods) noexcept;
      static void MouseWheelInput(GLFWwindow* window, double dx, double dy) noexcept;

      static void DropInput(GLFWwindow* window, int count, char const* paths[]) noexcept;

      // TODO Joystick

      Input() = delete;
   };
}

#endif // ZG_INPUT_HPP
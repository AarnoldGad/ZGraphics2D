/**
 * Mouse.hpp
 * 22 Jun 2021
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
#ifndef ZG_MOUSE_HPP
#define ZG_MOUSE_HPP

#include "zgraphics2D/zgmacros.hpp"

namespace zg
{
   class ZE_API Mouse
   {
   public:
      enum Button : uint32_t
      {
         Left = GLFW_MOUSE_BUTTON_LEFT,
         Right = GLFW_MOUSE_BUTTON_RIGHT,
         Middle = GLFW_MOUSE_BUTTON_MIDDLE,
         X1 = GLFW_MOUSE_BUTTON_4,
         X2 = GLFW_MOUSE_BUTTON_5,
         X3 = GLFW_MOUSE_BUTTON_6,
         X4 = GLFW_MOUSE_BUTTON_7,
         X5 = GLFW_MOUSE_BUTTON_8,
      };
   };
}

#endif // ZG_MOUSE_HPP
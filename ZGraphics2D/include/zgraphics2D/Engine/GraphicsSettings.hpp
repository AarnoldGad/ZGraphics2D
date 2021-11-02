/**
 * GraphicsSettings.hpp
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
#ifndef ZG_GRAPHICSSETTINGS_HPP
#define ZG_GRAPHICSSETTINGS_HPP

#include "zgraphics2D/defines.hpp"

#include "zgraphics2D/Window/ContextSettings.hpp"
#include "zgraphics2D/Window/FrameBufferSettings.hpp"
#include "zgraphics2D/Window/WindowSettings.hpp"
#include "zgraphics2D/Common/Colors.hpp"
#include "zgraphics2D/Window/Window.hpp"

namespace zg
{
   struct GraphicsSettings
   {
      std::string title = "ZEngine";
      glm::ivec2 size = { 800, 600 };
      glm::ivec2 pos = Window::PositionUndefined;
      glm::vec4 color = Colors::Beige;
      uint32_t clearMask = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT;

      ContextSettings context = {};
      FrameBufferSettings framebuffer = {};
      WindowSettings window = {};
   };
}

#endif // ZG_GRAPHICSSETTINGS_HPP

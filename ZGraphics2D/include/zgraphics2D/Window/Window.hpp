/**
 * Window.hpp
 * 24 Jun 2021
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
#ifndef ZG_WINDOW_HPP
#define ZG_WINDOW_HPP

#include "zgraphics2D/defines.hpp"

#include "zgraphics2D/Common/Colors.hpp"
#include "zgraphics2D/Common/Image.hpp"
#include "zgraphics2D/Window/ContextSettings.hpp"
#include "zgraphics2D/Window/FrameBufferSettings.hpp"
#include "zgraphics2D/Window/WindowSettings.hpp"
#include "zgraphics2D/Window/Event/WindowResisedEvent.hpp"

namespace zg
{
   namespace details
   {
      class WindowImpl;
   }

   class ZG_API Window
   {
   public:
      static glm::ivec2 constexpr PositionCentered = { 0xFF000000, 0xFF000000 };
      static glm::ivec2 constexpr PositionUndefined = { 0xFE000000, 0xFE000000 };

      static void Configure(WindowSettings window, ContextSettings context, FrameBufferSettings framebuffer);
      
      [[nodiscard]]
      static std::unique_ptr<Window> Make(std::string const& title, glm::ivec2 size, glm::ivec2 pos = PositionUndefined);

      void clear();
      void draw();

      void show();
      void hide();
      void close();

      std::string const& getTitle() const;
      glm::ivec2 getSize() const;
      glm::ivec2 getFramebufferSize() const;
      // Image const& getIcon() const;
      glm::ivec2 getPosition() const;
      float getOpacity() const;
      bool isVisible() const;
      bool shouldClose() const;
      glm::vec4 getColor() const;

      void setTitle(std::string const& title);
      void setSize(int width, int height);
      void setSize(glm::ivec2 size);
      void setIcon(Image const& icon);
      void setPosition(int x, int y);
      void setPosition(glm::ivec2 pos);
      void setOpacity(float opacity);
      void setVisible(bool visible);
      void setColor(float r, float g, float b, float a);
      void setColor(glm::vec4 color);

      void* getHandle() noexcept;

      Window(std::string const& title, glm::ivec2 size, glm::ivec2 pos = PositionUndefined);
      Window();
      ~Window();

   protected:
      std::unique_ptr<details::WindowImpl> m_impl;
   };
}

#endif // ZG_WINDOW_HPP

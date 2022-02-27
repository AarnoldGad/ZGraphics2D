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
   class ZG_API Window
   {
   public:
      static glm::ivec2 constexpr PositionCentered = { 0xFF000000, 0xFF000000 };
      static glm::ivec2 constexpr PositionUndefined = { 0xFE000000, 0xFE000000 };

      static void Configure(WindowSettings window, ContextSettings context, FrameBufferSettings framebuffer);
      static std::shared_ptr<Window> Make(std::string const& title, glm::ivec2 size, glm::ivec2 pos = PositionUndefined);

      virtual void clear() = 0;
      virtual void draw() = 0;

      virtual void show() = 0;
      virtual void hide() = 0;
      virtual void close() = 0;

      virtual std::string const& getTitle() const noexcept = 0;
      virtual glm::ivec2 getSize() const noexcept = 0;
      virtual glm::ivec2 getFramebufferSize() const noexcept = 0;
      // virtual Image const& getIcon() const noexcept = 0;
      virtual glm::ivec2 getPosition() const noexcept = 0;
      virtual float getOpacity() const noexcept = 0;
      virtual bool isVisible() const noexcept = 0;
      virtual bool shouldClose() const noexcept = 0;
      virtual glm::vec4 getColor() const noexcept = 0;
      virtual uint32_t getClearMask() const noexcept = 0;

      virtual void setTitle(std::string const& title) = 0;
      virtual void setSize(int width, int height) = 0;
      virtual void setSize(glm::ivec2 size) = 0;
      virtual void setIcon(Image const& icon) = 0;
      virtual void setPosition(int x, int y) = 0;
      virtual void setPosition(glm::ivec2 pos) = 0;
      virtual void setOpacity(float opacity) = 0;
      virtual void setVisible(bool visible) = 0;
      virtual void setColor(float r, float g, float b, float a) noexcept = 0;
      virtual void setColor(glm::vec4 color) noexcept = 0;
      virtual void setClearMask(uint32_t mask) noexcept = 0;

      virtual void* getHandle() noexcept = 0;

      virtual ~Window() = default;

   protected:
      virtual void open(std::string const& title, glm::ivec2 size, glm::ivec2 pos) = 0;
   };
}

#endif // ZG_WINDOW_HPP

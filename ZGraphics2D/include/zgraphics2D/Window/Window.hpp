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

#include "zgraphics2D/zgmacros.hpp"

#include "zgraphics2D/Window/ContextSettings.hpp"
#include "zgraphics2D/Window/FrameBufferSettings.hpp"
#include "zgraphics2D/Window/WindowSettings.hpp"

namespace zg
{
   class ZE_API Window
   {
   public:
      void create(std::string const& title, glm::ivec2 size, glm::vec4 color,
                  WindowSettings window = {}, ContextSettings context = {}, FrameBufferSettings framebuffer = {});

      std::string getTitle() const noexcept;
      glm::ivec2 getSize() const noexcept;
      //? getIcon() const noexcept;
      glm::ivec2 getPosition() const noexcept;
      float getOpacity() const noexcept;
      bool isVisible() const noexcept;
      bool shouldClose() const noexcept;
      glm::vec4 getColor() const noexcept;
      uint32_t getClearMask() const noexcept;

      void clear();
      void draw();

      void show();
      void hide();
      void close();

      void setTitle(std::string const& title);
      void setSize(int width, int height);
      void setSize(glm::ivec2 size);
      //void setIcon(?); // TODO Images
      void setPosition(int x, int y);
      void setPosition(glm::ivec2 pos);
      void setOpacity(float opacity);
      void setVisible(bool visible);
      void setColor(glm::vec4 color) noexcept;
      void setClearMask(uint32_t mask) noexcept;

      GLFWwindow* getHandle() noexcept;

      Window(std::string const& title, glm::ivec2 size, glm::vec4 color,
             WindowSettings window = {}, ContextSettings context = {}, FrameBufferSettings framebuffer = {});
      Window();
      ~Window();

   private:
      static void Moved(GLFWwindow* window, int x, int y);
      static void Resised(GLFWwindow* window, int width, int height);
      static void Closed(GLFWwindow* window);
      static void Refreshed(GLFWwindow* window);
      static void Focused(GLFWwindow* window, int focused);
      static void Iconified(GLFWwindow* window, int iconified);
      static void Maximised(GLFWwindow* window, int maximised);
      static void FramebufferResised(GLFWwindow* window, int width, int height);
      static void Scaled(GLFWwindow* window, float xscale, float yscale);

      template<typename EventType, typename... Args>
      static void PushWindowEvent(GLFWwindow* window, Args&&... args);

      void configureWindow(WindowSettings window, ContextSettings context, FrameBufferSettings framebuffer);
      void makeWindow();
      void installWindow();

      GLFWwindow* m_handle;

      std::string m_title;
      glm::ivec2 m_size;
      glm::vec4 m_color;
      uint32_t m_clearMask;
   };
}

#include "Window.inl"

#endif // ZG_WINDOW_HPP

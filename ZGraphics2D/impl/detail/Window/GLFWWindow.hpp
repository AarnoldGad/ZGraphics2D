/**
 * GLFWWindow.hpp
 * 23 Feb 2022
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
#ifndef ZG_WINDOWIMPL_HPP
#define ZG_WINDOWIMPL_HPP

#include "zgraphics2D/defines.hpp"

#include "zgraphics2D/Window/Window.hpp"

#include <GLFW/glfw3.h>

namespace zg { namespace details
{
   class ZG_DETAIL WindowImpl : public Window
   {
   public:
      static void ConfigureWindow(WindowSettings window, ContextSettings context, FrameBufferSettings framebuffer);

      void clear() override;
      void draw() override;

      void show() override;
      void hide() override;
      void close() override;

      std::string const& getTitle() const noexcept override;
      glm::ivec2 getSize() const noexcept override;
      glm::ivec2 getFramebufferSize() const noexcept override;
      // Image const& getIcon() const noexcept override;
      glm::ivec2 getPosition() const noexcept override;
      float getOpacity() const noexcept override;
      bool isVisible() const noexcept override;
      bool shouldClose() const noexcept override;
      glm::vec4 getColor() const noexcept override;
      uint32_t getClearMask() const noexcept override;

      void setTitle(std::string const& title) override;
      void setSize(int width, int height) override;
      void setSize(glm::ivec2 size) override;
      void setIcon(Image const& icon) override;
      void setPosition(int x, int y) override;
      void setPosition(glm::ivec2 pos) override;
      void setOpacity(float opacity) override;
      void setVisible(bool visible) override;
      void setColor(float r, float g, float b, float a) noexcept override;
      void setColor(glm::vec4 color) noexcept override;
      void setClearMask(uint32_t mask) noexcept override;

      void* getHandle() noexcept override;

      WindowImpl();
      ~WindowImpl();

   private:
      void open(std::string const& title, glm::ivec2 size, glm::ivec2 pos = Window::PositionUndefined) override;

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

      GLFWwindow* m_handle;

      std::string m_title;
      glm::ivec2 m_size;
      glm::ivec2 m_pos;
      glm::vec4 m_color;
      uint32_t m_clearMask;
   };
}}

#include "GLFWWindow.inl"

#endif // ZG_WINDOWIMPL_HPP

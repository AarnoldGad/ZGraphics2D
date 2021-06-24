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

namespace zg
{
   class ZE_API Window
   {
   public:
      std::string getName() const noexcept;
      std::tuple<size_t, size_t> getSize() const noexcept; // TODO Vectors
      //? getIcon() const noexcept;
      std::tuple<size_t, size_t> getPosition() const noexcept; // TODO Vectors
      float getOpacity() const noexcept;
      bool isVisible() const noexcept;
      bool shouldClose() const noexcept;
      //? getClearColor() const noexcept;
      uint32_t getClearMask() const noexcept;

      void clear();
      void draw();

      void show();
      void hide();
      void close();

      void setName(std::string const& name);
      void setSize(size_t width, size_t height); // TODO Vectors
      //void setIcon(?);
      void setPosition(size_t x, size_t y); // TODO Vectors
      void setOpacity(float opacity);
      void setVisible(bool visible);
      //void setClearColor(?); // TODO Vectors
      void setClearMask(uint32_t mask);

      GLFWwindow* getHandle() const noexcept;

      Window(std::string const& name, size_t width, size_t height);
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

      std::string m_name;
      uint32_t m_clearMask;

      GLFWwindow* m_handle;
   };
}

#include "Window.inl"

#endif // ZG_WINDOW_HPP
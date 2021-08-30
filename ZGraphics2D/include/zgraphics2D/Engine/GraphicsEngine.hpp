/**
 * GraphicsEngine.hpp
 * 22 May 2021
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
#ifndef ZG_GRAPHICSENGINE_HPP
#define ZG_GRAPHICSENGINE_HPP

#include "zgraphics2D/zgmacros.hpp"

#include "zgraphics2D/Engine/GraphicsSettings.hpp"
#include "zgraphics2D/Window/Window.hpp"
#include "zgraphics2D/Input/Keyboard.hpp"
#include "zgraphics2D/Input/Mouse.hpp"

namespace zg
{
   class ZG_API GraphicsEngine : public ze::Engine
   {
   public:
      static ze::Logger& UseGraphicsLogger() noexcept;

      Window& getWindow() noexcept;
      Keyboard& getKeyboard() noexcept;
      Mouse& getMouse() noexcept;

      void initialise() override;

      void tick(ze::Time deltaTime) override;

      void terminate() override;

      explicit GraphicsEngine(GraphicsSettings settings = {});
      ~GraphicsEngine();

      ze::Signal<void ()> renderingSignal;
      
   private:
      static void InitGLFW();
      static void LoadOpenGL();
      void openWindow();

      static void HandleGLFWError(int code, char const* description);

   private:
      static bool s_isGLFWInitialised;
      static bool s_isOpenGLLoaded;

      bool m_isInitialised;
      GraphicsSettings m_settings;

      Window m_window;
      Keyboard m_keyboard;
      Mouse m_mouse;
   };
}

#include "GraphicsEngine.inl"

#endif // ZG_GRAPHICSENGINE_HPP

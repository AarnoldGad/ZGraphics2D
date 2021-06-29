/**
 * GraphicsEngine.hpp
 * 22 May 2021
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
#ifndef ZG_GRAPHICSENGINE_HPP
#define ZG_GRAPHICSENGINE_HPP

#include "zgraphics2D/zgmacros.hpp"

#include "zgraphics2D/Window/Window.hpp"
#include "zgraphics2D/Input/Keyboard.hpp"

namespace zg
{
   class ZE_API GraphicsEngine : public ze::Engine
   {
   public:
      static ze::Logger& UseGraphicsLogger() noexcept;

      Window& getMainWindow() noexcept;
      Keyboard& getKeyboard() noexcept;

      void initialise() override;

      void tick(ze::Time deltaTime) override;

      void terminate() override;

      GraphicsEngine();
      ~GraphicsEngine();

   private:
      static void HandleGLFWError(int code, char const* description);

      static ze::DebugFileWriter s_gfxWriter;
      static ze::Logger s_gfxLogger;

      bool m_isInitialised;

      Window m_window;
      Keyboard m_keyboard;
   };
}

#include "GraphicsEngine.inl"

#endif // ZG_GRAPHICSENGINE_HPP

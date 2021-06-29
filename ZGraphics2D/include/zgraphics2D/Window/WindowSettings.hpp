/**
 * WindowSettings.hpp
 * 28 Jun 2021
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
#ifndef ZG_WINDOWSETTINGS_HPP
#define ZG_WINDOWSETTINGS_HPP

#include "zgraphics2D/zgmacros.hpp"

namespace zg
{
   struct WindowSettings
   {
      enum class ClientAPI : int
      {
         None = GLFW_NO_API,
         OpenGL = GLFW_OPENGL_API,
         OpenGLES = GLFW_OPENGL_ES_API
      };

      enum class ContextAPI : int
      {
         Native = GLFW_NATIVE_CONTEXT_API,
         EGL = GLFW_EGL_CONTEXT_API,
         Mesa = GLFW_OSMESA_CONTEXT_API
      };

      enum class Robustness : int
      {
         None = GLFW_NO_ROBUSTNESS,
         NoResetNotification = GLFW_NO_RESET_NOTIFICATION,
         LoseContextOnReset = GLFW_LOSE_CONTEXT_ON_RESET
      };

      enum class ReleaseBehavior : int
      {
         None = GLFW_RELEASE_BEHAVIOR_NONE,
         Any = GLFW_ANY_RELEASE_BEHAVIOR,
         Flush = GLFW_RELEASE_BEHAVIOR_FLUSH
      };

      enum class Profile : int
      {
         Any = GLFW_OPENGL_ANY_PROFILE,
         Compatibility = GLFW_OPENGL_COMPAT_PROFILE,
         Core = GLFW_OPENGL_CORE_PROFILE
      };

      bool resisable = false;
      bool visible = true;
      bool decorated = true;
      bool focused = true;
      bool floating = false;
      bool maximised = false;
      bool centerCursor = false;
      bool transparent = false;
      bool focusOnShow = true;
      bool scaleToMonitor = false;
      int refreshRate = -1;
      bool doubleBuffering = true;
      bool autoIconify = true;

      int redBits = 8;
      int greenBits = 8;
      int blueBits = 8;
      int alphaBits = 8;
      int depthBits = 24;
      int stencilBits = 8;
      int accumRedBits = 0;
      int accumGreenBits = 0;
      int accumBlueBits = 0;
      int accumAlphaBits = 0;
      bool srgbCapable = false;

      int samples = 0;
      bool stereo = false;

      ClientAPI api = ClientAPI::OpenGL;
      ContextAPI context = ContextAPI::Native;
      int versionMajor = 3;
      int versionMinor = 3;
      Robustness robustness = Robustness::None;
      ReleaseBehavior releaseBehavior = ReleaseBehavior::Any;
      bool forwardCompatibility = false;
      bool debugContext = false;
      Profile openglProfile = Profile::Core;

      bool cocoa_retinaFrameBuffer = true;
      std::string cocoa_frameName = "";
      bool cocoa_graphicsSwitching = false;

      std::string x11_className = "";
      std::string x11_instanceName = "";

      uint32_t clearMask = GL_COLOR_BUFFER_BIT;
      glm::vec4 clearColor = { 0.8f, 0.5f, 0.1f, 1.f };
   };
}

#endif // ZG_WINDOWSETTINGS_HPP

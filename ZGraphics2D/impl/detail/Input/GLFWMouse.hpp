/**
 * GLFWMouse.hpp
 * 26 Feb 2022
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
#ifndef ZG_MOUSEIMPL_HPP
#define ZG_MOUSEIMPL_HPP

#include "zgraphics2D/defines.hpp"

#include "zgraphics2D/Input/Mouse.hpp"
#include "zgraphics2D/Window/Window.hpp"

namespace zg { namespace details
{
   class ZG_DETAIL MouseImpl
   {
   public:
      static void ConnectWindow(std::shared_ptr<Window> window);
      static void DisconnectWindow(std::shared_ptr<Window> window);
      static void SetActiveWindow(std::shared_ptr<Window> window);

      static std::string GetButtonName(Mouse::Button button);

      static bool IsButtonPressed(Mouse::Button button);
      static glm::ivec2 GetPosition();

      static void SetPosition(glm::ivec2 pos);
      static void SetCursorMode(Mouse::CursorMode mode);
      static void SetRawMouseMotion(bool raw);

   private:
      MouseImpl() = delete;

      static void CursorPositionInput(GLFWwindow* window, double x, double y);
      static void CursorEnterInput(GLFWwindow* window, int entered);
      static void MouseButtonInput(GLFWwindow* window, int button, int type, int mods);
      static void MouseWheelInput(GLFWwindow* window, double dx, double dy);
      static void DropInput(GLFWwindow* window, int count, char const* paths[]);

      template<typename EventType, typename... Args>
      static void PushMouseEvent(GLFWwindow* window, Args&&... args);

      static std::shared_ptr<Window> s_window;
   };
}}

#include "GLFWMouse.inl"

#endif // ZG_MOUSEIMPL_HPP

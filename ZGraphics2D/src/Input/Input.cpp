#include "zgraphics2D/Input/Input.hpp"

namespace zg
{
   void Input::Initialise(GLFWwindow* window)
   {
      glfwSetKeyCallback(window, &Input::KeyInput);
      glfwSetCharCallback(window, &Input::TextInput);

      glfwSetCursorPosCallback(window, &Input::CursorPositionInput);
      glfwSetCursorEnterCallback(window, &Input::CursorEnterInput);

      glfwSetMouseButtonCallback(window, &Input::MouseButtonInput);
      glfwSetScrollCallback(window, &Input::MouseWheelInput);

      glfwSetDropCallback(window, &Input::DropInput);
   }

   void Input::KeyInput(GLFWwindow* window, int key, int scancode, int type, int mods) noexcept
   {

   }

   void Input::TextInput(GLFWwindow* window, uint32_t codepoint) noexcept
   {

   }

   void Input::CursorPositionInput(GLFWwindow* window, double x, double y) noexcept
   {

   }

   void Input::CursorEnterInput(GLFWwindow* window, int entered) noexcept
   {

   }

   void Input::MouseButtonInput(GLFWwindow* window, int button, int type, int mods) noexcept
   {

   }

   void Input::MouseWheelInput(GLFWwindow* window, double dx, double dy) noexcept
   {
       
   }

   void Input::DropInput(GLFWwindow* window, int count, char const* paths[]) noexcept
   {

   }
}
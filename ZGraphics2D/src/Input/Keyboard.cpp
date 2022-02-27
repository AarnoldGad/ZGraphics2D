#include "zgpch.hpp"

#include "zgraphics2D/Input/Keyboard.hpp"

#include "zgraphics2D/Window/Window.hpp"
#include "detail/Input/KeyboardImpl.hpp"

namespace zg
{
   void Keyboard::ConnectWindow(std::shared_ptr<Window> window)
   {
      details::KeyboardImpl::ConnectWindow(window);
   }

   void Keyboard::DisconnectWindow(std::shared_ptr<Window> window)
   {
      details::KeyboardImpl::DisconnectWindow(window);
   }

   void Keyboard::SetActiveWindow(std::shared_ptr<Window> window)
   {
      details::KeyboardImpl::SetActiveWindow(window);
   }

   std::string Keyboard::GetKeyName(Key key)
   {
      return details::KeyboardImpl::GetKeyName(key);
   }

   int Keyboard::GetKeyScancode(Key key)
   {
      return details::KeyboardImpl::GetKeyScancode(key);
   }

   bool Keyboard::IsKeyPressed(Key key)
   {
      return details::KeyboardImpl::IsKeyPressed(key);
   }

   uint32_t Keyboard::GetModifiers()
   {
      return details::KeyboardImpl::GetModifiers();
   }
}

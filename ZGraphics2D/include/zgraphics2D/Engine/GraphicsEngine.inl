#include <zengine/Memory/New.hpp>

inline zg::Window& zg::GraphicsEngine::getWindow() noexcept
{
   return m_window;
}

inline zg::Keyboard& zg::GraphicsEngine::getKeyboard() noexcept
{
   return m_keyboard;
}

inline zg::Mouse& zg::GraphicsEngine::getMouse() noexcept
{
   return m_mouse;
}

#include <zengine/Memory/NewOff.hpp>
